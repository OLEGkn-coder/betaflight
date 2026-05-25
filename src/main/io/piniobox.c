/*
 * Фінальний код для piniobox.c (Логіка повністю в ядрі)
 */

#include <stdint.h>

#include "platform.h"

#ifdef USE_PINIOBOX

#include "build/debug.h"
#include "common/time.h"
#include "common/utils.h"
#include "msp/msp_box.h"
#include "pg/pinio.h"
#include "pg/piniobox.h"
#include "scheduler/scheduler.h"
#include "piniobox.h"
#include "rx/rx.h"
#include "fc/core.h"
#include "fc/runtime_config.h"
#include "fc/rc.h"

typedef struct pinioBoxRuntimeConfig_s {
    uint8_t boxId[PINIO_COUNT];
} pinioBoxRuntimeConfig_t;

static pinioBoxRuntimeConfig_t pinioBoxRuntimeConfig;

void pinioBoxInit(const pinioBoxConfig_t *pinioBoxConfig)
{
    for (int i = 0; i < PINIO_COUNT; i++) {
        const box_t *box = findBoxByPermanentId(pinioBoxConfig->permanentId[i]);
        pinioBoxRuntimeConfig.boxId[i] = box ? box->boxId : BOXID_NONE;
    }
}

// Змінні для таймера безперервного утримання газу
static uint32_t customThrottleStartTime = 0;
static bool customThrottleTimerRunning = false;

// Змінні для роботи самого реле
static uint32_t customRelayActivationTime = 0;
static bool customRelayIsActive = false;
static bool customRelayHasFired = false;

static void updateCustomRelay(timeUs_t currentTimeUs) {
    bool isArmed = ARMING_FLAG(ARMED);
    uint16_t throttlePwm = rcData[THROTTLE];
    uint32_t currentMillis = currentTimeUs / 1000;

    // Скидання всіх станів при дизармі
    if (!isArmed) {
        customThrottleTimerRunning = false;
        customRelayHasFired = false;
        if (customRelayIsActive) {
            pinioSet(0, false);
            customRelayIsActive = false;
        }
        return;
    }

    // Запобіжник: якщо вже відстріляли у цьому польоті нічого не робимо
    if (customRelayHasFired && !customRelayIsActive) {
        return;
    }

    // Відстеження газу
    if (throttlePwm > 1950) {
        if (!customThrottleTimerRunning) {
            customThrottleTimerRunning = true;
            customThrottleStartTime = currentMillis;
        } else {
            // Безперервне утримання 4000 мс
            if ((currentMillis - customThrottleStartTime) >= 4000 && !customRelayHasFired) {
                customRelayHasFired = true;
                customRelayIsActive = true;
                customRelayActivationTime = currentMillis;
                pinioSet(0, true); // Вмикаємо реле
            }
        }
    } else {
        customThrottleTimerRunning = false; // Якщо скинули газ хоч на мить таймер обнуляється
    }

    // Таймер утримання напруги на реле 
    if (customRelayIsActive) {
        if ((currentMillis - customRelayActivationTime) >= 3000) {
            pinioSet(0, false); // Вимикаємо реле
            customRelayIsActive = false;
        } else {
            pinioSet(0, true);
        }
    }
}

void pinioBoxUpdate(timeUs_t currentTimeUs)
{
    for (int i = 0; i < PINIO_COUNT; i++) {
        if (pinioBoxRuntimeConfig.boxId[i] != BOXID_NONE) {
            pinioSet(i, getBoxIdState(pinioBoxRuntimeConfig.boxId[i]));
        }
    }

    // Наш кастомний виклик перекриває дефолтні налаштування Betaflight
    updateCustomRelay(currentTimeUs);
}

void pinioBoxTaskControl(void)
{
    setTaskEnabled(TASK_PINIOBOX, true);
}
#endif
// test build

/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
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

typedef struct pinioBoxRuntimeConfig_s {
    uint8_t boxId[PINIO_COUNT];
} pinioBoxRuntimeConfig_t;

static pinioBoxRuntimeConfig_t pinioBoxRuntimeConfig;

void pinioBoxInit(const pinioBoxConfig_t *pinioBoxConfig)
{
    // Convert permanentId to boxId_e

    for (int i = 0; i < PINIO_COUNT; i++) {
        const box_t *box = findBoxByPermanentId(pinioBoxConfig->permanentId[i]);

        pinioBoxRuntimeConfig.boxId[i] = box ? box->boxId : BOXID_NONE;
    }
}

static uint32_t customRelayActivationTime = 0;
static bool customRelayHasFired = false;
static bool customRelayIsActive = false;

static void updateCustomRelay(void) {
    // Отримуємо статус арму та значення газу
    bool isArmed = ARMING_FLAG(ARMED);
    uint16_t throttlePwm = rcData[THROTTLE];

    // скидання всіх станів
    if (!isArmed) {
        customRelayHasFired = false;
        if (customRelayIsActive) {
            pinioSet(0, false); // Примусово вимикаємо PINIO 1 (M7)
            customRelayIsActive = false;
        }
        return;
    }

    // Заармлено + Повний газ + Ще не стріляло
    if (isArmed && throttlePwm > 1950 && !customRelayHasFired) {
        customRelayActivationTime = millis();
        customRelayHasFired = true;
        customRelayIsActive = true;
        pinioSet(0, true); // Вмикаємо PINIO 1 на 3.3V
    }

    // Логіка таймера на 4 секунди
    if (customRelayIsActive) {
        if ((millis() - customRelayActivationTime) >= 4000) {
            pinioSet(0, false); // Знімаємо напругу через 4 секунди
            customRelayIsActive = false;
        } else {
            pinioSet(0, true);  // Підтримуємо 3.3V, поки час не вийшов
        }
    }
}




void pinioBoxUpdate(timeUs_t currentTimeUs)
{
    UNUSED(currentTimeUs);

    for (int i = 0; i < PINIO_COUNT; i++) {
        if (pinioBoxRuntimeConfig.boxId[i] != BOXID_NONE) {
            pinioSet(i, getBoxIdState(pinioBoxRuntimeConfig.boxId[i]));
        }
    }

    updateCustomRelay();
}

void pinioBoxTaskControl(void)
{
 setTaskEnabled(TASK_PINIOBOX, true);
}
#endif

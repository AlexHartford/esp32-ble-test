
/** NimBLE_Server Demo:
 *
 *  Demonstrates many of the available features of the NimBLE server library.
 *  
 *  Created: on March 22 2020
 *      Author: H2zero
 * 
*/
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "IOTComms.h"
#include <stdio.h>

extern "C" {void app_main(void);}

void app_main(void) {
    printf("Starting main\n");
    BLEsetup();

    for(;;){
        vTaskDelay(20);
    }

}
    

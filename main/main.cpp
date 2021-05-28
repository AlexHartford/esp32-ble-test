
/** NimBLE_Server Demo:
 *
 *  Demonstrates many of the available features of the NimBLE server library.
 *  
 *  Created: on March 22 2020
 *      Author: H2zero
 * 
*/


#include "IOTComms.h"
#include "globals.h"
#include "System.h"
#include <stdio.h>

extern "C" {void app_main(void);}

 SystemX* _sys;

 Device populateStartData(){
    Device ret;
    //char* buf;
    size_t buflen = 9;
    // read NVS flash for SN and stuff...
    debugPrintln("pop data1");
    nvs_handle fctry_handle;
    nvs_flash_init_partition("fctry");
    nvs_open_from_partition("fctry", "fctryNamespace",  
                NVS_READWRITE, &fctry_handle);
    nvs_get_str(fctry_handle, "serial_no", ret.SN, &buflen);
    

debugPrintln("pop data2");
    const esp_partition_t *running = esp_ota_get_running_partition();
    esp_app_desc_t running_app_info;
    if (esp_ota_get_partition_description(running, &running_app_info) == ESP_OK) {
        debugPrint("Running firmware version: ");
        debugPrintln(running_app_info.version);
        strcpy(ret.VER, running_app_info.version);
    }
    debugPrintln("pop data3");
    return ret;
}

void app_main(void) {
    printf("Starting main\n");
    debugSetup();
    BLEsetup();

   
    _sys = new SystemX(populateStartData());
    vTaskDelay(300);

    std::string event;

    for(;;){
        event = _sys->buttons->getEvents();
        vTaskDelay(20);
    }

}
    

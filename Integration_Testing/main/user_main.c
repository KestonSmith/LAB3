/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_spiffs.h"

#include "esp_system.h"
#include "esp_spi_flash.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "driver/gpio.h"


#include "esp_log.h"
#include "esp_system.h"
#include "freertos/semphr.h"

#define GPIO_OUTPUT_IO_0    0
#define GPIO_OUTPUT_PIN_SEL  (1ULL<<GPIO_OUTPUT_IO_0)

static const char *TAG = "main";


void static mock (){
 printf("Keston Smith 816001854\n");
int mod = 54%15;
    for (int i = mod; i >= 0; i--) {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
}


void static mock2(){
   uint32_t io_num=0;
   int cnt=0;
   for(int i=0; i<100; i++) {
      ESP_LOGI(TAG, "cnt: %d\n", cnt++);
      ESP_LOGI(TAG, "cnt: %d\n", cnt++);
	   gpio_set_level(GPIO_OUTPUT_IO_0, 0);
	   vTaskDelay(1000 / portTICK_PERIOD_MS);
	   ESP_LOGI(TAG, "GPIO[%d] intr, val: %d\n", io_num, gpio_get_level(io_num));
       
    }
    
}
void app_main()
{ 
 	printf("Integrating Units 1 and Unit 2");
    mock();
    
    mock2();
    printf("Restarting now.\n");

    
    fflush(stdout);
    esp_restart();
}

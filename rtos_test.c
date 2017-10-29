#include "FreeRtOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "croutine.h"

#include "Board_LED.h"                  // ::Board Support:LED
#include "Board_Buttons.h"              // ::Board Support:Buttons

#include "MKW41Z4.h"                    // Device header


static void myTask1(void* pvParameters);
static void myIdleTask(void* pvParameters);

int main()
{
	SystemInit();
	LED_Initialize();
	//LED_On(3);
	
	xTaskCreate(myTask1, (signed char*)"Task1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	xTaskCreate(myIdleTask, (signed char *)"IdleTask", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	
	vTaskStartScheduler();
	
	while(1);
}


/*Task1 ith priority 1*/
static void myTask1(void* pvParameters)
{
	while(1)
	{
		LED_On(1);
		vTaskDelay(500);
		LED_Off(1);
		vTaskDelay(500);
	}
}

static void myIdleTask(void* pvParameters)
{
	while(1)
	{
		LED_On(3);
		vTaskDelay(1000);
		LED_Off(3);
		vTaskDelay(1000);
	}
}

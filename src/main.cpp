#include "main.hpp"

void *operator new(size_t size) {
  return pvPortMalloc(size);
}

void *operator new[](size_t size){
	return pvPortMalloc(size); 
}

void operator delete(void *ptr) {
  vPortFree(ptr);
}

void operator delete[](void *p){
	vPortFree(p); 
}

__ALIGN_BEGIN USB_OTG_CORE_HANDLE  USB_OTG_dev __ALIGN_END;

void task_led_blinking(void *pvParameter) {
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  
  GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
 	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	uint8_t bit = 0;
	while(1) {
		GPIO_WriteBit(GPIOC, GPIO_Pin_8, BitAction(bit));
		bit = !bit;
    vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

int main() {

  xTaskCreate(
    task_led_blinking,
    "task_led_blinking",
    configMINIMAL_STACK_SIZE,
    NULL,
    configMAX_PRIORITIES, 
    NULL
  );

  vTaskStartScheduler();
  while(1) {}
}
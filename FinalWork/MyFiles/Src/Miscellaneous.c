#include "Miscellaneous.h"

int fputc(int ch,FILE *f)
{	
    uint8_t temp[1]={ch};
    HAL_UART_Transmit(&huart1,temp,1,10);
    return ch;
}

int fgetc(FILE *f)
{
	uint8_t ch;
	while (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE) == RESET);
	HAL_UART_Receive(&huart1, (uint8_t*)&ch, 2, 10);
	return ch;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2)  //500ms
		LL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
	
	if(htim->Instance == TIM3 && EnableBuzzerFlag)  //1ms
		LL_GPIO_TogglePin(BUZZER_GPIO_Port,BUZZER_Pin);	
}
/* 
 * This example shows how to use GPIO ports to get logical "1" or "0".
 * LED is attached to PE8. 
 */

#include "log.h"
#include "stm32f3xx.h"
#include "stdio.h"

void rcc_init()
{
	RCC->AHBENR     |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_DMA1EN;
    RCC->APB1ENR    |= RCC_APB1ENR_USART2EN;
}

int main()
{
	const int MAX_RESP_LEN = 50; 
	char resp[MAX_RESP_LEN];
	int resp_len = 0;
	char c = 0;
   
    rcc_init();
    log_init();
    
    while (1) {
        c = usart_recv_char_sync(USART2); // usart2 is initialized in log_init
        resp_len = snprintf(resp, MAX_RESP_LEN, "received char: %c\r\n", c);
        log_write(resp, resp_len);
    }
}


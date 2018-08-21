#include "delay.h"
#include <libopencm3/cm3/systick.h>
#include <libopencm3/cm3/nvic.h>

volatile unsigned long systickCtr;

//Setup SysTickTimer for 1ms tick
void initSysTick(void)
{
	systick_set_clocksource(STK_CSR_CLKSOURCE_AHB_DIV8);	//72 MHz / 8 = 9 MHz
	systick_set_reload(9000);	//9 MHz / 9000 = 1 kHz --> 1 ms
	systick_interrupt_enable();
	systick_counter_enable();
}

//ISR for SysTickTimer
void sys_tick_handler(void)
{
	systickCtr++;
}

//get value of systick counter
unsigned long getSysTickCnt(void)
{
	return systickCtr;
}

//idle for given milliseconds
void delay_ms(unsigned int ms)
{
	unsigned int timeBefore = getSysTickCnt();
	while(getSysTickCnt() < timeBefore + ms);
}

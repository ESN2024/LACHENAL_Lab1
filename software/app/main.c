#include <stdio.h>
#include "system.h"
#include <sys/alt_irq.h>
#include <io.h>
#include <alt_types.h>
#include "sys/alt_sys_init.h"
#include "altera_avalon_pio_regs.h" //access to PIO macros
#include "unistd.h" //access to usleep

volatile char edge_capture;
volatile char leds;
volatile __uint32_t speed_leds;

static void handle_interrupts(void* context, alt_u32 id)
{   

	if (edge_capture == 1){
		edge_capture = 0;
	}
	else
	{
		edge_capture = 1;
	}

	alt_printf("Interrupt");

	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE,1);
	
	char speed = IORD_ALTERA_AVALON_PIO_DATA(PIO_2_BASE);
	
	switch (speed) {
		case 0x00 :
			speed_leds = 1000000;
			break;
		case 0x01 :
			speed_leds = 800000;
			break;
		case 0x02 :
			speed_leds = 400000;
			break;
		case 0x03 :
			speed_leds = 200000;
			break;
	}
	
}


int main(){
	edge_capture = 0;
	leds = 0x01;
	alt_printf("Hello, World!\n");
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,0x00);

	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_1_BASE,1);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE,1);

	alt_irq_register( PIO_1_IRQ, NULL, handle_interrupts );

	while(1){
	
	        if (edge_capture == 1) 
        	{
        	    alt_printf("Les leds clignotent!\n");
				leds = leds << 1;
	    		IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,leds); 
			}
	
			else
			{
	    		IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,0x00);
				leds = 0x01;
			}
			usleep(speed_leds);
	}
	
	return 0;
}

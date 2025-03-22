#include "nios2_ctrl_reg_macros.h"
#include "io.h"
#include "miniSystem.h"

// function prototypes int main(void);
void interrupt_handler(void);
void the_exception(void);

int flag_up = 0;
int flag_down = 0;
int counter = 0;

int main(void)
{

    NIOS2_WRITE_STATUS(0x1);
    NIOS2_WRITE_IENABLE(0x1);

    IOWR(KEY_BASE, 3, 0); // clear interrupt capture register
    IOWR(KEY_BASE, 2, 0x3); // enable bits 0 and 1

    while (1)
    {
   	// check flags
    	if (flag_up &flag_down){ // if both high
    		flag_up=0;
    		flag_down =0;
    	}
    	if (flag_up){
    		counter++;
    		flag_up = 0; //reset
    	}
    	if (flag_down){
    		counter--;
    		flag_down = 0; // reset
    	}
    	IOWR(LEDR_BASE,0,counter);
    	for (int i =0; i<50000; i++){
    		asm ( "nop" );
    	}

    }
}

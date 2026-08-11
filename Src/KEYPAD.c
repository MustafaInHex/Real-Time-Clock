#include "KEYPAD.h"

void KEYPAD_initialize(void)
{
	DIO_portdirection(KEYPAD_PORT,0b00001111);
	DIO_pullup(KEYPAD_PORT,4);
	DIO_pullup(KEYPAD_PORT,5);
	DIO_pullup(KEYPAD_PORT,6);
	DIO_pullup(KEYPAD_PORT,7);
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned char KEYPAD_read(void)
{
	#if defined PROTEUS
unsigned char arr[4][4]={ {'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'} };


#elif defined HARDWARE

unsigned char arr[4][4]={ {'1','2','3','+'},{'4','5','6','-'},{'7','8','9','/'},{'*','0','c','='} };
	
	#endif
	
	 char row , col ;
	unsigned char returned_value=NOT_PRESSED;
	
	for(row=0;row<4;row++)
	{
		DIO_writepin(KEYPAD_PORT,0,1);
		DIO_writepin(KEYPAD_PORT,1,1);
		DIO_writepin(KEYPAD_PORT,2,1);
		DIO_writepin(KEYPAD_PORT,3,1);
		DIO_writepin(KEYPAD_PORT,row,0);
		
			for(col=0;col<4;col++)
			{
				if(BUTTON_status(KEYPAD_PORT,(col+4))==0)
				{
				
						returned_value= arr[row][col];
						break;
													
				}				
				
			}
			
			if(returned_value!=NOT_PRESSED)
			{
				break;
				
			}
	}
	//_delay_ms(200);               // always at the end of the function always!!!!
	return returned_value;
}



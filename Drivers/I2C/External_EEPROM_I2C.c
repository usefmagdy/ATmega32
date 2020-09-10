#include"External_EEPROM.h"
#include <util/delay.h>

int main(void)
{
	unsigned char val = 0;
	
	DDRD = 0xFF;
	PORTD = 0x00;

	// Init EEPROM
	EEPROM_Init();

	EEPROM_Write_Byte(0x0311, 0x0F); // Write 0xFF in the external EEPROM
	_delay_ms(10);
	EEPROM_Read_Byte(0x0311, &val); // Read 0xFF from the external EEPROM
	while(1)
	{
		PORTD = val; // out the read value from the external EEPROM
	}
	return 0;
}
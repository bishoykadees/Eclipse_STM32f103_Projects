#include "FLASH.h"

u8 array [1024];

int
main(int argc, char* argv[])
{


	u32 temp = 0;

	FLASH_Unlock();

	FLASH_ErasePage((void*)0x08002000);

	FLASH_WriteWord((void*)0x08002000,0xABCDEF12);

	FLASH_ErasePage((void*)0x08002000);

	FLASH_WriteProgram(array, (void*)0x08002000, 1024);

	temp = *((u32*)0x08002000);

	FLASH_WriteWord((void*)0x08002000,0x12345678);

	temp = *((u32*)0x08002000);

	FLASH_Lock();

	FLASH_WriteWord((void*)0x08002000,0x98765432);

	temp = *((u32*)0x08002000);

	while (1);
}

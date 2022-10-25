#include<stdio.h>

float get_temprature();
void write_data();
void read_data();

int main()
{
	int x=1;
	float temp;

	while(x)
	{
		printf("\n1. Read Temprature\n2. Write data to eeprom\n3. Read data from eeprom\n4. Exit\nChoice:");
		scanf("%d",&x);
		switch(x)
		{
			case 1:	printf("Reading temprature...\n");
				temp=get_temprature();
				printf("Temp = %0.2f\n",temp);
				break;
			case 2:	printf("Writing data to EEPROM...\n");
				write_data();
				break;
			case 3: printf("Reading data from EEPROM...\n");
				read_data();
				break;
			case 4: x=0;
				break;	
			default: printf("Wrong option!!!\n");
		}
		
	}
	printf("Program Ended...\n");
	return 0;	
}
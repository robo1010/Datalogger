#include"header.h"

float get_temprature();

#define SLAVE_ADDRESS 0x50				/*Address of the EEPROM*/

void write_data()
{

	int fd,i=0,j,k,wr;
	float temp;
	char buf[10],copy[20];

	fd = open("/dev/i2c-1", O_RDWR);
	if (fd < 0) 
	{
		perror("/dev/i2c-1:");
		exit(0);
	}

	if (ioctl(fd, I2C_SLAVE_FORCE, SLAVE_ADDRESS) == -1) 	        /* Set the i2c slave device */
	{
		perror("ioctl I2C_SLAVE");
		exit(0);
	}
	
	temp=get_temprature();				/*Take the Temprature reading from lm35*/
	sprintf(copy,"Temp=%0.2f",temp);

	buf[0] = 0x50;                  		/*starting address of eeprom*/
	for(j=1,k=0;k<10;j++,k++)
	{
		buf[j]=copy[k];
	}

	wr = write(fd, buf,10);				/*writing data to memory location*/
	if(wr < 0) {
		perror("\nWrite fail ");
		exit(0);
	}
	close(fd);
}

void read_data()
{
	int fd,i,rw;
	char buf[10];
	fd=open("/dev/i2c-1", O_RDWR);
	if(fd < 0) 
	{
		perror("/dev/i2c-2:");
		exit(0);
	}
        	/* Set the address of the i2c slave device */
	if (ioctl(fd, I2C_SLAVE_FORCE, SLAVE_ADDRESS) == -1) 
	{
		perror("ioctl I2C_SLAVE");
		exit(0);
	}

	buf[0] = 0x50;					/*Set the 8-bit address to read 1*/
	rw = write(fd, buf,1);
	if (rw == -1) 
	{
		perror("\nwrite fail");
		exit(0);
	}

	for (i=0;i<10;i++)				/*Clear buffer*/
	{
		buf[i]= 0;
	}

	rw = read(fd, buf,10);				/*Reading data from memory location*/
	if (rw == -1) 
	{
		perror("read");
		exit(0);
	}

	for(i=0;i<10;i++)				/*Printing the data from memory*/ 
	{
     		printf("%c",buf[i]);
	}
	printf("\n");
	close(fd);
}
#include"header.h"

float get_temprature()
{
	int fd, read_byte,d_out;
	float temp;
	char buff[1024];
	fd=open("/sys/bus/iio/devices/iio\:device0/in_voltage0_raw",O_RDONLY);
	if(fd < 0)
	{
		perror("Open failed");
		exit(0);
	}

	read_byte=read(fd,buff,sizeof(buff));
	if(read_byte < 0)
	{
		perror("Read fail");
		exit(0);
	}
	
	d_out=atoi(buff);				/* d_out is a digital output from LM35 temp sensor*/
	float d_outtt=d_out;
	temp=(d_outtt/4096)*2.5*100;			/* Actual temp calculation */
	return temp;	
	close(fd);
}
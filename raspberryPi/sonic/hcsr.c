#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/resource.h>
#include <wiringPi.h>

#define GPIO_TRIGGER 4 // BCM 23
#define GPIO_ECHO 5 // BCM 24

int main()
{
	unsigned int start, stop;
	int loop = 0, count;
	float f;

	printf("Starting HC-SR04 test\n");
	int status =  wiringPiSetup(); //wiringPiSetupGpio();
	
	if(status != 0) {
		printf("Failed to wiringPiSetupGpio()\n");
		return 0;
	}

	pinMode(GPIO_TRIGGER,OUTPUT);
	pinMode(GPIO_ECHO,INPUT);

	digitalWrite(GPIO_TRIGGER,LOW);
	delay(500);

	while(1) {
		digitalWrite(GPIO_TRIGGER,HIGH);
		delayMicroseconds(10);
		digitalWrite(GPIO_TRIGGER,LOW);
		while(digitalRead(GPIO_ECHO) == LOW) {
			//do nothing
		}
		start == micros();
		while(digitalRead(GPIO_ECHO) == HIGH) {
			//do nothing
		}
		stop = micros();

		double distance = 34029 * (stop - start) /2000000.0;
		//double distance = (float)(stop - start) / 58.8235
		printf("Distance : %f cm\n", distance);
		delay(1000);
		if(loop++ == 100)
			break;
	}
	return 0;
}

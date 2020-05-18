import RPi.GPIO as GPIO
import time

GPIO_TRIGGER = 23
GPIO_ECHO = 24

GPIO.setmode(GPIO.BCM)
print("Distance Measurement In Progress")

GPIO.setup(GPIO_TRIGGER,GPIO.OUT)
GPIO.setup(GPIO_ECHO,GPIO.IN)

GPIO.output(GPIO_TRIGGER,False)

print("Waiting For Sensor To settle")
time.sleep(2)

GPIO.output(GPIO_TRIGGER,True)
time.sleep(0.00001)
GPIO.output(GPIO_TRIGGER,False)

while GPIO.input(GPIO_ECHO) == 0 :
    pulse_start = time.time()

while GPIO.input(GPIO_ECHO) == 1 :
    pulse_end = time.time()


pulse_duration = pulse_end - pulse_start
distance = pulse_duration * 17150
distance = round(distance,2)

print("Distance:", distance,"cm")
GPIO.cleanup()


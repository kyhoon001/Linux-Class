import RPi.GPIO as GPIO
import time

def blink(pin) :
    GPIO.output(pin,GPIO.HIGH)
    time.sleep(1)
    GPIO.output(pin,GPIO.LOW)
    time.sleep(1)
    return

channel = 18
GPIO.setmode(GPIO.BCM)
GPIO.setup(channel, GPIO.OUT)

for i in range(0,50):
    blink(channel)

GPIO.cleanup()

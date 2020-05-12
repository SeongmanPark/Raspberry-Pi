#!/usr/bin/env python3
import RPi.GPIO as GPIO
import time

GPIO_TRIGGER = 23
GPIO_ECHO = 24

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
print("Distance Measurement In Progress")

GPIO.setup(GPIO_TRIGGER, GPIO.OUT)
GPIO.setup(GPIO_ECHO, GPIO.IN)

GPIO.output(GPIO_TRIGGER, False)
# 값이 나가지 않도록 만들어 줌

print("Waiting For Sensor To settle")
time.sleep(2)

while True:
    GPIO.output(GPIO_TRIGGER, True)
    # 트리거 핀에 10us 정도의 신호를 줌 !! -> 40khz 펄스를 자동적으로 8번 발생
    # 펄스를 발생시킨 직후 ECHO 핀은 HIGH가 됨
    time.sleep(0.00001)
    GPIO.output(GPIO_TRIGGER, False)

    while GPIO.input(GPIO_ECHO) == 0: # 초음파 데이터가 안 들어오는것 !!!!
        pulse_start = time.time()

    while GPIO.input(GPIO_ECHO) == 1: # 초음파 데이터가 들어오는 것 !!!!
        pulse_end = time.time()

    pulse_duration = pulse_end - pulse_start
    distance = pulse_duration * 17150
    # 음속으로 곱해주기
    distance = round(distance, 2)
    print("Distance : ", distance, "cm")
    time.sleep(1)
    GPIO.output(GPIO_TRIGGER, False)

GPIO.cleanup()

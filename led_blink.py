#led_blank.py
import RPi.GPIO as GPIO
import time

def blink(pin):
    GPIO.output(pin, GPIO.HIGH)
    # 1을 출력 -> 1에서 0으로 전기 흐름
    time.sleep(1)
    GPIO.output(pin, GPIO.LOW)
    # 0을 출력 -> 0에서 0으로 전기는 안 흐름
    time.sleep(1)
    return

channel = 17
GPIO.setmode(GPIO.BCM)
# 라즈베리 파이의 GPIO 모듈을 활성화
GPIO.setup(channel, GPIO.OUT) #BCM NO
# 출력모드로 선언

for i in range(0, 50):
    blink(channel)

GPIO.cleanup()
# 초기화해논것을 해지

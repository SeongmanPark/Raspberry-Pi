#led_sw_blink.py
import RPi.GPIO as GPIO
# General Purpose Input Output 
# 핀을 입력과 출력으로 사용할 수 있게하는 모듈
import time

GPIO.setmode(GPIO.BCM)
# 핀 번호를 라즈베리파이 BCM 모드로 참조
GPIO.setup(23, GPIO.IN, pull_up_down = GPIO.PUD_DOWN)
# 23번 핀을 입력으로 설정, 풀 다운 저항 연결하기 !!!
GPIO.setup(18, GPIO.OUT)
# 18번 핀을 출력으로 설정

print("Press the button")

try:
    while True:
        input_value = GPIO.input(23)
        # 23번 핀을 통해 받은 입력을 input_value에 저장 (스위치)
        # 스위치가 눌려지면 1 -> LED에 불이 들어옴
        if(input_value == True):
            GPIO.output(18, True)

        else:
            GPIO.output(18, False)

except KeyboardInterrupt:
    GPIO.cleanup()

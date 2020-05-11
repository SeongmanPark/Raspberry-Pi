#led_PWM.py
import time
import RPi.GPIO as GPIO
# General Purpose Input Output 
# 핀을 입력과 출력으로 사용할 수 있게하는 모듈
GPIO.setmode(GPIO.BCM)
# 핀 번호를 라즈베리파이 BCM 모드로 참조
GPIO.setup(18, GPIO.OUT)
# gpio18번 핀을 출력으로 사용

p=GPIO.PWM(18, 50)
# gpio 18번에 50hz 주파수 지정
# 펄스폭변조 -> 순수 아날로그 제어를 모방한 것.
# 0과 1 신호로 이루어져 있는 디지털 신호를 아날로그 같이 사용할 수 있다.
# 전원이 on되는 시간을 펄스 폭이라 하고, 펄스 폭을 조정함으로써 on과 off사이의 전압을 흉내낼 수 있다.

p.start(0)

try:
    while True:
        for dc in range(0, 101, 5):
            p.ChangeDutyCycle(dc)
            # 듀티 사이클 지정, 전체 주기에서 HIGH 상태가 차지하는 비율
            # 5씩 증가
            time.sleep(0.1)
        for dc in range(100, -1, -5):
            p.ChangeDutyCycle(dc)
            # 듀티 사이클 지정, 전체 주기에서 HIGH 상태가 차지하는 비율
            # -5씩 감소
            time.sleep(0.1)

except KeyboardInterrupt:
    pass

p.stop()
GPIO.cleanup()

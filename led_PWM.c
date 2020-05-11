#include <wiringPi.h>
#include <stdio.h>

#define LED 1
// wPi 1번을 LED 출력으로 사용
// 라즈베리파이 핀 단자에서 꼭 PMW 기능을 사용할 수 있는 번호에 꽂아야 작동가능 !!!!
int bright = 0;
// 밝기 값 0

int main()
{
	wiringPiSetup();
	// 초기화
	pinMode(LED, PWM_OUTPUT);
	// LED를 PWM output으로 지정
	digitalWrite(LED, LOW);
	// 출력에 LOW값 쓰기.

	while(1)
	{
		for(bright = 0; bright < 1024; ++bright)
		{
			pwmWrite(LED, bright);
			// 1ms 간격으로 점점 밝아짐
			delay(1);
		}

		for(bright = 1023; bright >= 0; --bright)
		{
			pwmWrite(LED, bright);
			// 1ms 간격으로 점점 어두워짐
			delay(1);
		}
	}
	return 0;
}

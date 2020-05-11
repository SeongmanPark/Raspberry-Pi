// led_blink.c
// wiringPi -> C언어로 GPIO핀을 제어할 수 있는 기능을 제공하는 라이브러리
#include <wiringPi.h>

int main()
{
	wiringPiSetup();
	// 초기화를 진행 !!!
	pinMode(1, OUTPUT);
	// 1번 핀은 OUTPUT 모드 지정
	for(;;)
	{
		digitalWrite(1, HIGH); delay(500);
		// 출력에다가 HIGH값을 주고 500ms 기다리기
		digitalWrite(1, LOW); delay(500);
		// 출력에다가 LOW값을 주고 500ms 기다리기
	}
	return 0;
}

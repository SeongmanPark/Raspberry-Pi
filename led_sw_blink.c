//led_sw_blink.c
#include <wiringPi.h>
#include <stdio.h>
#define KEY 4
// GPIO 23
#define LED 1
// GPIO 18
int main()
{
	int pressed, i;

	wiringPiSetup();
	// 초기화 진행
	pullUpDnControl(KEY, PUD_DOWN);
	// 풀업다운 함수
	// ( 핀 번호, 입력핀으로 설정되었을 때 PUD_DOWN = 1일때 enable된다.)
	pinMode(KEY, INPUT);
	// KEY를 입력으로
	pinMode(LED, OUTPUT);
	// LED를 출력으로 설정
	while(1)
	{
		pressed = digitalRead(KEY);
		// KEY입력을 통해 값을 읽어 pressed변수에 저장
		if(pressed) // HIGH일 때
		{
			printf("Key pressed !!!\n");
			for(i =0; i<3; i++) // LED 껏다 켰다 3번 반복 500ms 주기로
			{
				digitalWrite(LED, HIGH);
				delay(500);
				digitalWrite(LED, LOW);
				delay(500);
			}
		}
		delay(200);
	}
	return 0;
}

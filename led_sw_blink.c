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
	// 쓰는 이유 ? 스위치를 on / off 하더라도 아직 미세하게 남아있는 전류와 전압차 때문에
	// 라즈베리파이에서 정확하게 HIGH 값과 LOW값을 catch하지 못 한다.
	// 실제로 printf를 찍어본 결과 0 , 1 값이 수시로 바뀌는 현상을 보았다.
	// 풀업다운 함수를 사용하여 해결했음
	// 전자과 사람들 말로는 풀업다운 전용 회로로 구성하던지 풀업다운 함수를 사용하던지 둘로 나뉜다고 한다.
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

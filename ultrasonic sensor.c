// 초음파 센서
// 40KHZ의 펄스 신호를 출력하여 반사되어 돌아오는 펄스의 시간을 측정하여 거리를 계산 !!!
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <wiringPi.h>

#define GPIO_TRIGGER 4 // BCM 23 OUTPUT 트리거를 발생하는 출력 핀
#define GPIO_ECHO 5 // BCM 24 INPUT 반사된 초음파를 감지하는 입력 핀

int main()
{
    unsigned int start, stop;
    int loop = 0;

    printf("Starting HC-SR04 test\n");
    int status = wiringPiSetup();
    // 초기화 wPi Number 사용
    if(status != 0)
    {
        perror("Failed to wiringPiSetup()");
        exit(1);
    }

    pinMode(GPIO_TRIGGER, OUTPUT);
    pinMode(GPIO_ECHO, INPUT);
    // 트리거를 출력으로, 에코를 입력으로 사용 !!!
    digitalWrite(GPIO_TRIGGER, LOW);
    // 트리거에 LOW값 입력 후
    delay(500);
    // 500ms 기다리고 시작 !!!
    while(1)
    {
        // send 10us pulse to trigger
        digitalWrite(GPIO_TRIGGER, HIGH);
        // 트리거 핀에 10us 정도의 신호를 줌 !! -> 초음파 센서에서 40khz 펄스를 자동적으로 8번 발생
        // 펄스를 발생시킨 직후 ECHO 핀은 HIGH가 됨
        delayMicroseconds(10);
        digitalWrite(GPIO_TRIGGER, LOW);
        while(digitalRead(GPIO_ECHO) == LOW)
        {
            // do nothing
        }
        // ECHO 핀은 HIGH가 됨
        start = micros();
        while(digitalRead(GPIO_ECHO) == HIGH)
        {
            // do nothing
        }
        // 발생된 초음파가 반사되어 다시 감지되었을 때 ECHO 핀은 LOW상태가 됨
        stop = micros();
        // stop - start 발생된 초음파가 다시 반사되어 올때까지 걸리는 시간으로 거리를 구함
        double distance = 34029 * (stop - start) / 2000000.0;
        // double distance = (float)(stop - start) / 58.8235;
        printf("Distance : %f cm\n", distance);
        delay(1000);
        if(loop++ == 100)
        {
            break;
        }
    }
    return 0;
}

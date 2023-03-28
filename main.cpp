#include "mbed.h"

Thread thread;
PwmOut PWM1(D6);

AnalogIn Ain(A0);
AnalogOut Aout(D7);

void led_breathing()
{
float width[20] = {0.2f, 0.4f, 0.6f , 0.8f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f , 1.0f, 0.8f, 0.6f, 0.4f, 0.2f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    
    while (1) {
        PWM1.period_ms(5);
        
        
        for (int i = 0; i <= 19; i++) {
            PWM1.pulsewidth_ms(5 * width[i]);
            ThisThread::sleep_for(50ms);
        }
        
    } 
}

int main()
{
    thread.start(led_breathing);
    int sample = 640;
    int i;
    float ADCdata[640];

    for (i = 0; i < sample; i++)
    {
        ADCdata[i] = Ain;
        ThisThread::sleep_for(5000ms / sample);
    }
    for (i = 0; i < sample; i++)
    {
        printf("%f\r\n", ADCdata[i]);
        ThisThread::sleep_for(1ms);
    }

    while(1){

    }

}


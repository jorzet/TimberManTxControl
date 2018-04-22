#include <VirtualWire.h>

#define ADC1 A0
#define ADC2 A1
#define ADC3 A2
#define ADC4 A3
#define ADC5 A4
#define ADC6 A5

#define TX 12
#define RX 2
#define LED1 10
//#define LED2 11
#define PUSH 3

int mov1;
int mov2;
int mov3;
int mov4;
int mov5;
int mov6;
float outmov1;
float outmov2;
float outmov3;
float outmov4;
float outmov5;
float outmov6;
int anterior=8;

int dato;

void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(LED1,OUTPUT);
  
  pinMode(ADC1,INPUT);
  pinMode(ADC2,INPUT);
  pinMode(ADC3,INPUT);
  pinMode(ADC4,INPUT);
  pinMode(ADC5,INPUT);
  pinMode(ADC6,INPUT);
  
  vw_set_tx_pin(TX);
  vw_set_rx_pin(RX);
  vw_set_ptt_pin(PUSH);
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);
  
  Serial.begin(9600);
}

void loop() {

  mov1 = analogRead(ADC1);
  mov2 = analogRead(ADC2);
  mov3 = analogRead(ADC3);
  mov4 = analogRead(ADC4);
  mov5 = analogRead(ADC5);
  mov6 = analogRead(ADC6);
  
  outmov1 = mov1 * (5.0 / 1023.0);
  outmov2 = mov2 * (5.0 / 1023.0);
  outmov3 = mov3 * (5.0 / 1023.0);
  outmov4 = mov4 * (5.0 / 1023.0);
  outmov5 = mov5 * (5.0 / 1023.0);
  outmov6 = mov6 * (5.0 / 1023.0);
  
      if(outmov1>3 & anterior!=1){
        dato=1;
        Serial.println("a");
        vw_send((uint8_t*)dato,sizeof(dato));
        vw_wait_tx();  
        anterior=1;
      }
      else if(outmov2>3 & anterior!=2){
        dato=2;
        Serial.println("b");
        vw_send((uint8_t*)dato,sizeof(dato));
        vw_wait_tx();  
        anterior=2;
      }
      else if(outmov3>3 & anterior!=3){
        dato=3;
        Serial.println("c");
        vw_send((uint8_t*)dato,sizeof(dato));
        vw_wait_tx();  
        anterior=3;
      }
      else if(outmov4>3 & anterior!=4){
        dato=4;
        Serial.println("d");
        vw_send((uint8_t*)dato,sizeof(dato));
        vw_wait_tx();  
        anterior=4;
      }
      else if(outmov5>3 & anterior!=5){
        dato=5;
        Serial.println("e");
        vw_send((uint8_t*)dato,sizeof(dato));
        vw_wait_tx();  
        anterior=5;
      }
      else if(outmov6>3 & anterior!=6){
        dato=6;
        Serial.println("f");
        vw_send((uint8_t*)dato,sizeof(dato));
        vw_wait_tx();  
        anterior=6;
      } 
       
       
  //sprintf(datos,"%d,%d,%d,%d",sensor1,sensor2,sensor3,sensor4);

  //digitalWrite(LED1,HIGH);
       //vw_send((uint8_t*)datos,strlen(datos));
       //vw_wait_tx();   
    //   delay(100);
  //digitalWrite(LED1,LOW);

}


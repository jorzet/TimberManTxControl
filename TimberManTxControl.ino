/*
 * This code configures the transmition pins between the RF 433 MHz 
 * module and Arduino. It also has pins to read when user push 
 * some button. according to the button the Arduino is going to 
 * send a value to RF 433 MHz module
 * 
 * @author: Jorge Zepeda Tinoco on 22/04/18
 * @email: jorzet.94@gmail.com
 */

#include <VirtualWire.h>

/*
 * Defines macros to set button input
 */
#define ADC1 A0
#define ADC2 A1
#define ADC3 A2
#define ADC4 A3
#define ADC5 A4
#define ADC6 A5

/*
 * defines macros movements
 */
#define MOVEMENT_ONE "a"
#define MOVEMENT_TWO "b"
#define MOVEMENT_THREE "c"
#define MOVEMENT_FOUR "d"
#define MOVEMENT_FIVE "e"
#define MOVEMENT_SIX "f"

/*
 * Defines macros for input and output pins
 * (serial[Rx, Tx], LED and button)
 */
#define TX 12
#define RX 2
#define LED1 10
//#define LED2 11
#define PUSH 3

/*
 * Variables to set analog inputs from buttons
 * with resolution 0 to 1024
 */
int mov1;
int mov2;
int mov3;
int mov4;
int mov5;
int mov6;

/*
 * Variables to set voltage equivalent
 */
float outmov1;
float outmov2;
float outmov3;
float outmov4;
float outmov5;
float outmov6;

/*
 * variables to know last data and current data
 */
int last = 8;
int data;

void setup() {

    // setup OUTPUT 
    pinMode(LED1, OUTPUT);

    // setup INPUTS
    pinMode(ADC1, INPUT);
    pinMode(ADC2, INPUT);
    pinMode(ADC3, INPUT);
    pinMode(ADC4, INPUT);
    pinMode(ADC5, INPUT);
    pinMode(ADC6, INPUT);

    // setup RF module
    vw_set_tx_pin(TX);
    vw_set_rx_pin(RX);
    vw_set_ptt_pin(PUSH);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);

    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() {

    // read analog inputs
    mov1 = analogRead(ADC1);
    mov2 = analogRead(ADC2);
    mov3 = analogRead(ADC3);
    mov4 = analogRead(ADC4);
    mov5 = analogRead(ADC5);
    mov6 = analogRead(ADC6);

    // cast analog input to voltage
    outmov1 = mov1 * (5.0 / 1023.0);
    outmov2 = mov2 * (5.0 / 1023.0);
    outmov3 = mov3 * (5.0 / 1023.0);
    outmov4 = mov4 * (5.0 / 1023.0);
    outmov5 = mov5 * (5.0 / 1023.0);
    outmov6 = mov6 * (5.0 / 1023.0);

    /*
     * Check if voltage is higer than 3 and 
     * check last data
     */
    if (outmov1 > 3 & last != 1) {
        data = 1;
        Serial.println(MOVEMENT_ONE);
        vw_send((uint8_t *)data, sizeof(data));
        vw_wait_tx();  
        last = 1;
    } else if (outmov2 > 3 & last != 2) {
        data = 2;
        Serial.println(MOVEMENT_TWO);
        vw_send((uint8_t *)data, sizeof(data));
        vw_wait_tx();  
        last = 2;
    } else if (outmov3 > 3 & last != 3) {
        data = 3;
        Serial.println(MOVEMENT_THREE);
        vw_send((uint8_t *)data, sizeof(data));
        vw_wait_tx();  
        last = 3;
    } else if (outmov4 > 3 & last != 4) {
        data = 4;
        Serial.println(MOVEMENT_FOUR);
        vw_send((uint8_t *)data, sizeof(data));
        vw_wait_tx();  
        last = 4;
    }else if (outmov5 > 3 & last != 5) {
        data = 5;
        Serial.println(MOVEMENT_FIVE);
        vw_send((uint8_t *)data, sizeof(data));
        vw_wait_tx();  
        last = 5;
    } else if (outmov6 > 3 & last != 6) {
        data = 6;
        Serial.println(MOVEMENT_SIX);
        vw_send((uint8_t *)data, sizeof(data));
        vw_wait_tx();  
        last = 6;
    } 
       
       
    //sprintf(datas, "%d, %d, %d, %d", sensor1, sensor2, sensor3, sensor4);
    //digitalWrite(LED1,HIGH);
    //vw_send((uint8_t *)datas, strlen(datas));
    //vw_wait_tx();   
    //delay(100);
    //digitalWrite(LED1,LOW);
}


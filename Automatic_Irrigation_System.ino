
// AUTOMATIC IRRIGATION SYSTEM

/* The program for AUTOMATIC IRRIGATION SYSTEM IS Written and Tested by__


DISCLAIMER: This is a Open Source Software and This Software is distributed in the hope that it will be useful,
            but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 

Connection Details 
ARDUINO PINS
0_________________N/C
1_________________N/C
2_________________LCD-14
3_________________LCD-13
4_________________LCD-12
5_________________LCD-11
6_________________N/C
7_________________WATER_LEVEL_STATUS_LED
8_________________N/C
9_________________SPEAKER
10________________N/C
11________________LCD-6
12________________LCD-4
13________________PUMP_STATUS_LED)_AND_TO_RELAY
A0________________SOIL_MOISTURE_SENSOR
A4________________LM35_(TEMPERATURE_SENSOR)  //Bug reported for Unstable Temperature Reading 

LCD-1_____________GND
LCD-5_____________GND
LCD-2_____________+Vcc
LCD-3_____________LCD_BRIGHTNESS


*/
 
#include <LiquidCrystal.h> //LCD Library
#include <Wire.h>  
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
#include <NewTone.h>

#define NOTE_C4 262 
#define NOTE_D4 294 
#define NOTE_E4 330 
#define NOTE_F4 349 
#define NOTE_G4 392 
#define NOTE_A4 440 
#define NOTE_B4 494 
#define NOTE_C5 523
#define trig_pin 2 
#define echo_pin 4 
#define MAX_DISTANCE 400

 LiquidCrystal_I2C lcd(0x3F,16,2);
void play_tone();
// Melody (liberated from the toneMelody Arduino example sketch by Tom Igoe).
int melody[] = { 262, 196, 196, 220, 196, 0, 247, 262 };
int noteDurations[] = { 4, 8, 8, 4, 4, 4, 4, 4 };

int temp;
//int T_Sensor = A4;
int M_Sensor = A0;
int W_led = 7;
int P_led = 13;
int Speaker = 7;
int val;
int cel;  
int GREEN = 7;
int RED = 8;
//int Water_Pump = A5;
long duration;
int distance;
NewPing sonar = NewPing(trig_pin, echo_pin, MAX_DISTANCE);

void setup()
 {
    lcd.init();
    lcd.clear(); 
    pinMode(P_led,OUTPUT);
    pinMode(7,INPUT);
    pinMode(9,OUTPUT);
    pinMode(RED, OUTPUT);
//    pinMode(trig_pin, OUTPUT);
//    pinMode(echo_pin, INPUT);
    pinMode(Speaker, OUTPUT);
    Serial.begin(9600);
    /*
    val = analogRead(T_Sensor); //Read Temperature sensor value 
    
    int mv = ( val/1024.0)*5000; 
    cel = mv/10;
    */
    lcd.backlight();
    //lcd.setCursor(0,1);
    lcd.print("SMART IRRIGATOR");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("AUTOMATIC");
    lcd.setCursor(0,1);
    lcd.print("IRIGATION SYSTEM");
    delay(2500);
    lcd.clear(); 
   
  
    delay(1000);
}

void loop()
{
  /**********/
//// Clear the trigPin by setting it LOW:
//  digitalWrite(trig_pin, LOW);
//  
//  delayMicroseconds(10);
// // Trigger the sensor by setting the trigPin high for 10 microseconds:
//  digitalWrite(trig_pin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trig_pin, LOW);
//  
//  // Read the echoPin. pulseIn() returns the duration (length of the pulse) in microseconds:
//  duration = pulseIn(echo_pin, HIGH);
//  
//  // Calculate the distance:
//  distance = duration*0.034/2;
//  
//  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
//  Serial.print("Distance = ");
//  Serial.print(distance);
//  Serial.println(" cm");
//  
//  delay(100);
  delay(50); 
  //read current distance
  distance = sonar.ping_cm();
  // Measure distance and print to the Serial Monitor:
  Serial.print("Distance = ");
  // Send ping, get distance in cm and print result (0 = outside set distance range):
  Serial.print(distance); 
  Serial.println(" cm");
  /**********/
//  int duration, distance;
//  digitalWrite(trigpin, HIGH);
//
//  delayMicroseconds(10000);  
//  digitalWrite(trigpin, LOW);
//
//  duration = pulseIn(echopin,HIGH);
//  distance = ( duration / 2) / 29.1;
//  Serial.println("cm:"); 
//  Serial.println(distance);


//if(  (distance > 0) && (distance <= 10)   ) 
//{
//  digitalWrite(led1, HIGH); 
//  digitalWrite(led2, HIGH);
//  digitalWrite(led3, HIGH);
//  digitalWrite(led4, HIGH);
//  digitalWrite(led5, HIGH); 
//} else
//if(  (distance > 10) && (distance <= 20)  ) 
//{
//
//  digitalWrite(led1, LOW); 
//  digitalWrite(led2, HIGH);
//  digitalWrite(led3, HIGH);
//  digitalWrite(led4, HIGH);
//  digitalWrite(led5, HIGH); 
//
//} else
//
//if(  (distance > 20) && (distance <= 30)  ) 
//{
//
//  digitalWrite(led1, LOW); 
//  digitalWrite(led2, LOW);
//  digitalWrite(led3, HIGH);
//  digitalWrite(led4, HIGH);
//  digitalWrite(led5, HIGH);
//} else
//
//if(  (distance > 30) && (distance <= 40)  ) 
//{
//
//  digitalWrite(led1, LOW); 
//  digitalWrite(led2, LOW);
//  digitalWrite(led3, LOW);
//  digitalWrite(led4, HIGH);
//  digitalWrite(led5, HIGH);
//} else
//
//if(  (distance > 50) && (distance <= 60)  ) 
//{
//
//  digitalWrite(led1, LOW); 
//  digitalWrite(led2, LOW);
//  digitalWrite(led3, LOW);
//  digitalWrite(led4, LOW);
//  digitalWrite(led5, HIGH);
//} else
//
//if(  distance > 60 ) 
//{
//
//  digitalWrite(led1, LOW); 
//  digitalWrite(led2, LOW);
//  digitalWrite(led3, LOW);
//  digitalWrite(led4, LOW);
//  digitalWrite(led5, LOW);
//} 
  lcd.clear();
    /* val = analogRead(T_Sensor); //Read Temperature sensor value 
    Serial.println(val);
    int mv = ( val/1024.0)*5000; 
     cel = mv/10;
  */
  int Moisture = analogRead(M_Sensor); //Read Moisture Sensor Value 
  Serial.println(Moisture);
/*
  lcd.setCursor(0,0);
  lcd.print("TEMP:");
  lcd.setCursor(5,0);
  lcd.print(cel);
  lcd.setCursor(7,0);
  lcd.print("*C");
 */
 if (Moisture> 550)   // for dry soil
  { 
        lcd.setCursor(0,0);
        lcd.print("DRY SOIL");
        //lcd.setCursor(11,1);
        //lcd.print("SOIL");
       if (distance > 13 && distance < 19/*) && (distance <= 40)*/) //test the availability of water in storage
       {
         digitalWrite(13, HIGH);
         
         //digitalWrite(GREEN, HIGH);
        // delay(500);
         lcd.setCursor(0,1);
         lcd.print("PUMP:ON");
       }
       else
        if (distance > 12){
         digitalWrite(13, LOW);
         lcd.setCursor(0,1);
         lcd.print("PUMP:OFF");
         digitalWrite(RED, HIGH);
          //delay(500);
         //play_tone();
         lcd.setCursor(11,0);
        lcd.print("WATER");
        lcd.setCursor(11,1);
        lcd.print("LOW");
         
           
//           tone(Speaker, NOTE_C4, 500); 
//           delay(500); 
//           tone(Speaker, NOTE_D4, 500);
//           delay(500); 
//           tone(Speaker, NOTE_E4, 500); 
//           delay(500); 
//           tone(Speaker, NOTE_F4, 500); 
//           delay(500); 
//           tone(Speaker, NOTE_G4, 500); 
//           delay(500);
       }
    }
 
     if (Moisture>= 350 && Moisture<=550) //for Moist Soil
    { 
      lcd.setCursor(0,0);
     lcd.print("MOIST SOIL");
     //lcd.setCursor(11,1);
     //lcd.print("SOIL");
     digitalWrite(13,LOW);
     lcd.setCursor(0,1);
     lcd.print("PUMP:OFF");    
  }
 
  if (Moisture < 350)  // For Soggy soil
  { 
    lcd.setCursor(0,0);
     lcd.print("SOGGY SOIL");
     //lcd.setCursor(11,1);
     //lcd.print("SOIL");
     digitalWrite(13,LOW);
     lcd.setCursor(0,1);
     lcd.print("PUMP:OFF");
  }
 delay(1000);    
}  

void play_tone(){
  for (unsigned long freq = 125; freq <= 15000; freq += 10) { 
    NewTone(Speaker, freq); // Play the frequency (125 Hz to 15 kHz sweep in 10 Hz steps).
    delay(1); // Wait 1 ms so you can hear it.
  }
  noNewTone(Speaker); // Turn off the tone.

  delay(1000); // Wait a second.

  for (int thisNote = 0; thisNote < 8; thisNote++) { // Loop through the notes in the array.
    int noteDuration = 1000/noteDurations[thisNote];
    NewTone(Speaker, melody[thisNote], noteDuration); // Play thisNote for noteDuration.
    delay(noteDuration * 4 / 3); // Wait while the tone plays in the background, plus another 33% delay between notes.
  }

  while(1); // S
}


/*References_________________________________________________
https://www.arduino.cc/en/Reference/LiquidCrystalSetCursor
http://www.instructables.com/id/Connect-A-16x2-LCD-Display-To-An-Arduino/
http://www.instructables.com/id/Soil-Moisture-Sensor/
http://www.instructables.com/id/Arduino-Temperature-Sensor-Interfacing-LM35-THE-EA/
https://www.arduino.cc/en/Reference/digitalRead
http://www.instructables.com/id/ARDUINO-TEMPERATURE-SENSOR-LM35/
http://www.electroschematics.com/6519/simple-soil-moisture-sensor-arduino-project/

*/

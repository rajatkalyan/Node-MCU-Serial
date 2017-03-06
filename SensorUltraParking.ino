#include<NewPing.h>
#include <StopWatch.h>
StopWatch timer1;
StopWatch timer2;
StopWatch timer3;

#define trig1 11
#define echo1 10
#define trig2 9
#define echo2 6
#define MAX_DISTANCE 370
NewPing sonar1(trig1, echo1, MAX_DISTANCE);
NewPing sonar2(trig2, echo2, MAX_DISTANCE);
int sensor_1 = 0;
int sensor_2 = 0;
int count = 0;
int flag = 0;

long int t1;
long int t2;
long int t3;
int entry = 0;
int Exit = 0;
long duration1, distance1;
long duration2, distance2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  //delay(100);
  flag=0;
  //Serial.println(flag);
  delay(50);// Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS1 = sonar1.ping(); // Send ping, get ping time in microseconds (uS).
  distance1 = sonar1.convert_cm(uS1);

  if (distance1 > 4) {
    timer1.start();
  }
  if (distance1 == 0) {

    timer1.stop();
    t1 = timer1.value();




  }
  unsigned int uS2 = sonar2.ping(); // Send ping, get ping time in microseconds (uS).

  distance2 = sonar2.convert_cm(uS2);


  if (distance2 > 4) {
    timer2.start();
    //flag = 1;
  }
  if (distance2 == 0) {

    timer2.stop();
    t2 = timer2.value();
    //flag = 0;

  }
  if ((distance1 > 4) && (distance2 > 4)) {
    timer3.start();
  }
  if ((distance1 == 0) && (distance2 == 0)) {
    timer3.stop();
    t3 = timer3.value();


    if (t3 > 0 && t1 > 0 && t2 > 0 ) {


      //Serial.println(t1);
      ///Serial.println(t2);
      //Serial.println(t3);
      //Serial.println(t3);
      if ((t1 >= 100) && (t3 >= 10)) {
        flag=1;
        //Serial.println("ENtry");
        if ((t2 > 4) && (flag==1)) {
          //flag=0;
          entry++;
          //Serial.print("ENTRY:");
          Serial.println(entry);
          entry=entry;
          //Serial.println(flag);
        }


      }



      
      timer1.reset();
      timer2.reset();
      timer3.reset();



    }
  }





}

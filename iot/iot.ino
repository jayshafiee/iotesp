#include <MakerKit.h>

#define BLYNK_TEMPLATE_ID           "TMPL6VHqEmg9I"
#define BLYNK_DEVICE_NAME           "iot"
#define BLYNK_AUTH_TOKEN            "CFnL9IojSRcETJK4eEBVSo-L2hUo3WXW"


#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "GRANADA";
char pass[] = "";
#include <Adafruit_NeoPixel.h>
 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(5, 4, NEO_GRB + NEO_KHZ800);

BLYNK_WRITE(V0)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
    analogWrite(25,100);

  } else {
    digitalWrite(18,HIGH);
    digitalWrite(19,LOW);
    analogWrite(15,100);

  }
}

BLYNK_WRITE(V1)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0x3366ff);
    pixels.setPixelColor(1, 0x3366ff);
    pixels.setPixelColor(2, 0x3366ff);
    pixels.setPixelColor(3, 0x3366ff);
    pixels.setPixelColor(4, 0x3366ff);
    pixels.show();
    pixels.show();

  }
}

BlynkTimer Timer1;

void Timer1_TimerEvent()
{
  Blynk.virtualWrite(V20, ultrasonic(12,27));
  Blynk.virtualWrite(V21, analogRead(39));
}


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pixels.begin();

  pinMode(39, INPUT);
  Timer1.setInterval(300, Timer1_TimerEvent);

 
}


}
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL4m4QaeWx9"
#define BLYNK_TEMPLATE_NAME "ESP32 Temperature monitor "
#define BLYNK_AUTH_TOKEN "VcJPp_lNL-etod6H7Ew83IQO60PqgiUj"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4

#define TMP36_PIN 34   // ADC-pin

char auth[] = "VcJPp_lNL-etod6H7Ew83IQO60PqgiUj";
char ssid[] = "Altibox257312";
char pass[] = "qrv9PErq";

BlynkTimer timer;

void sendTemperature() {
  int adc = analogRead(TMP36_PIN);
  float voltage = adc * (3.3 / 4095.0);
  float temperature = (voltage - 0.5) * 100.0;

  Serial.print("ADC: ");
  Serial.print(adc);
  Serial.print("  Temp: ");
  Serial.println(temperature);

  Blynk.virtualWrite(V0, temperature);
}

void setup() {
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(2000L, sendTemperature);
}

void loop() {
  Blynk.run();
  timer.run();
}
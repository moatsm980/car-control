#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX | TX

const int ledPin = 4; // دبوس LED

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(ledPin, OUTPUT); // إعداد الدبوس كخرج
}

void loop() {
  if (BTSerial.available()) {
    char command = BTSerial.read();
    if (command == '1') {
      // افتح الأضواء
      Serial.println("Lights ON");
      digitalWrite(ledPin, HIGH); // تشغيل الأضواء
    } else if (command == '0') {
      // أغلق الأضواء
      Serial.println("Lights OFF");
      digitalWrite(ledPin, LOW); // إيقاف الأضواء
    }
  }
}

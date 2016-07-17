#include <Bridge.h>
#include <Process.h>

#define TILT 8

const unsigned long interval = 3600000; //1時間ごとにチェック

String curlCmd;
Process process;
unsigned long time;
//boolean first = true;

void setup() {
  // put your setup code here, to run once:
  Bridge.begin();
  Serial.begin(19200);
  pinMode(TILT, INPUT_PULLUP);
  time = millis();
  checkKey();
  //Serial.println("setup done");
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("yo");
  Serial.println(digitalRead(TILT));
  if(millis() - time >= interval) {
    time = millis();
    checkKey();
  }
  delay(100);
}

void checkKey() {
  if(digitalRead(TILT) == HIGH) {
    curlCmd = "curl -k -X POST -H \"Content-Type: application/json\" -d \'{\"value1\":\"部室\",\"value2\":\"開いて\"}' https://maker.ifttt.com/trigger/ooo/with/key/xxx";
  } else {
    curlCmd = "curl -k -X POST -H \"Content-Type: application/json\" -d \'{\"value1\":\"部室\",\"value2\":\"閉まって\"}' https://maker.ifttt.com/trigger/ooo/with/key/xxx";
  }

  process.runShellCommand(curlCmd);

  Serial.print("Response:");
  while (process.available()) {
    char c = process.read();
    Serial.write(c);
  }
  return;
}


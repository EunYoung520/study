#include <Servo.h>
Servo sr, sl;

void setup() {
  Serial.begin(9600);
  sr.attach(13);
  sl.attach(12);
}

void loop() {
  if (Serial.available()) {
    char b[2];  // pitch b[0], roll b[1]
    int p, r;
    Serial.readBytes(b, 2);
    
    p = b[0] * 3;  // 피치값 -90~0~90, 전 후진
    r = b[1];      // 롤 값 -90~0~90, 좌 우회전
    
    // 서보 각도 제어를 위해 write() 대신 writeMicroseconds() 사용
    sr.writeMicroseconds(1500 + p - r);
    sl.writeMicroseconds(1500 - p - r);
    
    Serial.write('1');  // 읽었음을 확인하는 값
  }
}

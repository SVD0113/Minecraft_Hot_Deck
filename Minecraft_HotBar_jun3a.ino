#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

// 물리적 연결 핀
#define TFT_MOSI 11  // SDA
#define TFT_SCLK 12  // SCL
#define TFT_DC    9  // DC
#define TFT_RST  10  // RES
#define TFT_CS   -1  

Adafruit_ST7789 tft = Adafruit_ST7789(&SPI, TFT_CS, TFT_DC, TFT_RST);

void setup(void) {
  Serial.begin(115200);
  delay(1000); 

  // 통신망 개통
  SPI.begin(TFT_SCLK, -1, TFT_MOSI, -1);

  // ★ 스모킹 건: 리뷰어가 말한 바로 그 전설의 초기화 코드 (SPI_MODE3 강제 적용) ★
  tft.init(240, 240, SPI_MODE3);
  tft.invertDisplay(true); 
  
  // 까만 화면으로 덮기
  tft.fillScreen(ST77XX_BLACK);
  
  // 성공 메시지 출력
  tft.setRotation(0);
  tft.setCursor(20, 50);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(2);
  tft.println("Sucess");
  
  tft.setCursor(20, 100);
  tft.setTextColor(ST77XX_GREEN);
  tft.println("Sibal, SEX!!");
}

void loop() {}
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

// LCD ekran ayarları
Adafruit_LiquidCrystal lcd(0);

// Pin tanımları
const int isitmaButonPin = 2;
const int demlemeButonPin = 3;

// Durum değişkenleri
bool isitiliyor = false;
bool demleniyor = false;
unsigned long isitmaBaslangicZamani = 0;
unsigned long demlemeBaslangicZamani = 0;

// Süre sabitleri (saniye cinsinden)
const unsigned long isitmaSuresi = 5;
const unsigned long demlemeSuresi = 3;
const unsigned long bayatSuresi = 7;
bool bayatMesajiGosterildi = false;


void setup() {
  pinMode(isitmaButonPin, INPUT_PULLUP);
  pinMode(demlemeButonPin, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.print("Isit'a basin");
  lcd.setCursor(0, 1);
  lcd.print("su isinsin");
}

void loop() {
  // Isitma butonunun basili olup olmadigini kontrol et
  if (digitalRead(isitmaButonPin) == HIGH && !isitiliyor && !demleniyor) {
    lcd.clear();
    lcd.print("Isitiliyor...");
    isitiliyor = true;
    isitmaBaslangicZamani = millis();
    bayatMesajiGosterildi = false;
  }

  // Demleme butonunun basili olup olmadigini kontrol et
  if (digitalRead(demlemeButonPin) == HIGH) {
    lcd.clear();
    lcd.print("Demleniyor...");
    demleniyor = true;
    demlemeBaslangicZamani = millis();
  }

  // Isitma suresini kontrol et
  if (isitiliyor && (millis() - isitmaBaslangicZamani) >= (isitmaSuresi * 1000)) {
    lcd.clear();
    lcd.print("Isitma tamamlandi");
    lcd.setCursor(0, 1);
    lcd.print("Demle'ye basin");
    isitiliyor = false;
    bayatMesajiGosterildi = true;

  }

  // Demleme suresini kontrol et
  if (demleniyor && (millis() - demlemeBaslangicZamani) >= (demlemeSuresi * 1000)) {
    lcd.clear();
    lcd.print("Hazir!");
    demleniyor = false;
    bayatMesajiGosterildi = false;

  }

 // Bayatlama suresini kontrol et
if (demleniyor == false && isitiliyor == false && bayatMesajiGosterildi == false && (millis() - demlemeBaslangicZamani) >= (bayatSuresi * 1000)) {
    lcd.clear();
    lcd.print("Cay bayatti!");
    demleniyor = false;
    bayatMesajiGosterildi = true;
  }
}

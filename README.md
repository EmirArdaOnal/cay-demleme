# cay-demleme
Tea control system written with Arduino and I2C LCD display

Tabii, işte kodunuzun ayrıntılı bir açıklaması:

1. Kütüphane ve LCD Ekran Ayarları:
   - `Wire.h` ve `Adafruit_LiquidCrystal.h` kütüphaneleri eklenir.
   - LCD ekran için bir `Adafruit_LiquidCrystal` nesnesi oluşturulur.

2. Pin Tanımları:
   - `isitmaButonPin` ve `demlemeButonPin` değişkenleri, sıcaklık kontrol ve demleme butonlarına bağlı olduğu pin numaralarını tanımlar.

3. Durum Değişkenleri:
   - `isitiliyor` ve `demleniyor` değişkenleri, sıcaklık kontrol ve demleme işlemlerinin durumunu tutar.
   - `isitmaBaslangicZamani` ve `demlemeBaslangicZamani` değişkenleri, sıcaklık kontrol ve demleme işlemlerinin başlama zamanını tutar.
   - `bayatMesajiGosterildi` değişkeni, bayatlama mesajının gösterilip gösterilmediğini kontrol eder.

4. Süre Sabitleri:
   - `isitmaSuresi`, `demlemeSuresi` ve `bayatSuresi` değişkenleri, sırasıyla sıcaklık kontrol, demleme ve bayatlama sürelerini saniye cinsinden belirler.

5. `setup()` Fonksiyonu:
   - Buton pinleri giriş olarak ayarlanır.
   - LCD ekran başlatılır ve başlangıç mesajı yazdırılır.

6. `loop()` Fonksiyonu:
   - Sıcaklık Kontrol İşlemi:
     - Sıcaklık kontrol butonuna basılıp basılmadığı kontrol edilir.
     - Eğer sıcaklık kontrol işlemi başlatılmamışsa ve demleme işlemi de devam etmiyorsa:
       - LCD ekran temizlenir.
       - "Isitiliyor..." mesajı yazdırılır.
       - `isitiliyor` durumu `true` olarak ayarlanır.
       - Sıcaklık kontrol işleminin başlama zamanı kaydedilir.
       - Bayatlama mesajının gösterildiği durum sıfırlanır.

   - Demleme İşlemi:
     - Demleme butonuna basılıp basılmadığı kontrol edilir.
     - Eğer demleme işlemi başlatılmışsa:
       - LCD ekran temizlenir.
       - "Demleniyor..." mesajı yazdırılır.
       - `demleniyor` durumu `true` olarak ayarlanır.
       - Demleme işleminin başlama zamanı kaydedilir.

   - Sıcaklık Kontrol Süresi:
     - Sıcaklık kontrol işlemi aktif durumdaysa ve belirlenen süre geçmişse:
       - LCD ekran temizlenir.
       - "Isitma tamamlandi" mesajı yazdırılır.
       - İkinci satıra "Dem

le'ye basin" mesajı yazdırılır.
       - Sıcaklık kontrol işlemi durumu `false` olarak ayarlanır.
       - Bayatlama mesajının gösterildiği durum `true` olarak ayarlanır.

   - Demleme Süresi:
     - Demleme işlemi aktif durumdaysa ve belirlenen süre geçmişse:
       - LCD ekran temizlenir.
       - "Hazir!" mesajı yazdırılır.
       - Demleme işlemi durumu `false` olarak ayarlanır.
       - Bayatlama mesajının gösterildiği durum sıfırlanır.

   - Bayatlama Süresi:
     - Demleme ve sıcaklık kontrol işlemleri devre dışıysa ve bayatlama mesajı henüz gösterilmemişse ve belirlenen süre geçmişse:
       - LCD ekran temizlenir.
       - "Cay bayatti!" mesajı yazdırılır.
       - Demleme işlemi durumu `false` olarak ayarlanır.
       - Bayatlama mesajının gösterildiği durum `true` olarak ayarlanır.


[Proje Link](https://www.tinkercad.com/things/3k4cIkqJ8BD-caycemlemesistemi)

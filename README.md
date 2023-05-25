# cay-demleme
Tea control system written with Arduino and I2C LCD display

1. `Wire.h` kütüphanesi, I2C haberleşmesi için gerekli fonksiyonları içerir.
2. `Adafruit_LiquidCrystal` kütüphanesi, I2C arayüzüne sahip LCD ekranları kontrol etmek için kullanılır.
3. `lcd` nesnesi, LCD ekranın tanımlanması için kullanılır. Parametre olarak 0 geçilerek I2C adresi otomatik olarak algılanır.
4. `isitmaButonPin` ve `demlemeButonPin` değişkenleri, ısıtma ve demleme butonlarının bağlı olduğu pin numaralarını temsil eder.
5. `isitiliyor` ve `demleniyor` değişkenleri, ısıtma ve demleme işlemlerinin durumunu tutar (true/false).
6. `isitmaBaslangicZamani` ve `demlemeBaslangicZamani` değişkenleri, ısıtma ve demleme işlemlerinin başlangıç zamanını saklar.
7. `isitmaSuresi`, `demlemeSuresi` ve `bayatSuresi` değişkenleri, ısıtma, demleme ve bayatlama sürelerini saniye cinsinden belirler.
8. `bayatMesajiGosterildi` değişkeni, "Cay bayatti!" mesajının gösterilip gösterilmediğini tutar.
9. `setup` fonksiyonu, başlangıç ayarlarını yapar. İlgili pinleri giriş olarak ayarlar ve LCD ekrana başlangıç mesajlarını yazar.
10. `loop` fonksiyonu, sürekli olarak çalışır ve ana kodun gerçekleşmesini sağlar.
11. İlk olarak, ısıtma butonunun basılı olup olmadığı kontrol edilir. Eğer ısıtma işlemi aktif değilse (`isitiliyor = false`) ve demleme işlemi de aktif değilse (`demleniyor = false`), LCD ekrana "Isitiliyor..." mesajı yazılır ve ısıtma işlemi başlatılır. Ayrıca, `isitmaBaslangicZamani` değişkeni güncellenir ve `bayatMesajiGosterildi` sıfırlanır.
12. Demleme butonu kontrol edilir. Eğer demleme butonuna basıldıysa, LCD ekrana "Demleniyor..." mesajı yazılır ve demleme işlemi başlatılır. Aynı zamanda, `demlemeBaslangicZamani` değişkeni güncellenir.
13. Isıtma süresi kontrol edilir. Eğer ısıtma işlemi aktif (`isitiliyor = true`) ve belirlenen süre geçmişse (`(millis() - isitmaBaslangicZamani) >= (isitmaSuresi * 1000)`), LCD ekrana "Is

itma tamamlandi" ve "Demle'ye basin" mesajları yazılır, ısıtma işlemi durdurulur (`isitiliyor = false`) ve `bayatMesajiGosterildi` ayarlanır.
14. Demleme süresi kontrol edilir. Eğer demleme işlemi aktif (`demleniyor = true`) ve belirlenen süre geçmişse (`(millis() - demlemeBaslangicZamani) >= (demlemeSuresi * 1000)`), LCD ekrana "Hazir!" mesajı yazılır ve demleme işlemi durdurulur (`demleniyor = false`). Aynı zamanda, `bayatMesajiGosterildi` sıfırlanır.
15. Bayatlama süresi kontrol edilir. Eğer demleme ve ısıtma işlemleri devre dışı (`demleniyor = false` ve `isitiliyor = false`) ve `bayatMesajiGosterildi` false ise (`bayatMesajiGosterildi = false`) ve belirlenen süre geçmişse (`(millis() - demlemeBaslangicZamani) >= (bayatSuresi * 1000)`), LCD ekrana "Cay bayatti!" mesajı yazılır, `bayatMesajiGosterildi` ayarlanır ve demleme işlemi durdurulur (`demleniyor = false`).



[Proje Link](https://www.tinkercad.com/things/20cGe4lFDXM-caydemle)

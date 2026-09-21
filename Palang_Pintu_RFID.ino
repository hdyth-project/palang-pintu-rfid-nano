#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

// ================= PIN =================
#define SS_PIN       10
#define RST_PIN       9
#define SERVO_PIN     6
#define LED_MERAH     4
#define LED_HIJAU     5

// ================= RFID =================
MFRC522 rfid(SS_PIN, RST_PIN);

// ================= SERVO =================
Servo palang;

// ================= UID KARTU =================
// GANTI UID DI BAWAH DENGAN UID KARTU KAMU
// Contoh UID:  DE AD BE EF
byte UID_KARTU[] = {
  0xDE, 0xAD, 0xBE, 0xEF //ganti sesuai uid
};

byte PANJANG_UID = sizeof(UID_KARTU);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  palang.attach(SERVO_PIN);
  pinMode(LED_MERAH, OUTPUT);
  pinMode(LED_HIJAU, OUTPUT);
  // Kondisi awal
  palang.write(0);
  digitalWrite(LED_MERAH, HIGH);
  digitalWrite(LED_HIJAU, LOW);

  Serial.println("================================");
  Serial.println(" SISTEM PALANG RFID");
  Serial.println("================================");
  Serial.println("Silakan scan kartu...");
}

bool kartuValid() {

  if (rfid.uid.size != PANJANG_UID) {
    return false;
  }

  for (byte i = 0; i < PANJANG_UID; i++) {
    if (rfid.uid.uidByte[i] != UID_KARTU[i]) {
      return false;
    }
  }

  return true;
}

// ================= TAMPILKAN UID =================
void tampilkanUID() {

  Serial.print("UID kartu: ");

  for (byte i = 0; i < rfid.uid.size; i++) {

    if (rfid.uid.uidByte[i] < 0x10) {
      Serial.print("0");
    }

    Serial.print(rfid.uid.uidByte[i], HEX);

    if (i < rfid.uid.size - 1) {
      Serial.print(" ");
    }
  }

  Serial.println();
}

// ================= BUKA PALANG =================
void bukaPalang() {

  Serial.println("KARTU VALID!");
  Serial.println("Palang membuka...");

  digitalWrite(LED_MERAH, LOW);
  digitalWrite(LED_HIJAU, HIGH);

  // Buka palang
  palang.write(90);

  // Palang terbuka selama 3 detik
  delay(3000);

  Serial.println("Palang menutup...");

  // Tutup palang
  palang.write(0);

  delay(500);

  digitalWrite(LED_HIJAU, LOW);
  digitalWrite(LED_MERAH, HIGH);

  Serial.println("Palang tertutup.");
  Serial.println("Silakan scan kartu...");
}

// ================= LOOP =================
void loop() {

  // Tidak ada kartu baru
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  // Tidak bisa membaca kartu
  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Tampilkan UID ke Serial Monitor
  tampilkanUID();

  // Periksa kartu
  if (kartuValid()) {

    bukaPalang();

  } else {

    Serial.println("KARTU TIDAK TERDAFTAR!");

    // Pastikan palang tetap tertutup
    palang.write(0);

    digitalWrite(LED_HIJAU, LOW);
    digitalWrite(LED_MERAH, HIGH);

    delay(1000);

    Serial.println("Silakan scan kartu...");
  }

  // Hentikan komunikasi dengan kartu
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  delay(300);
}

# 🚧 Palang Pintu RFID Otomatis:
Sistem palang pintu otomatis berbasis **Arduino Nano** yang menggunakan **RFID RC522** sebagai akses masuk. Ketika kartu RFID yang terdaftar berhasil dipindai, servo akan membuka palang, LED hijau menyala, kemudian palang kembali ke posisi awal dan LED merah menyala kembali.

## 📌 Fitur:
- 🔐 Akses menggunakan kartu RFID
- 🚧 Palang otomatis menggunakan servo
- 🟢 LED hijau sebagai indikator akses diterima
- 🔴 LED merah sebagai indikator palang tertutup
- ⚡ Berbasis Arduino Nano
- 📡 Menggunakan modul RFID RC522

## 🧰 Komponen
1. Arduino Nano 1X
2. RFID RC522 1X
3. Servo SG90 1X
4. LED Merah 1X
5. LED Hijau 1X
6. Kabel jumper (Secukupnya)

## ⚙️ Cara Kerja
1. Sistem berada dalam kondisi palang tertutup.
2. LED merah menyala sebagai indikator palang tertutup.
3. Kartu RFID didekatkan ke RFID RC522.
4. Arduino membaca UID kartu.
5. Jika kartu terdaftar, servo bergerak sekitar 90° untuk membuka palang.
6. LED hijau menyala sebagai indikator akses diterima.
7. Setelah beberapa saat, servo kembali ke posisi awal.
8. LED merah kembali menyala.

## 🔌 Koneksi Pin
### RFID RC522 → Arduino Nano
| SDA   | D10  |
| SCK   | D13  |
| MOSI  | D11  |
| MISO  | D12  |
| RST   | D9   |
| 3.3V  | 3.3V |
| GND   | GND  |

### Komponen lainnya

| Komponen | Pin Arduino Nano |
| Servo SG90 | D6 |
| LED Hijau  | D4 |
| LED Merah  | D5 |

> Catatan: Nomor pin dapat disesuaikan dengan program yang digunakan.

## 🧠 Teknologi
- Arduino Nano
- RFID RC522
- Servo Motor
- LED Indicator
- Arduino IDE


### 👨‍💻 Pembuat
**Hidayatullah**
Project Elektronika & Embedded System

# **Eksperimen 11 - Race Condition dalam Akses Memori**

![AI](../Assets/AIFlag.jpg)

**1. Identifikasi Problem**

Race condition adalah fenomena yang terjadi ketika dua atau lebih thread mencoba mengakses dan memodifikasi lokasi memori yang sama secara bersamaan. Hal ini dapat menyebabkan hasil yang tidak terduga dan sering kali sulit direproduksi. Eksperimen ini bertujuan untuk menyelidiki efek race condition dan mengidentifikasi kondisi di mana race condition terjadi dalam sebuah aplikasi multi-threading.

**2. Deskripsi Problem**

Dalam lingkungan komputasi, thread adalah unit eksekusi terkecil yang dapat dijadwalkan oleh sistem operasi. Ketika beberapa thread mencoba mengakses atau memodifikasi data yang sama secara bersamaan tanpa mekanisme sinkronisasi yang tepat, race condition dapat terjadi. Hasil dari race condition tidak dapat diprediksi, tergantung pada urutan eksekusi thread, yang dapat berbeda-beda setiap kali program dijalankan.

Masalah utama yang diselidiki dalam eksperimen ini adalah bagaimana race condition terjadi, dampaknya terhadap integritas data, dan bagaimana cara mengatasinya menggunakan mekanisme sinkronisasi seperti mutex atau semaphore.

**3. Metodologi Eksperimen**

**Alat dan Bahan:**

- Bahasa pemrograman dengan dukungan multi-threading (misalnya C++, Java, atau Python).
- Komputer dengan sistem operasi yang mendukung multi-threading.
- Alat analisis performa (misalnya, profiler atau debugger).

**Desain Eksperimen:**

1. Implementasi Tanpa Sinkronisasi:

- Buat program sederhana yang memiliki beberapa thread, di mana setiap thread mencoba menambahkan nilai ke variabel shared counter tanpa mekanisme sinkronisasi.
- Hitung berapa kali hasil akhir dari counter tersebut tidak sesuai dengan ekspektasi (misalnya, hasil yang tidak sama dengan jumlah total increment yang dilakukan oleh semua thread).

2. Implementasi dengan Sinkronisasi:

- Modifikasi program dengan menambahkan mekanisme sinkronisasi (misalnya, mutex atau semaphore) untuk menghindari race condition.
- Ulangi percobaan dan catat hasil akhir dari counter.

**Parameter yang Diukur:**

Hasil akhir dari variabel counter setelah semua thread selesai dieksekusi.
Waktu eksekusi total dari program dengan dan tanpa sinkronisasi.

**4. Pelaksanaan Eksperimen**

1. **Tahap 1:** Implementasi Tanpa Sinkronisasi

- Implementasikan kode yang menginisialisasi beberapa thread untuk melakukan operasi increment pada shared counter.
- Jalankan program beberapa kali untuk melihat apakah race condition terjadi, dengan mencatat hasil counter dan waktu eksekusi.

2. **Tahap 2:** Implementasi dengan Sinkronisasi

- Tambahkan mekanisme sinkronisasi seperti mutex pada bagian kode yang mengakses dan memodifikasi shared counter.
- Jalankan kembali program beberapa kali untuk memastikan race condition teratasi.
- Catat hasil counter dan waktu eksekusi.

3. **Pengulangan:**

- Ulangi setiap percobaan beberapa kali untuk mengumpulkan data yang cukup untuk analisis statistik.

**5. Analisis Hasil Eksperimen**

**1. Perbandingan Hasil Akhir Counter:**

- Bandingkan hasil akhir dari counter dalam percobaan tanpa sinkronisasi dengan hasil dari percobaan yang menggunakan sinkronisasi. Jika race condition terjadi, hasil counter dalam percobaan tanpa sinkronisasi kemungkinan besar akan bervariasi dan tidak sesuai dengan ekspektasi.

**2. Analisis Waktu Eksekusi:**

- Analisis dampak penggunaan mekanisme sinkronisasi terhadap waktu eksekusi. Biasanya, penambahan sinkronisasi akan meningkatkan waktu eksekusi karena adanya overhead, namun integritas data akan terjaga.

**3. Kesimpulan:**

- Evaluasi apakah mekanisme sinkronisasi yang digunakan efektif dalam mencegah race condition.
- Diskusikan implikasi dari race condition dalam aplikasi dunia nyata dan pentingnya penggunaan mekanisme sinkronisasi yang tepat dalam desain aplikasi multi-threading.

Hasil dari eksperimen ini diharapkan dapat memberikan pemahaman yang lebih mendalam mengenai race condition dan bagaimana cara mengatasinya dalam pemrograman multi-threading.

Source: [Link Prompt](https://chatgpt.com/share/0bc2cee8-463b-4813-a0ff-111196d30755)

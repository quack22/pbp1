# **Eksperimen 09 - Permasalahan Pengalokasian Memori pada Embedded Systems**

![AI](../Assets/AIFlag.jpg)

**1. Identifikasi Problem**

Pada sistem operasi dan pemrograman, memori program dibagi menjadi beberapa segmen, yaitu segmen data, segmen text, dan segmen BSS. Kesalahan dalam penanganan segmen-segmen ini, seperti mencoba menulis ke segmen text yang seharusnya bersifat read-only, dapat menyebabkan kesalahan runtime. Penelitian ini bertujuan untuk mengidentifikasi potensi masalah yang muncul ketika segmen-segmen ini tidak dikelola dengan baik, serta menganalisis dampaknya terhadap stabilitas dan keamanan program.

**2. Deskripsi Problem**

Segmen text dalam memori menyimpan kode program yang dieksekusi dan bersifat read-only. Segmen data menyimpan variabel global dan statis yang diinisialisasi, sementara segmen BSS (Block Started by Symbol) menyimpan variabel global dan statis yang tidak diinisialisasi. Kesalahan yang sering terjadi adalah upaya menulis ke segmen text atau membaca dari segmen BSS yang belum diinisialisasi. Eksperimen ini akan mempelajari konsekuensi dari tindakan tersebut terhadap eksekusi program dan mengidentifikasi potensi kesalahan runtime yang dihasilkan.

**3. Metodologi Eksperimen**

Eksperimen ini akan dilakukan dengan membuat beberapa program kecil dalam bahasa C yang secara sengaja melakukan kesalahan penanganan segmen memori. Program-program ini akan mencakup:

- Menulis ke segmen text.
- Membaca dari segmen BSS yang belum diinisialisasi.
- Mengakses segmen data dengan cara yang tidak semestinya.

Langkah-langkah yang akan diikuti:

- Membuat kode program yang mengeksekusi operasi pada segmen-segmen memori.
- Mengkompilasi dan menjalankan program untuk mengamati hasilnya.
- Menggunakan alat debugging (seperti GDB) untuk menganalisis kesalahan yang muncul.
- Mencatat perilaku program dan hasil runtime error yang terjadi.

**4. Pelaksanaan Eksperimen**

- **Eksperimen 1:** Menulis ke Segmen Text

  - Buat program sederhana dalam bahasa C yang mencoba menulis ke alamat memori yang berada di segmen text.
  - Kompilasi dan jalankan program tersebut.
  - Amati kesalahan yang muncul, misalnya segmentation fault.

- **Eksperimen 2:** Membaca dari Segmen BSS yang Tidak Diinisialisasi

  - Buat program yang mendeklarasikan variabel global tanpa inisialisasi (segmen BSS) dan coba cetak nilainya sebelum inisialisasi.
  - Kompilasi dan jalankan program tersebut.
  - Amati output yang diberikan oleh program.

- **Eksperimen 3: Manipulasi Segmen Data secara Tidak Wajar**
  - Buat program yang mencoba mengakses dan mengubah data dalam segmen data dengan cara yang tidak semestinya (misalnya menulis ke alamat memori yang bukan milik variabel).
  - Kompilasi dan jalankan program tersebut.
  - Amati dan catat perilaku program.

**5. Analisis Hasil Eksperimen**

- **Eksperimen 1:**

  - Diharapkan terjadi runtime error (segmentation fault) karena upaya menulis ke segmen text yang bersifat read-only.
  - Kesalahan ini menunjukkan pentingnya perlindungan segmen text dalam mencegah modifikasi yang tidak sah terhadap kode program.

- **Eksperimen 2:**

  - Output dari variabel BSS yang belum diinisialisasi mungkin menunjukkan nilai acak atau tidak terdefinisi.
  - Hal ini mengindikasikan bahwa membaca dari segmen BSS tanpa inisialisasi dapat menyebabkan perilaku yang tidak dapat diprediksi.

- **Eksperimen 3:**
  - Jika program mencoba mengakses memori yang tidak diizinkan, kemungkinan besar akan terjadi runtime error.
  - Kesalahan ini menunjukkan risiko keamanan jika segmen data tidak dikelola dengan baik.

Setelah semua eksperimen dilaksanakan, hasilnya akan dibandingkan dan dianalisis untuk memahami bagaimana kesalahan penanganan segmen memori dapat mempengaruhi stabilitas program, serta untuk memberikan rekomendasi pengelolaan memori yang lebih baik.

Source: [Link Prompt](https://chatgpt.com/share/47814e4d-121f-4b8b-bd63-d0fafd4b728e)

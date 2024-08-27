# **Eksperimen 02 - Fragmentasi Memori di Heap**

![AI](../Assets/AIFlag.jpg)

**1. Identifikasi Problem**

**Masalah yang Dihadapi:** Fragmentasi memori di heap dapat memengaruhi kinerja aplikasi, khususnya dalam hal kecepatan alokasi dan de-alokasi memori. Dalam konteks aplikasi yang memiliki pola alokasi memori yang berbeda-beda, penting untuk memahami sejauh mana fragmentasi memengaruhi kinerja.

**Tujuan Eksperimen:** Menilai dampak fragmentasi memori terhadap kinerja alokasi dan de-alokasi memori dengan menggunakan beberapa pola alokasi yang berbeda.

**2. Deskripsi Problem**

**Fragmentasi Memori:** Merujuk pada kondisi di mana ruang memori bebas yang tersedia terpecah menjadi blok-blok kecil yang terpisah, yang bisa mengurangi efisiensi alokasi memori baru.
Kinerja Alokasi dan De-alokasi: Fokus pada waktu yang dibutuhkan untuk mengalokasikan dan melepaskan memori, yang bisa dipengaruhi oleh pola alokasi memori aplikasi.

**Variasi Pola Alokasi:** Aplikasi yang berbeda memiliki pola alokasi yang bervariasi, seperti alokasi besar-besaran di awal, alokasi bertahap, atau pola acak.

**3. Metodologi Eksperimen**

Pemilihan Pola Alokasi:

- Pola A: Alokasi besar-besaran di awal, kemudian de-alokasi bertahap.
- Pola B: Alokasi dan de-alokasi secara acak.
- Pola C: Alokasi bertahap dan de-alokasi serentak di akhir.
  Pengaturan Lingkungan:
  Menggunakan satu atau lebih bahasa pemrograman yang mendukung alokasi memori dinamis (misalnya, C atau C++).
  Penggunaan alat profiling memori untuk melacak fragmentasi dan waktu eksekusi.
  Variabel yang Diukur:
  Waktu yang dibutuhkan untuk alokasi dan de-alokasi.
  Tingkat fragmentasi memori yang terjadi.
  Pendekatan Pengukuran:
  Menjalankan beberapa siklus alokasi dan de-alokasi untuk setiap pola, kemudian mencatat waktu dan fragmentasi.

**4. Pelaksanaan Eksperimen**

- **Langkah 1:** Implementasi kode dengan pola alokasi dan de-alokasi sesuai dengan deskripsi di atas.
- **Langkah 2:** Menjalankan kode dalam kondisi terkontrol untuk setiap pola alokasi, mengumpulkan data waktu eksekusi dan fragmentasi memori.
- **Langkah 3:** Ulangi eksperimen beberapa kali untuk mendapatkan hasil yang konsisten dan mengurangi pengaruh noise atau anomali.
- **Langkah 4:** Simpan dan dokumentasikan hasil setiap siklus eksperimen dengan hati-hati.

**5. Analisis Hasil Eksperimen**

- **Langkah 1:** Bandingkan waktu alokasi dan de-alokasi antara pola-pola yang berbeda untuk menentukan pola mana yang paling terpengaruh oleh fragmentasi.
- **Langkah 2:** Evaluasi tingkat fragmentasi memori untuk setiap pola, dan analisis korelasi antara fragmentasi dan penurunan kinerja.
- **Langkah 3:** Interpretasikan hasil dengan mempertimbangkan aplikasi nyata, dan identifikasi skenario di mana fragmentasi memori bisa menjadi masalah kritis.
- **Langkah 4:** Buat kesimpulan dan rekomendasi untuk manajemen memori yang lebih efisien dalam aplikasi dengan pola alokasi tertentu.

Source: [Link Prompt](https://chatgpt.com/share/e55bb3f0-3230-40e7-aea9-92a62a97aa1d)

# **Eksperimen 01 - Memory Leak pada Penggunaan Malloc**

![AI](../Assets/AIFlag.jpg)

Berikut adalah susunan rencana eksperimen dengan topik "Mengapa penting untuk mengantisipasi kasus memory leak pada implementasi program saat menggunakan 'malloc'":

**1. Identifikasi Problem**

- **Issue:** Memory leak sering terjadi saat penggunaan fungsi malloc pada bahasa C/C++ tanpa diikuti oleh free.
- **Dampak:** Memory leak dapat menyebabkan penggunaan memori yang tidak efisien, menurunkan performa program, dan bahkan menyebabkan crash pada program.
- **Relevansi:** Antisipasi memory leak penting untuk memastikan stabilitas dan efisiensi program, terutama pada aplikasi dengan alokasi memori dinamis yang intensif.

**2. Deskripsi Problem**

- **Apa itu Memory Leak?:** Memory leak terjadi ketika memori yang telah dialokasikan oleh program tidak dibebaskan kembali setelah tidak lagi digunakan, sehingga menyebabkan kebocoran memori.
- **Peran malloc:** malloc adalah fungsi untuk mengalokasikan memori secara dinamis di heap, namun tidak otomatis membebaskan memori tersebut. Tanpa free, memori yang dialokasikan tetap terpakai.
- **Konsekuensi Jangka Panjang:** Dalam aplikasi jangka panjang atau yang berjalan terus-menerus (seperti server), memory leak dapat secara bertahap menghabiskan memori sistem, menyebabkan performa menurun hingga crash.

**3. Metodologi Eksperimen**

- **Langkah 1:** Siapkan dua program sederhana yang menggunakan malloc untuk alokasi memori dinamis.
  > Program A: **Tidak menggunakan free** untuk membebaskan memori.\
  >  Program B: **Menggunakan free** untuk membebaskan memori.
- Langkah 2: Jalankan kedua program dalam waktu yang lama dan ukur penggunaan memori setiap beberapa waktu.
- Langkah 3: Gunakan alat monitoring (misal: Valgrind) untuk mendeteksi adanya memory leak pada kedua program.

**4. Pelaksanaan Eksperimen**

- Langkah 1: Tulis kedua program dengan menggunakan malloc untuk alokasi memori.
- Langkah 2: Jalankan kedua program secara paralel dalam skenario yang serupa (misal: menjalankan loop besar).
- Langkah 3: Lakukan monitoring secara berkala terhadap penggunaan memori untuk kedua program menggunakan alat seperti top, htop, atau Valgrind.
- Langkah 4: Catat hasil penggunaan memori dari kedua program setelah beberapa waktu berjalan.

**5. Analisis Hasil Eksperimen**

- Langkah 1: Bandingkan penggunaan memori antara Program A dan Program B setelah periode waktu yang ditentukan.
- Langkah 2: Identifikasi apakah ada peningkatan penggunaan memori yang signifikan pada Program A (yang tidak menggunakan free).
- Langkah 3: Analisis data dari Valgrind untuk mendeteksi adanya memory leak dan jumlah memori yang hilang.
- Langkah 4: Buat kesimpulan tentang pentingnya antisipasi memory leak dan relevansi free dalam menjaga efisiensi memori program.
  Ini adalah overview dan langkah-langkah detail yang perlu diambil untuk menyusun eksperimen tentang pentingnya mengantisipasi memory leak saat menggunakan malloc.

Source: [Link Prompt](https://chatgpt.com/share/64049234-0d52-4b04-8665-60f687ad7619)

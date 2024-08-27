# **Eksperimen 10 - Konsistensi antara Segmen Data, Text, dan BSS**

![AI](../Assets/AIFlag.jpg)

**1. Identifikasi Problem**

Pada sistem embedded, memori yang tersedia sangat terbatas dibandingkan dengan sistem komputer umum. Salah satu tantangan utama dalam pengembangan perangkat lunak untuk sistem ini adalah pengelolaan memori yang efisien. Heap, sebagai area memori yang digunakan untuk alokasi dinamis, seringkali menjadi sumber permasalahan jika tidak dikelola dengan baik. Penggunaan heap yang tidak efisien dapat menyebabkan fragmentasi memori, kehabisan memori, dan bahkan kegagalan sistem.

**2. Deskripsi Problem**

Heap adalah bagian dari memori yang dialokasikan dan dikelola secara dinamis selama runtime. Pada sistem embedded dengan sumber daya memori yang terbatas, penggunaan heap yang tidak efisien, seperti alokasi memori berulang tanpa pembebasan atau alokasi memori dengan ukuran yang bervariasi, dapat menyebabkan fragmentasi dan kehabisan memori. Fragmentasi menyebabkan ruang memori yang tersedia terpecah menjadi potongan-potongan kecil yang tidak dapat digunakan, sementara kehabisan memori mengakibatkan sistem tidak bisa lagi mengalokasikan memori baru yang dibutuhkan.

**3. Metodologi Eksperimen**

Eksperimen ini akan menggunakan sistem embedded sederhana dengan kapasitas memori terbatas. Perangkat lunak akan dikembangkan untuk menjalankan beberapa skenario alokasi memori yang umum ditemui dalam pengembangan sistem embedded:

- **Skenario 1:** Alokasi dan pembebasan memori secara berulang dengan ukuran yang konstan.
- **Skenario 2:** Alokasi memori dengan ukuran yang bervariasi dan pembebasan yang tidak teratur.
- **Skenario 3:** Alokasi memori tanpa pembebasan memori, mensimulasikan kebocoran memori (memory leak).

Setiap skenario akan dijalankan pada sistem embedded, dan penggunaan memori akan dipantau secara real-time untuk mengidentifikasi tanda-tanda fragmentasi atau kehabisan memori.

**4. Pelaksanaan Eksperimen**

1.  Persiapan Sistem:

- Siapkan sistem embedded dengan alat monitoring memori.
- Kembangkan tiga aplikasi sederhana sesuai dengan skenario yang telah ditentukan.

2.  Pengujian Skenario 1:

- Jalankan aplikasi yang melakukan alokasi dan pembebasan memori dengan ukuran yang konstan.
- Pantau penggunaan memori dan catat waktu yang dibutuhkan hingga fragmentasi menyebabkan kegagalan alokasi.

3.  Pengujian Skenario 2:

- Jalankan aplikasi yang melakukan alokasi memori dengan ukuran yang bervariasi dan pembebasan yang tidak teratur.
- Pantau penggunaan memori, perhatikan pola fragmentasi, dan catat waktu hingga terjadi kehabisan memori.

4.  Pengujian Skenario 3:

- Jalankan aplikasi yang melakukan alokasi memori tanpa pembebasan untuk mensimulasikan memory leak.
- Pantau penggunaan memori dan catat waktu hingga terjadi kehabisan memori.

5.  Pengumpulan Data:

- Kumpulkan data mengenai penggunaan memori, jumlah alokasi yang berhasil dan gagal, dan waktu yang dibutuhkan untuk mencapai kondisi kegagalan pada setiap skenario.

**5. Analisis Hasil Eksperimen**

**Skenario 1:** Jika fragmentasi menyebabkan kegagalan alokasi, ini menunjukkan bahwa bahkan dengan ukuran alokasi yang konstan, pengelolaan heap yang tidak optimal dapat menyebabkan masalah pada sistem embedded dengan sumber daya terbatas.

**Skenario 2:** Diharapkan terjadi fragmentasi yang lebih cepat dibandingkan skenario 1, menunjukkan bahwa ukuran alokasi yang bervariasi memperburuk fragmentasi memori.

**Skenario 3:** Kecepatan terjadinya kehabisan memori pada skenario ini akan menunjukkan dampak dari kebocoran memori pada sistem embedded. Jika sistem cepat kehabisan memori, ini menunjukkan betapa kritisnya pengelolaan heap yang baik untuk mencegah kebocoran memori.

Kesimpulan dari eksperimen ini akan membantu dalam mengidentifikasi strategi yang lebih baik untuk pengelolaan memori pada sistem embedded, seperti penggunaan algoritma pengelolaan heap yang lebih efisien atau pembatasan alokasi memori dinamis.

Source: [Link Prompt](https://chatgpt.com/share/c69b8aa7-3bcc-45cb-89f2-48c205bde0d9)

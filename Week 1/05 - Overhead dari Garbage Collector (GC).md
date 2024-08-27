# **Eksperimen 05 - Overhead dari Garbage Collector (GC)**

![AI](../Assets/AIFlag.jpg)

**1. Identifikasi Problem**

Garbage collection (GC) adalah mekanisme otomatis dalam manajemen memori yang membebaskan memori yang tidak lagi digunakan oleh program. Meskipun GC mempermudah pengembangan aplikasi dengan mengurangi risiko kebocoran memori, overhead yang ditimbulkannya dapat mempengaruhi kinerja program. Overhead ini mencakup waktu yang dihabiskan oleh GC untuk mendeteksi dan membebaskan memori, yang dapat mengakibatkan penurunan kinerja aplikasi, terutama pada aplikasi dengan kebutuhan memori yang tinggi atau real-time.

**2. Deskripsi Problem**

Penelitian ini bertujuan untuk mengukur dan menganalisis overhead yang ditimbulkan oleh garbage collector pada manajemen memori dalam berbagai kondisi program. Overhead GC akan dievaluasi berdasarkan waktu eksekusi program dan penggunaan CPU ketika GC diaktifkan dibandingkan dengan ketika GC dinonaktifkan (jika memungkinkan). Eksperimen ini akan fokus pada berbagai skenario program, termasuk program yang mengalokasikan banyak objek kecil, objek besar, serta frekuensi alokasi dan dealokasi objek yang berbeda-beda.

**3. Metodologi Eksperimen**

Eksperimen ini akan dilakukan dengan menggunakan bahasa pemrograman yang mendukung garbage collection, seperti Java atau C#. Struktur eksperimen meliputi:

- **Pemilihan Skenario Program:**
  - **Skenario 1:** Program yang mengalokasikan banyak objek kecil secara terus menerus.
  - **Skenario 2:** Program yang mengalokasikan beberapa objek besar.
  - **Skenario 3:** Program dengan frekuensi alokasi dan dealokasi objek yang tinggi.
- **Konfigurasi Lingkungan:**
  - Lingkungan eksekusi akan dijalankan pada mesin dengan spesifikasi tertentu (CPU, RAM, dll.).
  - Eksperimen akan dilakukan dengan GC diaktifkan dan dinonaktifkan (jika memungkinkan) untuk melihat perbedaannya.
- **Pengumpulan Data:**
  - Waktu eksekusi total program.
  - Jumlah waktu yang dihabiskan oleh GC.
  - Penggunaan CPU selama eksekusi.
  - Memory footprint program.

**4. Pelaksanaan Eksperimen**

**Persiapan Lingkungan:**

- Setup lingkungan dengan bahasa pemrograman yang dipilih (misalnya, Java dengan HotSpot JVM).
- Konfigurasi alat monitoring untuk mengumpulkan data terkait penggunaan CPU, waktu eksekusi, dan aktivitas GC (misalnya, VisualVM atau JConsole untuk Java).

**Implementasi Skenario:**

- Implementasi kode untuk masing-masing skenario yang telah ditentukan.
- Pastikan skenario dapat dijalankan dengan dan tanpa GC untuk melihat perbedaannya.

**Pengumpulan Data:**

- Jalankan tiap skenario secara berulang untuk mendapatkan data yang akurat.
- Kumpulkan data terkait waktu eksekusi, penggunaan CPU, dan waktu yang dihabiskan oleh GC.

**Eksperimen Kontrol:**

- Lakukan kontrol eksperimen dengan menjalankan program tanpa GC (jika memungkinkan) atau dengan GC yang dimodifikasi untuk meminimalisir aktivitasnya.

**5. Analisis Hasil Eksperimen**

**Waktu Eksekusi:**

- Bandingkan waktu eksekusi program dengan GC aktif vs. tanpa GC untuk masing-masing skenario. Analisis berapa banyak overhead waktu yang ditimbulkan oleh GC.

**Penggunaan CPU:**

- Evaluasi bagaimana penggunaan CPU berubah dengan adanya aktivitas GC. Identifikasi apakah ada peningkatan penggunaan CPU yang signifikan saat GC aktif.

**Memory Footprint:**

- Periksa bagaimana memory footprint program berubah saat GC aktif dibandingkan saat dinonaktifkan. Apakah ada perbedaan signifikan dalam alokasi memori yang tidak dibebaskan dengan segera ketika GC tidak aktif?

**Overhead GC:**

- Analisis secara keseluruhan overhead yang ditimbulkan oleh GC, termasuk penurunan kinerja (jika ada) dan perbedaan dalam manajemen memori.

**Kesimpulan:**

- Berdasarkan analisis di atas, simpulkan sejauh mana garbage collector mempengaruhi kinerja aplikasi dalam berbagai kondisi dan kapan penggunaannya dapat menimbulkan overhead yang signifikan. Identifikasi rekomendasi untuk pengembangan aplikasi yang lebih efisien dalam konteks manajemen memori.

Source: [Link Prompt](https://chatgpt.com/share/de453258-e035-4b08-92f1-c5bb5d0ef5e7)

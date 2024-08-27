# **Eksperimen 07 - Stack Overflow**

![AI](../Assets/AIFlag.jpg)

**1. Identifikasi Problem**

**Masalah:** Stack overflow adalah kondisi di mana stack, yaitu area memori yang digunakan oleh program untuk menyimpan variabel lokal, parameter fungsi, dan informasi lain yang diperlukan oleh proses eksekusi, kehabisan ruang. Salah satu penyebab umum stack overflow adalah penggunaan rekursi yang terlalu dalam atau alokasi memori yang terlalu besar untuk variabel lokal. Ketika stack overflow terjadi, program bisa mengalami crash atau menunjukkan perilaku yang tak terduga.

**2. Deskripsi Problem**

Stack overflow terjadi karena stack memiliki ukuran yang terbatas. Ketika sebuah program menggunakan rekursi dalam yang tidak terkendali atau mengalokasikan memori dalam jumlah besar di dalam stack, maka ukuran stack bisa melampaui batas yang diizinkan oleh sistem. Akibatnya, program tidak dapat melanjutkan eksekusi dan bisa berhenti secara mendadak (crash) atau memberikan hasil yang tidak diinginkan.

Dalam eksperimen ini, kita akan membuat sebuah program yang menggunakan rekursi untuk menghitung faktorial dari sebuah angka, tetapi dengan sengaja membuat rekursi yang terlalu dalam untuk memicu stack overflow. Program ini akan memberikan wawasan tentang bagaimana stack overflow dapat terjadi dan efeknya terhadap program.

**3. Metodologi Eksperimen**

- **Alat dan Bahan:** Komputer dengan sistem operasi yang mendukung pemrograman C/C++, Python, atau Java.

- **Pendekatan:**
  - Membuat program yang menggunakan rekursi untuk menghitung faktorial.
  - Menjalankan program dengan nilai input yang cukup besar untuk memicu stack overflow.
  - Mencatat gejala dan hasil yang muncul setelah terjadinya stack overflow.

**4. Pelaksanaan Eksperimen**

**a. Penulisan Program**

Kita akan menulis program sederhana menggunakan rekursi untuk menghitung faktorial dari sebuah angka besar. Berikut adalah contoh dalam bahasa C:

```
#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int num = 100000; // Nilai yang sangat besar untuk memicu stack overflow
    printf("Factorial of %d is %llu\n", num, factorial(num));
    return 0;
}
```

**b. Menjalankan Program**

Kompilasi program di atas menggunakan kompiler C seperti GCC.
Jalankan program dan amati hasilnya.

**c. Mengamati Hasil**

- Jika stack overflow terjadi, program akan mengalami crash, biasanya dengan pesan error seperti "Segmentation Fault" di sistem berbasis Unix/Linux, atau mungkin pesan error spesifik lainnya tergantung pada OS yang digunakan.
- Jika tidak terjadi stack overflow, program akan menghasilkan nilai faktorial (meskipun mungkin akan memakan waktu sangat lama dan memori yang besar).

**5. Analisis Hasil Eksperimen**

**Analisis Hasil:**

- Kondisi Stack Overflow: Jika program mengalami crash, ini menunjukkan bahwa stack overflow telah terjadi. Hal ini disebabkan oleh rekursi yang terlalu dalam, di mana setiap panggilan fungsi baru menambahkan data ke stack, hingga akhirnya ukuran stack melebihi kapasitas maksimal.
- Efek Stack Overflow: Crash yang terjadi biasanya menunjukkan bahwa sistem operasi menghentikan program untuk mencegah kerusakan lebih lanjut. Dalam beberapa kasus, mungkin akan muncul pesan error yang dapat membantu dalam diagnosis masalah.
- Perilaku Program: Jika program tidak crash, tetapi memberikan hasil yang tidak diinginkan, ini menunjukkan bahwa stack mungkin mendekati kapasitasnya tetapi belum sepenuhnya overflown. Perilaku ini bisa berbeda tergantung pada implementasi bahasa dan sistem operasi.

**Kesimpulan:** Eksperimen ini menunjukkan bagaimana penggunaan rekursi yang terlalu dalam dapat menyebabkan stack overflow, mengakibatkan crash atau perilaku tak terduga pada program. Penting bagi programmer untuk mempertimbangkan batasan stack dan mengelola rekursi serta alokasi memori dengan hati-hati untuk menghindari masalah ini.

Source: [Link Prompt](https://chatgpt.com/share/4bbf8791-f47c-481e-b7a1-dfc2e9c02b3e)

# **Eksperimen 08 - Kesalahan Alokasi Dinamis dengan new**

![AI](../Assets/AIFlag.jpg)

**1. Identifikasi Problem**

Ketika menggunakan alokasi dinamis dengan kata kunci new dalam bahasa pemrograman seperti C++, jika alokasi memori gagal dan tidak ada mekanisme penanganan kesalahan, maka akan terjadi kebocoran memori. Ini terjadi karena memori yang dialokasikan tidak akan pernah dibebaskan kembali jika program tidak menangani pengecualian yang terjadi saat alokasi memori gagal. Akibatnya, penggunaan memori meningkat tanpa batas, yang dapat menyebabkan sistem kehabisan memori dan program crash.

**2. Deskripsi Problem**

Dalam bahasa C++, new digunakan untuk mengalokasikan memori secara dinamis di heap. Namun, jika alokasi memori gagal (misalnya, karena kekurangan memori), new akan melemparkan pengecualian std::bad_alloc. Jika pengecualian ini tidak ditangani dengan benar, memori yang sebelumnya telah dialokasikan dapat terlepas begitu saja tanpa dibebaskan, menyebabkan kebocoran memori.

Kebocoran memori ini bisa sangat berbahaya, terutama dalam aplikasi yang berjalan dalam waktu lama atau yang membutuhkan alokasi memori yang besar dan sering. Ini akan menyebabkan program menggunakan lebih banyak memori dari yang seharusnya, hingga akhirnya sistem menjadi tidak stabil.

**3. Metodologi Eksperimen**

Eksperimen ini akan dilakukan dengan langkah-langkah sebagai berikut:

1.  Membuat program sederhana yang menggunakan alokasi dinamis dengan new tanpa penanganan pengecualian.
2.  Menjalankan program untuk melihat apa yang terjadi ketika alokasi memori gagal.
3.  Membuat versi kedua dari program yang sama, namun kali ini dengan penanganan pengecualian untuk menangani kegagalan alokasi memori.
4.  Mengamati perbedaan hasil antara kedua program tersebut.

**4. Pelaksanaan Eksperimen**

Program Tanpa Penanganan Pengecualian

```
#include <iostream>

int main() {
    int* array = new int[1000000000]; // Mengalokasikan memori yang sangat besar
    std::cout << "Memori berhasil dialokasikan!" << std::endl;
    delete[] array; // Membebaskan memori
    return 0;
}

```

Pada program ini, kita mencoba mengalokasikan memori yang sangat besar tanpa menangani kemungkinan kegagalan alokasi.

**Program Dengan Penanganan Pengecualian**

```
#include <iostream>
#include <new> // Untuk std::bad_alloc

int main() {
    try {
        int* array = new int[1000000000]; // Mengalokasikan memori yang sangat besar
        std::cout << "Memori berhasil dialokasikan!" << std::endl;
        delete[] array; // Membebaskan memori
    } catch (const std::bad_alloc& e) {
        std::cerr << "Alokasi memori gagal: " << e.what() << std::endl;
    }
    return 0;
}
```

Pada program kedua, kita menangkap pengecualian `std::bad_alloc` jika alokasi memori gagal, sehingga kita dapat menghindari kebocoran memori.

**5. Analisis Hasil Eksperimen**

**Program Tanpa Penanganan Pengecualian**

Ketika dijalankan, program ini akan mencoba mengalokasikan memori dalam jumlah yang sangat besar. Jika sistem tidak memiliki cukup memori, alokasi akan gagal, namun karena tidak ada penanganan pengecualian, program akan crash, atau dalam kasus terbaik, hanya mengabaikan kegagalan ini tanpa memberikan informasi apapun. Selain itu, jika alokasi memori sebelumnya tidak dibebaskan, akan terjadi kebocoran memori.

**Program Dengan Penanganan Pengecualian**

Pada program ini, ketika alokasi memori gagal, pengecualian std::bad_alloc akan ditangkap, dan pesan kesalahan akan ditampilkan. Memori yang telah dialokasikan sebelum pengecualian terjadi akan dibebaskan, sehingga tidak ada kebocoran memori.

**Kesimpulan:**

- Program yang tidak menangani pengecualian dari new berpotensi menyebabkan kebocoran memori dan crash program.
- Dengan menambahkan penanganan pengecualian, kita dapat menghindari kebocoran memori dan memastikan bahwa program memberikan pesan kesalahan yang sesuai jika terjadi masalah dalam alokasi memori.

Source: [Link Prompt](https://chatgpt.com/share/5eb3acd7-8442-47cd-aa12-3adc5bf80a70)

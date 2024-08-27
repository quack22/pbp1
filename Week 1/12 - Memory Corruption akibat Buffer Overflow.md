# **Eksperimen 12 - Memory Corruption akibat Buffer Overflow**

![AI](../Assets/AIFlag.jpg)

**1. Identifikasi Problem**

**Problem:** Kerentanan buffer overflow adalah salah satu celah keamanan yang memungkinkan penyerang menulis data melebihi batas buffer yang dialokasikan, yang dapat menyebabkan korupsi memori dan potensi eksekusi kode berbahaya.

**2. Deskripsi Problem**

**Deskripsi:** Buffer adalah area memori sementara yang digunakan untuk menyimpan data saat dipindahkan dari satu tempat ke tempat lain. Dalam beberapa bahasa pemrograman, buffer tidak memiliki perlindungan batas yang kuat, sehingga memungkinkan data yang dimasukkan melebihi kapasitas buffer. Ketika data tersebut melebihi batas, data tersebut dapat menimpa memori di lokasi lain, yang dapat menyebabkan kerusakan pada program, perilaku tak terduga, atau bahkan memberikan kesempatan kepada penyerang untuk menjalankan kode berbahaya.

Buffer overflow biasanya terjadi dalam bahasa pemrograman seperti C atau C++ yang tidak secara otomatis mengelola memori atau memeriksa batasan array. Dengan memanipulasi data yang dimasukkan ke buffer, penyerang dapat mengubah alur eksekusi program, seperti mengubah nilai return address dan menjalankan kode arbitrer.

**3. Metodologi Eksperimen**

**Tujuan Eksperimen:** Mendemonstrasikan bagaimana buffer overflow dapat menyebabkan memory corruption dan berpotensi memungkinkan eksekusi kode berbahaya.

**Alat dan Bahan:**

- Komputer dengan sistem operasi Linux atau Windows
- Compiler C/C++
- Editor teks (misalnya: Vim, Visual Studio Code)
- Program contoh yang rentan terhadap buffer overflow

**Langkah-langkah:**

- Persiapan Lingkungan: Pastikan compiler C/C++ terinstal pada sistem.
- Penulisan Program: Buat program C yang rentan terhadap buffer overflow.
- Kompilasi Program: Kompilasi program tanpa menggunakan proteksi buffer overflow (seperti stack canaries).
- Pelaksanaan Buffer Overflow: Eksekusi program dengan input yang menyebabkan overflow buffer.
- Pengamatan: Amati perilaku program dan perubahan memori setelah buffer overflow terjadi.

**4. Pelaksanaan Eksperimen**

**Langkah-langkah Pelaksanaan:**

1. **Menulis Program Rentan:** Buat program sederhana dalam C yang mengandung buffer overflow. Berikut adalah contoh kode yang rentan:

```
#include <stdio.h>
#include <string.h>

void vulnerable_function(char *str) {
    char buffer[10];
    strcpy(buffer, str);  // Tidak ada pemeriksaan batas buffer
    printf("Input Anda: %s\n", buffer);
}

int main() {
    char input[100];
    printf("Masukkan input: ");
    gets(input);  // Penggunaan gets() yang tidak aman
    vulnerable_function(input);
    return 0;
}
```

2. **Kompilasi Program:** Kompilasi program di atas dengan perintah: `gcc -o vuln_program vuln_program.c -fno-stack-protector`

3. **Eksekusi Program dengan Input Berbahaya:** Jalankan program dan masukkan string yang lebih panjang dari buffer (misalnya, 20 karakter): `./vuln_program Masukkan input: AAAAAAAAAAAAAAAAAAAAAAAAAAAA`

4. **Pengamatan:** Setelah program dijalankan, program mungkin akan crash, atau menunjukkan perilaku tidak biasa. Jika stack memory layout bisa diakses, perubahan nilai pada register atau pointer bisa diamati.

**5. Analisis Hasil Eksperimen**

**Analisis:**

- **Perilaku Program:** Buffer overflow mungkin menyebabkan program crash atau menghasilkan output yang tidak terduga. Ini menunjukkan bahwa data telah menimpa area memori yang tidak dimaksudkan.

- **Potensi Eksekusi Kode Berbahaya:** Dalam skenario yang lebih kompleks, buffer overflow dapat digunakan untuk menimpa alamat pengembalian fungsi, sehingga memungkinkan eksekusi kode berbahaya.

- **Keamanan:** Eksperimen ini menunjukkan betapa pentingnya pemeriksaan batas buffer dan penggunaan fungsi-fungsi yang lebih aman seperti strncpy dan fgets untuk mencegah buffer overflow.

Kesimpulan: Eksperimen ini membuktikan bahwa buffer overflow dapat menyebabkan korupsi memori, crash pada program, dan potensi risiko eksekusi kode berbahaya. Penting untuk mengimplementasikan praktik pemrograman yang aman untuk mencegah kerentanan ini.

Source: [Link Prompt](https://chatgpt.com/share/250676b5-3e0c-4380-a9bb-16bf4f7b9c16)

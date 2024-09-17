
# Memori Bersama (Shared Memory)

Dalam program paralel atau **concurrent programming**, memori bersama (**shared memory**) merujuk pada mekanisme di mana beberapa **thread** atau **proses** dapat mengakses memori yang sama untuk berbagi data. Ini memungkinkan komunikasi yang efisien antara unit-unit eksekusi (thread atau proses) dalam sebuah aplikasi. Namun, memori bersama juga membawa tantangan baru, terutama terkait dengan **race conditions** dan **deadlocks**.

## A. Mengapa Memori Bersama Penting
- **Efisiensi**: Memori bersama memungkinkan **pengaksesan data secara langsung** antara thread atau proses tanpa perlu mekanisme komunikasi yang mahal (seperti message passing).
- **Penghematan Waktu**: Karena semua thread dapat membaca atau menulis ke memori yang sama, tidak diperlukan salinan terpisah dari data. Ini menghemat waktu dan memori.
  
Namun, **akses paralel** ke memori bersama ini harus dikelola dengan hati-hati agar tidak menyebabkan masalah **konsistensi data**.

## B. Masalah Utama dalam Pengelolaan Memori Bersama
1. **Race Conditions**:
   - Race condition terjadi ketika dua atau lebih thread atau proses mengakses memori bersama secara bersamaan, dan hasil akhir bergantung pada urutan eksekusi.
   - Contoh race condition adalah ketika satu thread membaca nilai dari memori sementara thread lain menulis ke memori yang sama secara bersamaan, yang bisa menyebabkan hasil yang tidak diinginkan atau data korup.
   
2. **Deadlocks**:
   - Deadlock terjadi ketika dua atau lebih thread atau proses saling menunggu sumber daya yang dipegang oleh satu sama lain, sehingga tidak ada yang bisa melanjutkan eksekusi.
   - Dalam konteks memori bersama, deadlock bisa terjadi jika dua thread mencoba mengunci dua sumber daya berbeda, tetapi saling menunggu pelepasan kunci dari satu sama lain.

## C. Thread Safety dan Manajemen Akses Memori
Untuk menghindari race conditions dan deadlocks dalam memori bersama, penting untuk menerapkan teknik **thread safety**. Thread safety memastikan bahwa beberapa thread dapat mengakses memori bersama tanpa menyebabkan inkonsistensi data atau konflik.

Beberapa metode umum untuk memastikan thread safety dalam penggunaan memori bersama:

1. **Locks (Penguncian)**:
   - Penguncian adalah mekanisme untuk memastikan bahwa hanya satu thread yang dapat mengakses memori bersama pada suatu waktu.
   - **Mutex (Mutual Exclusion)**: Salah satu alat penguncian paling umum. Mutex memastikan bahwa hanya satu thread yang bisa mengunci dan mengakses memori bersama, sementara thread lain harus menunggu hingga kunci dibebaskan.
   
   Contoh penggunaan mutex di C (dengan pthreads):

   ```c
   pthread_mutex_t lock;  // Definisi mutex

   void* thread_function(void* arg) {
       pthread_mutex_lock(&lock);  // Mengunci
       // Akses memori bersama di sini
       pthread_mutex_unlock(&lock);  // Membuka kunci
       return NULL;
   }

   int main() {
       pthread_mutex_init(&lock, NULL);  // Inisialisasi mutex
       
       // Membuat dan menjalankan thread
       pthread_t thread1, thread2;
       pthread_create(&thread1, NULL, thread_function, NULL);
       pthread_create(&thread2, NULL, thread_function, NULL);
       
       // Bergabung dengan thread
       pthread_join(thread1, NULL);
       pthread_join(thread2, NULL);
       
       pthread_mutex_destroy(&lock);  // Menghancurkan mutex setelah digunakan
       return 0;
   }
   ```

2. **Semaphore**:
   - Semaphore mirip dengan mutex, tetapi bisa mengontrol akses oleh beberapa thread pada waktu yang sama. Sebuah semaphore memiliki hitungan (count), yang menunjukkan berapa banyak thread yang dapat mengakses memori bersama secara bersamaan.
   - Contoh penggunaan semaphore bisa ditemukan dalam manajemen akses ke sumber daya terbatas, seperti buffer berbatas dalam sistem produsen-konsumen.

3. **Atomic Operations**:
   - Operasi **atomik** adalah operasi yang tidak dapat dipecah-pecah atau diinterupsi oleh thread lain. Operasi ini memastikan bahwa tindakan seperti penambahan atau pengurangan variabel dilakukan dengan aman oleh beberapa thread tanpa menyebabkan race condition.
   - Dalam C++, header `<atomic>` menyediakan tipe data atomik yang aman digunakan dalam lingkungan multi-threading, seperti `std::atomic<int>`.

   Contoh:

   ```cpp
   #include <atomic>
   #include <thread>

   std::atomic<int> counter(0);

   void increment() {
       for (int i = 0; i < 1000; ++i) {
           counter++;
       }
   }

   int main() {
       std::thread t1(increment);
       std::thread t2(increment);

       t1.join();
       t2.join();

       std::cout << "Final counter value: " << counter << std::endl;
       return 0;
   }
   ```

4. **Read-Write Locks**:
   - **Read-Write locks** memungkinkan beberapa thread untuk membaca memori bersama secara bersamaan, tetapi membatasi akses tulis hanya untuk satu thread pada satu waktu. Ini berguna ketika ada lebih banyak pembacaan daripada penulisan di memori bersama.
   
   Dalam pthreads, ini bisa dilakukan dengan `pthread_rwlock_t`.

## D. Deadlock Prevention
Deadlocks dapat dicegah dengan beberapa strategi:
1. **Mengunci sumber daya dalam urutan yang konsisten**: Jika semua thread mengunci sumber daya dalam urutan yang sama, maka deadlock bisa dihindari.
2. **Menggunakan timeout pada penguncian**: Dengan menerapkan batas waktu untuk penguncian, thread bisa keluar dari kondisi deadlock jika kunci tidak bisa diperoleh dalam jangka waktu tertentu.
3. **Menggunakan algoritma deadlock detection**: Dalam beberapa kasus, sistem dapat mendeteksi kondisi deadlock dan mencoba menyelesaikannya dengan cara tertentu (misalnya, mematikan satu thread atau membebaskan sumber daya).

## Kesimpulan
Memori bersama adalah konsep penting dalam program paralel atau concurrent, tetapi harus dikelola dengan hati-hati untuk menghindari **race conditions** dan **deadlocks**. Penggunaan mekanisme seperti **mutex**, **semaphore**, **atomic operations**, dan **read-write locks** sangat penting dalam memastikan **thread safety** dan kinerja aplikasi yang andal dan efisien.

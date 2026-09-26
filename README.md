
## Janji
Saya Raditya Novandrian dengan NIM 2508283 mengerjakan TP-2 dalam mata kuliah DPBO untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan.

### 1. Desain Class (Encapsulation)
*   **Atribut Private & Protected:** Seluruh atribut dibuat `private` atau `protected` 
*   **Getter:** Akses data dilakukan melalui metode `public` berupa *getter*.

### 2. Pengelolaan Koleksi Data
*   **Python:** Menggunakan struktur data `list` dinamis.
*   **Java & C++:** Menggunakan *array* statis dengan batas alokasi manual (contoh: 50 elemen). 
*   **PHP:** Menggunakan `$_SESSION` yang berisi *array of objects* sebagai tempat penyimpanan sementara. Gambar disimpan secara fisik di folder lokal `uploads/`, sedangkan objek hanya menyimpan jalur aksesnya.

### 3. Antarmuka (Interface)
*   **Versi CLI (C++, Java, Python):** Program berjalan di terminal dengan sistem menu interaktif. Format tabel diatur agar menyesuaikan lebar string secara dinamis.
*   **Versi Web (PHP):** Antarmuka dibangun menggunakan elemen HTML.

## Penjelasan Atribut dan Methods

Program ini menggunakan konsep **Multilevel Inheritance** yang terdiri dari 3 hierarki *class*:

### 1. Class Media 
*   **Deskripsi:** Merepresentasikan entitas media secara umum.
*   **Atribut (`protected`):**
    *   `id` (String): Identifier unik media.
    *   `title` (String): Judul dari media.
    *   `language` (String): Bahasa utama yang digunakan.
*   **Methods:** `getId()`, `getTitle()`, `getLanguage()` berfungsi sebagai *getter* untuk mengakses atribut dasar.

### 2. Class VideoFormat 
*   **Deskripsi:** Mewarisi dari `Media`. Merepresentasikan spesifikasi teknis dari format media berbasis video.
*   **Atribut (`protected`):**
    *   `resolution` (String): Resolusi video (contoh: 1080p, 4K).
    *   `aspectRatio` (String): Rasio aspek tayangan (contoh: 16:9).
    *   `extension` (String): Ekstensi file video (contoh: .mp4, .mkv).
*   **Methods:** `getResolution()`, `getAspectRatio()`, `getExtension()` sebagai *getter* atribut format.

### 3. Class Movie 
*   **Deskripsi:** Mewarisi dari `VideoFormat`. Merepresentasikan entitas spesifik berupa film layar lebar.
*   **Atribut (`private`):**
    *   `genre` (String): Kategori genre film.
    *   `director` (String): Nama sutradara film.
    *   `duration` (String): Durasi film lengkap dengan satuannya (contoh: "148 min").
    *   `foto_produk` (String): *Path* direktori lokal untuk menyimpan gambar poster (Khusus PHP).
*   **Methods:** 
    *   `getGenre()`, `getDirector()`, `getDuration()`, `getFotoProduk()` sebagai *getter* atribut spesifik film.
    *   `getRowData()` / `printTableRow()`: Method pembantu pada versi CLI (C++, Java, Python) untuk mencetak baris dengan format panjang karakter dinamis.

## Penjelasan Alur Program

1. **Inisialisasi Data Awal (Hardcode):** Saat program pertama kali dijalankan, fungsi utama (atau inisialisasi `$_SESSION` pada PHP) secara otomatis membuat dan menyisipkan 5 objek `Movie` ke dalam *array* atau *list* dengan data yang sudah dihardcode.

2. **Menu Utama dan Interaksi:** Sistem menampilkan menu interaktif. Pada versi CLI, menu dijalankan menggunakan `while(true)` yang memberikan opsi: Tambah Data, Tampilkan Tabel, atau Keluar.

3. **Alur Tambah Data (Add Saja):** Jika dipilih, program akan meminta *input* kesembilan atribut secara berurutan. Pada antarmuka PHP, form memproses teks serta memindahkan file `foto_produk` terunggah ke folder `uploads/`. Setelah selesai, program melakukan instansiasi dan menempatkannya ke koleksi data.

4. **Alur Menampilkan Tabel Dinamis (Show):** Program mengeksekusi algoritma pencarian string terpanjang pada tiap kolom untuk menentukan `width` masing-masing kolom, kemudian mencetak seluruh data.


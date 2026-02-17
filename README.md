# Queens LinkedIn Solver
Tugas Kecil 1 IF2211 Strategi Algoritma — Semester II 2025/2026

## Deskripsi Program
Program ini menyelesaikan permainan **Queens** pada platform LinkedIn menggunakan algoritma **brute force**. Pemain harus menempatkan Queen pada papan berukuran N×N dengan aturan berikut:
- Setiap **baris** hanya boleh berisi satu Queen.
- Setiap **kolom** hanya boleh berisi satu Queen.
- Setiap **daerah warna** hanya boleh berisi satu Queen.
- Tidak ada dua Queen yang boleh **bersebelahan**, termasuk secara diagonal.

Program akan mencoba seluruh kemungkinan kombinasi posisi Queen (C(N², K) kombinasi, di mana K adalah jumlah warna unik), memeriksa validitasnya satu per satu, lalu menampilkan solusi beserta waktu eksekusi dan jumlah konfigurasi yang ditinjau.

---

## Requirement

| Komponen | Keterangan |
|----------|------------|
| Compiler | `g++` (GCC/G++ dengan dukungan C++11 atau lebih baru) |
| OS | Linux / macOS / Windows (dengan MinGW atau WSL) |
| Library | Standard C++ (`<iostream>`, `<fstream>`, `<vector>`, `<set>`, `<chrono>`) — tidak ada library eksternal |

Pastikan `g++` sudah terinstal dan dapat diakses dari terminal:
```bash
g++ --version
```

---

## Cara Kompilasi dan Menjalankan Program

```bash
# 1. Masuk ke folder src dan kompilasi
cd src
g++ -std=c++11 -o ../bin/queens main.cpp helperfunctions.cpp

# 2. Kembali ke root, lalu masuk ke folder bin
cd ..
cd bin

# 3. Jalankan program
./queens
```

### Alur Penggunaan

1. Program meminta nama file input. Masukkan nama file yang ada di folder `test/`, misalnya:
   ```
   Masukkan nama file : tc1.txt
   ```
2. Program akan menampilkan informasi papan: ukuran, jumlah warna, dan total kombinasi yang akan dicoba.
3. Tekan **Enter** untuk memulai proses pencarian.
4. Setelah selesai, program menampilkan:
   - Papan solusi (dengan `#` menandai posisi Queen)
   - Waktu pencarian (ms)
   - Jumlah konfigurasi yang ditinjau
5. Jika solusi ditemukan, Anda dapat memilih untuk menyimpannya ke file. File akan tersimpan di folder `test/` dengan nama `<namafile>_solution.txt`.
6. Program menawarkan opsi untuk mencoba file lain atau keluar.

---

## Author

**Fahd Muhammad Zahid**  
NIM: 13524078  
Kelas: K02  
IF2211 Strategi Algoritma — Institut Teknologi Bandung

GitHub: [https://github.com/fahdmz/Tucil1_13524078](https://github.com/fahdmz/Tucil1_13524078)

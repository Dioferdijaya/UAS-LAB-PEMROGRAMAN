#ifndef TOKO_H
#define TOKO_H

// Deklarasi struktur untuk barang
struct Barang {
    char nama[50];
    int harga;
    int jumlah;
};

// Deklarasi fungsi-fungsi yang digunakan dalam program utama
void tambahBarang(struct Barang barang[], int *jumlah_barang, int kapasitas_toko);
void kurangiBarang(struct Barang barang[], int *jumlah_barang);
void tampilkanBarang(struct Barang barang[], int jumlah_barang);
void pembayaran(struct Barang barang[], int jumlah_barang);
void beliBarang(struct Barang barang[], int *jumlah_barang);
void muatDataBarang(struct Barang barang[], int *jumlah_barang);


#endif

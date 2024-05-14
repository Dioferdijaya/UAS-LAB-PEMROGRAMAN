#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Barang {
    char nama[50];
    int harga;
    int jumlah;
};

// Fungsi untuk menampilkan daftar barang yang sudah dimasukkan ke dalam toko
void tampilkanBarang(struct Barang barang[], int jumlah_barang) {
    printf("\nDaftar Barang di Toko:\n");
    printf("------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Nama", "Harga", "Jumlah");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < jumlah_barang; i++) {
        printf("| %-20s | %-10d | %-10d |\n", barang[i].nama, barang[i].harga, barang[i].jumlah);
    }
    printf("------------------------------------------------------\n");
}

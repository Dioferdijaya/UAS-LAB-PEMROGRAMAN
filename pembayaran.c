#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Barang {
    char nama[50];
    int harga;
    int jumlah;
};


// Fungsi untuk melakukan pembayaran
void pembayaran(struct Barang barang[], int jumlah_barang) {
    int total_pembelian = 0;
    printf("\nBarang yang dibeli:\n");
    for (int i = 0; i < jumlah_barang; i++) {
        printf("%s (Harga: %d, Jumlah: %d)\n", barang[i].nama, barang[i].harga, barang[i].jumlah);
        total_pembelian += barang[i].harga * barang[i].jumlah;
    }
    printf("\nTotal pembelian: %d\n", total_pembelian);
}
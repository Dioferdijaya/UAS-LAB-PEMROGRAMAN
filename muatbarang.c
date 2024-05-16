#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Barang {
    char nama[50];
    int harga;
    int jumlah;
};


// Fungsi untuk memuat data barang dari file eksternal saat program dimulai
void muatDataBarang(struct Barang barang[], int *jumlah_barang) {
    FILE *file = fopen("barang.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %d %d", barang[*jumlah_barang].nama, &barang[*jumlah_barang].harga, &barang[*jumlah_barang].jumlah) == 3) {
            (*jumlah_barang)++;
        }
        fclose(file);
    } else {
        printf("Gagal membuka file barang.txt\n");
    }
}
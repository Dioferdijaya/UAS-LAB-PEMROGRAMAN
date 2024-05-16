#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Barang {
    char nama[50];
    int harga;
    int jumlah;
};

void beliBarang(struct Barang barang[], int *jumlah_barang) {
    char nama_barang[50];
    int jumlah_beli;
    int total_harga = 0;
    
    printf("\nMasukkan nama barang yang ingin dibeli: ");
    scanf("%s", nama_barang);
    
    // Mencari barang berdasarkan nama
    int i;
    for (i = 0; i < *jumlah_barang; i++) {
        if (strcmp(nama_barang, barang[i].nama) == 0) {
            printf("Masukkan jumlah barang yang ingin dibeli: ");
            scanf("%d", &jumlah_beli);
            
            if (jumlah_beli <= barang[i].jumlah) {
                barang[i].jumlah -= jumlah_beli;
                total_harga = jumlah_beli * barang[i].harga;
                printf("Barang berhasil dibeli! Total harga: %d\n", total_harga);
                
                // Menyimpan data barang yang telah diperbarui ke dalam file eksternal
                FILE *file = fopen("barang.txt", "w");
                if (file != NULL) {
                    for (int j = 0; j < *jumlah_barang; j++) {
                        fprintf(file, "%s %d %d\n", barang[j].nama, barang[j].harga, barang[j].jumlah);
                    }
                    fclose(file);
                } else {
                    printf("pembelian anda berhasil.\n");
                }
            } else {
                printf("Jumlah barang yang ingin dibeli melebihi stok yang tersedia.\n");
            }
            break;
        }
    }
    if (i == *jumlah_barang) {
        printf("Barang dengan nama tersebut tidak ditemukan.\n");
    }
}
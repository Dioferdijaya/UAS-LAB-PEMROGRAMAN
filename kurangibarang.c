#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Barang {
    char nama[50];
    int harga;
    int jumlah;
};
// Fungsi untuk mengurangi barang dari stok toko dan menyimpan perubahan ke dalam file
void kurangiBarang(struct Barang barang[], int *jumlah_barang) {
    if (*jumlah_barang > 0) {
        char nama_barang[50];
        printf("\nMasukkan nama barang yang ingin dikurangi stoknya: ");
        scanf("%s", nama_barang);
        
        // Mencari barang berdasarkan nama
        int i;
        for (i = 0; i < *jumlah_barang; i++) {
            if (strcmp(nama_barang, barang[i].nama) == 0) {
                int jumlah_kurangi;
                printf("Masukkan jumlah barang yang ingin dikurangi: ");
                scanf("%d", &jumlah_kurangi);
                
                if (jumlah_kurangi <= barang[i].jumlah) {
                    barang[i].jumlah -= jumlah_kurangi;
                    printf("Stok barang berhasil dikurangi!\n");

                    // Menyimpan data barang ke dalam file eksternal
                    FILE *file = fopen("barang.txt", "w");
                    if (file != NULL) {
                        for (int j = 0; j < *jumlah_barang; j++) {
                            fprintf(file, "%s %d %d\n", barang[j].nama, barang[j].harga, barang[j].jumlah);
                        }
                        fclose(file);
                    } else {
                        printf("Gagal menyimpan data barang ke dalam file.\n");
                    }

                    break;
                } else {
                    printf("Jumlah barang yang ingin dikurangi melebihi stok yang tersedia.\n");
                    break;
                }
            }
        }
        if (i == *jumlah_barang) {
            printf("Barang dengan nama tersebut tidak ditemukan.\n");
        }
    } else {
        printf("Tidak ada barang yang tersedia untuk dikurangi stoknya.\n");
    }
}
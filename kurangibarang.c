<<<<<<< HEAD
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
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Barang {
    char nama[50];
    int harga;
    int jumlah;
};

void kurangiBarang(struct Barang barang[], int jumlah_barang) {
    if (jumlah_barang > 0) {
        char nama_barang[50];
        printf("\nMasukkan nama barang yang ingin dikurangi stoknya: ");
        scanf("%s", nama_barang);

        int i;
        for (i = 0; i < jumlah_barang; i++) {
            if (strcmp(nama_barang, barang[i].nama) == 0) {
                int jumlah_kurangi;
                printf("Masukkan jumlah barang yang ingin dikurangi: ");
                scanf("%d", &jumlah_kurangi);

                if (jumlah_kurangi <= barang[i].jumlah) {
                    barang[i].jumlah -= jumlah_kurangi;
                    printf("Stok barang berhasil dikurangi!\n");

                    FILE *file = fopen("barang.txt", "w");
                    if (file != NULL) {
                        for (int j = 0; j < jumlah_barang; j++) {
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
        if (i == jumlah_barang) {
            printf("Barang dengan nama tersebut tidak ditemukan.\n");
        }
    } else {
        printf("Tidak ada barang yang tersedia untuk dikurangi stoknya.\n");
    }
}

int main() {
    struct Barang barang[100];
    int jumlah_barang = 0;

    
    FILE *file = fopen("barang.txt", "r");
    if (file == NULL) {
        file = fopen("barang.txt", "w");
        if (file == NULL) {
            printf("Gagal membuat file barang.txt.\n");
            return 1;
        } else {
            printf("File barang.txt berhasil dibuat.\n");
        }
        fclose(file);
    }

    
    file = fopen("barang.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %d %d", barang[jumlah_barang].nama, &barang[jumlah_barang].harga, &barang[jumlah_barang].jumlah) == 3) {
            jumlah_barang++;
        }
        fclose(file);
    }

    int choice;
    do {
        printf("\nMenu:\n1. Kurangi barang\n2. Keluar\nPilih opsi: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (jumlah_barang > 0) {
                    kurangiBarang(barang, jumlah_barang);
                } else {
                    printf("Tidak ada barang yang tersedia untuk dikurangi stoknya.\n");
                }
                break;
            case 2:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Opsi tidak valid.\n");
        }
    } while (choice != 2);

    return 0;
}
>>>>>>> 7fb5bc36a6a96948cf141d7a72f864ecf1172e8a

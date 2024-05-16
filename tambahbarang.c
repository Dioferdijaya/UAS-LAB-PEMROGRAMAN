#include <stdio.h>

struct Barang {
    char nama[50];
    int harga;
    int jumlah;
};
// Fungsi untuk menambahkan barang ke toko dan menyimpannya ke dalam file
void tambahBarang(struct Barang barang[], int *jumlah_barang, int kapasitas_toko) {
    // Memeriksa apakah masih ada ruang di array barang
    if (*jumlah_barang < kapasitas_toko) {
        printf("\nMasukkan detail barang:\n");
        printf("Nama: ");
        scanf("%s", barang[*jumlah_barang].nama);
        printf("Harga: ");
        scanf("%d", &barang[*jumlah_barang].harga);
        printf("Jumlah: ");
        scanf("%d", &barang[*jumlah_barang].jumlah);
        
        // Memperbarui total kapasitas toko
        kapasitas_toko -= barang[*jumlah_barang].jumlah;
        
        // Menyimpan data barang ke dalam file eksternal
        FILE *file = fopen("barang.txt", "a");
        if (file != NULL) {
            fprintf(file, "%s %d %d\n", barang[*jumlah_barang].nama, barang[*jumlah_barang].harga, barang[*jumlah_barang].jumlah);
            fclose(file);
        } else {
            printf("Gagal menyimpan data barang ke dalam file.\n");
        }
        
        (*jumlah_barang)++;
        printf("Barang berhasil ditambahkan!\n");
    } else {
        printf("Maaf, tidak dapat menambahkan barang lagi. Kapasitas toko penuh.\n");
    }
}
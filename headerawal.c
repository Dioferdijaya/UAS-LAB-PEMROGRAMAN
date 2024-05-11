#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Barang {
    char nama[50];
    int harga;
    int jumlah;
};


int main() {
    struct Barang barang[100];
    int jumlah_barang = 0;
    int kapasitas_toko = 100; // Kapasitas awal toko
    char opsi;
    int username,sandi;

    // Memuat data barang dari file eksternal saat program dimulai
    muatDataBarang(barang, &jumlah_barang);

    printf("silakan login ke akun admin 12 store\n");
    printf("silakan masukan username:");
    scanf("%d", &username);
    printf("masukan sandi : ");
    scanf("%d", &sandi);
    //username 1212 dan sandi 321
    if(username==1212 && sandi==321){
        
    do {
        printf("Selamat datang di toko 12 store\n");
      
        printf("Silahkan masukan pilihan anda\n");
        printf("1. Menambahkan barang ke toko 12 store\n");
        printf("2. Mengurangi barang pada toko 12 store\n");
        printf("3. Melihat seluruh daftar barang toko 12 store\n");
        printf("4. Melakukan transaksi pembayaran\n");
        printf("5. Keluar\n");
        printf("Pilih opsi: ");
        scanf(" %c", &opsi);

        switch (opsi) {
            case '1':
                tambahBarang(barang, &jumlah_barang, kapasitas_toko);
                break;

            case '2':
                kurangiBarang(barang, &jumlah_barang);
                break;

            case '3':
                tampilkanBarang(barang, jumlah_barang);
                break;

            case '4':
                pembayaran(barang, jumlah_barang);
                break;

            case '5':
                printf("Terima kasih. Program selesai.\n");
                break;

            default:
                printf("Opsi tidak valid. Silakan pilih opsi yang sesuai.\n");
        }
    } while (opsi != '5');
    
    }else{printf("sandi yang anda masukan salah atau username salah\n");

    
    }
    return 0;
}

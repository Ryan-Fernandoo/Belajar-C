
#include <stdio.h>

#define MAX_AKTIVITAS 50
#define LEBAR 60

int main() {
    char nama[100];
    char aktivitas[MAX_AKTIVITAS][100];
    char pilihan;
    int durasi[MAX_AKTIVITAS];
    int jumlahAktivitas, jumlahAwal, jumlahTambahan;
    int totalJam, sisaJam;
    int i, j, menu;

    do {
        totalJam = 0;
        jumlahAktivitas = 0;

        // Tampilan awal
        printf("\n============================================================\n");
        printf("                 REKAP KEGIATAN MAHASISWA\n");
        printf("============================================================\n");

        printf("Masukkan nama mahasiswa : ");
        scanf(" %99[^\n]", nama);

        printf("\nHalo, %s!\n", nama);
        printf("Mari catat kegiatanmu hari ini.\n");

        // Menentukan jumlah aktivitas awal
        do {
            printf("\nBerapa aktivitas yang ingin dicatat hari ini? ");

            if (scanf("%d", &jumlahAwal) != 1) {
                printf("Masukkan angka yang valid!\n");
                while (getchar() != '\n');
                jumlahAwal = 0;
            } else if (jumlahAwal < 1 ||
                       jumlahAwal > MAX_AKTIVITAS) {
                printf("Jumlah aktivitas harus 1 sampai %d.\n",
                       MAX_AKTIVITAS);
            }
        } while (jumlahAwal < 1 ||
                 jumlahAwal > MAX_AKTIVITAS);

        // Input aktivitas awal
        for (i = 0; i < jumlahAwal && totalJam < 24; i++) {
            int indeks = jumlahAktivitas;

            printf("\n--- Aktivitas ke-%d ---\n", i + 1);
            printf("Nama aktivitas          : ");
            scanf(" %99[^\n]", aktivitas[indeks]);

            while (1) {
                sisaJam = 24 - totalJam;
                printf("Durasi aktivitas (jam)  : ");

                if (scanf("%d", &durasi[indeks]) != 1) {
                    printf("Durasi harus berupa angka!\n");
                    while (getchar() != '\n');
                    continue;
                }

                if (durasi[indeks] <= 0) {
                    printf("Durasi harus lebih dari 0 jam.\n");
                } else if (durasi[indeks] > sisaJam) {
                    printf("Durasi melebihi sisa waktu %d jam!\n",
                           sisaJam);
                    printf("Silakan masukkan durasi yang benar.\n");
                } else {
                    totalJam += durasi[indeks];
                    jumlahAktivitas++;
                    break;
                }
            }
        }

        // Menanyakan aktivitas yang terlupakan
        while (totalJam < 24 &&
               jumlahAktivitas < MAX_AKTIVITAS) {

            sisaJam = 24 - totalJam;

            printf("\n------------------------------------------------------------\n");
            printf("Total waktu tercatat : %d jam\n", totalJam);
            printf("Sisa waktu           : %d jam\n", sisaJam);
            printf("------------------------------------------------------------\n");

            do {
                printf("Apakah ada aktivitas yang terlupakan? (Y/N): ");
                scanf(" %c", &pilihan);

                if (pilihan != 'Y' && pilihan != 'y' &&
                    pilihan != 'N' && pilihan != 'n') {
                    printf("Masukkan Y atau N.\n");
                }
            } while (pilihan != 'Y' && pilihan != 'y' &&
                     pilihan != 'N' && pilihan != 'n');

            if (pilihan == 'N' || pilihan == 'n') {
                break;
            }

            do {
                printf("Berapa aktivitas tambahan yang ingin dicatat? ");

                if (scanf("%d", &jumlahTambahan) != 1) {
                    printf("Masukkan angka yang valid!\n");
                    while (getchar() != '\n');
                    jumlahTambahan = 0;
                } else if (jumlahTambahan < 1 ||
                           jumlahTambahan >
                           MAX_AKTIVITAS - jumlahAktivitas) {
                    printf("Jumlah tambahan tidak valid.\n");
                }
            } while (jumlahTambahan < 1 ||
                     jumlahTambahan >
                     MAX_AKTIVITAS - jumlahAktivitas);

            for (j = 0; j < jumlahTambahan &&
                        totalJam < 24; j++) {

                int indeks = jumlahAktivitas;

                printf("\n--- Aktivitas tambahan ke-%d ---\n", j + 1);
                printf("Nama aktivitas          : ");
                scanf(" %99[^\n]", aktivitas[indeks]);

                while (1) {
                    sisaJam = 24 - totalJam;
                    printf("Durasi aktivitas (jam)  : ");

                    if (scanf("%d", &durasi[indeks]) != 1) {
                        printf("Durasi harus berupa angka!\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    if (durasi[indeks] <= 0) {
                        printf("Durasi harus lebih dari 0 jam.\n");
                    } else if (durasi[indeks] > sisaJam) {
                        printf("Durasi melebihi sisa waktu %d jam!\n",
                               sisaJam);
                        printf("Silakan masukkan durasi yang benar.\n");
                    } else {
                        totalJam += durasi[indeks];
                        jumlahAktivitas++;
                        printf("Aktivitas berhasil dicatat.\n");
                        break;
                    }
                }
            }
        }

        // Laporan akhir
        printf("\n============================================================\n");
        printf("                 LAPORAN KEGIATAN HARIAN\n");
        printf("============================================================\n");
        printf("Nama mahasiswa : %s\n\n", nama);

        for (i = 0; i < jumlahAktivitas; i++) {
            printf("%2d. %-30.30s : %2d jam\n",
                   i + 1, aktivitas[i], durasi[i]);
        }

        printf("------------------------------------------------------------\n");
        printf("%-35s : %2d\n",
               "Jumlah aktivitas", jumlahAktivitas);
        printf("%-35s : %2d jam\n",
               "Total waktu", totalJam);
        printf("%-35s : %2d jam\n",
               "Sisa waktu", 24 - totalJam);
        printf("============================================================\n");

        // Pilihan akhir
        printf("\nApa yang ingin kamu lakukan?\n");
        printf("1. Buat rekap baru\n");
        printf("2. Keluar dari program\n");

        do {
            printf("Pilihan kamu (1/2): ");

            if (scanf("%d", &menu) != 1) {
                printf("Masukkan angka 1 atau 2.\n");
                while (getchar() != '\n');
                menu = 0;
            } else if (menu != 1 && menu != 2) {
                printf("Pilihan tidak valid. Masukkan 1 atau 2.\n");
            }
        } while (menu != 1 && menu != 2);

    } while (menu == 1);

    printf("\nTerima kasih telah menggunakan program ini!\n");
    printf("Sampai jumpa!\n");

    return 0;
}

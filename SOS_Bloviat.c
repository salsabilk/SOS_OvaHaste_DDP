#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

typedef struct {
	char nama[100];
	int skor;
}Pemain;

void menu_awal(); 
/*Deskripsi Modul
Prosedure
Menampilkan UI Menu Awal 
I.S : Menu awal tidak tampil
F.S : Menu awal tampil di layar 
=========================================================================================*/

void skuy_main(); 
/*Deskripsi Modul
Prosedure
Modul bertujuan untuk memanggil modul-modul lain untuk menjalankan permainan SOS
I.S : Proses permainan SOS belum bisa dijalankan
F.S : Proses permainan SOS sudah bisa dijalankan
=========================================================================================*/

void display_tutor(); 
/*Deskripsi Modul
Prosedure
Menampilkan UI Tata Cara Bermain 
I.S : UI Tata Cara Bermain belum tampil
F.S : UI Tata Cara bermain tampil dan opsi untuk kembali terbaca
=========================================================================================*/

void display_udahan(); 
/*Deskripsi Modul
Prosedure
Menampilkan UI keluar jika pemain memilih untuk keluar permainan
I.S : Menu tampilan keluar belum tampil
F.S : Menu tampilan keluar tampil di layar
=========================================================================================*/

void display_arena(); 
/*Deskripsi Modul
Prosedure
Menampilkan UI memilih papan dimensi permainan 
I.S : Tampilan Menu Memilih Papan belum muncul ke layar
F.S : Tampilan Menu memilih papan tampil di layar 
=========================================================================================*/

void gambar_papan(int pilihan_papan); 
/*Deskripsi Modul
Prosedure
Membuat dan menampilkan papan permainan sesuai dengan papan dimensi yang dipilih
I.S : gambar papan permainan belum tampil pada layar
F.S : gambar papan permainan sudah tampil pada layar
=========================================================================================*/

void mengosongkan_papan(int pilihan_papan); 
/*Deskripsi Modul
Prosedure
Modul untuk mengisi papan dengan space (papan tidak emiliki isi)
I.S : Isi dari papan belum diketahui
F.S : Papan terisi dengan space
=========================================================================================*/

int cek_papan(int pilihan_papan); 
/*Deskripsi Modul
Function
Modul untuk mengecek apakah papan sudah terisi penuh atau belum
I.S : Bagian papan yang sudah terisi dan belum terisi belum diketahui
F.S : Bagian papan yang sudah terisi dan belum terisi diketahui 
=========================================================================================*/

void papan_skor(Pemain player1, Pemain player2); 
/*Deskripsi Modul
Prosedure
Menampilkan Skor player diatas papan permainan
I.S : Tampilan skor belum tampil kelayar
F.S : Tampilan skor sudah tampil kelayar
=========================================================================================*/

void gotoxy(int x, int y); 
/*Deskripsi Modul
Prosedure
Modul untuk meletakkan kursor di titik koordinat yang ditentukkan
I.S : Kursor belum diletakkan pada titik koordinat yang diinginkan
F.S : Kursor sudah diletakkan pada titik koordinat yang diinginkan
=========================================================================================*/

void loading(int bg, int fg, int panjang, int delay, int simbol[20]); 
/*Deskripsi Modul
Prosedure
Modul menampilkan tampilan awal sebelum pemain masuk ke menu awal
I.S : Tampilan loading belum dibuat
F.S : Tampilan loading sudah dibuat
=========================================================================================*/

void display_loading(); 
/*Deskripsi Modul
Prosedure
Modul untuk menampilkan UI Loading
I.S : Loading belum tampil ke layar
F.S : Loading sudah tampil ke layar
=========================================================================================*/

void display_menang(Pemain player); 
/*Deskripsi Modul
Prosedure
Menampilkan Tampilan Menang pada layar dan membaca opsi udahan
I.S : Tampilan Menang belum muncul ke layar
F.S : Tampilan Menang tampil di layar dan pilihan opsi udahan terbaca 
=========================================================================================*/

void display_draw(); 
/*Deskripsi Modul
Prosedure
Menampilkan Tampilan draw pada layar dan membaca opsi udahan
I.S : Tampilan Draw belum muncul ke layar
F.S : Tampilan draw tampil di layar dan pilihan opsi udahan terbaca
=========================================================================================*/

int waktu_awal();
/*Deskripsi Modul
Fungsi
//Modul untuk mendeklarasikan waktu awal penginputan.
I.S : Batas waktu bermain tiap pemain tidak dibatasi
F.S : Batas waktu bermain pemain dibatasi
=========================================================================================*/

int waktu_akhir();
/*Deskripsi Modul
Fungsi
//Modul untuk mendeklarasikan waktu akhir.
I.S : Batas waktu bermain tiap pemain tidak dibatasi
F.S : Batas waktu bermain pemain dibatasi
=========================================================================================*/

void display_nama(); 
/*Deskripsi Modul
Prosedure
//Modul untuk menampilkan tampilan menu Nama dan membaca nama player 1 dan player 2
I.S : Menu tampilan Nama belum tampil
F.S : Menu tampilan nama tampil dan nama kedua pemain sudah terbaca
=========================================================================================*/

int input_sos(Pemain player1, Pemain player2, int *giliran, int pilihan_papan); 
/*Deskripsi Modul
Function
Modul untuk menginputkan huruf S atau O ke papan
I.S : Huruf S atau O belum tampil pada baris dan kolom yang diinginkan pada papan permainan
F.S : Huruf S atau O sudah tampil pada baris dan kolom yang diinginkan pada papan permainan
=========================================================================================*/

int cari_sos(); 
/*Deskripsi Modul
Function
//Modul untuk mencari kalimat SOS dari sebuah papan permainan
I.S : Kalimat SOS yang dibentuk pada papan belum terdeteksi
F.S : Kalimat SOS yang dibentuk pada papan sudah terdeteksi
=========================================================================================*/

void memilih_opsi_menu();
/*Deskripsi Modul
Procedure
//Modul untuk memilih opsi dari menu utama untuk menuju fitur atau pilihan yang diinginkan 
I.S : Pilihan untuk menu berikutnya belum terpilih
F.S : Opsi terpilih dan melanjutkan sesuai pilihan yang diinginkan
=========================================================================================*/

void cek_opsi_udahan(int opsi_udahan);
/*Deskripsi Modul
Procedure
//Modul untuk memilih opsi udahan sesuai dengan hasil bacaan "opsi_udahan"
I.S : Pilihan untuk menuju opsi berikutnya belum disesuaikan
F.S : Program melanjutkan ke modul yang dipilih (keluar permainan atau kembali ke menu awal) 
=========================================================================================*/

int memilih_opsi_papan();
/*Deskripsi Modul
Function
//Modul untuk memilih papan sesuai dengan dimensi papan yang diinginkan
I.S : Dimensi papan belum terpilih
F.S : Dimensi papan sudah terpilih
=========================================================================================*/

int membandingkan_nilai(Pemain player1, Pemain player2);
/*Deskripsi Modul
Funtion
//Modul untuk membandingkan skor hasil permainan untuk menentukkan pemenang
I.S : Skor hasil permainan belum dibandingkan
F.S : Skor hasil permainan sudah dibandingkan dan hasil permainan dapat ditentukkan
=========================================================================================*/

/*VARIABEL GLOBAL*/ 
char papan[10][10];
int baris, kolom; // untuk menyimpan baris dan kolom yang dipilih pemain

int main(){
	display_loading();
	menu_awal();
	memilih_opsi_menu();
}

/*Deskripsi Modul
Prosedure
Menampilkan UI Loading
I.S : Loading belum tampil ke layar
F.S : Loading sudah tampil ke layar
=========================================================================================*/
void display_loading(){
	int bg, fg, delay, panjang;
	int simbol[20] = {2,3,4,5,6,14,16,22,35,36,62,64,158,174,175,176,177,178,219};
	system("cls");
   	system("color E0"); 
   	loading(20 - 1, 19 - 1, 30 , 1, simbol);
   	gotoxy(48,10);
}

/*Deskripsi Modul
Prosedure
Menampilkan UI keluar jika pemain memilih untuk keluar permainan dan membaca opsi keluar
I.S : Menu tampilan keluar belum tampil
F.S : Menu tampilan keluar tampil dan opsi udahan terbaca
=========================================================================================*/
void loading(int bg, int fg, int panjang, int delay, int simbol[20]){
 int k, l;
   for (k=0; k<=panjang; k+=2)
   {
      gotoxy(48,10);
      printf("\n\tLOADING\n\t");
      for (l=0; l<k; l++){
         printf("%c", simbol[fg]);
      }
      for (l=0; l<panjang-1; l++){
         printf("%c", simbol[bg]);
      Sleep(delay);
      }
   }
}

/*Deskripsi Modul
Prosedure
Menampilkan UI Menu Awal 
I.S : Menu awal tidak tampil
F.S : Menu awal tampil di layar
=========================================================================================*/
void menu_awal(){
	system("cls");
	system("color E0"); 
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t WELCOME TO                                   \n");
	printf("\t\t _____________________________________________________________________________________   \n");
	printf("\t\t\xb3SOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSS\xb3\n");
	printf("\t\t\xb3OSSOSSOSSOSSOSSOSSOSSOSSO          SSOSS         OSSOS          SSOSSOSSOSSOSSOSSOSSO\xb3\n");
	printf("\t\t\xb3SSOSSOSSOSSOSSOSSOSSOSSOS  SOSSOSSOSSOS  SOSSOSS  OSSO  SSOSSOSSOSSOSSOSSOSSOSSOSSOSS\xb3\n");
	printf("\t\t\xb3OSSOSSOSSOSSOSSOSSOSSOSSO  SSOSSOSSOSSO  SSOSSOS  SOSS  SOSSOSSOSSOSSOSSOSSOSSOSSOSSO\xb3\n");
	printf("\t\t\xb3SSOSSOSSOSSOSSOSSOSSOSSOS          SOSS  OSSOSSO  SSOS          SOSSOSSOSSOSSOSSOSSOS\xb3\n");
	printf("\t\t\xb3SOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOS  SOSS  OSSOSSO  SSOSSOSSOSSO  SSOSSOSSOSSOSSOSSOSSO\xb3\n");
	printf("\t\t\xb3SSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSO  SSOS  SOSSOSS  OSSOSSOSSOSS  OSSOSSOSSOSSOSSOSSOSS\xb3\n");
	printf("\t\t\xb3OSSOSSOSSOSSOSSOSSOSSOSSO          SSOSS         OSSOS          SOSSOSSOSSOSSOSSOSSOS\xb3\n");
    printf("\t\t\xb3SOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSS\xb3\n");
    printf("\t\t\xb3OSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSOSSO\xb3\n");
	printf("\t\t\xb3\t\t\t\t\t                                              \xb3\n");
    printf("\t\t\xb3    [1] SKUY MAIN                                                                    \xb3\n");
    printf("\t\t\xb3    [2] TUTOR?                                                                       \xb3\n");
    printf("\t\t\xb3    [3] UDAHAN                                                    CREATED BY BLOVIAT \xb3\n"); 
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
	printf("\t\t MAU APA? "); 	
}

/*Deskripsi Modul
Prosedure
Modul bertujuan untuk memanggil modul-modul lain untuk menjalankan permainan SOS
I.S : Proses permainan SOS belum bisa dijalankan
F.S : Proses permainan SOS sudah bisa dijalankan
=========================================================================================*/
void skuy_main(){
	int giliran = 1;
	int pilihan_papan;
	int opsi_udahan;
	int hasil;
	Pemain player1, player2;
	player1.skor = 0;
	player2.skor = 0;
	display_nama();
	scanf("%s", &player1.nama);
	printf("\n\t\t     Player 2 :");
	scanf("%s", &player2.nama);
	do{
	display_arena();
	pilihan_papan = memilih_opsi_papan();
	}	while (pilihan_papan == 0);
	mengosongkan_papan(pilihan_papan);
	while (!cek_papan(pilihan_papan)) {
		system("cls");
		baris = 0; kolom = 0;
		papan_skor(player1, player2);
		gambar_papan(pilihan_papan);
		
		int input = input_sos(player1, player2, &giliran, pilihan_papan);
		if (input){
			int point = cari_sos();
			if(!point) {
				printf("Yahhh Kamu belum dapat point :(");
				getch();
				giliran = (giliran + 1) %2;
			}
			else {
				if(giliran == 1){
					player1.skor++;
				} else {
					player2.skor++;
				}
				printf("Yeayy Kamu dapat 1 point. Yuk main lagi :)");
				getch();
			}
		}
	}
	hasil = membandingkan_nilai(player1, player2);
	switch(hasil){
		case 0:
		display_draw();
		scanf("%d", &opsi_udahan);
		cek_opsi_udahan(opsi_udahan);
		case 1:
		display_menang(player1);
		scanf("%d", &opsi_udahan);
		cek_opsi_udahan(opsi_udahan);
		case 2:
		display_menang(player2);
		scanf("%d", &opsi_udahan);
		cek_opsi_udahan(opsi_udahan);
		}
}

/*Deskripsi Modul
Prosedure
//Modul untuk menampilkan tampilan menu nama player 
I.S : Menu tampilan Nama belum tampil
F.S : Menu tampilan nama tampil 
=========================================================================================*/
void display_nama() {
	system("cls");
	system("color E0");
	printf("\n\n\n\n\n\n");
	printf("\t\t _____________________________________________________________________________________   \n");
	printf("\t\t\xb3\t\t\t                                                              \xb3\n");
	printf("\t\t\xb3\t\t\t                                                              \xb3\n");
	printf("\t\t\xb3\t      ****      **       ***       **            **       ***                 \xb3\n");
	printf("\t\t\xb3\t      ** **     **      ** **      ***          ***      ** **                \xb3\n");
	printf("\t\t\xb3\t      **  **    **     **   **     ** *        * **     **   **               \xb3\n");
	printf("\t\t\xb3\t      **   **   **    **     **    **  *      *  **    **     **              \xb3\n");
	printf("\t\t\xb3\t      **    **  **   ***********   **   *    *   **   ***********             \xb3\n");
	printf("\t\t\xb3\t      **     ** **  **         **  **    *  *    **  **         **            \xb3\n");
	printf("\t\t\xb3\t      **      **** **           ** **     **     ** **           **           \xb3\n");
    printf("\t\t\xb3                                                                                     \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
    printf("\t\t     Player 1 :");
}

/*Deskripsi Modul
Prosedure
Menampilkan UI Tata Cara Bermain 
I.S : UI Tata Cara Bermain belum tampil
F.S : UI Tata Cara bermain tampil 
=========================================================================================*/
void display_tutor(){
	system("cls");
	system("color E0");
	printf("\n\n\n\n\n\n");
	printf("\t\t _____________________________________________________________________________________   \n");
	printf("\t\t\xb3\t\t\t                                                              \xb3\n");
	printf("\t\t\xb3 Tata Cara dan Aturan Main :                                                         \xb3\n");
	printf("\t\t\xb3 1.Setelah masuk ke menu bermain, permainan akan dimulai dengan langkah player 1     \xb3\n");
	printf("\t\t\xb3   sebagai giliran pertama.                                                          \xb3\n");
	printf("\t\t\xb3 2.Player 1 akan diminta untuk memasukkan baris dan kolom untuk mengisi huruf 'S'    \xb3\n");
	printf("\t\t\xb3   atau 'O' pada papan.                                                              \xb3\n");
	printf("\t\t\xb3 3.Waktu yang diberikan untuk mengisi huruf 'S'/'O' untuk setiap player yaitu 15     \xb3\n");
	printf("\t\t\xb3   detik.                                                                            \xb3\n");
	printf("\t\t\xb3 4.Jika player melewati batas waktu yang telah ditentukan, maka giliran akan hangus  \xb3\n");
    printf("\t\t\xb3   hangus dan giliran bermain akan beralih ke pemain lawan.                          \xb3\n");
    printf("\t\t\xb3 5.Pemain akan mendapatkan satu poin jika berhasil merangkai kata 'SOS' baik secara  \xb3\n");
    printf("\t\t\xb3   vertikal, horizontal, maupun diagonal.                                            \xb3\n");
    printf("\t\t\xb3 6.Setelah papan terisi penuh, maka pemenang dapat ditentukan berdasarkan peraih     \xb3\n");
    printf("\t\t\xb3   skor tertinggi.                                                                   \xb3\n");
    printf("\t\t\xb3 7.Jika skor kedua player sama, maka permainan akan dinyatakan seri.                 \xb3\n");
    printf("\t\t\xb3\t\t\t                                                              \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
    printf("\t\t Pilih angka berapa saja dan enter untuk kembali ke menu awal : ");	
}

/*Deskripsi Modul
Prosedure
Menampilkan UI keluar 
I.S : Menu tampilan keluar belum tampil
F.S : Menu tampilan keluar tampil di layar
=========================================================================================*/
void display_udahan(){
	system("cls");
	system("color E0");
	printf("\n\n\n\n\n\n");
	printf("\t\t _____________________________________________________________________________________   \n");
	printf("\t\t\xb3\t\t\t\t\t                                              \xb3\n");
	printf("\t\t\xb3\t      *     *       ***       *    *  ***  ***      **   ********             \xb3\n");
	printf("\t\t\xb3\t       *   *       ** **      *   *    *   ** *     **          *             \xb3\n");
	printf("\t\t\xb3\t        * *       **   **     *  *     *   **  *    **          *             \xb3\n");
	printf("\t\t\xb3\t         *       **     **    ***      *   **   *   **     ******             \xb3\n");
	printf("\t\t\xb3\t         *      ***********   *  *     *   **    *  **     *                  \xb3\n");
	printf("\t\t\xb3\t         *     **         **  *   *    *   **     * **     *                  \xb3\n");
	printf("\t\t\xb3\t         *    **           ** *    *  ***  **      ***     @                  \xb3\n");
	printf("\t\t\xb3\t\t\t\t\t                                              \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n");
    printf("\t\t\xb3\t\t\t\t\t                                              \xb3\n");
    printf("\t\t\xb3    [1] GA JADI DEH                                                                  \xb3\n");
    printf("\t\t\xb3    [Angka berapa saja selain 1] YAKIN                                               \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
  	printf("\t\t MAU APA? : ");
}

/*Deskripsi Modul
Prosedure
Menampilkan UI memilih papan dimensi permainan
I.S : Tampilan Menu Memilih Papan belum muncul ke layar
F.S : Tampilan Menu memilih papan tampil di layar
=========================================================================================*/
void display_arena(){
	system("cls");
	system("color E0");
	printf("\n\n\n\n\n\n");
	printf("\t\t _____________________________________________________________________________________   \n");
	printf("\t\t\xb3\t\t\t\t\t                                              \xb3\n");
	printf("\t\t\xb3\t          ***       ********  ********  ***      **       ***                 \xb3\n");
	printf("\t\t\xb3\t         ** **      *      *  *         ** *     **      ** **                \xb3\n");
	printf("\t\t\xb3\t        **   **     *      *  *         **  *    **     **   **               \xb3\n");
	printf("\t\t\xb3\t       **     **    ********  ********  **   *   **    **     **              \xb3\n");
	printf("\t\t\xb3\t      ***********   *    *    *         **    *  **   ***********             \xb3\n");
	printf("\t\t\xb3\t     **         **  *     *   *         **     * **  **         **            \xb3\n");
	printf("\t\t\xb3\t    **           ** *      *  ********  **      *** **           **           \xb3\n");
    printf("\t\t\xb3                                                                                     \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n");
	printf("\t\t\xb3\t\t\t\t\t                                              \xb3\n");
    printf("\t\t\xb3    [1] 3 x 3                                                                        \xb3\n");
    printf("\t\t\xb3    [2] 5 x 5                                                                        \xb3\n");
    printf("\t\t\xb3    [3] 7 x 7                                                                        \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
    printf("\t\t Mau Pilih Yang Mana Nih? : "); 
    
}

/*Deskripsi Modul
Prosedure
Modul untuk mengisi papan dengan space (papan tidak memiliki isi)
I.S : Isi dari papan belum diketahui
F.S : Papan terisi dengan space
=========================================================================================*/
void mengosongkan_papan(int pilihan_papan){
	for (int i = 0; i < pilihan_papan; i++){
		for (int j = 0; j < pilihan_papan; j++){
			papan[i][j] = ' ';
		}
	}
}

/*Deskripsi Modul
Function
Modul untuk mengecek apakah papan sudah terisi penuh atau belum
I.S : Bagian papan yang sudah terisi dan belum terisi belum diketahui
F.S : Bagian papan yang sudah terisi dan belum terisi diketahui 
=========================================================================================*/
int cek_papan(int pilihan_papan){
	for( baris = 0; baris < pilihan_papan; baris++){
		for( kolom = 0; kolom < pilihan_papan; kolom++ ){
			if (papan[baris][kolom] == ' '){
				return 0;
			}
		}
	}
	return 1;
}

/*Deskripsi Modul
Prosedure
Modul untuk meletakkan kursor di titik koordinat yang ditentukkan
I.S : Kursor belum diletakkan pada titik koordinat yang diinginkan
F.S : Kursor sudah diletakkan pada titik koordinat yang diinginkan
=========================================================================================*/
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/*Deskripsi Modul
Fungsi
//Modul untuk menampilkan tampilan menu Nama dan membaca nama player 1 dan player 2
I.S : Batas waktu bermain tiap pemain tidak dibatasi
F.S : Batas waktu bermain pemain dibatasi
=========================================================================================*/
int waktu_awal(){
	clock_t time;
	time = clock();
	return time;
}

/*Deskripsi Modul
Fungsi
//Modul untuk menampilkan tampilan menu Nama dan membaca nama player 1 dan player 2
I.S : Batas waktu bermain tiap pemain tidak dibatasi
F.S : Batas waktu bermain pemain dibatasi
=========================================================================================*/
int waktu_akhir(){
	clock_t time;
	time = clock();
	return time;
}

/*Deskripsi Modul
Prosedure
Menampilkan Skor player diatas papan permainan
I.S : Tampilan skor belum tampil kelayar
F.S : Tampilan skor sudah tampil kelayar
=========================================================================================*/
void papan_skor(Pemain player1, Pemain player2) {
	gotoxy(0,0);
	gotoxy(13,1);  printf("VS");
	gotoxy(1,1);   printf("%s\n", player1.nama);
	gotoxy(20,1);  printf("%s\n", player2.nama);
	gotoxy(1,2);   printf("%d\n", player1.skor);
	gotoxy(20,2);  printf("%d\n", player2.skor);
}

/*Deskripsi Modul
Prosedure
Membuat dan menampilkan papan permainan sesuai dengan papan dimensi yang dipilih
I.S : gambar papan permainan belum tampil pada layar
F.S : gambar papan permainan sudah tampil pada layar
=========================================================================================*/
void gambar_papan(int pilihan_papan){
	system ("color E0");
	int i, j;
	printf("\n   ");
	for (i = 0; i <= pilihan_papan; i++) {
		printf("\n   ");
		for (j = 0; j <= pilihan_papan; j++) {
			if (!i && !j) printf("      ");
			else if (!i && j == pilihan_papan) printf("   %2d  ", j);
			else if (!i) printf("  %2d  ", j);
			else if (!j) printf("  %2d  \xb3", i);
			else if (baris && kolom && baris == i && kolom == j) printf("     \xb3");
			else printf("  %c  \xb3", papan[i - 1][j - 1]);
		}
		printf("   \n   ");
		for (j = 0; j <= pilihan_papan; j++) {
			if (i == pilihan_papan && !j) printf("      ");
			else if (i == pilihan_papan) printf("\xc1\xcd\xcd\xcd\xcd\xcd");
			else if (!j) printf("      ");
			else printf("\xc5\xcd\xcd\xcd\xcd\xcd");
			if (i == pilihan_papan && j == pilihan_papan) printf("\xd9");
			else if (j == pilihan_papan) printf("\xb4");
		}
	}
	printf("\n");
}

/*Deskripsi Modul
Function
Modul untuk menginputkan huruf S atau O ke papan
I.S : Huruf S atau O belum tampil pada baris dan kolom yang diinginkan pada papan permainan
F.S : Huruf S atau O sudah tampil pada baris dan kolom yang diinginkan pada papan permainan
=========================================================================================*/
int input_sos(Pemain player1, Pemain player2, int *giliran, int pilihan_papan){
	int waktu;
	double waktuIsi;
	waktu = waktu_awal();
	if(*giliran == 1){
					printf("\n\n Giliran : %s\n", player1.nama);
				}else{
					printf("\n\n Giliran : %s\n", player2.nama);
	}
	do{
		printf("\n\n\xdb Baris : ");
		scanf("%d", &baris);
		printf("\n\n\xdb Kolom : ");
		scanf("%d", &kolom);
		printf("\n INPUT POSISI TIDAK VALID! \n \xaf TEKAN ENTER UNTUK MELANJUTKAN!");
	}while(!(baris > 0 && baris <= pilihan_papan && kolom > 0 && kolom <= pilihan_papan));
	
	system("cls");
	switch (papan[baris - 1][kolom -1]) {
		case 'S':
		case 'O': printf("\xaf\xaf POSISI SUDAH DIISI !!!\n\xaf\xaf TEKAN ENTER UNTUK MELANJUTKAN!");
			getch();
			return 0;
			default:
			system("cls");
			papan_skor(player1, player2);
			gambar_papan(pilihan_papan);
			waktu = waktu_akhir()-waktu;
			waktuIsi = ((double)waktu)/CLOCKS_PER_SEC;
			if (waktuIsi<=15){
				if(*giliran == 1){
					printf("\n\n Giliran : %s\n\xdb Baris : %d\n\xdb Kolom : %d\n\xaf\xaf S/O? ", player1, baris, kolom);
				}else{
					printf("\n\n Giliran : %s\n\xdb Baris : %d\n\xdb Kolom : %d\n\xaf\xaf S/O? ", player2, baris, kolom);
				}
				char ch;
				scanf(" %c", &ch);
				switch (ch) {
					case 's':
					case 'S': papan[baris - 1][kolom - 1] = 'S'; return 1;
					case 'o':
					case 'O': papan[baris - 1][kolom - 1] = 'O'; return 1;
				}
				printf("\xaf\xaf Invalid letter!!\n\xaf\xaf Press any key to continue!!");
				getch();
				return 0;
			}
			else{
				papan_skor(player1, player2);
				gambar_papan(pilihan_papan);
				printf("\n Waktu Habis, Giliran Anda Hangus!");
				*giliran = (*giliran + 1) % 2;
				getch();
				return 0;
			}
	}
}

/*Deskripsi Modul
Function
//Modul untuk mencari kalimat SOS dari sebuah papan permainan
I.S : Kalimat SOS yang dibentuk pada papan belum terdeteksi
F.S : Kalimat SOS yang dibentuk pada papan sudah terdeteksi
=========================================================================================*/
int cari_sos(){
	if (papan[baris - 1][kolom - 1] == 'S') {
		if (papan[baris - 3][kolom - 3] == 'S' && papan[baris - 2][kolom - 2] == 'O'){return 1;} //diagonal kiri atas
		if (papan[baris - 3][kolom - 1] == 'S' && papan[baris - 2][kolom - 1] == 'O'){return 1;} //vertikal atas
		if (papan[baris - 3][kolom + 1] == 'S' && papan[baris - 2][kolom] == 'O'){return 1;} //diagonal kanan atas
		if (papan[baris - 1][kolom - 3] == 'S' && papan[baris - 1][kolom - 2] == 'O'){return 1;} //horizontal kiri
		if (papan[baris - 1][kolom + 1] == 'S' && papan[baris - 1][kolom] == 'O'){return 1;} //horizontal kanan
		if (papan[baris + 1][kolom - 3] == 'S' && papan[baris][kolom - 2] == 'O'){return 1;} //diagonal kiri bawah
		if (papan[baris + 1][kolom - 1] == 'S' && papan[baris][kolom - 1] == 'O'){return 1;} //vertikal bawah
		if (papan[baris + 1][kolom + 1] == 'S' && papan[baris][kolom] == 'O'){return 1;} //diagonal kanan bawah
	}
	else {
		if (papan[baris - 2][kolom - 2] == 'S' && papan[baris][kolom] == 'S') return 1; //diagonal kiri(\)
		if (papan[baris - 2][kolom - 1] == 'S' && papan[baris][kolom - 1] == 'S') return 1; //vertikal
		if (papan[baris - 2][kolom] == 'S' && papan[baris][kolom - 2] == 'S') return 1; //diagonal kanan (/)
		if (papan[baris - 1][kolom - 2] == 'S' && papan[baris - 1][kolom] == 'S') return 1; //horizontal
	}
	return 0;
}

/*Deskripsi Modul
Prosedure
Menampilkan Tampilan Menang pada layar 
I.S : Tampilan Menang belum muncul ke layar
F.S : Tampilan Menang tampil di layar 
=========================================================================================*/
void display_menang(Pemain player)
{	system("cls");
	system("color E0");
	printf("\n\n\n\n\n\n");
	printf("\t\t ______________________________________________________________________________________   \n");
	printf("\t\t\xb3 WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER \xb3\n");
	printf("\t\t\xb3 WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER \xb3\n");
	printf("\t\t\xb3 WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER \xb3\n");
	printf("\t\t\xb3 WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER \xb3\n");
	printf("\t\t\xb3 WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER \xb3\n");
	printf("\t\t\xb3 WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER \xb3\n");
	printf("\t\t\xb3 WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER \xb3\n");
	printf("\t\t\xb3 WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER \xb3\n");
	printf("\t\t\xb3 WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER \xb3\n");
	printf("\t\t\xb3 WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER WINNER \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n");
    printf("\t\t\t\t Selamat Kepada %s Telah Memenangkan Permainan\n", &player); 
    printf("\t\t _____________________________________________________________________________________   \n");
	printf("\t\t\xb3\t\t\t\t\t                                              \xb3\n");
    printf("\t\t\xb3    [1] MAIN LAGI                                                                    \xb3\n");
    printf("\t\t\xb3    [Angka berapa saja selain 1] YAKIN                                               \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
printf("\t\t MAU APA? : ") ;
}

/*Deskripsi Modul
Prosedure
Menampilkan Tampilan draw pada layar
I.S : Tampilan Draw belum muncul ke layar
F.S : Tampilan draw tampil di layar
=========================================================================================*/
void display_draw()
{	system("cls");
	system("color E0");
	printf("\n\n\n\n\n\n");
	printf("\t\t _____________________________________________________________________________________   \n");
	printf("\t\t\xb3\t\t                                                                      \xb3\n");
	printf("\t\t\xb3\t     *******    ********        ***       **               **  ***            \xb3\n");
	printf("\t\t\xb3\t     *     **   *      *       ** **      **               **  ***            \xb3\n");
	printf("\t\t\xb3\t     *      **  *      *      **   **      **             **   ***            \xb3\n");
	printf("\t\t\xb3\t     *      **  ********     **     **     **     ***     **   ***            \xb3\n");
	printf("\t\t\xb3\t     *      **  *    *      ***********     **   ** **   **    ***            \xb3\n");
	printf("\t\t\xb3\t     *     **   *     *    **         **     ** **   ** **     ***            \xb3\n");
	printf("\t\t\xb3\t     *******    *      *  **           **     ***     ***       @             \xb3\n");
	printf("\t\t\xb3\t\t\t\t   PERMAINAN SERI                                     \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n");
    printf("\t\t\xb3\t\t\t\t\t                                              \xb3\n");
    printf("\t\t\xb3    [1] MAIN LAGI                                                                    \xb3\n");
    printf("\t\t\xb3    [Angka berapa saja selain 1] YAKIN                                               \xb3\n");
    printf("\t\t\xb3_____________________________________________________________________________________\xb3\n\n");
  	printf("\t\t MAU APA? : "); 
}

/*Deskripsi Modul
Procedure
Modul untuk memilih opsi dari menu utama untuk menuju fitur atau pilihan yang diinginkan 
I.S : Pilihan untuk menu berikutnya belum terpilih
F.S : Opsi terpilih dan melanjutkan sesuai pilihan yang diinginkan
=========================================================================================*/
void memilih_opsi_menu()
{   int opsi;
	int opsi_tutor;
	int opsi_udahan;
	do{
		scanf(" %d",&opsi); 
		switch(opsi){
   			case 1:
   				skuy_main();
   				break;
        	case 2:
   				display_tutor();
				opsi = 0;   
				scanf("%d", &opsi_tutor);				
   				switch(opsi_tutor){
			default:
	      		menu_awal();
	      		memilih_opsi_menu();
	     			break;
				}
   				break;
			case 3:
   				display_udahan();
   				scanf("%d", &opsi_udahan);
   				switch(opsi_udahan){
   					case 1:
   						menu_awal();
   						memilih_opsi_menu();
   						break;
   					default:
   						exit(0);
				   }	
   				break;	
	   		 default:
   			 	printf("\t\t\t\t PILIHANMU TIDAK TEPAT, Klik Enter Untuk Mengulang!");
      		 	getch();
      		 	menu_awal();
      		 	memilih_opsi_menu();
			}
	} while (opsi != 1 || opsi != 2 || opsi != 3);
	exit(0);
}

/*Deskripsi Modul
Function
//Modul untuk memilih papan sesuai dengan dimensi papan yang diinginkan
I.S : Dimensi papan belum terpilih
F.S : Dimensi papan sudah terpilih
=========================================================================================*/
int memilih_opsi_papan()
{	int ukuran; 
	scanf("%d",&ukuran);
	switch(ukuran){
		case 1:
			return 3;
		case 2:
			return 5;
		case 3:
			return 7;
		 default:	
		 	printf("\t\t\t\t PILIHANMU TIDAK TEPAT, Klik Enter Untuk Mengulang!");
		 	getch();
		 	return 0;
      	 	break;
		}
}

/*Deskripsi Modul
Funtion
//Modul untuk membandingkan skor hasil permainan untuk menentukkan pemenang
I.S : Skor hasil permainan belum dibandingkan
F.S : Skor hasil permainan sudah dibandingkan dan hasil permainan dapat ditentukkan
=========================================================================================*/
int membandingkan_nilai(Pemain player1, Pemain player2)
{ 	system("cls");
	system("color E0");
	if(player1.skor == player2.skor ){
		return 0;
	} else if (player1.skor > player2.skor){
		return 1;
	} else if (player1.skor < player2.skor){
		return 2;
  	}
}

/*Deskripsi Modul
Procedure
//Modul untuk memilih opsi udahan sesuai dengan hasil bacaan "opsi_udahan"
I.S : Pilihan untuk menuju opsi berikutnya belum disesuaikan
F.S : Program melanjutkan ke modul yang dipilih (keluar permainan atau kembali ke menu awal) 
=========================================================================================*/
void cek_opsi_udahan(int opsi_udahan)
{   switch(opsi_udahan){
   		case 1:	
  		main();
   			break;
  		default:
  		exit(0);
   			break;
	}
}







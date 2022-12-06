#include <stdio.h>
#include <string.h>

void pilihan();

struct mahasiswa{
	char nama[100];
	int nilai;
};

void header(){
	system("cls");
    printf("\t\t\t===========================================================\n");
    printf("\t\t\t|               Program Mengurutkan Nilai                 |\n");
    printf("\t\t\t|                        Kelompok 07                      |\n");
    printf("\t\t\t===========================================================\n");
}

void cover(){
    printf("\t\t\t===========================================================\n");
    printf("\t\t\t|               Program Mengurutkan Nilai                 |\n");
    printf("\t\t\t|                        Kelompok 07                      |\n");
    printf("\t\t\t|_________________________________________________________|\n");
    printf("\t\t\t|Anggota kelompok :                    NIM :              |\n");
    printf("\t\t\t|=> Putu Gede Prayatna Dharma Parijata   => 2205551068    |\n");
    printf("\t\t\t|=> I Gde Teja Baskara                   => 2205551065    |\n");
    printf("\t\t\t|=> I Nyoman Michael Suputra             => 2205551056    |\n");
    printf("\t\t\t|=> Adriant Satrio Putra                 => 2205551021    |\n");
    printf("\t\t\t|=> I Gede Satya Ariya Putra Sangjaya    => 2205551040    |\n");
    printf("\t\t\t|=> Made Abdy Arysada                    => 2205551043    |\n");
    printf("\t\t\t===========================================================\n");
}

void keluar(){
    system("cls||clear");
    system("exit");
}


void pilihan_ulang(){
    char huruf_ulang[1];

    printf("\nLakukan lagi? ya/keluar(Y/E) : ");
    scanf("%s", &huruf_ulang);
    fflush(stdin);

    if((strcmp(huruf_ulang, "Y") != 0) && (strcmp(huruf_ulang, "y") != 0) && (strcmp(huruf_ulang, "E") != 0) && (strcmp(huruf_ulang, "e") != 0)){
		printf("\nPilihan Tidak ada! Pilih Menu Yang Benar!");
        return pilihan_ulang();
    }else if((strcmp(huruf_ulang, "Y") == 0)){
        system("cls||clear");
		pilihan();
    }else if((strcmp(huruf_ulang, "y") == 0)){
        system("cls||clear");
		pilihan();
    }else{
        keluar();
    }
}

int sorting(){
    char input_sort[1];
	int hasil = 0;

    printf("\nApakah anda ingin melakukan mengurutkan nilai ? (Y/N) : ");
    scanf("%s", &input_sort);
    fflush(stdin);

    if((strcmp(input_sort, "Y") != 0) && (strcmp(input_sort, "y") != 0) && (strcmp(input_sort, "N") != 0) && (strcmp(input_sort, "n") != 0)){
		printf("\nPilihan Tidak ada! Pilih Menu Yang Benar!");
        return sorting();
    }else if((strcmp(input_sort, "Y") == 0)){
		hasil = 1;
    }else if((strcmp(input_sort, "y") == 0)){
		hasil = 1;
    }else{
		hasil = 0;        
    }
	return hasil;
}

int readAsistenin(struct mahasiswa siswa[]){
	int a = 0;
	FILE *in = fopen("asistenin.txt","r");
	if(!in){
		printf("File asistenin.txt tidak ditemukan\n");
		printf("Silahkan buat file asistenin.txt terlebih dahulu\n");
	}else{
        printf("Nilai Mahasiswa : \n");
		while(!feof(in)){
			printf("    ");
		    fscanf(in,"%[^\n]\n", &siswa[a].nama);
		    fscanf(in,"%d\n", &siswa[a].nilai);
            fflush(stdin);
		    printf("%d. %s : %d\n", a+1, siswa[a].nama, siswa[a].nilai);
		    a++;
		}
	}
	fclose(in);

	return a;
}

void sortData(struct mahasiswa siswa[], int a){
	struct mahasiswa temp;
	int i, j;
	for(i = 0; i < a - 1; i++){
		for(j = 0; j < a - 1; j++){
			if(siswa[j+1].nilai > siswa[j].nilai){
				temp = siswa[j+1];
				siswa[j+1] = siswa[j];
    			siswa[j] = temp;
			}
    	}
	}
}

void output(struct mahasiswa siswa[], int a){
	int i;
	FILE *out = fopen("asistenout.txt","w");
	fprintf(out, "Nilai Algoritma dan Pemrograman :\n");
	for(i = 0; i < a; i++){
		fprintf(out,"%d. %s %d\n", i+1, siswa[i].nama, siswa[i].nilai);
	}
	fclose(out);
}

void pilihan(){
	struct mahasiswa siswa[50];
	struct mahasiswa temp;
	int a = 0;
	int i, j, k;
	int sort;
	char tempNama[100];
	int tempNilai;

    printf("\t\t\t===========================================================\n");
    printf("\t\t\t|               Program Mengurutkan Nilai                 |\n");
    printf("\t\t\t|                        Kelompok 07                      |\n");
    printf("\t\t\t===========================================================\n");
    printf("Mengecek file asistenin.txt...");
    sleep(1);
	printf("\n\n");

	a = readAsistenin(siswa);

	printf("\n");
	sort = sorting();

	if(sort == 1){
		sortData(siswa, a);
		printf("\n");
		output(siswa, a);

		printf("Data berhasil dimasukan ke dalam asistenout.txt\n");
	}
	printf(" ============================================================\n");
	pilihan_ulang();

}

int main(){
	header();
	system("pause"); 
	system("cls||clear");

	cover();
	system("pause");
	system("cls||clear");
    
    pilihan();

    return 0;
}

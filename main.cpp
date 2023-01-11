#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
///Tugas Pra UAS
///Mengebangkan game lagi tambah 4hal fitur terbaru 4(contoh: Musuh g bisa makan. Setelah makan Kecepatannya meningkat...Makan Tubuh H membesar


                                                      ///1. H random posisi ketika start game
                                                      ///2. Memiliki Fitur Nyawa
                                                      ///3. Ketika tidak makan dalam waktu 10s makan score akan berkurang

using namespace std;

struct node{
    int value;
    struct node*next;
};

struct node *head = NULL;
struct node *tail = NULL;

bool isEmpty(){
    return head == NULL;
}

void gotoxy(int x, int y)
{
    COORD koordinat;
    koordinat.X=x;
    koordinat.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);
}

void tunda(){
    float a=1;
    do
    {
        a=a+0.1;
    } while (a<1000000);
}

void arena()
{
    for (int x=2;x<70;x++)
    {
        for (int y=1;y<24;y++)
        {
            gotoxy(x,y);
            cout<<" ";
        }
    }
}

void garis()
{
    gotoxy(1,1);printf("%c",218);
    gotoxy(1,24);printf("%c",192);
    gotoxy(21,2);printf("Panah = Bergerak ; ESC = Keluar");
    for(int x=2;x<70;x++)
    {
        gotoxy(x,1);printf("%c",196);
        gotoxy(x,3);printf("%c",196);
        gotoxy(x,24);printf("%c",196);
    }
    gotoxy(70,1);printf("%c",191);
    gotoxy(70,24);printf("%c",217);

    for (int y=2;y<24;y++)
    {
        gotoxy(1,y);printf("%c",179);
        gotoxy(70,y);printf("%c",179);
    }
}

int acakX(){
    int x=rand();//diisi nilai random
    if(x<2)
        return(x%69)+2;
    else
        return(x%69);
}

int acakY(){
    int y=rand();
    if((y%23)<5)
        return (y%23)+5;
    else
        return (y%23);
}

int HacakX(){
    int x=rand();//diisi nilai random
    if(x<2)
        return(x%69)+2;
    else
        return(x%69);
}

int HacakY(){
    int y=rand();
    if((y%23)<5)
        return (y%23)+5;
    else
        return (y%23);
}

void hapusReset()
{
         node *key=head; // kita deklarasikan terlebih dahulu variabel key dengan tipe data sruct node yang dimana isi dari key sama denga head
         node *previous=NULL; //kita deklarasikan kembali varibel previus dengan tipe data struck yang dimana memiliki value sama dengan null

         if(isEmpty())
         {


         }
         else
         {
                while(key!=NULL) //ulangi ketika key tidak sama dengan null
                {
                    previous=key; // disini kita isi variabel previous dengan copas data key yang memiliki data head
                    previous=previous->next; // setelah itu kita pindahkan variabel previus ke pendatang 1 sehingga previus berpindah urutan 2
                    head=previous; // setelah berpindah pendatang 1 itu kita jadikan head
                    free(key); // kemudian kita panggil fungsi c++ untuk menghapus key

                    break; // kita break agar langsung berhenti tidak melooping lag

                 }
                    previous=key; // kita samakan variabel baru previous dengan key
                    key=key->next; // kita pindahkan variabel key ke pendatang baru
         }
}

int main()
{
    reset :
    char key;

    int x_Hero;
    int y_Hero;
    int xHeroPrev=x_Hero;
    int yHeroPrev=y_Hero;

    float xEnemy=60;
    float yEnemy=23;
    float xEnemyPrev=xEnemy;
    float yEnemyPrev=yEnemy;

    // langkah enemy
    float lEnemy = 0.1;

    int score=0;
    int xKantong=69;
    float cariDetik=0;

    int tembok_kanan=69;
    int tembok_kiri=2;
    int tembok_atas=4;
    int tembok_bawah=23;

    int arah = 0;
    int delay=0;

    int nyawaPlayer;

    arena();
    garis();

    int fruitPin=0;

    ///RANDOM HERO
    srand(time(NULL));
    x_Hero = rand()%40+ 20;
    y_Hero = rand()%10+ 9;

    gotoxy(x_Hero, y_Hero); cout << "H";

    ///RANDOM FRUIT
    srand(time(0));
    int xFruit=acakX();
    int yFruit=acakY();

    gotoxy(xFruit,yFruit);cout << "*";


    ///DETEKSI TOMBOL PANAH
    if(kbhit()){
        key = getch();
    }

    do
    {
        ///CEK DETIK
        cariDetik+=0.5;
        if((int)cariDetik%10==0)
        {
            gotoxy(3,4);printf("            ");
            ///CAridetik
            gotoxy(3,4);printf("Detik: %.0f", cariDetik/10);
        }
        if (cariDetik/10 == 10)
        {
            cariDetik=0;
            if (xKantong < 69)
            {
                xKantong++;
                score--;
                gotoxy(xKantong,2);printf(" ");

            }else if(xKantong = 70){
                score = 0;
                gotoxy(xKantong,2);printf("            "); ///Nimpa garis karena udah sama 70
            }
            //gotoxy(3,2);printf("Score : %d", score);
        }

/*
        // Membuat buah tidak hilang ketika musuh mengenai buah
        if((int)xEnemy == xFruit  && (int)yEnemy == yFruit){
    		fruitPin = 1;
    		gotoxy(xEnemyPrev, yEnemyPrev);
    		printf(" ");
		}
		else if(fruitPin == 1){
			fruitPin = 0;
			gotoxy(xEnemyPrev, yEnemyPrev);
			printf("*");
		}
		else{
			gotoxy(xEnemyPrev, yEnemyPrev);
    		printf(" ");
		}
		*/
        /// Menghilangkan jejak Hero dan Enemy
        gotoxy(xHeroPrev,yHeroPrev);printf(" ");
        gotoxy(xEnemyPrev,yEnemyPrev);printf("      ");

        //informasi Posisi
        //gotoxy(1,1);printf("Posisi Hero : [%d,%d]",x_Hero,y_Hero);
        //gotoxy(40,1);printf("Posisi Prev Hero : [%d,%d]",xHeroPrev,yHeroPrev);

        //Informasi Hero dan Enemy
        gotoxy(x_Hero,y_Hero);printf("H");
        gotoxy(xEnemy,yEnemy);printf(" O ");

        //Pergerakan Enemy
        if (x_Hero<=xEnemy)
        {
            xEnemyPrev = xEnemy;
            xEnemy -= lEnemy; //Mengurangi lEnemy dari xEnemy dan memberikan hasilnya ke xEnemy yang ditampung di xEnemyPrev
        }
        if (x_Hero>xEnemy) // jika posisi hero ada di kanan musuh
        {
            xEnemyPrev = xEnemy;
            xEnemy += lEnemy;
        }
        if (y_Hero<yEnemy) // jika posisi hero ada di atas musuh
        {
            yEnemyPrev = yEnemy;
            yEnemy -= lEnemy;
        }
        if (y_Hero>yEnemy) // jika posisi hero ada di bawah musuh
        {
            yEnemyPrev = yEnemy;
            yEnemy += lEnemy;
        }

        ///GERAK PANAH
        if(kbhit())
            key = getch();
        // Menggerakkan Hero
        if (toupper(key)==75)   ///panah Kiri
        {
            xHeroPrev=x_Hero;
            yHeroPrev=y_Hero;
            x_Hero--;
            if (x_Hero<=tembok_kiri)
                x_Hero=tembok_kiri;
        }
        if (toupper(key)==80)   ///panah Bawah
        {
            xHeroPrev=x_Hero;
            yHeroPrev=y_Hero;
            y_Hero++;
            if(y_Hero>=tembok_bawah)
                y_Hero=tembok_bawah;
        }
        if (toupper(key)==77)  ///panah Kanan
        {
            xHeroPrev=x_Hero;
            yHeroPrev=y_Hero;
            x_Hero++;
            if(x_Hero>=tembok_kanan)
                x_Hero=tembok_kanan;
        }
        if (toupper(key)==72)   ///panah Astas
        {
            xHeroPrev=x_Hero;
            yHeroPrev=y_Hero;
            y_Hero--;
            if(y_Hero<=tembok_atas)
                y_Hero=tembok_atas;
        }

        if (toupper(key)==32)   ///STOP
        {

        }

        if (toupper(key)=='F')   ///TelePort
        {
            gotoxy(x_Hero,y_Hero);printf(" ");
                                x_Hero = xFruit-1;
                                y_Hero = yFruit-1;

        }
        tunda();

        ///HEALTH
        if((x_Hero==(int)xEnemy)&&(y_Hero==(int)yEnemy))
                         {
                            gotoxy(75,7);cout<<nyawaPlayer;
                            nyawaPlayer++;
                            x_Hero = acakX();
                            y_Hero = acakY();
                            gotoxy(75,7);cout << "Nyawa Sisa: " <<nyawaPlayer;

                            if(nyawaPlayer == 2)
                            {
                                    char pilihan;

                                     gotoxy(76,22);cout<<"Coba Lagi (y=MAIN/t=CLOSE)"<<endl;
                                     gotoxy(77,23);cin>>pilihan;
                                     if(pilihan=='y')
                                     {
                                        score = 0;
                                        nyawaPlayer =0;
                                        hapusReset();
                                        system("cls");
                                        goto reset;
                                     }
                                      if(pilihan=='t')
                                     {
                                         score = 0;
                                         nyawaPlayer=0;
                                         hapusReset();

                                         break;
                                     }
                                     break;
                            }

                         }
        ///WIN MAKAN 5 BUAH
        if(x_Hero==xFruit && y_Hero==yFruit){
            //mmbuat bintangnya ilang, kemudian dipanggil lagi
            score++;
            gotoxy(3,2);printf("Score : %d", score);//ketika posisi dimakan akan mencetak
            //gotoxy(xKantong,2),printf("%d", score);
            xKantong--; ///nampung score
            if(score >= 5){
                gotoxy(10,10); printf("Selamat Anda Berhasil Menang!");
                break;
            }
            xFruit = acakX();
            yFruit = acakY();
            gotoxy(xFruit,yFruit);
            cout << "*";
        }
        if(((int)xEnemy == xFruit)&&((int)yEnemy == yFruit))
           {
               xFruit = acakX();
               yFruit = acakY();
               gotoxy(xFruit, yFruit);
               cout << "*";
           }

    } while (key!=27);

    return 0;
}

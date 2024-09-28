#include<stdio.h>
#include<conio.h>
#include<windows.h>

void set_ukuran_console();
void set_judul_console();
void bingkai();
void clear();
void loading();
void posisi(int x, int y);
void warna_text(int color);
void warna_latar(int color);


#define outputHandle GetStdHandle(STD_OUTPUT_HANDLE)
#define BLACK 0x0
#define DARK_BLUE 0x1
#define DARK_GREEN 0x2
#define DARK_CYAN 0x3
#define DARK_RED 0x4
#define DARK_PURPLE 0x5
#define DARK_YELLOW 0x6
#define DARK_WHITE 0x7
#define GRAY 0x8
#define BLUE 0x9
#define GREEN 0xa
#define CYAN 0xb
#define RED 0xc
#define PURPLE 0xd
#define YELLOW 0xe
#define WHITE 0xf


int text_color = FOREGROUND_INTENSITY;
int bg_color = 0;

void posisi(int x, int y)
{
    COORD position = {x, y};
    SetConsoleCursorPosition(outputHandle, position);
}

void warna_text(int color)
{
    SetConsoleTextAttribute(outputHandle, color | (bg_color << 4));
    text_color = color;
}

void warna_latar(int color)
{
    SetConsoleTextAttribute(outputHandle, text_color | (color << 4));
    bg_color = color;
}

void set_ukuran_console()
{
    system(mode con  cols cols=150 line=40);
    return 0;
}

void set_judul_console()
{
    setConsoleTitle("mini projekan fadli");
}

void bingkai(){
    warna_teks(6);
    warna_latar(14);
    //garis horizontal
    for (int a=0; a<166; a++)
    {
        posisi(a,41); printf("%c",219);  //bawah
        posisi(a, 0); printf("%c",219);  //atas
    }
    //garis vertikal
    for (int a=0; a<42; a++)
    {
        posisi(0  ,a); printf("%c%C",219,219); //kiri
        posisi(164,a); printf("%c%C",219,219); //kanan
    }

    //garis tipis
    //arsir vertikal
    for (int a=1; a<41; a++)
    {
        posisi(2  ,a); printf("%c%c",177,177);   //kiri
        posisi(146,a); printf("%c%c",177,177);   //kanan
    }
    //arsir horizontal
    for (int a=2; a<162; a++)
    {
        posisi(a,39); printf("%c",177);  //bawah
        posisi(a, 1); printf("%c",177);  //atas
    }
}
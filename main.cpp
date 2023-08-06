#include <windows.h>
#include <iostream>
#include <conio.h>

#define IZQ 75
#define DER 77

char avion_l1[] = {' ', ' ', ' ', '*', ' ', ' ', ' ', 0};
char avion_l2[] = {' ', ' ', '*', '*', '*', ' ', ' ', 0};
char avion_l3[] = {' ', '*', ' ', '*', ' ', '*', ' ', 0};

char explocion_l1[] = {' ', '*', ' ', '*', ' ', '*', ' ', 0};
char explocion_l2[] = {' ', ' ', '*', '*', '*', ' ', ' ', 0};
char explocion_l3[] = {' ', '*', ' ', '*', ' ', '*', ' ', 0};

char explocion_r1[] = {'*', ' ', '*', '*', ' ', '*', ' ', 0};
char explocion_r2[] = {' ', '*', '*', '*', '*', ' ', ' ', 0};
char explocion_r3[] = {'*', ' ', '*', '*', ' ', '*', ' ', 0};

int num_vidas = 3;
int corazones = 3;
int ix = 45;
int iy = 20;

//Coordenadas
int y = 20, x = 85;
int yy = 12, xx = 85; // Ast_B
int y1 = 6, x1 = 85;  // Ast_C
int y2 = 9, x2 = 85;  // Ast_D
/*
int y = 8, x = 12;
int yy = 12, xx = 17;
int y1 = 6, x1 = 58;
int y2 = 9, x2 = 70; */

int i, v;

int repeticion = 0, nivel = 1;
bool condicion = false;

void gotoxy(int x, int y)
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;

    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon, dwPos);
}

void vidas(int v)
{
    gotoxy(2, 1);
    printf("VIDAS %d", v);
}

void barraSalud(int n)
{
    x = 95;
    gotoxy(x, 1);
    printf(" ");
    gotoxy(x + 1, 1);
    printf(" ");
    gotoxy(x + 2, 1);
    printf(" ");

    for (v = 0; v < n; v++)
    {
        gotoxy(x + v, 1);
        printf("%c", 3);
    }
}

void explocion(void)
{
    gotoxy(ix, iy);
    puts(explocion_l1);
    gotoxy(ix, iy + 1);
    puts(explocion_l2);
    gotoxy(ix, iy + 2);
    puts(explocion_l3);
    Sleep(380);

    gotoxy(ix, iy);
    puts(explocion_r1);
    gotoxy(ix, iy + 1);
    puts(explocion_r2);
    gotoxy(ix, iy + 2);
    puts(explocion_r3);
    Sleep(380);

    gotoxy(ix, iy);
    puts(avion_l1);
    gotoxy(ix, iy + 1);
    puts(avion_l2);
    gotoxy(ix, iy + 2);
    puts(avion_l3);
}

void jugar(void)
{
    // rutinas de los asteroides
    // A1
    gotoxy(x, y);
    printf("%c", 2);
    // A2
    gotoxy(xx, yy);
    printf("%c", 'b');
    // A3
    gotoxy(x1, y1);
    printf("%c", 'c');
    // A4
    gotoxy(x2, y2);
    printf("%c", 'd');

    /*     Sleep(70);
        // Al mover se deben limpiar los asteroides
        // A1
        gotoxy(x, y);
        printf(" ");
        // A2
        gotoxy(xx, yy);
        printf(" ");
        // A3
        gotoxy(x1, y1);
        printf(" ");
        // A4
        gotoxy(x2, y2);
        printf(" "); */
}

int main()
{
    vidas(num_vidas);
    barraSalud(3);
    jugar();
    explocion();
    getch();
}
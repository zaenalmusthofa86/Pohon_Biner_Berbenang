//Membuat dan menelusuri pohon biner berbenang
//Berbenang.cpp
#include<stdio.h>
#include<stdlib.h> //malloc supaya jalan tambahin library ini
#include<math.h>
#include<conio.h>
#include <iostream>

using namespace std;

struct Node
{
    char INFO;
    int FlagKiri, FlagKanan;
    struct Node *Right;
    struct Node *Left;
};
typedef struct Node Simpul;
Simpul *P,*Q,*Akar,*Head;

void Inisialisasi()
{
    Akar = NULL;
    Head = NULL;
}

void BuatSimpul(char X)
{
    P = (Simpul*) malloc(sizeof(Simpul));
    if(P!=NULL)
    {
        P->INFO = X;
        P->Left = NULL;
        P->Right = NULL;
        P->FlagKiri = 0;
        P->FlagKanan = 0;
    }
    else
    {   printf("Memori Penuh Broo..");
        return;
    }
}

void BuatSimpulAkar()
{
    if(Akar == NULL)
    {
        Akar = P;
        Akar->INFO = 'L';
    }
    else
    {
        printf("Akar sudah ada Broo..");
        return;
    }
}

void BuatSimpulHead()
{
        if(Head == NULL)
    {
        Head = P;
        Head->Left = Akar;
        Head->Right = Head;
    }
    else
    {
        printf("Head sudah ada Broo..");
        exit(1);
    }
}

void InOrderBenang(Simpul *T)
{
    Simpul *Q, *R;
    Q = T;
    do
    {
        R = Q->Right;
        if(Q->FlagKanan == 0)
        {
            while(R->FlagKiri == 0)
            {
                R = R->Left;
            }
        }
        Q = R;
        if(Q != T)
            printf("%c", Q->INFO);
    }
    while(Q != T);
}
int main()
{
    //clrscr(); //tidak berfungsi
    system("cls"); //gantinya menggunakan ini
    Inisialisasi();
    BuatSimpul('L'); BuatSimpulAkar();
    BuatSimpul('h'); BuatSimpulHead();
    BuatSimpul('O'); Akar->Left = P;
    BuatSimpul('O'); Akar->Right = P;
        P->Right = Head; P->FlagKanan = 1;
    BuatSimpul('J'); Akar->Left->Left = P;
        P->Left = Head; P->FlagKiri = 1;
        P->Right = Akar->Left; P->FlagKanan = 1;
    BuatSimpul('M');
        Akar->Left->Right = P; Q = P;
    BuatSimpul('O'); Akar->Right->Left = P;
        P->Left = Akar; P->Right = Akar->Right;
        P->FlagKiri = 1; P->FlagKanan = 1;
     BuatSimpul('O'); Q->Left = P;
        P->Left = Akar->Left; P->Right = Q;
        P->FlagKiri = 1; P->FlagKanan = 1;
    BuatSimpul('B'); Q->Right = P;
        P->Left = Q; P->Right = Akar;
        P->FlagKiri = 1; P->FlagKanan = 1;

    cout << "===================================" << endl;
    cout << "|  PROGRAM POHON BINER BERBENANG  |" << endl;
    cout << "===================================" << endl;
    cout << "          Zaenal Mustofa " << endl;
    cout << "           311810782 " << endl;
    cout << "            TI.18.C2 " << endl;
    cout <<endl;
    cout <<endl;

    printf("Hasil dari program pohon biner berbenang adalah: ");
    InOrderBenang(Head);
    getch();
    return(0);
}

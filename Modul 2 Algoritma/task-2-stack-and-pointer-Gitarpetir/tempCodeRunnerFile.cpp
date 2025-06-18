#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

#define max 20
string data [max];
int Tumpuk = 0;

int kosong()
{
    if(Tumpuk == 0){
        return 1;
    }
    else {
        return 0;
    }
}
int penuh()
{
    if(Tumpuk >= max)
    {
    return 1;}
    else
    {
    return 0;}
}

void input ()
{
    if (!penuh())
    {
        cout << "Masukkan Data : "; cin >> data[Tumpuk];
        Tumpuk++;
    } 
}
void hapus()
{
    if(!kosong())
    {
         cout << "\nData Teratas Sudah Terambil";
         Tumpuk--;
    }
    else 
    cout <<" Data Kosong";
}
void tampil() 
{
    if(!kosong()){
        cout << "\nData Tersimpan : " << endl;
        for(int a = 0; a < Tumpuk; a++){
            cout << a+1 << ". "<< data[a] << endl;
        }
    } 
    else {
        cout << "\nData Kosong!" << endl;
    }
}

void bersih ()
{
    Tumpuk = 0;
}

int main(){
    int pilih;

    stack:
    tampil();
    cout<<"Menu Utama\n1. Push\n2. Pop\n3. Hapus semua\n4. Hentikan Program\nPilih : "; cin >> pilih;

    if(pilih == 1){
        input();
        goto stack;
    }
    else if(pilih == 2){
        hapus();
        goto stack;
    }
    else if(pilih == 3){
        bersih();
        goto stack;
    }
    else if(pilih == 4){
        cout << "Program berhenti!!";
    }
}
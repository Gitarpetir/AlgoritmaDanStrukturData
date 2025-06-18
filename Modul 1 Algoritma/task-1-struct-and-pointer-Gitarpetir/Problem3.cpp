#include<iostream>

using namespace std;

struct HURUF{
    char huruf;
    int angka;
    string kata;
};
struct HURUF isi;
int main(){
    cout<<"Masukkan sebuah huruf : "; cin>>isi.huruf; 
    cout<<"Masukkan sebuah kata : "; cin>>isi.kata; 
    cout<<"Masukkan sebuah angka : "; cin>>isi.angka;
    cout<<"\nHuruf yang anda masukkan adalah : "<<isi.huruf;
    cout<<"\nKata yang anda masukkan adalah : "<<isi.kata;
    cout<<"\nAngka yang anda masukkan adalah : "<<isi.angka;
    return 0;
}
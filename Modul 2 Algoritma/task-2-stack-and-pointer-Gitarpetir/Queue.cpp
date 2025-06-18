#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#define max 20

string data[max];
int top = 0;

int isFull(){
    if(top >= max){
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(){
    if(top == 0){
        return 1;
    } else {
        return 0;
    }
}
void view(){
    if(!isEmpty()){
        cout << "\nData Antrian : " <<endl;
        for(int a = 0; a < top; a++){
            cout << a+1 << ". " << data[a] << endl;
        }   
        } else {
            cout << "Antrian Kosong" << endl;
        }
    if(isFull()){
        cout << "Antrian Penuh" << endl;
    }
    cout << endl;
}

void enqueue(){
    if(!isFull()){
        cout << "Masukkan Data : ";
        cin >> data[top];
        top++;
    }
} 

void dequeue(){
    if(!isEmpty()){
        for(int a = 0; a < top; a++){
            data[a] = data[a+1];
        }
        top--;
    }
}
int main() {
    int pil;

    queue:
    cout << "Menu Utama\n1. Insert\n2. Delete\n3. View\n4. Quit\nPilihan : "; cin >> pil;

    switch(pil)
    {
    case 1:
        enqueue();
        goto queue;
    case 2:
        dequeue();
        goto queue;
    case 3:
        view();
        goto queue;
    default:
        cout << "TERIMA KASIH";
    }
}

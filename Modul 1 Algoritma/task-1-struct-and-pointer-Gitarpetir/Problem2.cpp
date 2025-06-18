#include <iostream>

using namespace std;

struct mudik {
    string plat;
    string jenis;
    string nama;
    string alamat;
    string kota;
};

int main() {

    mudik transportasi = {
        "DA1234MK",
        "RUSH",
        "Andika Hartanto",
        "Jl. Kayu Tangi 1",
        "Banjarmasin"
    };

    cout<< "Plat Nomor Kendaraan : " << transportasi.plat<<endl;
    cout<< "Jenis Kendaraan      : " << transportasi.jenis<<endl;
    cout<< "Nama Pemilik         : " << transportasi.nama<<endl;
    cout<< "Alamat               : " << transportasi.alamat<<endl;
    cout<< "Kota                 : " << transportasi.kota<<endl;

    return 0;
}

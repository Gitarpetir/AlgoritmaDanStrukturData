#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

void sequentialSearch(const vector<int> &nums, int target){
    cout << "Mencari " << target << " menggunakan Sequential Search...\n";

    int count = 0;

    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            cout << "Angka ditemukan di indeks ke-" << i << endl;
            count++;
        }
    }
    if (count == 0) {
        cout << "Angka tidak ditemukan dalam daftar.\n";
    } else {
        cout << "Jumlah kemunculan angka " << target << ": " << count << " kali\n";
    }
}

void binarySearch(const vector<int> &nums, int target){
    int high = nums.size() - 1;
    int low = 0;
    int index = -1;

    while (low <= high){
        int mid = low + (high - low) / 2;
        
        if (nums[mid] == target){
            index = mid;
            break;
        }
        if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    if (index == -1) cout << "angka " << target << " tidak ditemukan pada array" << endl;
    else cout << "angka " << target << " ditemukan pada indeks ke " << index << endl; 
}

void clearScreen(){
    system("cls");
}

void explain(){
    cout << "=== Perbandingan Sequential Search dan Binary Search ===\n\n";
    cout << "1. Cara Kerja:\n";
    cout << "- Sequential Search: Memeriksa elemen satu per satu dari awal hingga target ditemukan atau data habis.\n";
    cout << "- Binary Search: Membagi data terurut menjadi dua bagian secara berulang, mencari di bagian yang sesuai.\n\n";
    cout << "2. Kompleksitas Waktu dan Ruang (Big-O):\n";
    cout << "- Sequential Search: Waktu O(n), Ruang O(1)\n";
    cout << "- Binary Search: Waktu O(log n), Ruang O(1)\n\n";
    cout << "3. Persyaratan Awal:\n";
    cout << "- Sequential Search: Tidak perlu data terurut.\n";
    cout << "- Binary Search: Data harus sudah terurut.\n\n";
    cout << "4. Penggunaan Terbaik:\n";
    cout << "- Sequential Search: Data kecil atau tidak terurut, pencarian sekali saja.\n";
    cout << "- Binary Search: Data besar yang sudah terurut, pencarian banyak kali.\n\n";
    cout << "5. Kelebihan dan Kekurangan:\n";
    cout << "- Sequential Search:\n";
    cout << "  Kelebihan: Mudah, fleksibel, tidak perlu urut.\n";
    cout << "  Kekurangan: Lambat untuk data besar.\n";
    cout << "- Binary Search:\n";
    cout << "  Kelebihan: Cepat, efisien untuk data besar terurut.\n";
    cout << "  Kekurangan: Perlu data terurut, sorting butuh waktu jika data acak.\n\n";
}


int main() {
    int opt, target;
    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums (100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto &val: nums) {
                    val = (dist(rng));
                }

                cout << "Daftar angka Random:\n";
                for (const auto &val : nums) {
                    cout << val << " ";
                }
                cout << endl;
                cout << "Masukkan angka yang ingin dicari: "; cin >> target;

                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val: nums) {
                    val = (dist(rng));
                }
                cout << "Daftar angka Random:\n";
                for (const auto &val : nums) {
                    cout << val << " ";
                }
                cout << endl;

                sort(nums.begin(), nums.end());
                cout << "Daftar setelah diurutkan (untuk Binary Search):\n";
                for (const auto &val : nums) {
                    cout << val << " ";
                }
                cout << "\n";

                cout << "Masukkan angka yang ingin dicari: "; cin >> target;

                binarySearch(nums, target);
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Programme was made by Muhammad Alfi Gunawan (2410817110009)" << endl;
                break;

            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}
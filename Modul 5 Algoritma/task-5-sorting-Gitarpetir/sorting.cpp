#include <iostream>
#include <functional>
#include <chrono>
#include <iomanip>
#include <string>
#include <conio.h>


using namespace std;

string name = "Muhammad Alfi Gunawan";
string id = "2410817110009";

void timeSort(const function<void()>& sortFunc, const string& sortName) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << fixed << setprecision(10);
    cout << sortName << "\ntook " << duration.count() << " seconds\n";
}

void insertionSort(string &str) {
    for (int i = 1; i < (int)str.size(); ++i) {
        int j = i;
        while (j > 0 && str[j] < str[j - 1]) {
            swap(str[j], str[j - 1]);
            j--;
        }
    }
}


void merge(string &str, int left, int mid, int right) {
    int length1 = mid - left + 1;
    int length2 = right - mid;

    string L = str.substr(left, length1);
    string R = str.substr(mid + 1, length2);

    int i = 0, j = 0, k = left;
    while (i < length1 && j < length2) {
        if (L[i] <= R[j]) {
            str[k++] = L[i++];
        } else {
            str[k++] = R[j++];
        }
    }

    while (i < length1) {
        str[k++] = L[i++];
    }
    while (j < length2) {
        str[k++] = R[j++];
    }
}

void mergeSort(string &str, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(str, left, mid);
        mergeSort(str, mid + 1, right);
        merge(str, left, mid, right);
    }
}

void shellSort(string &str, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            auto temp = str[i];
            int j;
            for (j = i; j >= gap && str[j - gap] > temp; j -= gap) {
                str[j] = str[j - gap];
            }
            str[j] = temp;
        }
    }
}

void bubbleSort(string &str) {
    int n = str.length();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (str[j] > str[j + 1]) {
                swap(str[j], str[j + 1]);
            }
        }
    }
}

void quickSort(string &str, int first , int last){
    int i, j, pivot, buffer;
    if(first < last){
        pivot = first;
        i = first;
        j = last;

        while (i < j){
            while( str[i] <= str[pivot] && i < last)
            i++;
            while( str[j] > str[pivot])
            j--;
            if (i < j){
                buffer = str[i];
                str[i] = str[j];
                str[j] = buffer;
            }
        }
        buffer = str[pivot];
        str[pivot] = str[j];
        str[j] = buffer;
        quickSort(str, first, j-1);
        quickSort(str, j+1, last);
    }
}

void selectionSort(string &str) {
    for (int i = 0; i < (int)str.size() - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < (int)str.size(); j++){
            if (str[j] < str[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i){
            int temp = str[i];
            str[i] = str[min_index];
            str[min_index] = temp;
        }
    }
}


int main() {
    int ch;
    string temp;

    do {
        cout << "===================================================\n";
        cout << "|                     Sorting                      \n";
        cout << "===================================================\n";
        cout << "| Pilihan Sorting Algoritma:                      |\n";
        cout << "| 1. Insertion Sort                               |\n";
        cout << "| 2. Merge Sort                                   |\n";
        cout << "| 3. Shell Sort                                   |\n";
        cout << "| 4. Bubble Sort                                  |\n";
        cout << "| 5. Quick Sort                                   |\n";
        cout << "| 6. Selection Sort                               |\n";
        cout << "| 7. Exit                                         |\n";
        cout << "===================================================\n";
        cout << "Masukkan Pilihan: ";
        cin >> ch;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            ch = -1;
        }

        if (ch >= 1 && ch <= 3) {
            temp.clear();
            for (char c : name) {
                if (isalpha(c)) temp += c;
            }
            cout << "Data Sebelum Diurutkan: " << name << endl;

            if (ch == 1)
                timeSort([&] { insertionSort(temp); }, "Insertion Sort");
            else if (ch == 2)
                timeSort([&] { mergeSort(temp, 0, temp.length() - 1); }, "Merge Sort");
            else
                timeSort([&] { shellSort(temp, temp.length()); }, "Shell Sort");

            cout << "Data Setelah Diurutkan: " << temp << endl;

        } else if (ch >= 4 && ch <= 6) {
            temp = id;
            cout << "Data Sebelum Diurutkan: " << temp << endl;

            if (ch == 4)
                timeSort([&] { bubbleSort(temp); }, "Bubble Sort");
            else if (ch == 5)
                timeSort([&] { quickSort(temp, 0, temp.length() - 1); }, "Quick Sort");
            else
                timeSort([&] { selectionSort(temp); }, "Selection Sort");

            cout << "Data Setelah Diurutkan: " << temp << endl;

        } else if (ch == 7) {
            cout << "Terima kasih telah menggunakan program ini.\n";

        } else {
            cout << "Opsi salah, coba lagi!.\n";
        }

        if (ch != 7) {
            cout << "\nTekan tombol apa saja untuk melanjutkan!\n";
            getch();
            system("cls");
        }

    } while (ch != 7);

    return 0;
}

    #include <iostream>
    using namespace std;

    int maksimal = 10;
    string dataBarang[10];
    int top = 0;

    //Fungsi untuk mengecek data penuh atau tidak
    bool isFullBarang(){
        if( top == maksimal ){
            return true;
        }else{
            return false;
        }
    }

    //Fungsi untuk mengecek data kosong
    bool isEmptyBarang(){
        if( top == 0 ){
            return true;
        }else{
            return false;
        }
    }

    //Fungsi untuk menambahkan data diatas tumpukan
    void pushDataBarang(string data) {
        if (isFullBarang()) {
            cout << "Data Tumpukan Penuh" << endl;
        } else {
            dataBarang[top] = data;
            top++;
        }
    }

    // Fungsi untuk menghapus satu data pada tumpukan paling atas
    void popDataBarang() {
        if (isEmptyBarang()) {
            cout << "Data kosong!!" << endl;
        } else {
            dataBarang[top-1] = "";
            top--;
        }
    }

    //Fungsi untuk melihat posisi data tertentu
    void peekDataBarang(int posisi){
        if( isEmptyBarang() ){
            cout << "Data kosong!!" << endl;
        }else if (top < posisi){
            cout << "Data Tidak Ditemukan!!" << endl;
        }
        else{
            int index = top;
            for( int i = 0; i < posisi; i++ ){
                index--;
            }
            cout << "Data posisi ke-" << posisi << " adalah " << dataBarang[index] << endl;
            cout << "\n" << endl;
        }
    }

// Fungsi untuk merubah data pada posisi tertentu
void changeDataBarang(string data, int posisi) {
    if (isEmptyBarang()) {
        cout << "Data kosong!!" << endl;
    } else if (top < posisi) {
        cout << "Data Tidak Ditemukan!!" << endl;
    } else {
        cout << "Data yang dirubah diurutan ke : " << posisi << endl;
        int index = 0;
        for (int i = 0; i < posisi; i++) {
            index++;
        }
        dataBarang[index-1] = data;
    }
}

    //Fungsi untuk menghitung jumlah data pada tumpukan
    int countDataBarang(){
        if( isEmptyBarang() ){
            return 0;
        }else{
            return top;
        }
    }

    //Fungsi untuk menghapus seluruh data pada tumpukan
    void destroyDataBarang(){
        for( int i = 0; i < top; i++ ){
            dataBarang[i] = "";
        }
        top = 0;
    }

   // Fungsi untuk menampilkan data
    void displayDataBarang() {
    if (isEmptyBarang()) {
        cout << "Data kosong!!" << endl;
    } else {
        cout << ".:Data stack pada array:." << endl;
        for (int i = maksimal - 1; i >= 0; i--) {
            if (dataBarang[i] != "") {
                cout << "Data Ke "<< i + 1 << ": " << dataBarang[i] << endl;
            }
        }
        cout << "\n" << endl;
    }
}


int main() {
    int pilih, posisi;
    string data;

    ulang:
    cout << "================================================" << endl;
    cout << ":: Menu Operator Stack Pada Array ::" << endl;
    cout << "================================================" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Change" << endl;
    cout << "5. Count" << endl;
    cout << "6. Destroy" << endl;
    cout << "7. Is Full" << endl;
    cout << "8. Is Empty" << endl;
    cout << "10. Keluar" << endl;
    cout << "Silahkan Pilih Berdasarkan Nomor : ";
    cin >> pilih;

    if (pilih == 1) {
        cout << "Push" << endl;
        cout << "Masukkan data: ";
        cin >> data;
        pushDataBarang(data);
        system("CLS");
        cout << "Push berhasil" << endl;
        displayDataBarang();
    } else if (pilih == 2) {
        cout << "Pop" << endl;
        popDataBarang();
        system("CLS");
        cout << "Pop berhasil" << endl;
        displayDataBarang();
    } else if (pilih == 3) {
        system("CLS");
        cout << "Peek" << endl;
        cout << "Masukkan posisi: ";
        cin >> posisi;
        peekDataBarang(posisi);
        cout << "Peek berhasil" << endl;
        displayDataBarang();
    } else if (pilih == 4) {
        cout << "Change" << endl;
        cout << "Masukkan data: ";
        cin >> data;
        cout << "Masukkan posisi: ";
        cin >> posisi;
        changeDataBarang(data, posisi);
        system("CLS");
        cout << "Change berhasil" << endl;
        displayDataBarang();
    } else if (pilih == 5) {
        system("CLS");
        cout << "Count" << endl;
        cout << "Jumlah data: " << countDataBarang() << endl;
        cout << "Count berhasil" << endl;
        displayDataBarang();
    } else if (pilih == 6) {
        cout << "Destroy" << endl;
        destroyDataBarang();
        system("CLS");
        cout << "Destroy berhasil" << endl;
        displayDataBarang();
    } else if (pilih == 7) {
        system("CLS");
        cout << "Apakah data Penuh ? " << isFullBarang() << endl;
        displayDataBarang();
    } else if (pilih == 8) {
        system("CLS");
        cout << "Apakah data Kosong ? " << isEmptyBarang() << endl;
        displayDataBarang();
    } else if (pilih == 10) {
        return 0;
    } else {
        system("CLS");
        cout << "Nomor yang Anda Pilih Tidak Tersedia, Silahkan Memilih Lagi" << endl;
        cin.ignore();
        cin.get();
    }
    goto ulang;

    return 0;
}

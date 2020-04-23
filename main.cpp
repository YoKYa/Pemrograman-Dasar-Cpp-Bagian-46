#include <iostream>
#include <fstream>

using namespace std;

struct Buku{
    string Nama;
    int Harga;
};

void WriteBuku(Buku &DataBuku, fstream &File ){
    File.write(reinterpret_cast<char*>(&DataBuku), sizeof(Buku));
}
Buku ReadBuku(int Posisi,fstream &File){
    Buku Buku1;

    File.seekp((Posisi-1)*sizeof(Buku));
    File.read(reinterpret_cast<char*>(&Buku1), sizeof(Buku));
    return Buku1;
}


int main(){
    fstream File, File2;
    int Nomor, hasil;

    cout << "Masukkan Nomor yang dijadikan binary : ";
    cin >> Nomor;

    // Menulis Nomor Ke binary
    File.open("text.bin",ios::out | ios::binary);
    File.write(reinterpret_cast<char*>(&Nomor),sizeof(Nomor));
    File.close();

    // Membaca Binary Ke Nomor
    File.open("text.bin", ios::in | ios::binary);
    File.read(reinterpret_cast<char*>(&hasil),sizeof(hasil));
    cout << "Nomor yang dihasilkan yaitu : " << hasil;

    // Menulis Binary dalam struct
    Buku Buku1, Buku2, Hasil; // Deklarasi
    Buku1.Nama = "Kami Bukan Sarjana Kertas"; // Mengisi Struct
    Buku1.Harga = 80000;                      // Mengisi Struct
    Buku2.Nama = "Kami Bukan Jongos Berdasi"; // Mengisi Struct
    Buku2.Harga = 82000;                      // Mengisi Struct

    File2.open("text2.bin", ios::trunc | ios::out | ios::in | ios::binary);
    WriteBuku(Buku1, File2);
    WriteBuku(Buku2, File2);

    // Membaca dalam struct
    Hasil = ReadBuku(1,File2);
    cout << endl << endl << "Nama Buku \t: " << Hasil.Nama << endl;
    cout << "Harga \t\t: " << Hasil.Harga;
    
    File.close();

    return 0;
}
#include <iostream>
using namespace std;

const int mhs_maksimal = 300;
int jumlah_mhs = 2;
string mahasiswa[mhs_maksimal][7] = {{"Aris", "130", "80", "90", "75", "85", "70"}, {"Faris", "131", "70", "85", "75", "90", "80"}};
string data_mhs[7] = {"Nama", "NIM", "Algoritma", "Basis Data", "Matematika", "Logika Informatika", "MRV"};
string password = "admin";
string username = "admin";

void menampilkan_predikat_nilai(string array[]) {
  int rerata = 0;
  for(int i = 2; i < 7; i++){
    rerata += stoi(array[i]);
  }
  rerata = rerata / 5;
  if(rerata > 80) cout<<"Nilai : A"<<endl;
  else if(rerata > 68) cout<<"Nilai : B"<<endl;
  else if(rerata > 56) cout<<"Nilai : C"<<endl;
  else if(rerata > 45) cout<<"Nilai : D"<<endl;
  else cout<<"Nilai : E" <<endl;
  cout<<"----------------------"<<endl;
}

void menambahkan_data() {
  if(jumlah_mhs >= mhs_maksimal){
    cout<<"Data penuh! Tidak bisa menambah mahasiswa."<<endl;
    return;
  }
  cout<<"Masukan data mahasiswa"<<endl;
  for(int i = 0; i < 7; i++){
    if(i == 2){cout << "Masukan 5 nilai mata kuliah" << endl;}
    cout<<data_mhs[i]<<" : ";
    cin>>mahasiswa[jumlah_mhs][i];
  }
  cout<<"Data "<<mahasiswa[jumlah_mhs][0] << " berhasil ditambahkan"<<endl;
  jumlah_mhs++;
  system("pause");
  system("cls");
}

void login_admin(string input_pass, string input_usename) {
  if(password == input_pass && username == input_usename){
    system("cls");
    cout<<"\nLogin berhasil\n\n";
    menambahkan_data();
  }else{
    system("cls");
    cout<<"Username atau password salah"<<endl;
    system("pause");
    cout<<"Akses ditolak !"<<endl;
    system("pause");
    system("cls");
  }
}

int cari_index_data(string nim) {
  for(int i = 0; i < jumlah_mhs; i++){
    if(mahasiswa[i][1] == nim)
      return i;
  }
  return -1;
}

void cari_mhs() {
  system("cls");
  string nim;
  cout<<"Masukan NIM yang dicari : ";
  cin>>nim;
  cout<<"----------------------"<<endl;
  int index = cari_index_data(nim);
  if(index >= 0){
    for(int i = 0; i < 7; i++){
        cout<<data_mhs[i]<<" : "<<mahasiswa[index][i]<<endl;
    }
    menampilkan_predikat_nilai(mahasiswa[index]);
    system("pause");
    system("cls");
  }else{
    cout<<"NIM tidak ditemukan"<<endl;
    system("pause");
    system("cls");
  }
}

int main() {
  int pilih;
  string input_pass, input_usename;

  do{
    cout<<"======= MENU UTAMA ======="<<endl;
    cout<<"1. Lihat data mahasiswa"<<endl;
    cout<<"2. Cari data mahasiswa"<<endl;
    cout<<"3. Input data (hanya admin)"<<endl;
    cout<<"4. Keluar"<<endl;
    cout<<"Pilih menu (1-4) : ";
    cin>>pilih;
    
    switch(pilih){
      case 1:
        system("cls");
        for(int i = 0; i < jumlah_mhs; i++){
          cout<<"----------------------"<<endl;
          cout<<"Nama : " << mahasiswa[i][0]<<endl;
          cout<<"NIM  : " << mahasiswa[i][1]<<endl;
          menampilkan_predikat_nilai(mahasiswa[i]);
        }
        system("pause");
        system("cls");
        break;
      case 2:
        cari_mhs();
        break;
      case 3:
        system("cls");
        cout<<"======= LOGIN ADMIN ======="<<endl;
        cin.ignore();
        cout<<"Username : ";
        getline(cin, input_usename);
        cout<<"Password : ";
        getline(cin, input_pass);
        login_admin(input_pass, input_usename);
        break;
      case 4:
        cout<<"\nTerima Kasih\n";
        return 0;
      default:
        system("cls");
        cout<<"Input diluar jangkauan"<<endl;
        system("pause");
        system("cls");
        break;
    }
  }while(pilih != 4);
return 0;
}

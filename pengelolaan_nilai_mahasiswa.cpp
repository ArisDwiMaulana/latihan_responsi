#include <iostream>
#include <vector>
using namespace std;

void menampilkan_data_mhs(vector <string> array){
  int rerata = 0;
  for (size_t i = 0; i < array.size(); i++) {
    if (i > 1) {
      rerata += stoi(array[i]);
    }
  }
  rerata = rerata/(5);
  cout<<"Nama : "<<array[0]<<endl;
  cout<<"NIM  : "<<array[1]<<endl;
  if (rerata > 80) {
    cout<<"Nilai : A"<<endl;
  }else if (rerata>68 && rerata<=80) {
    cout<<"Nilai : B"<<endl;
  }else if (rerata>56 && rerata<=68) {
    cout<<"Nilai : C"<<endl;
  }else if (rerata>45 && rerata<=56) {
    cout<<"Nilai : D"<<endl;
  }else if (rerata <= 45) {
    cout<<"Nilai : E"<<endl;
  }
  cout<<"----------------------"<<endl;;
}

int main () {
  //                                     nama     nim    ---------nilai-----------
  vector <vector <string>> mahasiswa = {{"Aris", "130", "80", "90", "75", "85", "70"}, {"Faris", "131", "70", "85", "75", "90", "80"}};
  int pilih;

  do{
    cout<<"======= MENU UTAMA ======="<<endl;
    cout<<"1. Lihat data mahasiswa"<<endl;
    cout<<"2. Cari data mahasiswa"<<endl;
    cout<<"3. Input data (hanya andmin)"<<endl;
    cout<<"4. Keluar"<<endl;
    cout<<"Pilih menu (1-4) : ";
    cin>>pilih;

    switch (pilih) {
      case 1:
        for (size_t i = 0; i < mahasiswa.size(); i++) {
           menampilkan_data_mhs(mahasiswa[i]);
         } 
        break;
      default:
        cout<<"Input diluar jangkauan"<<endl;
        break;
    }
    
  }while(pilih != 4);
    
  return 0;
}

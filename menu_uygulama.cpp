// C++ program for the above approach
#include <bits/stdc++.h>
  
#define max 20
using namespace std;
  
// Structure of Employee
struct employee {
    string name;
    string bolum;
    string soyad;
    float maas;
};
  
int num;
void showMenu();
  
// Array of Employees to store the
// data in the form of the Structure
// of the Array
employee emp[max], tempemp[max],
    sortemp[max], sortemp1[max];
  
// Function to build the given datatype
void build()
{
    cout << "tablo olusturuluyor\n";
    cout << "maximum karakter sayisi "
         << max << "\n";
  
    cout << "kac tane personel ekleyeceksiniz  "
         << "sayisini yaziniz:";
    cin >> num;
  
    if (num > 20) {
        cout << "maximum sayi 20 ";
        num = 20;
    }
    cout << "Bilgileri giriniz:\n";
  
    for (int i = 0; i < num; i++) {
        cout << "Personelin Adı ";
        cin >> emp[i].name;

        cout << "Personelin Soyadı:";
        cin >> emp[i].soyad;
  
        cout << "Personelin Calıştığı Bölüm: \n";
        cin >> emp[i].bolum;

        cout << "Personelin Maaşı: \n";
        cin >> emp[i].maas;
    }
  
    showMenu();
}
  
// Function to insert the data into
// given data type
void ekle()
{
    if (num < max) {
        int i = num;
        num++;
  
        cout << "Personel Bilgilerini Giriniz:\n";
        cout << "Personel Adi: ";
        cin >> emp[i].name;

        cout << "Personel Soyadi: ";
        cin >> emp[i].soyad;
  
        cout << "Personelin Çalıştığı Bölüm: \n";
        cin >> emp[i].bolum;

        cout << "Personelin Maaşı: \n";
        cin >> emp[i].maas;
  
    }
    else {
        cout << "personel tablosu full dolu!\n";
    }
  
    showMenu();
}
  
// Function to delete record at index i
void silIndex(int i)
{
    for (int j = i; j < num - 1; j++) {
        emp[j].name = emp[j + 1].name;
        emp[j].soyad = emp[j + 1].soyad;
        emp[j].bolum = emp[j + 1].bolum;
        emp[j].maas = emp[j + 1].maas;
    }
    return;
}
  
// Function to delete record
void personelSil()
{   
    string name;
    string soyad;
    cout << "cikarmak istediğiniz personelin adini giriniz:" << endl;
    cin >> name;
    cout << "cikarmak istediğiniz personelin soyadini giriniz:" << endl;
    cin >> soyad;

    for (int i = 0; i < num; i++) {
        if (emp[i].name == name && emp[i].soyad == soyad) {
            silIndex(i);
            num--;
            break;
        }
    }
    showMenu();
}
  
void arama()
{   
    string name;
    string soyad;

    cout << "Aramak istediginiz personelin adını giriniz:"<<endl;
    cin >> name;
    cout << "Aramak istediginiz personelin soyadını giriniz:"<<endl;
    cin >> soyad;
  
    for (int i = 0; i < num; i++) {
  
     
        if (emp[i].name == name && emp[i].soyad == soyad) {
            cout << "personelin adi: "
                 << emp[i].name << "\n";
            cout << "personelin Soyadi: "
                 << emp[i].soyad << "\n";
            cout << "calistigi bölüm: "
                 << emp[i].bolum << "\n";
            cout << "personelin maasi: "
                 << emp[i].maas << "\n";
            break;
        }
        else {
            cout<<"Aradığınız personel bulunamadı."<<endl;
        }
    }
  
    showMenu();
}

void toplam(){
    float top;
    for(int i = 0; i < num; i++){
        top = top + emp[i].maas;
    }
    cout << top;
}

// Function to show menu
void showMenu()
{
  

    cout<<"---------Menu------------\n";
    cout<<" \n  ";
    cout << "Personel Tablosu Oluştur (1)\n";
    cout << "Yeni Personel Ekle       (2)\n";
    cout << "Personeli Çıkart   (3)\n";
    cout << "Personel ara     (4)\n";
    cout << "Toplam Maaş       (5)\n";
    cout << "Çıkış             (6)\n";
  
    int option;
  
    // Input Options
    cin >> option;
  
    // Call function on the bases of the
    // above option
    if (option == 1) {
        build();
    }
    else if (option == 2) {
        ekle();
    }
    else if (option == 3) {
        personelSil();
    }
    else if (option == 4) {
        arama();
    }
    else if (option == 5) {
        toplam();
    }
    else if (option == 6) {
        return;
    }
    else {
        cout << "Expected Options"
             << " are 1/2/3/4/5/6";
        showMenu();
    }
}
  
// Driver Code
int main()
{
  
    showMenu();
    return 0;
}
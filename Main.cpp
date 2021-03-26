#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;

//Entity for Data Mahasiswa
struct Mahasiswa {
    //property
    int no;
    string nrp;
    string name;
    string gender;

    //default constructor
    Mahasiswa() {
        no = 0;
        nrp = "";
        name = "";
        gender = "";
    };

    //constructor with params
    Mahasiswa(int no, string nrp, string name, string gender) {
        this->no = no;
        this->nrp = nrp;
        this->name = name;
        this->gender = gender;
    };
};

//Read Data from data-nama.txt
vector<string> readDataTXT() {
    string data; // variable untuk menyimpan data sementara dari txt
    vector<Mahasiswa> list; // array dinamis untuk menyimpan data mahasiswa
    vector<string> listData; // array dinamis menyimpan data dari variable data

    ifstream stream; //read file

    stream.open("daftar-nama.txt", ios::app); //open file txt
    if (stream.is_open()) {  // kondisi jika file txt berhasil dibuka
        while (!stream.eof()) {
            getline(stream, data); // ambil semua data dari txt dan simpan dalam variable data
            listData.push_back(data); // simpan data ke dalam array dinamis
        }
    }
    else {
        cout << "Data Not Found"; //kondisi jika file tidak berhasil dibuka
    }

    stream.close(); // close file
    return listData; // return list data
}

void createDataCSV() {
    ofstream stream; // write file
    stream.open("4210191018_MDFebrian.csv", ios::trunc); // open file
    vector<string> list = readDataTXT(); //get all data
    vector<Mahasiswa> listMahasiswa; // deklarasi vector object mahasiswa

    // remove data
    list.erase(list.begin());
    list.erase(list.begin() + 0);

    //loop object list
    for (auto temp : list) {
        //  get no
        string no = temp.substr(0, temp.find('\t'));
        temp.erase(0, temp.find(no) + temp.find('\t') + 1);
        //get nrp
        string nrp = temp.substr(0, temp.find('\t'));
        temp.erase(0, temp.find(nrp) + temp.find('\t') + 1);
        //get name
        string name = temp.substr(0, temp.find('\t'));
        temp.erase(0, temp.find(name) + temp.find('\t') + 1);
        // get gender
        string gender = temp.substr(0, temp.find('\t'));

        //copy data to object mahasiswa
        Mahasiswa mahasiswa = Mahasiswa(atoi(no.c_str()), nrp, name, gender);

        //add data to array list
        listMahasiswa.push_back(mahasiswa);

    }

    //write data to csv
    for (auto& i : listMahasiswa) {
        stream << i.no << ", " << i.nrp << ", " << i.name << ", " << i.gender << endl;
        cout << i.no << ", " << i.nrp << ", " << i.name << ", " << i.gender << endl;
    }

    stream.close(); // close file
}

void readDataCSV() {
    string data; // variable untuk menyimpan data sementara dari txt
    vector<Mahasiswa> listMahasiswa; // array dinamis untuk menyimpan data mahasiswa
    vector<string> list; // array dinamis menyimpan data dari variable data

    ofstream write; //read file
    ifstream read;
    read.open("4210191018_MDFebrian.csv"); //open file txt
    write.open("4210191018_MDFebrian.csv", ios::app);
    if (read.is_open()) {  // kondisi jika file txt berhasil dibuka
        while (!read.eof()) {
            getline(read, data); // ambil semua data dari txt dan simpan dalam variable data
            list.push_back(data); // simpan data ke dalam array dinamis
        }
    }
    else {
        cout << "Data Not Found"; //kondisi jika file tidak berhasil dibuka
    }
    int i = 0;
    for (auto temp : list) {
        //  get no
        string no = temp.substr(0, temp.find(','));
        temp.erase(0, temp.find(no) + temp.find(',') + 1);
        //get nrp
        string nrp = temp.substr(0, temp.find(','));
        temp.erase(0, temp.find(nrp) + temp.find(',') + 1);
        //get name
        string name = temp.substr(0, temp.find(','));
        temp.erase(0, temp.find(name) + temp.find(',') + 1);
        // get gender
        string gender = temp.substr(0, temp.find(','));

        //copy data to object mahasiswa

        //copy data to object mahasiswa
        Mahasiswa mahasiswa = Mahasiswa(atoi(no.c_str()), nrp, name, gender);

        if (i == 27) {
            break;
        }

        //add data to array
        listMahasiswa.push_back(mahasiswa);
        i++;
    }

    //reserve data
    vector<Mahasiswa> temp;
    int j = 0;
    for (int i = listMahasiswa.size() - 1; i >= 0; i--) {
        Mahasiswa mahasiswa;
        mahasiswa.no = (j + 1) + listMahasiswa.size();
        mahasiswa.nrp = listMahasiswa[i].nrp;
        mahasiswa.name = listMahasiswa[i].name;
        mahasiswa.gender = listMahasiswa[i].gender;
        temp.push_back(mahasiswa);

        j++;
    }

    //write data to csv
    for (auto &i : temp) {
        write << i.no << "," << i.nrp << "," << i.name << "," << i.gender << endl;
        cout << i.no << "," << i.nrp << "," << i.name << "," << i.gender << endl;
    }
    read.close(); //close file
    write.close(); //close file
}

int main() {
    createDataCSV();
    cout << endl;
    readDataCSV();
    system("pause");
    return 0;
}
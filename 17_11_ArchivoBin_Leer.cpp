#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void escribir();
void leer();

struct Registro{
    char nombre[20];
    char apellido[20];
};

int main(){
    escribir();
    leer();

    system("pause");
    return 0;
}

void escribir(){
    ofstream archivoBin;

    archivoBin.open("Archivo_Binario.dat", ios::out | ios::binary);

    if(archivoBin.fail()){
        cout<<"Error, no se puede crear el archivo";
        exit(1);
    }

    Registro persona;
    cout<<"Pidiendo datos: "<<endl;
    cout<<"Digite un nombre: "; cin.getline(persona.nombre, 20, '\n');
    cout<<"Digite un apellido: "; cin.getline(persona.apellido, 20, '\n');

    //Escribirmos en el archivo Binario
    archivoBin.write((char *)&persona, sizeof(Registro));

    archivoBin.close();
}

void leer(){
    ifstream archivoBin;

    archivoBin.open("Archivo_Binario.dat", ios::in | ios::binary);

    if(archivoBin.fail()){
        cout<<"Error, no se pudo abrir el archivo";
        exit(1);
    }

    //Leemos el archivo binario
    Registro persona;
    archivoBin.read((char *)&persona, sizeof(Registro));

    cout<<"\n\tMostrando los datos leidos: "<<endl;
    cout<<"Nombre: "<<persona.nombre<<endl;
    cout<<"Apellido: "<<persona.apellido<<endl;

    archivoBin.close();
}
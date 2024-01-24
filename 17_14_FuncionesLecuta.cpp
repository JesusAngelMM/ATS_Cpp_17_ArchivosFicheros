#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void escribir();
void leer();

int main(){
    escribir();
    leer();
    system("pause");
    return 0;
}

void escribir(){
    ofstream archivo;
    archivo.open("Posicion.txt", ios::out);
    if(archivo.fail()){
        cout<<"Error, no se pudo crear el archivo";
        exit(1);
    }
    cout<<"Posicion actual: "<<archivo.tellp()<<endl;
    archivo<<"Hola que tal... ";
    //archivo.seekp(5);
    archivo<<"como estas?";
    archivo.close();
}
void leer(){
    ifstream archivo;
    archivo.open("Posicion.txt", ios::in);
    if(archivo.fail()){
        cout<<"Error, no se pudo crear el archivo";
        exit(1);
    }
    string linea;
    archivo.seekg(5);
    cout<<"\nPosicion actual: "<<archivo.tellg()<<endl;
    getline(archivo, linea);
    cout<<linea<<endl;
    archivo.close();
}
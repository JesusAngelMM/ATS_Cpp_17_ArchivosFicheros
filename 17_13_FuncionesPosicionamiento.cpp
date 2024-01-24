#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void escribir();

int main(){
    escribir();
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
    archivo.seekp(5);
    archivo<<"como estas?";
    archivo.close();
}
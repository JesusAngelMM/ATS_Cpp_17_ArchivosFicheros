#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void lectura();

int main(){

    lectura();

    system("pause");
    return 0;
}

void lectura(){
    ifstream archivo;
    string nombre_Archivo, texto;

    cout<<"Digite el nombre o la ubicacion del archivo o fichero: ";
    getline(cin, nombre_Archivo);

    archivo.open(nombre_Archivo.c_str(), ios::in);  //Abrimos el archivo en modo lectura

    if(archivo.fail()){
        cout<<"Error, no se pudo leer el archivo";
        exit(1);
    }

    while(!archivo.eof()){
        getline(archivo, texto);
        cout<<texto<<endl;
    }

    archivo.close();  //Cerramos el archivo
}
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
    string nombre_Archivo, frase;
    cout<<"Digite el nombre del archivo: "; 
    getline(cin, nombre_Archivo);

    archivo.open(nombre_Archivo.c_str(), ios::out);  //Abriendo el archivo.
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);  //Salir del programa
    }
    cout<<"\nDigite el texto del archivo: ";
    getline(cin, frase);

    archivo<<frase;
    
    archivo.close();  //Cerrar el archivo
}
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void escribirFrase();

int main(){

    escribirFrase();

    system("pause");
    return 0;
}

void escribirFrase(){
    ofstream archivo;
    string nombre_Archivo, frase;
    char res;

    cout<<"Digite el nombre del archivo: "; 
    getline(cin, nombre_Archivo);

    archivo.open(nombre_Archivo.c_str(), ios::out);  //Abriendo el archivo

    if(archivo.fail()){
        cout<<"Error, no se pudo abrir el archivo"<<endl;
        exit(1);
    }

    do{
        fflush(stdin);  //Limpiamos el buffer
        cout<<"Digite una frase: ";
        getline(cin, frase);
        archivo<<frase<<endl;

        cout<<"Desea agregar otra frase (S/n): "; cin>>res;
    }while(res == 'S' || res == 's');

    archivo.close();  //Cerrar el archivo.
}
/*
## 17.12 Ejercicio 5 - Pulsaciones de un atleta
Crear un archivo binario donde almacenar un Registro que contenga las pulsaciones de un atleta en una determinada hora, el programa debe tener un menú con las siguientes opciones:
1. Comenzar a digitar las pulsaciones.
2. Añadir mas pulsaciones.
3. Mostrar las pulsaciones registradas.
4. Salir
*/

#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void menu();
void escribirPulsacion();
void aniadirPulsacion();
void mostrarPulsacion();

struct Registro{
    float hora;
    int pulsaciones;
};


int main(){

    menu();

    system("pause");
    return 0;
}

void menu(){
    int opcion;

    do{
        cout<<"\t.:MENU:."<<endl;
        cout<<"1. Comenzar a digitar las pulsaciones."<<endl;
        cout<<"2. Aniadir mas pulsaciones."<<endl;
        cout<<"3. Mostrar las pulsaciones registradas."<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Digite una opcion: "; cin>>opcion;

        switch (opcion){
        case 1: escribirPulsacion();
            break;
        case 2: aniadirPulsacion();
            break;
        case 3: mostrarPulsacion();
            break;
        case 4:
            break;
        default:
                cout<<"Se equivoco de opcion de menu..."<<endl;
            break;
        }
        system("pause");
        system("cls");
    }while(opcion != 4);
}

void escribirPulsacion(){
    ofstream archivo_Binario;

    archivo_Binario.open("Pulsaciones.dat", ios::out | ios::binary);

    if(archivo_Binario.fail()){
        cout<<"Error, no se puede crear el archivo";
        exit(1);
    }

    Registro pulso;
    cout<<"\nDigite la hora [Hr.Min]: "; cin>>pulso.hora;
    cout<<"Digite la cantidad de pulsaciones: "; cin>>pulso.pulsaciones;

    archivo_Binario.write((char *)&pulso, sizeof(Registro));
    archivo_Binario.close();
}
void aniadirPulsacion(){
    ofstream archivo_Binario;

    archivo_Binario.open("Pulsaciones.dat", ios::app | ios::binary);

    if(archivo_Binario.fail()){
        cout<<"Error, no se puede crear el archivo";
        exit(1);
    }

    Registro pulso;
    cout<<"\nDigite la hora [Hr.Min]: "; cin>>pulso.hora;
    cout<<"Digite la cantidad de pulsaciones: "; cin>>pulso.pulsaciones;

    archivo_Binario.write((char *)&pulso, sizeof(Registro));
    archivo_Binario.close();
}
void mostrarPulsacion(){
    ifstream archivo_Binario;

    archivo_Binario.open("Pulsaciones.dat", ios::in | ios::binary);

    if(archivo_Binario.fail()){
        cout<<"Error, no se puede crear el archivo";
        exit(1);
    }

    cout<<"\nImprimiendo datos registrados: "<<endl;
    cout<<"........................................\n\n";

    Registro pulso;
    while(!archivo_Binario.eof()){
        archivo_Binario.read((char *)&pulso, sizeof(Registro));
        if(!archivo_Binario.eof()){
            cout<<"Hora [Hr.Min]: "<<pulso.hora<<endl;
            cout<<"Pulsaciones: "<<pulso.pulsaciones<<endl<<endl;
        }
    }
    archivo_Binario.close();
}
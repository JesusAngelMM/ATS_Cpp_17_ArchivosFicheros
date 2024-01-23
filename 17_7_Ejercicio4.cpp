#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

struct Datos{
    string nombre, apellido, telefono;
}datos;

void menu();
void crear_Contacto();
void agregar_Contacto();

int main(){

    menu();

    return 0;
}

void menu(){
    int opcion;
    do{
        cout<<"\tMENU"<<endl;
        cout<<"0. Salir del programa."<<endl;
        cout<<"1. Crear (nombre, apellidos, telefono)."<<endl;
        cout<<"2. Agregar mas contactos (nombre, apellidos, telefono)."<<endl;
        cout<<"3. Visualizar contactos existentes."<<endl;
        cout<<"Digite su opcion: "; 
        cin>>opcion;

        switch (opcion){
        case 1:
            crear_Contacto();
            cout<<"\n";
            system("pause");
            break;
        case 2:
            agregar_Contacto();
            cout<<"\n";
            system("pause");
            break;
        
        default:
            break;
        }
        system("cls");
    }while(opcion != 0);
}

void crear_Contacto(){
    ofstream archivo;
    char respuesta;

    archivo.open("AgendaTelefonica.txt", ios::out);

    if(archivo.fail()){
        cout<<"Error, no se pudo crear el archivo :/";
        exit(1);
    }
    archivo<<"\tAgenda Telefonica"<<endl;

    do{
        fflush(stdin);
        cout<<"Digite su nombre: "; getline(cin, datos.nombre);
        cout<<"Digite su apellido: "; getline(cin, datos.apellido);
        cout<<"Digite su telefono: "; getline(cin, datos.telefono);

        archivo<<"Nombre: "<<datos.nombre<<endl;
        archivo<<"Apellido: "<<datos.apellido<<endl;
        archivo<<"Telefono: "<<datos.telefono<<endl<<endl;

        cout<<"Desea agregar otro contacto (S/n): "; cin>>respuesta;
    }while (respuesta == 'S' || respuesta == 's');
    
    archivo.close();
}
void agregar_Contacto(){
    ofstream archivo;
    char respuesta;

    archivo.open("AgendaTelefonica.txt", ios::app);

    if(archivo.fail()){
        cout<<"Error, no se pudo abrir el archivo";
        exit(1);
    }

    do{
        fflush(stdin);
        cout<<"\nDigite su nombre: "; getline(cin, datos.nombre);
        cout<<"Digite su apellido: "; getline(cin, datos.apellido);
        cout<<"Digite su telefono: "; getline(cin, datos.telefono);

        archivo<<"Nombre: "<<datos.nombre<<endl;
        archivo<<"Apellido: "<<datos.apellido<<endl;
        archivo<<"Telefono: "<<datos.telefono<<endl<<endl;

        cout<<"Desea agregar otro contacto (S/n): "; cin>>respuesta;
    }while (respuesta == 'S' || respuesta == 's');

    archivo.close();
}
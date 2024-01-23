#include<iostream>
#include<fstream>
using namespace std;

void aniadir();

int main() {
    aniadir();  // Llamamos directamente a la función aniadir

    system("pause");
    return 0;
}

void aniadir() {
    ofstream archivo;
    string text;

    archivo.open("prueba.txt", ios::app);  // Abrimos el archivo en modo añadir

    if (archivo.fail()) {
        cout << "Error, no se pudo abrir el archivo";
        exit(1);
    }

    cout<<"Digite el texto que quere agregar: "; getline(cin, text);
    archivo <<text;  // Añadimos texto

    archivo.close();
}

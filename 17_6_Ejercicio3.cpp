#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void insert();

int main(){

    insert();

    system("pause");
    return 0;
}

void insert(){
    ofstream file;
    string name_File, text;
    char op;

    cout<<"Name file: ";
    getline(cin, name_File);

    file.open(name_File.c_str(), ios::app);

    if(file.fail()){
        cout<<"Fall, the file don't exist";
        exit(1);
    }

    do{
        fflush(stdin);
        cout<<"\nInstert the text: ";
        getline(cin, text);

        file<<text<<endl;

        cout<<"\n\tContinue (Y/n): ";
        cin>>op;
    }while(op == 'Y' || op == 'y');

    file.close();
}
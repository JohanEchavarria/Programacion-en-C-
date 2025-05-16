#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

void borrar(char a[]){
    for(int i=0; i<11;i++){
        if (a[i] == '\n')
            a[i] = '\0';
    }
}

void extraer(char b[]){
    int v[10], num, limite;

   limite = strlen(b);

   if(limite != 10)
    cout << "Cedula No Valida";

   if(limite == 10){

    for(int i=0;i<10;i++){
           num = b[i]-48;
           v[i] = num; }

//VALIDACION CEDULA PROCESO

    int vec[10], suma, ultimo, ultimon;
    if (v[0] == 1|| v[0] == 2){
        if (v[2] > 0 && v[2] < 6 ){

            for (int i=0; i<9; i+=2){
                vec[i] = v[i] *2;
                if (vec[i] >= 10)
                    vec[i] -= 9;
            }

            for (int i=1; i<9; i+=2){
                vec[i] = v[i];

            }

            suma=0;
            for(int i=0; i<10; i++){
                suma = suma + vec[i];
            }

            if (suma == 10)
                ultimo = 0;
            else if(suma >10 && suma<20)
                ultimo = 20;
            else if(suma >20 && suma<30)
                ultimo = 30;
            else if(suma >30 && suma<40)
                ultimo = 40;
            else cout << "Cedula Incorrecta";


            ultimon = ultimo - suma;

            if (ultimon == v[9])
                cout << "Cedula VERIFICADA";
            else
                cout << "Cedula NO VERIFICADA";


            }

            else
                cout << "Cedula incorrecta";

    }
}
}


int main(){
    char cedula[11],op;

    do{
        cout << "Ingrese numero de cedula: ";
        fgets(cedula,11,stdin);


        borrar(cedula);
        extraer(cedula);

        cout << endl;
        cout << endl;

        cout << "Desea ingresar otro numero? (S/N)";
        fflush(stdin);
        op = getch();

        cout <<endl;

    } while (op == 'S' || op == 's');

    system("pause");
    return 0;
}

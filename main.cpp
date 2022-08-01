/****************************************************
* Jorge Caraballo                            		*
* V-30.366.057                                   	*
* ESTRUCTURA DE DATOS                               *
* SECCIÓN 01                                        *
* PRACTICA #2, 'Listas, Pilas y Colas'.				*
****************************************************/

// Librerias Incluidas
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "List/List.hpp"

using namespace std;

//Nombre del archivo a leer
const string FILE_NAME = "doc.txt";

//Declaracion de funciones
void readFile(List&); //Lee el archivo y registra los procesos en la lista
int sleep(const float); //Auxiliar para la simulacion del reloj
void menu(char&); //Menu para insertar o eliminar algun proceso
bool addProcess(List&); //Agrega un proceso adicional a la lista
bool removeProcess(List&); //Elimina un proceso de la lista, debe indicar el nombre del proceso

// Funcion Main
int main()
{
    List l; //Lista para almacenar los procesos
    int time = 0; //Tiempo transcurrido
    int seconds; //Tiempo de ejecucion del programa
    char opc = '\0'; //Opcion del usuario
    bool flag = false; //Indica si se completo un proceso

    //Solicitamos el tiempo de ejecucion del programa
    cout << "Tiempo de ejecucion (sg): ";
    cin >> seconds;

    //Leemos los procesos del archivo
    readFile(l);

    //Mientra la lista no este vacia y no se haya cumplido el tiempo
    while(!l.empty() and time < seconds)
    {
        //Mostramos los procesos y la informacion
        l.print();
        cout << "\tTiempo transcurrido: " << time << " sg" << endl; 
        cout << "\tTiempo restante: " << seconds-time << " sg" << endl;
        
        //Contamos el segundo transcurrido
        time += sleep(.2);
        
        //Si en el segundo anterior se elimino un proceso...
        if(flag)
        {
            //Mostramos el menu y ejecutamos segun la opcion del usuario
            menu(opc);
            if(opc == '1') addProcess(l);
            if(opc == '2') removeProcess(l);
        }

        //Decrementamos el tiempo de la lista
        flag = l.countTime();
    }

    //Mostramos la informacion al finalizar el programa
    l.print();
    cout << "\tTiempo transcurrido: " << time << " sg" << endl; 
    cout << "\tTiempo restante: " << seconds-time << " sg" << endl;

    return 0;
}


//Lee el archivo de procesos
void readFile(List& l)
{
    ifstream file; //Entrada del archivo
    string name; //Nombre del proceso
    int time; //Tiempo del proceso

    //Abrimos el archivo
    file.open(FILE_NAME);

    //Mientras no sea el final del archivo...
    while(!file.eof())
    {
        //Leemos el nombre y el tiempo del proceso
        file >> name;
        file >> time;

        //Agregamos el proceso a la lista
        l.push(name,time);
    }

    //Cerramos el archivo
    file.close();
}


//Auxiliar del tiempo, retrasa 'n' segundos
int sleep(const float seconds)
{
    //Referencia del momento
    clock_t start = clock();

    //Mientras no hayan pasado 'n' segundos, retrasamos el programa
    while(clock() < (start + (seconds * CLOCKS_PER_SEC)));
    return 1;
}

//Menu
void menu(char& opc)
{
    //Motramos el menu y solicitamos la opcion a ejecutar
    cout << "\n\n\t---Ingrese una opcion---" << endl;
    cout << "\t[1] Agregar un proceso" << endl;
    cout << "\t[2] Borrar un proceso" << endl;
    cout << "\t[0] Continuar" << endl;
    cout << "\tOPC [ ]\b\b";
    cin >> opc;
    fflush(stdin);
}

//Agrega un proceso a la lista
bool addProcess(List& l)
{
    string name; //Nombre del proceso
    int time; //Tiempo del proceso

    //Solicitamos el nombre del proceso
    cout << "\tProcess name: ";
    cin >> name; 
    //Solicitamos el tiempo del proceso
    cout << "\n\tProcess Time: ";
    cin >> time; 

    //Agregamos el proceso a la lista
    return l.push(name,time);
}

//Elimina un proceso de la lista
bool removeProcess(List& l)
{
    string name;//Nombre del proceso a eliminar

    //Solicitamos el proceso a eliminar
    cout << "Type the name of process to delete: ";
    cin >> name;

    //Eliminamos el proceso
    return l.pop(name);
}

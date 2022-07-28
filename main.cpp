/****************************************************
* Henry Manuel Navarro                         		*
* V-28.031.608                                   	*
* ESTRUCTURA DE DATOS                               *
* SECCIÓN 01                                        *
* PRACTICA #2, 'Listas, Pilas y Colas'.				*
****************************************************/

// Librerias Incluidas
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "List/List.hpp"

using namespace std;

void readFile(List&);

// Funcion Main
int main()
{
    List l;
    readFile(l);

    l.print();

    return 0;
}

void readFile(List& l)
{
    ifstream file;
    string name;
    int time;

    file.open("doc.txt");
    while(!file.eof())
    {
        file >> name;
        file >> time;
        l.push(name,time);
    }
    file.close();
}


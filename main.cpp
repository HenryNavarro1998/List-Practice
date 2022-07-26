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
#include "List/List.hpp"

using namespace std;

// Funcion Main
int main()
{
    List l;

    l.push("pro1",10);
    l.push("pro2",15);
    l.push("pro3",12);
    l.push("pro4",18);
    l.push("pro5",25);
    l.push("pro6",20);

    l.print();

    return 0;
}
#ifndef List_hpp
#define List_hpp

//Librerias importadas
#include <iostream>
#include <cstdlib>

using namespace std;

//Estructura de un Nodo (Proceso)
struct Node
{
    string name; //Nombre del Proceso
    int time; //Tiempo del Proceso
    Node* next; //Apuntador al siguiente Proceso

    //Constructor de un Nodo (Proceso)
    Node(const string& name="", const int time=0, Node* next=NULL):
        name(name), time(time), next(next){};
};

//Clase Lista (Lista Delta)
class List
{
    //Atributos
    private:
        Node *first, *last; //Apuntadores Cabeza (Primero) y Cola (Ultimo)
        int length; //Longitud de la Lista
        int completed; //Procesos Completados

    //Metodos        
    public:
        List(): first(NULL), last(NULL), length(0), completed(0){}; //Constructor
        ~List() { while(pop()); }; //Destructor

        bool empty() const { return first == NULL; }; //Lista Vacia, retornar true si la lista esta vacia
        bool push(const string, const int); //Inserta un elemento en la lista
        bool pop(); //Elimina la cabeza de la lista
        bool pop(const string&); //Elimina un Proceso de la Lista 
        bool countTime(); //Decrementa el tiempo de la Lista, si es necesario, llama a pop()
        void print() const; //Muestra la Lista
};

#endif
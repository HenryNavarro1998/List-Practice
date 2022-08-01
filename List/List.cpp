#include "List.hpp"

//Inserta un elemento en la Lista
bool List::push(const string name, int time)
{
    Node* node = new Node(name,time); //Nuevo proceso a insertar
    Node* iter = first; //Iterador, recorre la lista en busqueda de la posicion del nuevo proceso
    Node* prev = NULL; //Auxiliar, apunta un proceso antes del elemento a insertar

    //Mientras no sea el final de la lista y no se encuentre la posicion del elemento
    while(iter && node->time >= iter->time)
    {
        node->time -= iter->time; //Decrementamos el tiempo del proceso
        prev = iter; //Movemos prev a la posicion de iter
        iter = iter->next; //Movemos iter al siguiente elemento
    }

    //Enlazamos el Proceso a la lista
    node->next = iter;

    //Si existe iter...
    if(iter)
        iter->time -= node->time; //Decrementamos el tiempo de iter

    //Enlazamos el nodo a su elemento predecesor, en caso de no haber, lo hacemos cabeza de la lista
    if(prev)
        prev->next = node;
    else
        first = node;

    //Incrementamos la longitud
    length++;
    return true;
}

//Elimina la cabeza de la Lista
bool List::pop()
{
    //Si la lista esta vacia, retornamos falso
    if(empty())
        return false;

    //Auxiliar a eliminar
    Node* aux = first;

    first = first->next; //Movemos la cabeza de la lista
    delete aux; //Eliminamos el auxiliar

    //Decrementamos la longitud de la lista
    length--;
    return true;
}

//ELimina un Proceso segun el nombre
bool List::pop(const string& name)
{
    Node* iter = first; //Iterador
    Node* prev = NULL; //Apuntador previo
    bool flag = false; //Bandera

    //Buscamos el proceso a eliminar
    while(iter and iter->name != name)
    {
        prev = iter;
        iter = iter->next;
    }

    //Si lo encontramos
    if(iter){

        //Si no es el primero elemento,
        if(prev){
            prev->next = iter->next; //Desenlazamos el elemento a eliminar
             
             //Si el Proceso a borrar, no es el ultimo de la lista...
             if(iter->next) 
                iter->next->time += iter->time; //Ajustamos el tiempo del siguiente elemento
        
        }else{ //Sino,
            
            //Movemos la cabeza de la lista
            first = first->next;

            //Si existe el elemento, ajustamos el tiempo
            if(first)
                first->time += iter->time;
        }
        
        //Reducimos la longitud de la lista
        length--;
        flag = true;
    }

    return flag;
}

//Decrementa el tiempo de un proceso
bool List::countTime()
{
    //Bandera para indicar si fue completado un proceso
    bool flag = false;
    
    //Si existe la cabeza de la lista
    if(first)
        first->time--;  //Decrementamos el tiempo
    
    //Mientras exista la cabeza y su tiempo sea menor o igual a "0"
    while(first && first->time <= 0)
    {
        completed++; //Marcamos el proceso completado
        pop(); //Eliminamos la cabeza de la lista
        flag = true; //Actualizamos la bandera
    }
    
    return flag;
}


//Muestra la lista
void List::print() const
{
    system("cls || clear");
    for(Node* i = first; i; i = i->next)
        cout << "\t" << i->name << "\t" << i->time << endl;
    cout << endl;
    cout << "\n\tProcesos Completados: " << completed << endl;
    cout << "\tProcesos Restantes: " << length << endl;
}
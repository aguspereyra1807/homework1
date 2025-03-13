#include <memory>
#include <iostream>

using namespace std;

struct Node {
    unique_ptr<int> value;
    shared_ptr<Node> next;
};

struct List {
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    size_t size;
};

// i. Devuelve un nodo.
shared_ptr<Node> create_node(int value);

// ii. Inserta un nodo al frente de la lista.
void push_front(unique_ptr<List> &list, int value);

// iii. Inserta un nodo al final de la lista.
void push_back(unique_ptr<List> &list, int value);

// iv. Inserta un nodo en la posición que se le pase a la función. 
//     Si se le pasa una posición mayor al largo de la lista, se debe indicar lo ocurrido y se debe de agregar el nodo al final de la lista.
void insert(unique_ptr<List> &list, int value, size_t pos);

// v. Borra un nodo en la posición que se le pase a la función. 
//    Similar a la función insert(), si la posición es mayor que el largo de la lista, se debe de borrar el último nodo.
void erase(unique_ptr<List> &list, size_t pos);

// vi. Imprime la lista completa, separando el valor en cada nodo con “->”
void print_list(unique_ptr<List> &list);

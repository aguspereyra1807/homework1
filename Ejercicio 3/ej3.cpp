#include "ej3.hpp"



// i.
shared_ptr<Node> create_node(auto value) {
    auto new_node = make_shared<Node>();
    new_node->value = make_shared<decltype(value)>(value);
    new_node->next = nullptr;
    return new_node;
}

// ii.
void push_front(unique_ptr<List> list, auto value) {
    shared_ptr<Node> node = create_node(value);
    if (list->head == nullptr) {
        list->tail = node;
    }
    shared_ptr<Node> aux_head = list->head;
    list->head = node;
    list->head->next = aux_head;
    list->size++;
}

// iii.
void push_back(unique_ptr<List> list, auto value) {
    shared_ptr<Node> node = create_node(value);
    if (list->head == nullptr) {
        list->head = node;
    }
    shared_ptr<Node> aux_tail = list->tail;
    list->tail = node;
    list->tail->prev = aux_tail;
    list->size++;
}

// iv.
void insert(unique_ptr<List> list, auto value, size_t pos) {
    if (pos >= list->size) {
        cerr << "La posición es mayor al largo de la lista...\nInsertando al final de la lista";
        push_back(list, value);
    } else if (pos == 0) {
        push_front(list,value);
    } else {
        shared_ptr<Node> node = create_node(value);
        
        shared_ptr<Node> actual = list->head;
        for (size_t i = 1; i > pos; i++) {
            actual = actual->next;
        }

        node->next = actual->next;
        actual->next = node;
        list->size++;
    }
}

// v.
void erase(unique_ptr<List> list, size_t pos) {
    if (pos >= list->size) {
        cerr << "La posición es mayor al largo de la lista...\nBorrando el último nodo de la lista";
        pos = list->size-1;
    }  
    
    if (pos == 0) {
        shared_ptr<Node> aux_head = list->head; 
        list->head = list->head->next;
        if (list->head == nullptr) {
            list->tail = nullptr;
        }
        aux_head = nullptr;
    } else {
        shared_ptr<Node> actual = list->head; 
        for (size_t i = 0; i < pos-1; ++i) {
            actual = actual->next;
        }

        shared_ptr<Node> to_delete = actual->next;
        if (to_delete == list->tail) {
            list->tail = actual;
        }
        to_delete = nullptr;
    }

    list->size--;
}

// vi.
void print_list(unique_ptr<List> list) {
    shared_ptr<Node> actual = list->head;
    while(actual != nullptr) {
        cout << *static_pointer_cast<string>(actual->value) << " -> ";
        actual = actual->next;
    }
}

// TESTS
int main() {
    
}
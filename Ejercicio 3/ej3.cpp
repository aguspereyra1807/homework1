#include "ej3.hpp"

// i.
shared_ptr<Node> create_node(int value) {
    try {
        shared_ptr<Node> new_node = make_shared<Node>();
        new_node->value = make_unique<int>(value);
        new_node->next = nullptr;   
        return new_node;
    } catch(bad_alloc&) {
        throw runtime_error("Memoria insuficiente");
    }
}

// ii.
void push_front(unique_ptr<List> &list, int value) {
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
void push_back(unique_ptr<List> &list, int value) {
    shared_ptr<Node> node = create_node(value);
    if (list->head == nullptr) {
        list->head = node;
    }
    shared_ptr<Node> aux_tail = list->tail;
    aux_tail->next = node;
    list->tail = node;
    list->size++;
}

// iv.
void insert(unique_ptr<List> &list, int value, size_t pos) {
    if (pos >= list->size-1) {
        if (pos >= list->size) cerr << "La posición es mayor al largo de la lista...\nInsertando al final de la lista:" << endl; 
        push_back(list, value);
    } else if (pos == 0) {
        push_front(list,value);
    } else {
        shared_ptr<Node> node = create_node(value);
        
        shared_ptr<Node> actual = list->head;

        for (size_t i = 0; i < pos-1; i++) {
            actual = actual->next; 
        }

        node->next = actual->next;
        actual->next = node;
        list->size++;
    }
}

// v.
void erase(unique_ptr<List> &list, size_t pos) {
    if (pos >= list->size) {
        cerr << "La posición es mayor al largo de la lista...\nBorrando el último nodo de la lista" << endl;
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

        if (actual->next == list->tail) {
            list->tail = actual;
        }
        shared_ptr<Node> to_delete = actual->next;
        
        actual->next = actual->next->next;
        to_delete = nullptr;
    }

    list->size--;
}

// vi.
void print_list(unique_ptr<List> &list) {
    shared_ptr<Node> actual = list->head;
    cout << *(actual->value);
    actual = actual->next;
    while(actual != nullptr) {
        cout << " -> " << *(actual->value);
        actual = actual->next;
    }
    cout << endl;
}

// TESTS
int main() {
    unique_ptr<List> l;
    try {
        l = make_unique<List>();
        l->head = nullptr;
        l->tail = nullptr;
        l->size = 0;
    } catch(bad_alloc&) {
        throw runtime_error("Memoria insuficiente");
        return 1;
    }

    cout << "- Se creó la lista correctamente" << endl;

    cout << "========================\n" << "push_front()" << endl;
    for (int i = 5; i >= 1; --i) {
        push_front(l, i);
        cout << "- Se insertó al inicio el elemento " << i << endl;
    }
    cout << "- Lista: ";
    print_list(l);

    cout << "========================\n" << "push_back()" << endl;

    for (int i = 6; i < 10; ++i) {
        push_back(l, i);
        cout << "- Se insertó al final el elemento " << i << endl;
    }  
    cout << "- Lista: ";
    print_list(l);

    cout << "========================\n" << "insert()" << endl;

    insert(l,0,0);
    cout << "- Se insertó un '0' en la pos 0" << " | size -> " << (l->size) << endl;
    insert(l,0,l->size-1);
    cout << "- Se insertó un '0' en la pos 'size-1' (" << l->size << ")" << " | size -> " << (l->size) << endl;
    insert(l,0,5);
    cout << "- Se insertó un '0' en la pos 5 "<< " | size -> " << (l->size) << endl;
    insert(l,0,l->size+1);
    cout << "- Se insertó un '0' fuera de la lista (size+1)" <<  " | size -> " << (l->size) << endl;
    

    cout << "- Lista: ";
    print_list(l);

    cout << "========================\n" << "erase()" << endl;

    erase(l,0);
    cout << "- Se eliminó el primer elemento" << " | size -> " << (l->size) << endl;
    print_list(l);
    cout << endl;

    erase(l,l->size-1);
    cout << "- Se eliminó el último elemento" << " | size -> " << (l->size) << endl;
    print_list(l);
    cout << endl;

    erase(l,l->size+1);
    cout << "- Se eliminó un elemento fuera de la lista (size+1)" << " | size -> " << (l->size) << endl;
    print_list(l);
    cout << endl;

    erase(l,4);
    cout << "- Se eliminó el elemento i=4" << " | size -> " << (l->size) << endl;
    print_list(l);
    cout << endl;

    return 0;
}
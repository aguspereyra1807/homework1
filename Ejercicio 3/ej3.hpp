#include <memory>
#include <iostream>

using namespace std;

typedef struct node {
    unique_ptr<void> value;
    shared_ptr<Node> next;
} Node;

typedef struct list {
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    size_t size;
} List;


unique_ptr<Node> create_node(auto value);
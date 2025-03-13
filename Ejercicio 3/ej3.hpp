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
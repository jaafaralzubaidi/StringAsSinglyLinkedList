
#include <iostream>

class Node{
public:
    char data;
    Node * next;

    Node(char c =0, Node *n=NULL) : data(c), next(n) {}

};
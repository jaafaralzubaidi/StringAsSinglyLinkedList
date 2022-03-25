#include "SLLString.h"
#include <iostream>

using namespace std;

SLLString::SLLString() : head(NULL) {}
    
    
SLLString::SLLString(const string &other) : head(NULL){
    for(int i = 0; i < other.size(); i++){
        char temp =  other[i];
        appendNode(temp);
    }  
} 


SLLString::~SLLString(){
    destroy();
}


SLLString::SLLString(const SLLString &other) {
    head = new Node(NULL, NULL);
    *this = other;
}


SLLString& SLLString::operator=(const SLLString &other){
    if(this != &other){  // different addresses
        if(!isEmpty())
            destroy(); // head is NULL

        Node *temp = NULL;  
        Node *otherPtr = other.head;

        while(otherPtr){
            if(head == NULL){
                // address of new node is assigned to temp and head
                temp = new Node(otherPtr->data); 
                head = temp;
            }else{
                // make a new node and pass the address to temp->next
                temp->next = new Node (otherPtr->data);
                temp = temp->next; 
            }

        otherPtr = otherPtr->next; 
        }
        
    }
    return *this;
}


SLLString& SLLString::operator+= (const SLLString& other){
    Node *otherPtr = other.head;
    Node *temp = NULL;
    while(otherPtr){
        temp = new Node(otherPtr->data, NULL);
        appendNode(temp->data);
        otherPtr = otherPtr->next;
    }
    return *this;
}


ostream& operator<<(ostream &os, SLLString &list){
    Node *ptr = list.head;
    while(ptr){
        os << ptr->data;
        ptr = ptr->next;
    }
    return os;
}


char& SLLString::operator[](const int index){
    
    int size = length();
    Node *ptr = head;
    
    if(index >= size || index < 0){
        cout << "Index out of bound" << endl;
        exit(0);
    }
    for(int i = 0; i < index ; i++)
        ptr = ptr->next;   

    return ptr->data;
}


int SLLString::length() const{
    if(isEmpty())
        return 0;
    
    int count = 0;
    Node *ptr = head;
    while(ptr){
        count++;
        ptr = ptr->next;
    }
    return count;
}


void SLLString::erase(char key){
    Node *ptr = head;
    Node *keyPtr = head; // will point to the node with the key
    Node *prevPtr = NULL; // Will pint to the previous node that is pointing to the key
    while(ptr){

        
        while( (keyPtr->data != key) && (keyPtr != ptr) ){
            // prevPtr will point to keyPtr if key is not found otherwise will point to the previous node 
            prevPtr = keyPtr;
            keyPtr = keyPtr->next;
        }

        if(keyPtr->data == key){
            prevPtr->next = keyPtr->next;
            keyPtr = keyPtr->next;
            
        } 
        ptr = ptr->next;
    }
}


SLLString::SLLString(const char *other) : head (NULL) {
        
        while(*other != '\0'){
        char temp =  *other;
        other++;
        appendNode(temp);
    }  
}

 int SLLString::findSubstring(const SLLString& substring){
    Node *ptr = head;
    Node *substringPtr = substring.head;
    int count = -1;
    int size = substring.length();
     
    while(ptr){
        count++;
        if(ptr->data == substringPtr->data){
        
            Node *checkerPtr = ptr;
            
            for(int i = 0; i < size; i++){
                
                if(checkerPtr->data != substringPtr->data)
                    break;
            
                checkerPtr = checkerPtr->next;
                substringPtr = substringPtr->next;

            }
            return count;
        }
        
        ptr = ptr->next;
    }
    return -1;
 }

void SLLString::appendNode(char c){
    if(head == NULL){
        head = new Node(c);
    }
    else{
        Node *ptr = head;
        while(ptr->next)
            ptr = ptr->next;
        
        ptr->next = new Node(c,NULL);
    }
}

bool SLLString::isEmpty() const{
    return head == NULL;
}

void SLLString::print(){
    Node *ptr = head;
    while(ptr){
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout <<"NULL"<< endl;
}

void SLLString::destroy(){
    Node *ptr = head;
    while(ptr){
        ptr = ptr->next;
        delete head;
        head = ptr;
    }
}



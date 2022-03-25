#ifndef SLLSTRING_H
#define SLLSTRING_H

#include <iostream>
#include "Node.h"

using namespace std;

class SLLString{

private:
    Node *head;
    

public:
    SLLString(); //Default constructor

    SLLString(const string& other); //copy constructor taking a C++ string as parameter.
    ~SLLString(); // destructor
    
    SLLString(const SLLString& other); //copy constructor taking another SLLString 
    SLLString& operator=(const SLLString& other); // assignment constructor
    
    
    SLLString& operator+= (const SLLString& other); // concatenation
    friend ostream& operator<<(ostream&, SLLString&);
    char& operator[](const int n); //get character at index n.
    
    int length() const; // get length of this string.
    void erase(char c); //erase all occurrences of character c from the current string.
    SLLString(const char*);
    int findSubstring(const SLLString& substring); // find the index of the first occurrence of substring in the current string. Returns -1 if not found.

    void appendNode(char c);
    bool isEmpty() const;
    void print();
    void destroy();

    
    

};

#endif // !SLLSTRING_H



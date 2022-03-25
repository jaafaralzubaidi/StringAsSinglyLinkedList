#include <iostream>
#include "SLLString.h"

int main(){

    SLLString s;

    SLLString str("Hello world!");
    str.print();
    
    SLLString newStr;
    newStr = str;
 
   
    newStr += SLLString(" CS@BC");
    newStr[6] = 'W';
    
    cout << newStr << endl; // Hello World! CS@BC
    cout << "length: " << newStr.length() << endl; //18
    
    int loc = newStr.findSubstring("World");
    cout << "location: " << loc << endl; // 6
    
    newStr.erase('l'); //erase the letter l.
    cout << newStr << endl; // Heo Word! CS@BC
    
    newStr.erase('C');
    cout << newStr << endl; // Heo Word! S@B
}
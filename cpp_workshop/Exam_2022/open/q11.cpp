//q11

#include <algorithm>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

//with our own List/Link classes (in the back of the test)
//write a method to ge tthe size of the list 

int List::size() const{
    if(isEmpty()){
        return 0;
    }
    int count = 0;
    Link* current = head;
    while(current != nullptr){
        count++;
        current = current->next;
    }
    return count;
}

//now write method to remove all elements in
// the list that match the bool function (as paramater)
void List::removeAll(bool (*func)(int value)){
    //remove first element 
    while(head != nullptr && func(head->value)){ //while elem is valid and matches the bool fn
        removeFirst(); 
    }
    if(isEmpty()){
        return; //nothing left to remove
    }

    Link* current = head;
    Link* previous;
    while(current != nullptr){

        if(func(current->next->value)){
            previous = current->next; 
            current->next = previous->next;
            previous->next = nullptr;
            delete previous; //remove the element
        }
        current = current->next; //move on to next element
    }
}
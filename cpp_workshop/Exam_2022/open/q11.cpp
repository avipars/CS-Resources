//q11

#include <string>
#include <iostream>

#include "List.h" //the provided List class
using namespace std;

//with our own List/Link classes (in the back of the test)
//write a method to ge tthe size of the list 

int List::size() const{ //iterative solution
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

//alternate recursive way to do things
int List::getSize() const //wrapper for function
{
    return getSize(head, 0); //calls inner function
}

int List::getSize(Link *p, int count) const
{
    if (p == nullptr) //checks if it exists
    {
        return count;
    }
    else
    {
        return getSize(p->next, count + 1); //call one node deeper
    }
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

//slightly different variation
void List::removeAll(bool (*func)(int val)){ //wrapper function

    //check if the head is null
    if(isEmpty()){
        return;
    }
    if(func(head->value)){ //start at head and remove as many as possible till we hit something not matching
        removeFirst();
        removeAll(func);
    }
    else{ // no match, keep going
        Link* current = head; //start at new head
        while(current->next != nullptr){
            if(func(current->next->value)){ //next value needs to be removed
                Link* temp = current->next; //save the next value
                current->next = temp->next; //remove the next value
                temp->next = nullptr; //set the next value to null
                delete temp; //delete the next value
            }
            else{
                current = current->next; //no match, move to next value
            }
        }
    }
}
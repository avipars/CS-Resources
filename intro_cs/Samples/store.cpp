/*
    Question1Store.cpp
    This program manages a supermarket "database" using structs for item types, and allows for different actions and queries to be performed.
 */

#include <iostream>
#include <cstring>              //string manipulation function
#include <string>               //string class
#pragma warning(disable : 4996) //disables the warning of strcpy - for moodle

using namespace std;

#define MAX_SIZE 21 //max size of characters in the string - accounting for the null character at the end

enum cases //each possible action
{
    EXIT, ADD, FIND, SOLD, ORDER, PRINT
};

struct Item
{
    int prodCode;        //product code
    char name[MAX_SIZE]; //name of Item - string
    int amount;          //stored amount in inStock
    int minAmount;       //amount needed to order
    double price;        //real number
};

//function prototypes
//non-destructive actions
void print(const Item *store, const int size);
void findPrice(const Item *store, const int numItems);

//destructive actions 
void addItem(Item *store, const int maxSize, int &numItems);
void sold(Item *store, const int numItems);
void order(Item *store, const int numItems);

//additional helper function
int searchForElement(const Item *store, const int numItems, const int code);
int verifyInputInt();
double verifyInputDouble();
void error();

//code from the assignment
int main()
{
    
    int maxItems; 
    cout << "enter max number of items:" << endl;
    maxItems = verifyInputInt(); //we don't want an array with negative or zero size

    Item *store = new Item[maxItems];   //pointer to the array of items - allocate memory for the array

    int numItems = 0; //size of array
    int choice;
    do
    {
        cout << "enter 0-5:" << endl;
        cin >> choice;

        switch (choice)
        {
            case EXIT: //zero - exit
            {
                break;
            }
            case ADD: //1 add item to array
            {
                addItem(store, maxItems, numItems);
                break;
            }
            case FIND: //2 find price of an item
            {
                findPrice(store, numItems);
                break;
            }
            case SOLD: //3 sell item and decrease stock
            {
                sold(store, numItems);
                break;
            }
            case ORDER: //4 order more units and increase stock
            {
                order(store, numItems);
                break;
            }
            case PRINT: //5 show us all the items in store
            {
                print(store, numItems);
                break;
            }
            default:
            {
                cout << "ERROR" << endl; //anything greater than 5 or less than zero
            }
        }
    } while (choice != 0); //keep on looping unless user wants to quit 

    if (store != NULL)  //free memory at end of program
    {
        delete[] store; //as I made a new array of items, i need to delete it 
        store = NULL;
    }
    return 0;
}

//code 1 - add an item to the array, or update if already there
void addItem(Item *store, const int maxSize, int &numItems)
{
    int code;
    cout << "enter code:" << endl;
    cin >> code;

    char name[MAX_SIZE]; //initialize string of 20 characters

    cout << "enter name:" << endl;

    cin.getline(name, MAX_SIZE); //clear the input - accounts for any dangling characters
    cin.getline(name, MAX_SIZE); //if user decides to use spaces, the getline call can deal with that ex: "Model T"

    int position = searchForElement(store, numItems, code); //now check to see if name is identical to the one already in the array

    bool doubleCode = (position != -1); //if position is not -1, then code is already in the array

    bool doubleName = (strcmp(name, (store+position)->name) == 0); //position is known already, now just confirm that name is identical

    int inStock;
    cout << "enter amount:" << endl;
    inStock = verifyInputInt();  //ensure the following inputs are all positive digits

    int toOrder;
    cout << "enter minimum amount:" << endl;
    toOrder = verifyInputInt();

    double cost; //accounts for decimal point in price
    cout << "enter price:" << endl;
    cost = verifyInputDouble();

    if (doubleCode && doubleName) //both match - update existing element
    {
        //update quantities but don't increase the size of array 
        (store + position)->amount += inStock;   //increase amount in stock by new amount
        (store + position)->minAmount = toOrder; //use latest min amount
        (store + position)->price = cost;        //use latest item price
    }
    else if (maxSize == numItems) //there is no room to spare in the array - and the item isn't already in the array (due to the way the if-else statement is set up)
    {
        //this condition needed to be placed above the other ones to avoid overfilling the array - and writing to memory that is not allocated
        error(); //not enough space in array
    }
    else if (doubleCode && !doubleName) //code is same but name is different
    {
        error();  //I elected to split up the different cases for better readability (and to explain why each case gets its prescibed actions)
    }
    else if ((!doubleCode && !doubleName) || (!doubleCode && doubleName)) //no need to add the new item to the array because it exists already
    {
        //add new item to the store 
        (store + numItems)->prodCode = code; //assign the code to the last element of array in addition to the other values
        (store + numItems)->amount = inStock;
        (store + numItems)->minAmount = toOrder;
        (store + numItems)->price = cost;

        //defined name as char array, cannot assign to it directly... so I need to copy each character individually
        strncpy((store + numItems)->name, name, MAX_SIZE); //copy the product name into the item struct - not exceeding 20 characters

        ++numItems; //increment number of items
    }
    else
    {
        error(); //any other case not mentioned above
    }
}

//code 2 - show price based on code
void findPrice(const Item *store, const int numItems)
{
    int code;
    cout << "enter code:" << endl; 
    cin >> code; //get code from user

    int position = searchForElement(store, numItems, code); //get the product code position in the array

    if (position != -1) //item exists
    {
        cout << "price: " << (store + position)->price << endl;  //print price
    }
    else
    {
        error(); //item isn't in the store, print error and exit
    }
}

//code 3 - record a sale and then deduct the amount sold from stock
void sold(Item *store, const int numItems)
{
    int prodCode; 
    cout << "enter code:" << endl;
    cin >> prodCode; //get code and then pull that item related to that code 

    int stock;  //amount in stock
    cout << "enter amount:" << endl;
    stock = verifyInputInt(); //only accept positive numbers - so the store won't go bankrupt

    int position = searchForElement(store, numItems, prodCode); //get the index of product

    if (position == -1)
    {
        error(); //code doesn't exist in array - error and exit 
    }

    //if the store over-sells an item, it should update stock to 0 otherwise deduct the amount sold from the stock
    ((store + position)->amount < stock) ? (store + position)->amount = 0 : (store + position)->amount -= stock;
}

//code 4 - go through all items in array and tell the stock manager to order more if item is low
void order(Item *store, const int numItems)
{
    int index = 0; 
    while (index < numItems) //loop through all items
    {   
        //case where the current stock is less than our pre-set minimum 
        if ((store + index)->amount < (store + index)->minAmount) //find the items needing replenishment - print them
        {
            cout << "item name: " << (store + index)->name << endl; //print the item details - name and code 
            cout << "code: " << (store + index)->prodCode << endl;

            int leftover = 5 + ((store + index)->minAmount - (store + index)->amount); //calculate amount needing to reorder add additional units for safety margin

            cout << "amount to order: " << leftover << endl; //tell store manager to order more of the item lacking in supply

            (store + index)->amount += leftover; //update the new ammount, making the assumption that the stock manager placed the order
        }
        ++index; //move to next element
    }
}

//code 5 - traverse array and print all items with details
void print(const Item *store, const int size)
{
    for (int i = 0; i < size; ++i) //traverse array up to the max size
    {
        cout << "name: " << (store + i)->name << endl; //get name and print it ... same for upcoming items  
        cout << "code: " << (store + i)->prodCode << endl;
        cout << "amount: " << (store + i)->amount << endl;
        cout << "minimum amount: " << (store + i)->minAmount << endl;
        cout << "price: " << (store + i)->price << endl;

        cout << endl; //new line for additional items
    }
}

//ensure that input is positive (for price)
double verifyInputDouble()
{
    bool flag = true;
    double input = -1; //default value
    while (flag) //keep the loop running until input is valid
    {
        cin >> input;
        if (input <= 0)
        {
            cout << "ERROR" << endl; //negative input
        }
        else
        {
            flag = false; //input is valid, leave loop
        }
    }
    return input;
}

//ensure that input is positive for everything else
int verifyInputInt()
{
    bool flag = true; 
    int input = -1; //default value

    while (flag) //keep the loop running until input is valid
    {
        cin >> input;
        if (input <= 0)
        {
            cout << "ERROR" << endl; //negative input
        }
        else
        {
            flag = false; //input is valid, leave loop
        }
    }
    return input;
}

void error() //save some typing and lines of code, in addition to potential error handing in the future - as only would change the error message once
{
    cout << "ERROR" << endl; //error message 
    return;
}

//as the array is unsorted, there is a need to search through every element to find match
//return the index of the item if exists, otherwise -1 
int searchForElement(const Item *store, const int numItems, const int code)
{
    int index = 0; //return the index of the element that matches the code
    while (index < numItems) //loop through all items
    {
        if ((store + index)->prodCode == code) //code is a match! 
        {
            return index; //found the code, can return it and leave the function
        }
        ++index; //move to next element
    }
    return -1; //item not found, return error code
}

/* sample run: 
enter max number of items:
3
enter 0-5:
1
enter code:
100
enter name:
mouse
enter amount:
3
enter minimum amount:
5
enter price:
10.99
enter 0-5:
1
enter code:
101
enter name:
keyboard
enter amount:
20
enter minimum amount:
15
enter price:
14.99
enter 0-5:
1
enter code:
145   
enter name:
monitor
enter amount:
25
enter minimum amount:
36
enter price:
999
enter 0-5:
4
item name: mouse
code: 100
amount to order: 7
item name: monitor
code: 145
amount to order: 16
enter 0-5:
5
name: mouse
code: 100
amount: 10
minimum amount: 5
price: 10.99

name: keyboard
code: 101
amount: 20
minimum amount: 15
price: 14.99

name: monitor
code: 145
amount: 41
minimum amount: 36
price: 999

enter 0-5:
33
ERROR
enter 0-5:
3
enter code:
101
enter amount:
55
enter 0-5:
2
enter code:
101
price: 14.99
enter 0-5:
1
enter code:
123     
enter name:
headphones
enter amount:
34
enter minimum amount:
21
enter price:
25
ERROR
enter 0-5:
5
name: mouse
code: 100
amount: 10
minimum amount: 5
price: 10.99

name: keyboard
code: 101
amount: 0
minimum amount: 15
price: 14.99

name: monitor
code: 145
amount: 41
minimum amount: 36
price: 999

enter 0-5:
1
enter code:
101
enter name:
keyboard
enter amount:
554
enter minimum amount:
52
enter price:
265
enter 0-5:
5
name: mouse
code: 100
amount: 10
minimum amount: 5
price: 10.99

name: keyboard
code: 101
amount: 554
minimum amount: 52
price: 265

name: monitor
code: 145
amount: 41
minimum amount: 36
price: 999

enter 0-5:
0
enter max number of items:
-52
ERROR
2
enter 0-5:
1
enter code:
150
enter name:
fdf
enter amount:
-5
ERROR
2
enter minimum amount:
-65
ERROR
4
enter price:
-5
ERROR
55
enter 0-5:
5
name: fdf
code: 150
amount: 2
minimum amount: 4
price: 55

enter 0-5:
0
*/
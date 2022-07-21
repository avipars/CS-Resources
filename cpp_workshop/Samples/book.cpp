//File operations - via a library 

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Book
{
    char name[10];
    char author[10];
    int quantity;
    float price;
};

void addBook() //add book to collection
{
    Book b;
    ofstream myfile;

    myfile.open("library.dat", ios::out | ios::binary | ios::app);
    if (!myfile)
    {
        throw "Error opening file for writing";
    }
    cout << "Enter the name of the book: ";
    cin >> b.name;
    cout << "Enter the author of the book: ";
    cin >> b.author;
    cout << "Enter the quantity of the book: ";
    cin >> b.quantity;
    cout << "Enter the price of the book: ";
    cin >> b.price;
    myfile.write((char *)&b, sizeof(Book));
    myfile.close();
}

void readFile() //print catalog
{
    Book book;

    ifstream input("library.dat");
    if (!input)
    {
        throw "Error opening file for reading";
    }
    input.read((char *)&book, sizeof(Book));

    int i = 0;
    cout << "Title"
         << "\t"
         << "Author"
         << "\t"
         << "Price"
         << "\t"
         << "Quantity" << endl;
    while (!input.eof())
    {
        if (book.author[0] != '\0')
        // input.seekg(i++ * sizeof(Book)); // go to the start of the file
        {
            cout << book.name << "\t" << book.author << "\t " << book.price << "\t"
                 << book.quantity << endl;
        }
        input.read((char *)&book, sizeof(Book));
    }

    input.close();
}

void remove(char *auth) //remove a book (set to null)
{
    Book book;
    fstream input("library.dat");
    if (!input)
    {
        throw "Error opening file for reading";
    }
    input.read((char *)&book, sizeof(Book)); //get first book to check for EOF
    int i = 0;
    bool found = false;
    while (!input.eof() && !found)
    {
        if (strcmp(book.author, auth) == 0)
        {                                            // if the author is the same as the one we want to remove
            input.seekg(i * sizeof(Book));           // go to the place where the book is with read ptr
            input.read((char *)&book, sizeof(Book)); // read the book
            input.seekp(i * sizeof(Book));           // go to the place where the book is with write ptr
            // input.write((char *)&book, sizeof(Book)); //now remove the book
            // set the same slot as empty
            book.name[0] = '\0';
            book.author[0] = '\0';
            book.quantity = 0;
            book.price = 0;
            input.write((char *)&book, sizeof(Book)); // now write the book
            //found, now exit the loop
            found = true;
        }
        input.read((char *)&book, sizeof(Book)); // read the book
        i++;
    }
    if(!found)
    {
        cout << "Author not found" << endl;
    }
    input.close();
}

int main() //menu
{
    int choice;
    bool err = false;

    do
    {
        cout << "0. Exit" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Read the file" << endl;
        cout << "3. Delete a book" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            try
            {
                addBook();
            }
            catch (const char *msg)
            {
                cout << msg << endl;
                err = true;
            }
            break;
        case 2:
            try
            {
                readFile();
            }
            catch (const char *msg)
            {
                cout << msg << endl;
                err = true;
            }
            break;
        case 3:
            try
            {
                cout << "Select a book via author: ";
                char author[10];
                cin >> author;

                remove(author);
            }
            catch (const char *msg)
            {
                cout << msg << endl;
                err = true;
            }
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 0 && err == false);
    return 0;
}

// q10 - template

class Arr // original arr class
{

protected:
    int *data;
    int size; // size in use
    int capacity; // available capacity

public:
    Arr(int capacity = 0);
    Arr(const Arr &);
    virtual ~Arr();
    Arr &operator=(const Arr &);
    int &operator[](int index);
    int getSize() const;
    int getCapacity() const;
    void insert(int value);
    void clear();
    int delLast();
};

// modified arr class to accept a template type
template <class T> // required in all template classes
class Arr2         // original arr class
{

protected:
    T *data;      // pointer to the data (T type)
    int size;     // size in use
    int capacity; // available capacity

public:
    Arr(int capacity = 0);
    Arr(const Arr &);
    virtual ~Arr();
    Arr &operator=(const Arr &);
    T &operator[](int index); // returns the T type at that spot
    int getSize() const;
    int getCapacity() const;
    void insert(T value); // insert T into array
    void clear();
    T delLast(); // delete last element and return it as a T
};
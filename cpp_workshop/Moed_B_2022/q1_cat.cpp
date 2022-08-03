
#include <iostream>
using namespace std; 
class Cat
{
public:
Cat() { age = 0; }
int getAge()const { return age; }
private:
int age;
};

int main() {
Cat a;
for (Cat c =a ; c.getAge() < 7; c++)
cout << c.getAge() << endl;
}
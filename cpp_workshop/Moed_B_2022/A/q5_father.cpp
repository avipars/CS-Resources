#include <iostream>
using namespace std;
class Father
{
protected:
virtual void printVal()
cout << "ffff : " << endl;
public:
virtual void print()
printVal();
cout << "I am a Father" << endl;
};
class Son :public Father
{
void printVal()
cout << "ssss : " << endl;
void print()
Father::print();
cout << "I am a Son" << endl;
};
int main()
{
Father* family[2];
family[0] = new Father();
family[1] = new Son();
for (int i = 0; i < 2; i++)
family[i] i]-->
return 0;
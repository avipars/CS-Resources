#include<iostream> //see my blog post on tech.aviparshan.com for specifics! This is an example of handling a specific data type seperately in a template class
using namespace std;
template<class Type>
class A{
	Type a;
public:
A(Type a);
};


template<>A<float>::A(float a){
    a=12.5;
    cout<<a<<endl;
}

//template for int type specific
template<>A<int>::A(int a){
    a=8;
    cout<<a<<endl;
}

template<class Type>A<Type>::A(Type a1){
	this->a=a1;
	cout<<a<<endl;
}

int main(){
	int a=2;
	float b=3.5;
	double c=7.5;
	A<int>ob1(a);
	A<float>ob2(b);
	A<double>ob3(c);
    return 0;
}

//output: 8

//12.5

//7.5

//https://tech.aviparshan.com/2022/07/learn-c-and-oop-easily-template.html

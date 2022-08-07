#pragma once
template <class T>
class Calc {
    protected:
        T a=0, b=0;
    public: 
        T add();
        T sub();
        T mul();
        T div();
        Calculator(T a, T b);
}

template <class T>
T Calculator<T>::add() {
    return a+b;
}
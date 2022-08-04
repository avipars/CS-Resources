#include <iostream>
using namespace std;
class Flower {
 public:
  Flower() { cout << "Empty Flower " << endl; }
  Flower(const Flower& other) { cout << "CC Flower" << endl; }
  Flower(Flower&& other) { cout << "Move Flower" << endl; }
  virtual ~Flower() { cout << "Dest Flower" << endl; };
  class Petal_Flower : public Flower {
   public:
    Petal_Flower() { cout << "Empty Petal " << endl; }
    Petal_Flower(const Petal_Flower& other) { cout << "CC Petal" << endl; }
    Petal_Flower(Petal_Flower&& other) {
      cout << "Move Petal" << endl;
      virtual ~Petal_Flower() { cout << "Dest Petal" << endl; }
    };
    Flower func(Flower a) {
      cout << "func n";
      return a;
    }
    int main() {
      Petal_Flower pf;
      func(pf);
      cout << "main n";
      return 0;
    }
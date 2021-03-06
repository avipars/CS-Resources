#include <iostream>
using namespace std;

//q12 all classes/fns
class ChefsDish{
    protected: 
        int dish = 0;
        float pricePerFood = 0; //dollars
        float amount = 0; //can half half portions
    public:
        ChefsDish(int dish, float pr, float am); 
        float priceCalc(); 
    private: 
        virtual float discountCalcuation(float price) const = 0;

};

ChefsDish::ChefsDish(int dish, float pr, float am){
    this->dish = dish;
    this->pricePerFood = pr;
    this->amount = am;
}

float ChefsDish::priceCalc(){
    return discountCalcuation(amount * pricePerFood);
}

class DairyFood: public ChefsDish{
    protected:
        bool coupon = false;
    public: 
        DairyFood(int dish, float pr, float am, bool coupon);
        float discountCalcuation(float price) const override;
};

DairyFood::DairyFood(int dish, float pr, float am, bool coupon): ChefsDish(dish, pr, am){
    this->coupon = coupon;
}


float DairyFood::discountCalcuation(float price) const{
    if(coupon){
        return price * 0.9; //if has coupon
    }
    else{
        return price;
    }
}

class MeatFood: public ChefsDish{
    public: 
        MeatFood(int dish, float pr, float am);
        float discountCalcuation(float price) const override;
};

MeatFood::MeatFood(int dish, float pr, float am): ChefsDish(dish, pr, am){} //ctor, nothing special about it, so it doesn't need a body

float MeatFood::discountCalcuation(float price) const{
    if(amount > 5){ 
        return price * 0.85; //discount for 6 or more dishes
    }
    else{
        return price;
    }
}

//pointer to a
float calculatePerOrder(ChefsDish** order, int size){
    float total = 0;
    for(int i = 0; i < size; i++)
    {
        total += order[i]->priceCalc();
    }
    return total;
}

int main(){ //bonus tester stuff, not required
    int n;
    cout << "enter quantity of dishes: ";
    cin >> n;
    ChefsDish** order = new ChefsDish*[n]; //make array of pointers to ChefsDish
    for(int i = 0; i < n; i++){
        int dish;
        float price, amount;
        bool coupon, isDairy;
       
        cout << "Dish#: ";
        cin >> dish;
        cout << "Price: ";
        cin >> price;
        cout << "Amount: ";
        cin >> amount;
        
        cout << "isDairy? 1 = yes, 0 = no" << endl;
        cin >> isDairy;

        if(isDairy){
            cout << "Coupon (1 = yes, 0 = no): ";
            cin >> coupon;
            order[i] = new DairyFood(dish, price, amount, coupon);
        }
        else{
            order[i] = new MeatFood(dish, price, amount);
        }

    }

            cout << "total: "<< calculatePerOrder(order, n) << endl;

    return 0;
}
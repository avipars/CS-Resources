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
        return price * 0.9;
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

MeatFood::MeatFood(int dish, float pr, float am): ChefsDish(dish, pr, am){

}

MeatFood::ChefsDish(int dish, float pr, float am): ChefsDish(dish, pr, am){

}

float MeatFood::discountCalcuation(float price) const{
    if(amount > 5){
        return price * 0.85;
    }
    else{
        return price;
    }
}

float calculatePerOrder(ChefsDish** order, int size){
    float total = 0;
    for(int i = 0; i < size; i++){
        total += order[i]->priceCalc();
    }
    return total;
}
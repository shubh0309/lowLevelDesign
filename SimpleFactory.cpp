#include<bits/stdc++.h>
using namespace std;
class Burger{
    public:
        virtual void prepare() = 0;
        virtual ~Burger() {}
};

class BasicBurger : public Burger{
    public:
        void prepare() override {
            cout<<"Preparing basic burger\n";
        }
};

class PremimumBurger : public Burger{
    public:
        void prepare() override {
            cout<<"Preparing premimum Burger\n";
        }
};

class BurgerFactory{
    public:
        Burger *  createBurger(string& type){
            if(type == "basic"){
                return new BasicBurger();
            }else if(type == "premimum"){
                return new PremimumBurger();
            }else{
                cout<<"Invalid Burger\n";
                return nullptr;
            }
        }
};

int main(){
    string type = "premimum";
    BurgerFactory *myFactoryBuger = new BurgerFactory();
    Burger* myBurger = myFactoryBuger->createBurger(type);
    myBurger->prepare();
    return 0;
}

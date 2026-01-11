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

class BasicWheatBurger : public Burger{
    public:
        void prepare() override {
            cout<<"Preparing basic Wheat burger\n";
        }
};

class PremimumWheatBurger : public Burger{
    public:
        void prepare() override {
            cout<<"Preparing premimum Wheat Burger\n";
        }
};

class BurgerFactory{
    public:
        virtual Burger* createBurger(string &type) = 0;
};

class SinghBurger : public BurgerFactory{
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

class WheatBurger : public BurgerFactory{
    public:
        Burger *  createBurger(string& type){
            if(type == "basic"){
                return new BasicWheatBurger();
            }else if(type == "premimum"){
                return new PremimumWheatBurger();
            }else{
                cout<<"Invalid Burger\n";
                return nullptr;
            }
        }
};

int main(){
    string type = "premimum";
    BurgerFactory *myFactoryBuger = new SinghBurger();
    Burger* myBurger = myFactoryBuger->createBurger(type);
    myBurger->prepare();
    
    BurgerFactory *myFactoryWheatBuger = new WheatBurger();
    Burger* myBurgerWheat = myFactoryWheatBuger->createBurger(type);
    myBurgerWheat->prepare();
    return 0;
}

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

class GarlicBread{
    public:
        virtual void prepare() = 0;
        virtual ~GarlicBread() {}
};

class BasicGarlicBread : public GarlicBread{
    public:
        void prepare() override {
            cout<<"Preparing basic GarlicBread\n";
        }
};

class PremimumGarlicBread : public GarlicBread{
    public:
        void prepare() override {
            cout<<"Preparing premimum GarlicBread\n";
        }
};

class BasicWheatGarlicBread : public GarlicBread{
    public:
        void prepare() override {
            cout<<"Preparing basic Wheat GarlicBread\n";
        }
};

class PremimumWheatGarlicBread : public GarlicBread{
    public:
        void prepare() override {
            cout<<"Preparing premimum Wheat GarlicBread\n";
        }
};


class MealFactory{
    public:
        virtual Burger* createBurger(string &type) = 0;
        virtual GarlicBread* createGarlicBread(string &type) = 0;
};

class SinghBurger : public MealFactory{
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
        
        GarlicBread *  createGarlicBread(string& type){
            if(type == "basic"){
                return new BasicGarlicBread();
            }else if(type == "premimum"){
                return new PremimumGarlicBread();
            }else{
                cout<<"Invalid Garlic Bread\n";
                return nullptr;
            }
        }
};

class WheatBurger : public MealFactory{
    public:
        Burger *createBurger(string& type){
            if(type == "basic"){
                return new BasicWheatBurger();
            }else if(type == "premimum"){
                return new PremimumWheatBurger();
            }else{
                cout<<"Invalid Burger\n";
                return nullptr;
            }
        }
        
        GarlicBread *createGarlicBread(string& type){
            if(type == "basic"){
                return new BasicWheatGarlicBread();
            }else if(type == "premimum"){
                return new PremimumWheatGarlicBread();
            }else{
                cout<<"Invalid Garlic Bread\n";
                return nullptr;
            }
        }
};

// main is our client code
int main(){
    string burgerType = "premimum";
    string garlicType = "basic";
    MealFactory *myFactory = new SinghBurger();
    Burger* myBurger = myFactory->createBurger(burgerType);
    GarlicBread *myGarlicBread = myFactory->createGarlicBread(garlicType);
    myBurger->prepare();
    myGarlicBread->prepare();
    
    
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

// interface classes
class Talkable{
    public:
        virtual void talk() = 0;
        virtual ~Talkable(){}
};

// concreate stratagies class
class NormalTalk : public Talkable{
    public :
        void talk(){
            cout<<"Normal talking \n";
        }
};

class NotTalk : public Talkable{
    public :
        void talk(){
            cout<<"Not talking \n";
        }
};

class Walkable{
    public:
        virtual void walk() = 0;
        virtual ~Walkable(){}
};

// concreate stratagies class
class NormalWalk : public Walkable{
    public :
        void walk(){
            cout<<"Normal walking \n";
        }
};

class NotWalk : public Walkable{
    public :
        void walk(){
            cout<<"Not walking \n";
        }
};

class Flyable{
    public:
        virtual void fly() = 0;
        virtual ~Flyable(){}
};

// concreate stratagies class
class NormalFly : public Flyable{
    public :
        void fly(){
            cout<<"Normal flying \n";
        }
};

class NotFly : public Flyable{
    public :
        void fly(){
            cout<<"Not flying \n";
        }
};

class Robot{
    protected:
        Walkable* walkBehaviour;
        Talkable* talkableBehaviour;
        Flyable* flyableBehabiour;
    
    public:
        Robot(Walkable* w, Talkable* t, Flyable* f){
            this->walkBehaviour = w;
            this->talkableBehaviour = t;
            this->flyableBehabiour = f;
        }
        
        void walk(){
            walkBehaviour->walk();
        }
        void talk(){
            talkableBehaviour->talk();
        }
        void fly(){
            flyableBehabiour->fly();
        }
        
        virtual void projection() = 0; // abstract method for sub classes
        
};

// create robot type
class CompaninonRobot : public Robot{
    public:
        CompaninonRobot(Walkable* w, Talkable* t, Flyable* f): Robot(w, t, f){}
        
    void projection () override{
        cout<<"displaying friendly companinon robot\n";
    }
};

int main(){
    Robot * robot1 = new CompaninonRobot(new NormalWalk(), new NormalTalk(), new NotFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();
    return 0;
}

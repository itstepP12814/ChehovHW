#include <iostream>

using namespace std;
int main() {
    class Human {
    public:
        Human(Female& F, Male& M);
        Human();
        virtual ~Human();
    };

    Human::Human(Female& F, Male& M) {
        //ctor
    }

    Human::~Human() {
        //dtor
    }

    class Female: public Human {
    private:
        Female(): Human();
        static Female* Eve;
    public:
        Female(Female& F, Male& M): Human(Female& F, Male& M);
        virtual ~Female();
        static const Female getEve() {
            if(!Eve) {
                Eve=new Female();
            }
            return *Eve;
        }
    };
    Female::Eve=NULL;
    Female::Female() {
        printf("\tЕва сконструирована\n");
    }
    Female::Female(Female& F, Male& M) {
        //ctor
    }

    Female::~Female() {
        //dtor
    }


    class Male {
    public:
        Male();
        virtual ~Male();
    protected:
    private:
    };
    Male::Male() {
        //ctor
    }

    Male::~Male() {
        //dtor
    }

    return 0;
}

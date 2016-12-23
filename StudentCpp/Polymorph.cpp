#include <iostream>
using namespace std;

namespace Polymorph
{
    class Base
    {
    public:
        virtual void Print() = 0;
    };

    class Element : Base
    {
    public:
        void Print() override
        {
            cout << "I'm Element!" << endl;
        }
    };

    class Container : Base
    {
    public:
        void Print() override
        {
            cout << "I'm Conrainer!" << endl;
        }
    };

    void Polymorph_Main()
    {
        Element* e = new Element();
        Base* pb = (Base*)e;
        pb->Print();

        Base* pb2 = (Base*) new Container();
        pb2->Print();

        Element e2;
        Base b;
    }
}
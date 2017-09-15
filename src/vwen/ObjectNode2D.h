


//#include "ObjectNode.h"
#include <iostream>
using namespace std;

namespace Vwen{

    class ObjectNode2D : public ObjectNode {
        public:
            void DoSomething(){
                cout << "Inside namespace vwen of ObjectNode2D" << endl;
            }
    };
    
}
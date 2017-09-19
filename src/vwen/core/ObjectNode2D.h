


//#include "ObjectNode.h"
#include <iostream>
using namespace std;

namespace vwen{
//header guard at start of header file
#ifndef OBJECTNODE2D_H
#define OBJECTNODE2D_H
    class ObjectNode2D : public ObjectNode {
        public:
            void DoSomething(){
                cout << "Inside namespace vwen of ObjectNode2D" << endl;
            }
    };
//End guard at bottom of header file
#endif 
}
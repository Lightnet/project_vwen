// https://msdn.microsoft.com/en-us/library/5cb46ksf.aspx
// https://stackoverflow.com/questions/41590/how-do-you-properly-use-namespaces-in-c
// https://www.tutorialspoint.com/cplusplus/cpp_namespaces.htm

//https://stackoverflow.com/questions/10816600/c-namespaces-how-to-use-in-header-and-source-files-correctly
#include "vwen.h"

#include <iostream>
using namespace std;

namespace Vwen{

    void ObjectNode::DoSomething(){
        cout << "Inside namespace vwen of ObjectNode" << endl;
    }

}


/*
namespace Vwen{

    class Vector3 {
        double x,y,z;
        public:
            Vector3(double px,double py,double pz)
            {
                x = px;
                y = py;
                z = pz;
            }
    };

    class Rotation {
        double x = 0;
        double y = 0;
        double z = 0;
        double w = 0;
    };

    class ObjectNode{
        //Vector3 pos;
        public:
            void DoSomething(){
                cout << "Inside namespace ObjectNode" << endl;
            }
            //void Position(Vector3 newpos){pos = newpos;}
    };

    void func() {
        cout << "Inside Vwen space" << endl;
    }
}
*/

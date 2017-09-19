



#include <iostream>
#include <string>
using namespace std;

namespace vwen{
//header guard at start of header file
#ifndef OBJECTNODE_H
#define OBJECTNODE_H
    class ObjectNode {

        public:
            bool isVisible = true;
            string name = "ObjectNode";
            virtual void DoSomething(){
                cout << "Inside namespace vwen of ObjectNode" << endl;
            }

            virtual void Position(){}
            virtual void Rotation(){}
            virtual void Render(){
                //cout << "namespace vwen of ObjectNode render" << endl;
            }
            virtual void Destroy(){
                
            }
    };
//End guard at bottom of header file
#endif 
}
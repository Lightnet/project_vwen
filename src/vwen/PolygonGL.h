#include <iostream>
using namespace std;

namespace Vwen{

    class PolygonGL : public ObjectNode{
        public:
            void DoSomething(){
                cout << "Inside namespace vwen of ObjectNode" << endl;
            }
            void Setup(){
                cout << "Inside namespace vwen of ObjectNode" << endl;
            }

            void Render(){
                cout << "Inside namespace vwen of ObjectNode" << endl;
            }
    };
    
}
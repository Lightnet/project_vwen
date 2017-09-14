// https://msdn.microsoft.com/en-us/library/5cb46ksf.aspx
// https://stackoverflow.com/questions/41590/how-do-you-properly-use-namespaces-in-c
// https://www.tutorialspoint.com/cplusplus/cpp_namespaces.htm
#include <iostream>
using namespace std;

namespace Vwen{

    class ObjectNode{
        public:
            void DoSomething(){}
    };

    void func() {
        cout << "Inside Vwen space" << endl;
    }
}
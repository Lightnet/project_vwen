/*
Notes:
  * if you have more than one same file include from header it will conflict to put main here. To handle file headers.
  * not they had to be in order to compile right tree branch build.
 */


//#include <iostream>
//using namespace std;

#include <glad/glad.h>
#include "core/core.h"

#include <string>
#include <iostream>
#include <list>

#include <vector>
#include <memory>

using namespace std;

namespace vwen{
    //string version = "0.0.1";

    GLuint VBO = 0; // vertex buffer object

    
    
    void func();
    void GetTree();
    void GetMainCamera();

    //testing...
    GLuint GetVBO(){
        VBO = VBO + 1;
        return VBO;
    }
    // http://www.cplusplus.com/reference/list/list/list/
    // http://en.cppreference.com/w/cpp/container/list
    // https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c
    // https://stackoverflow.com/questions/13906980/calling-an-overridden-function-from-a-list-of-its-base-class
    // https://stackoverflow.com/questions/6274136/objects-of-different-classes-in-a-single-vector
    // https://codereview.stackexchange.com/questions/41525/creating-objects-and-putting-them-into-stdlist
    // http://en.cppreference.com/w/cpp/memory/unique_ptr

    void addChild(ObjectNode node){
        //nodes.push_front(node);

        //nodes.push_back(node);
    }

    void nodeadd_test(){
        PolygonGL pol;
        //nodes.push_back(pol);

        nodes.push_back( std::make_unique<ObjectNode>( pol ));
    }

    void removeChild(){


    }

    void print_nodes(){
        //for (std::list<vwen::ObjectNode>::iterator it = nodes.begin(); it != nodes.end(); it++){
            //std::cout << *it << ' ';
        //}

        //for (ObjectNode node : nodes){
            //std::cout << 'node ';
            //std::cout << node << ' ';
            //std::cout << node.name << endl;
        //}
        std::cout << "END NODES " << endl;
    }
}
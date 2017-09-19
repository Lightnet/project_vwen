#define CORE_H

#include <glad/glad.h>

#include "ObjectNode.h"
#include "ObjectNode2D.h"
#include "../meshes/PolygonGL.h"

#include "renderer.h"

#include <string>
#include <iostream>
#include <list>

using namespace std;

namespace vwen{
    string version = "0.0.1";

    //GLuint VBO = 0; // vertex buffer object

    //std::list<ObjectNode> nodes;
    
    //void func();
    //void GetTree();
    //void GetMainCamera();

    //testing...
    //GLuint GetVBO(){
        //VBO = VBO + 1;
        //return VBO;
    //}
    // http://www.cplusplus.com/reference/list/list/list/
    // http://en.cppreference.com/w/cpp/container/list
    //void addChild(ObjectNode node){
        //nodes.push_front(node);
    //}

    //void removeChild(){
    //}

    //void print_nodes(){
        //for (std::list<vwen::ObjectNode>::iterator it = nodes.begin(); it != nodes.end(); it++){
            //std::cout << *it << ' ';
        //}

        //for (ObjectNode node : nodes){
            //std::cout << node << ' ';
            //std::cout << node.name << ' \n';
        //}
    //}
}
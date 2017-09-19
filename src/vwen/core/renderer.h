








#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <vector>


#include "ObjectNode.h"

//#include "vwen.h"

using namespace std;

namespace vwen{

    //std::shared_ptr<ObjectNode> nodes;
    //std::vector<ObjectNode> nodes;
    //std::unique_ptr<ObjectNode> nodes;

    std::vector<std::unique_ptr<ObjectNode>> nodes;


    void Renderer(){

        for(auto& p: nodes){
            std::cout << p->GetName() << '\n';
            p->Render(); // virtual dispatch
        }

        // Iterate and print values of vector
        //for(ObjectNode n : nodes) {
            //std::cout << n << '\n';
            //std::cout << "render" << '\n';
            //n.Render();
        //}
        //std::cout << endl;


        /*
        std::vector<ObjectNode>::iterator node;

        for(node = nodes.begin(); node != nodes.end(); ++node)
        {
            //node.Render();
            //std::cout << node << ' \n';
            //delete *it;
        }
        */

        //cout << "Inside namespace vwen of Renderer" << endl;
        //for (ObjectNode node : nodes){
        //for (const auto& node : nodes){
            //std::cout << node << ' ';
            //std::cout << node.name << ' \n';

            //std::cout << "RENDER!" << ' \n';
            //node.Render();
        //}

    }

}
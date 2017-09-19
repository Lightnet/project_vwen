/*
	Project: VWEN
	Information: SDL2 and ImGui
*/
//#include <glm/vec3.hpp> // glm::vec3
//#include <glm/vec4.hpp> // glm::vec4
//#include <glm/mat4x4.hpp> // glm::mat4
//#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

//#include <pybind11/embed.h>

//#include "vwen/glfw_glad_imgui.h"
//#include <vwen/glfw_glad_cube.h>
//#include "vwen/sdl2_glad.h"
//#include "vwen/sdl2_glad_imgui.h"
//#include "vwen/sdl2_launcher.h"

#include "vwen/sdl2_app.h"

#include <stdio.h>
#include <string>
#include <iostream>

#undef main

using namespace std;

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error %d: %s\n", error, description);
}

static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name << " <option(s)> SOURCES \n"
			  << "Options:\n"
			  << "\t-h,--help\t\tShow this help message\n"//<< "\t-d,--destination DESTINATION\tSpecify the destination path"
			  << "\t-d,-editor\t\t(Lanuch Editor)\n"
			  << "\t-d,-server\t\t(Lanuch Server)\n"
              << std::endl;
}
//----

//int main_test(int argc, char* argv[]) //main entry point
int main(int argc, char* argv[]) //main entry point
{
	if (argc < 3) {
        //printf(string(argc));
        show_usage(argv[0]);
        //printf("Len = %f",argc);
        //return 1;
    }

    for (int i = 1; i < argc; ++i) {
        //std::string arg = argv[i];
        std::string sarg( argv[i] );
        if ((sarg == "-h") || (sarg == "--help")) {
            //show_usage(argv[0]);
            printf("help here?");
            //return 0;
        } else if ((sarg == "-d") || (sarg == "--destination")) {
            if (i + 1 < argc) { // Make sure we aren't at the end of argv!
                //destination = argv[i++]; // Increment 'i' so we don't get the argument as the next argv[i].
            } else { // Uh-oh, there was no argument to the destination option.
                  //std::cerr << "--destination option requires one argument." << std::endl;
                //return 1;
            }  
        }else if(sarg == "-editor"){
            printf("found editor!");
        }else if(sarg == "-server"){
            printf("found server!");
        }else {
            //sources.push_back(argv[i]);
            //printf("default | arg: %s \n",sarg);
            printf("default\n");
        }
	}
    
    //glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.f);
    
	//sdl2_gl3w(argc, argv);
    //vwen_glfw_gl3_imgui(argc, argv);
    //vwen_glfw_glad_imgui(argc, argv);
    //vwen_glfw_glad_cube(argc, argv);

    //BaseSDL::app(argc,argv);
    //BaseSDL_imgui::app(argc,argv);
    //sdl2_launcher(argc,argv);
    //AppSDL::sdl_app(argc,argv);

    sdl_app(argc,argv);

    return 0;
}

/*
	Project: VWEN

	Information: Main entry. SDL and ImGui

*/

#include <imgui.h>
#include "imgui_impl_glfw_gl3.h"
#include <stdio.h>
#include <GL/gl3w.h>    // This example is using gl3w to access OpenGL functions (because it is small). You may use glew/glad/glLoadGen/etc. whatever already works for you.
#include <GLFW/glfw3.h>

#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error %d: %s\n", error, description);
}

static void show_usage(std::string name)
{
    //std::cerr << "Usage: " << argv[0] << " <option(s)> SOURCES"
              //<< "Options:\n"
              //<< "\t-h,--help\t\tShow this help message\n"
              //<< "\t-d,--destination DESTINATION\tSpecify the destination path"
              //<< std::endl;
}

int main(int argc, char* argv[])
//int main_glfw(int, char**)
{
    //using namespace std;

    printf("Len = %i \n",argc);

	if (argc < 3) {
        //printf(string(argc));
        //show_usage(argv[0]);
        //printf("Len = %f",argc);
        //return 1;
    }

    //string arg = "";

    //stringstream ss;
    //string oString;

    for (int i = 1; i < argc; ++i) {
        //std::string arg = argv[i];
        char* arg = argv[i];
        //string sarg = "-editor";
        //string sarg = "test";

        //printf("TEST:",sarg);
        //std::cout << "Char ARG: " << sarg << "\n";
        std::string sarg(arg);
        //std::cout << "Char ARG: " << sarg << "\n";
        //std::string str(arg);
        //ss << arg;
        //ss >> sarg;
        //oString= arg.string;

        //std::string arg(argv[i]);
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

    //ss = nullptr;



    // Setup window
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        return 1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui OpenGL3 example", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
    gl3wInit();

    // Setup ImGui binding
    ImGui_ImplGlfwGL3_Init(window, true);

    // Load Fonts
    // (there is a default font, this is only if you want to change it. see extra_fonts/README.txt for more details)
    //ImGuiIO& io = ImGui::GetIO();
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../extra_fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../extra_fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../extra_fonts/ProggyClean.ttf", 13.0f);
    //io.Fonts->AddFontFromFileTTF("../../extra_fonts/ProggyTiny.ttf", 10.0f);
    //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());

    bool show_test_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImColor(114, 144, 154);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        ImGui_ImplGlfwGL3_NewFrame();

        // 1. Show a simple window
        // Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets appears in a window automatically called "Debug"
        {
            static float f = 0.0f;
            ImGui::Text("Hello, world!");
            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
            ImGui::ColorEdit3("clear color", (float*)&clear_color);
            if (ImGui::Button("Test Window")) show_test_window ^= 1;
            if (ImGui::Button("Another Window")) show_another_window ^= 1;
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        }

        // 2. Show another simple window, this time using an explicit Begin/End pair
        if (show_another_window)
        {
            ImGui::SetNextWindowSize(ImVec2(200,100), ImGuiCond_FirstUseEver);
            ImGui::Begin("Another Window", &show_another_window);
            ImGui::Text("Hello");
            ImGui::End();
        }

        // 3. Show the ImGui test window. Most of the sample code is in ImGui::ShowTestWindow()
        if (show_test_window)
        {
            ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
            ImGui::ShowTestWindow(&show_test_window);
        }

        // Rendering
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui::Render();
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplGlfwGL3_Shutdown();
    glfwTerminate();

    return 0;
}

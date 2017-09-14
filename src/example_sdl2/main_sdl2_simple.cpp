/*
	Project: VWEN
*/

// SDL,GL3W
//#include <imgui.h>
//#include "imgui_impl_sdl_gl3.h"
#include <stdio.h>
#include <GL/gl3w.h>    // This example is using gl3w to access OpenGL functions (because it is small). You may use glew/glad/glLoadGen/etc. whatever already works for you.
#include <SDL.h>
#include <chrono>
#include <thread>

//https://www.youtube.com/watch?v=MeMPCSqQ-34 23:18

//https://www.khronos.org/opengl/wiki/Tutorial1:_Creating_a_Cross_Platform_OpenGL_3.2_Context_in_SDL_(C_/_SDL)

//int main(int, char**) //main entry point
int main_sdl(int, char*) //main entry point
{
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);

    SDL_Window *mainwindow; /* Our window handle */
    SDL_GLContext maincontext; /* Our opengl context handle */

    // Setup window
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_DisplayMode current;
    SDL_GetCurrentDisplayMode(0, &current);

    SDL_Window *win = SDL_CreateWindow(
        "Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
    maincontext = SDL_GL_CreateContext(win);
    gl3wInit();

    // Setup ImGui binding
    ImGui_ImplSdlGL3_Init(win);
    
    //START MAKING OPENGL CALL HERE
    //std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    //SDL_GL_SwapWindow(win);
    bool show_test_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImColor(114, 144, 154);

    // Main loop
    bool done = false;
    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSdlGL3_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;
        }
        //ImGui_ImplSdlGL3_NewFrame(win);
        
        // This makes our buffer swap syncronized with the monitor's vertical refresh 
        SDL_GL_SetSwapInterval(1);

        // Clear our buffer with a red background 
        glClearColor ( 0.1, 0.0, 0.0, 0.1 );
        glClear ( GL_COLOR_BUFFER_BIT );
        // Swap our back buffer to the front 
        SDL_GL_SwapWindow(win);
        // Wait 2 seconds 
        SDL_Delay(50);

        // Same as above, but green
        glClearColor ( 0.0, 0.1, 0.0, 0.1 );
        glClear ( GL_COLOR_BUFFER_BIT );
        SDL_GL_SwapWindow(win);
        SDL_Delay(50);

        // Same as above, but blue
        glClearColor ( 0.0, 0.0, 0.1, 0.01 );
        glClear ( GL_COLOR_BUFFER_BIT );
        SDL_GL_SwapWindow(win);
        SDL_Delay(50);
        // Rendering
        //glViewport(0, 0, 640, 480);
        //glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        //glClear(GL_COLOR_BUFFER_BIT);
        //ImGui::Render();
        //SDL_GL_SwapWindow(win);

        // Rendering
        //glViewport(0, 0, (int)ImGui::GetIO().DisplaySize.x, (int)ImGui::GetIO().DisplaySize.y);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        //ImGui::Render();
        SDL_GL_SwapWindow(win);
    }

    /* Delete our opengl context, destroy our window, and shutdown SDL */
    SDL_GL_DeleteContext(maincontext);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
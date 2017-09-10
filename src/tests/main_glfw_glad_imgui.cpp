/*
	Project: VWEN

	Information: Main entry. SDL and ImGui

*/

#include <imgui.h>
#include "imgui_impl_glfw_glad.h"
#include <stdio.h>
//#include <GL/gl3w.h>    // This example is using gl3w to access OpenGL functions (because it is small). You may use glew/glad/glLoadGen/etc. whatever already works for you.
#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include <GLFW/glfw3native.h>

//#include <glad/glad.h>
#include "linmath.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
//#include <vector>
#include "linmath.h"


static const struct
{
    float x, y;
    float r, g, b;
} vertices[3] =
{
    { -0.6f, -0.4f, 1.f, 0.f, 0.f },
    {  0.6f, -0.4f, 0.f, 1.f, 0.f },
    {   0.f,  0.6f, 0.f, 0.f, 1.f }
};
static const char* vertex_shader_text =
"uniform mat4 MVP;\n"
"attribute vec3 vCol;\n"
"attribute vec2 vPos;\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    color = vCol;\n"
"}\n";
static const char* fragment_shader_text =
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_FragColor = vec4(color, 1.0);\n"
"}\n";
static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}



using namespace std;

//static void error_callback(int error, const char* description)
//{
    //fprintf(stderr, "Error %d: %s\n", error, description);
//}

static void show_usage(std::string name)
{
    /*
    std::cerr << "Usage: " << "" << " <option(s)> SOURCES \n"
              << "Options:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\t-d,--destination DESTINATION\tSpecify the destination path"
              << std::endl;
              */
}

//int main(int argc, char* argv[])
int main_glfw_cube(int argc, char* argv[])
{
    //using namespace std;

    printf("Len = %i \n",argc);

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

    // Setup window
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        return 1;
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    GLFWwindow* window = glfwCreateWindow(1280, 720, "GLFW ImGui OpenGL3 Glad example", NULL, NULL);

    // Setup ImGui binding
    ImGui_ImplGlfwGlad_Init(window, true);


    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;


    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1); // Enable vsync

    //bool show_test_window = true;
    //bool show_another_window = false;
    //ImVec4 clear_color = ImColor(114, 144, 154);

    // NOTE: OpenGL error checks have been omitted for brevity
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);
    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    mvp_location = glGetUniformLocation(program, "MVP");
    vpos_location = glGetAttribLocation(program, "vPos");
    vcol_location = glGetAttribLocation(program, "vCol");
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(float) * 5, (void*) 0);
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
                          sizeof(float) * 5, (void*) (sizeof(float) * 2));

    // Main loop

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        //ImGui_ImplGlfwGlad_NewFrame();

        float ratio;
        int width, height;
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 1. Show a simple window
        // Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets appears in a window automatically called "Debug"
        //{
            //static float f = 0.0f;
            //ImGui::Text("Hello, world!");
            //ImGui::End();
        //}
        

        mat4x4 m, p, mvp;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        mat4x4_identity(m);
        mat4x4_rotate_Z(m, m, (float) glfwGetTime());
        mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        mat4x4_mul(mvp, p, m);
        glUseProgram(program);
        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*) mvp);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Rendering
        int display_w, display_h;
        //glfwGetFramebufferSize(window, &display_w, &display_h);
        //glViewport(0, 0, display_w, display_h);
        //glClear(GL_COLOR_BUFFER_BIT);
        //ImGui::Render();
        glfwSwapBuffers(window);
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
    //ImGui_ImplGlfwGlad_Shutdown();
    glfwTerminate();

    return 0;
}

/*
	Project: VWEN

	Information: Main entry. SDL and ImGui

*/

//#include <imgui.h>
//#include "imgui_impl_sdl_gl3.h"
#include <stdio.h>
#include <glad/glad.h>    // This example is using gl3w to access OpenGL functions (because it is small). You may use glew/glad/glLoadGen/etc. whatever already works for you.
#include <SDL.h>

// Window management
bool quit = false; // exit program
SDL_Window *window = NULL;
SDL_GLContext glContext;
SDL_Event event;

// Window parameters
char title[] = "First Window"; // window's title
short unsigned int wHeight       = 600;
short unsigned int wWidth        = 800;
short unsigned int initialPosX   = 100;
short unsigned int initialPosY   = 100;

// OpenGL
GLuint shaderProgram;

GLuint VAO; // vertex array object
GLuint VBO; // vertex buffer object

GLuint vertices = 3;
GLfloat vVertices[] = {0.0f, -0.5f, 0.0f,
                       -0.5f, 0.5f, 0.0f,
                        0.5f, 0.5f, 0.0f};

void _sdlError(const char *mes)
{
  fprintf(stderr, "%s: %s\n", mes, SDL_GetError());
  exit(1);
}

void Init()
{
  // Init SDL2     SDL_INIT_VIDEO - for video initialisation only
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    _sdlError("Could not initialize SDL");

  // Set attributes
  //SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
  //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

  //SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  //SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  // Create window
  window = SDL_CreateWindow(title, initialPosX, initialPosY, wWidth, wHeight, SDL_WINDOW_OPENGL);
  if(window == NULL)
    _sdlError("Could not create window");

  // Create OpenGL context
  glContext = SDL_GL_CreateContext(window);
  if(glContext == NULL)
    _sdlError("Could not create the OpenGL context");

  // Load OpenGL functions glad SDL
  //gladLoadGLLoader(SDL_GL_GetProcAddress);
  //gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
  gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress);

  // V-Sync
  SDL_GL_SetSwapInterval(1);
}

void PreLoop()
{
  printf("Vendor:          %s\n", glGetString(GL_VENDOR));
  printf("Renderer:        %s\n", glGetString(GL_RENDERER));
  printf("Version OpenGL:  %s\n", glGetString(GL_VERSION));
  printf("Version GLSL:    %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
}

void LoadShaders()
{
  // Shaders
const char* vertexShaderSource = "#version 450 core\n"
    "layout (location = 0) in vec3 position;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
    "}\0";
const char* fragmentShaderSource = "#version 450 core\n"
    "out vec4 color;\n"
    "void main()\n"
    "{\n"
    "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";
  
  // Build compile VERTEX_SHADER
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  // Check for compile errors VERTEX_SHADER
  GLint success;
  GLchar infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if(!success)
    {
      glGetShaderInfoLog(vertexShader, sizeof(infoLog), NULL, infoLog);
      printf("Error: vertex shader compilation error: %s\n", infoLog);
    }

  // Build compile FRAGMENT_SHADER
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  // Check for compile errors FRAGMENT_SHADER
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if(!success)
    {
      glGetShaderInfoLog(fragmentShader, sizeof(infoLog), NULL, infoLog);
      printf("Error: fragment shader compilation error: %s\n", infoLog);
    }
  
  // Link shaders
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  // glBindFragDataLocation(shaderProgram, 0, "color");
  glLinkProgram(shaderProgram);
  
  // Check the linking errors
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if(!success)
    {
      glGetProgramInfoLog(shaderProgram, sizeof(infoLog), NULL, infoLog);
      printf("Error: linking error: %s\n", infoLog);
    }

  // Link shaders with application
  GLuint position;
  glGetAttribLocation(shaderProgram, "position");
  glEnableVertexAttribArray(position);
  glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GLfloat), 0);
  
  // Delete shaders
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void OpenGLSet() // set up OpenGL
{
  GLint vpWidth, vpHeight;
  SDL_GL_GetDrawableSize(window, &vpWidth, &vpHeight);
  glViewport(0, 0, vpWidth, vpHeight);

  LoadShaders();

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  // Bind the Vertex Array Object first, then bind and set Vertex Buffers and attribute pointers
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vVertices), vVertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GLfloat), (GLvoid*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0); // ?
  glBindVertexArray(0);
  
}

void DeleteGLTrash()
{
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
}

void DeleteSDLTrash()
{
  SDL_GL_DeleteContext(glContext);
  SDL_DestroyWindow(window);
}

int vwen_sdl_glad(int argc, char* argv[]) //main
{
    /*
    // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }
    SDL_GL_LoadLibrary(NULL); // Default OpenGL is fine.

    // Setup window
    printf("setup gl\n");
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_DisplayMode current;
    SDL_GetCurrentDisplayMode(0, &current);
    SDL_Window *window = SDL_CreateWindow("ImGui SDL2+OpenGL3 example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
    SDL_GLContext glcontext = SDL_GL_CreateContext(window);
    printf("window created\n");
    */

    Init(); // Init SDL2 Glad

    //gl3wInit();

    // Use v-sync
    //SDL_GL_SetSwapInterval(1);

    // Disable depth test and face culling.
    //glDisable(GL_DEPTH_TEST);
    //glDisable(GL_CULL_FACE);

    PreLoop(); // To do before loop (display graphics card info)

    // Setup ImGui binding
    //ImGui_ImplSdlGL3_Init(window);

    // Load Fonts
    // (there is a default font, this is only if you want to change it. see extra_fonts/README.txt for more details)
    //ImGuiIO& io = ImGui::GetIO();
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../extra_fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../extra_fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../extra_fonts/ProggyClean.ttf", 13.0f);
    //io.Fonts->AddFontFromFileTTF("../../extra_fonts/ProggyTiny.ttf", 10.0f);
    //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());

    //bool show_test_window = true;
    //bool show_another_window = false;
    //ImVec4 clear_color = ImColor(114, 144, 154);
    printf("loop\n");
    // Main loop
    bool done = false;
    while (!done)
    {
        //printf("loop\n");
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            //ImGui_ImplSdlGL3_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;
        }
        //int w,h;
        //SDL_GetWindowSize(window, &w, &h);
        //glViewport(0, 0, 1280, 720);
        //glClearColor(0.0f, 0.5f, 1.0f, 0.0f);



        //ImGui_ImplSdlGL3_NewFrame(window);
        
        // 1. Show a simple window
        // Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets appears in a window automatically called "Debug"
        {
            //static float f = 0.0f;
            //ImGui::Text("Hello, world!");
            //ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
            //ImGui::ColorEdit3("clear color", (float*)&clear_color);
            //if (ImGui::Button("Test Window"))
            //{
                //show_test_window ^= 1;
                //printf("Window Click\n");
            //}
            //if (ImGui::Button("Another Window")) show_another_window ^= 1;
            //ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        }
        
        // 2. Show another simple window, this time using an explicit Begin/End pair
        //if (show_another_window)
        //{
            //ImGui::SetNextWindowSize(ImVec2(200,100), ImGuiCond_FirstUseEver);
            //ImGui::Begin("Another Window", &show_another_window);
            //ImGui::Text("Hello");
            //ImGui::End();

            //EditorWindow(&show_another_window);
        //}

        // 3. Show the ImGui test window. Most of the sample code is in ImGui::ShowTestWindow()
        //if (show_test_window)
        //{
            //ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
            //ImGui::ShowTestWindow(&show_test_window);
        //}
        
        // Rendering
        //glViewport(0, 0, (int)ImGui::GetIO().DisplaySize.x, (int)ImGui::GetIO().DisplaySize.y);
        //glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        //glClear(GL_COLOR_BUFFER_BIT);
        //ImGui::Render();

        glClearColor(0.1f, 0.1f, 0.2f, 1.0f); // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Rendering
        int display_w, display_h;
        //glfwGetFramebufferSize(window, &display_w, &display_h);
        //glViewport(0, 0, display_w, display_h);

        glViewport(0, 0, wWidth, wHeight);
  
        // Draw functions
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertices);
        glBindVertexArray(0);

        // draw our first triangle
        //glUseProgram(shaderProgram);
        //glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //glDrawArrays(GL_TRIANGLES, 0, 3);


        SDL_GL_SwapWindow(window);
        while(SDL_PollEvent(&event)) // handle events
        {
            if(event.type == SDL_QUIT)
                done = true;
        }
    }

    // Cleanup
    //ImGui_ImplSdlGL3_Shutdown();
    //SDL_GL_DeleteContext(glcontext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
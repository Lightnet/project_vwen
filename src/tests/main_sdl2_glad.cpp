/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/



#include <imgui.h>
#include <imgui_impl_sdl_glad.h>

//Using SDL and standard IO
#include <glad.h>    // This example is using gl3w to access OpenGL functions (because it is small). You may use glew/glad/glLoadGen/etc. whatever already works for you.
#include <SDL.h>
#include <SDL_syswm.h>

#include <stdio.h>
#include <stdlib.h>
#include <string>


#include "linmath.h"

#undef main

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

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

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

//GLuint vertices = 3;
GLfloat vVertices[] = {0.0f, -0.5f, 0.0f,
                       -0.5f, 0.5f, 0.0f,
                        0.5f, 0.5f, 0.0f};

void _sdlError(const char *mes)
{
	fprintf(stderr, "%s: %s\n", mes, SDL_GetError());
	exit(1);
}

//int main( int argc, char* args[] )
int main_sdl2( int argc, char* args[])
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	
	//The surface contained by the window
    SDL_Surface* screenSurface = NULL;
    

    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		// Request an OpenGL 4.5 context (should be core)
		//SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
		// Also request a depth buffer
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		//Create window
		window = SDL_CreateWindow( "SDL Glad GL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			
			// Check OpenGL properties
			printf("OpenGL loaded\n");
			gladLoadGLLoader(SDL_GL_GetProcAddress);

			//if(!gladLoadGL()) { exit(-1); }
			//printf("OpenGL Version %d.%d loaded\n", GLVersion.major, GLVersion.minor);

			//printf("Vendor:   %s\n", glGetString(GL_VENDOR));
			//printf("Renderer: %s\n", glGetString(GL_RENDERER));
			//printf("Version:  %s\n", glGetString(GL_VERSION));


			printf("Start Loop...\n");
			// Main loop
			bool done = false;
			while (!done)
			{
				SDL_Event event;
				while (SDL_PollEvent(&event))
				{
					//ImGui_ImplSdlGL3_ProcessEvent(&event);
					if (event.type == SDL_QUIT)
						done = true;
                }
                //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
                //glClear(GL_COLOR_BUFFER_BIT);

				//Get window surface
				screenSurface = SDL_GetWindowSurface( window );

				//Fill the surface white
				//SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
				
				//Update the surface
				SDL_UpdateWindowSurface( window );

				//Wait two seconds
				//SDL_Delay( 2000 );
				//SDL_GL_SwapWindow(window);
			}
		}
	}

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
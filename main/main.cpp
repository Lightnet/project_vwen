/*


*/

#include <imgui.h>
#include "imgui_impl_sdl.h"
#include <SDL.h>
#include <SDL_opengl.h>

int main(int argc, char* argv[])
{
	int posX = 100, posY = 100, width = 640, height = 480;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	SDL_Window *win = SDL_CreateWindow("ImGui SDL2+OpenGL VWEN", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	SDL_GLContext glcontext = SDL_GL_CreateContext(win);

	ImGui_ImplSdlGL2_Init(win);

	ImVec4 clear_color = ImColor(114, 144, 154);
	while (1) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			ImGui_ImplSdlGL2_ProcessEvent(&e);
			if (e.type == SDL_QUIT) {
				break;
			}
		}
		ImGui_ImplSdlGL2_NewFrame(win);
		ImGui::Begin("My window");
		ImGui::Text("Hello world.");
		ImGui::End();
		glViewport(0, 0, (int)ImGui::GetIO().DisplaySize.x, (int)ImGui::GetIO().DisplaySize.y);
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui::Render();
		SDL_GL_SwapWindow(win);
	}
	ImGui_ImplSdlGL2_Shutdown();
	SDL_GL_DeleteContext(glcontext);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
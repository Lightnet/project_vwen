/*
	Project: VWEN

	Information: Main entry. SDL and ImGui

*/

#include <SDL.h>
#include <SDL_syswm.h>
#include <SDL_opengl.h>
#include "imgui.h"
#include "editor.h"

#include <stdio.h>


void NodeInit(){
    printf("Editor Node Init!");
}

void EditorWindow(bool* p_open){
	
	ImGui::SetNextWindowSize(ImVec2(200,100), ImGuiCond_FirstUseEver);
	ImGui::Begin("Another Window", p_open);
	ImGui::Text("Editor Panel");
	ImGui::End();

}
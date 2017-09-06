


struct SDL_Window;
typedef union SDL_Event SDL_Event;

void        Shutdown();
void        NodeInit();

void EditorWindow(bool* p_open);

IMGUI_API bool        Init(SDL_Window* window);
IMGUI_API void        Shutdown();
IMGUI_API void        NewFrame(SDL_Window* window);
IMGUI_API bool        ProcessEvent(SDL_Event* event);
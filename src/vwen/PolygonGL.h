


#include "glad/glad.h"
#include <array>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

namespace Vwen{

    class PolygonGL : public ObjectNode{
        // OpenGL
	    GLuint shaderProgram;
    
        GLuint VAO; // vertex array object
        GLuint VBO; // vertex buffer object

        GLuint vertices = 3;
        //GLfloat vVertices[2];// = {0.0f, -0.5f, 0.0f,-0.5f, 0.5f, 0.0f,0.5f, 0.5f, 0.0f};
        

        public:
            //GLfloat vVertices[];// = {0.0f, -0.5f, 0.0f,-0.5f, 0.5f, 0.0f,0.5f, 0.5f, 0.0f};
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

            //void OpenGLSet(GLfloat _vVertices[]) // set up OpenGL
            void OpenGLSet(int _size,float _vVertices[],int _len) // set up OpenGL
            {
        
                LoadShaders();

                std::cout << " OpenGLSet Length of array = " <<  sizeof(_vVertices) << std::endl;

                float Vertices[] = {0.0f, -0.5f, 0.0f,-0.5f, 0.5f, 0.0f,0.5f, 0.5f, 0.0f};

                const int size = sizeof(_vVertices);

                float verts[size];

                std::copy(verts, verts + _len, _vVertices);


                for(int i=0; i<_len; i++){
                    verts[i] = Vertices[i];
                    cout << "vVertices GL"<< verts[i] << endl;
                }


                //std::memcpy();
                glGenVertexArrays(1, &VAO);
                glGenBuffers(1, &VBO);
                // Bind the Vertex Array Object first, then bind and set Vertex Buffers and attribute pointers
                glBindVertexArray(VAO);
                //std::array<const float,9> vVertices = {0.0f, -0.5f, 0.0f,-0.5f, 0.5f, 0.0f,0.5f, 0.5f, 0.0f};
                //float vVertices[] = _vVertices;
                //GLfloat vVertices[] = {0.0f, -0.5f, 0.0f,-0.5f, 0.5f, 0.0f,0.5f, 0.5f, 0.0f};
                glBindBuffer(GL_ARRAY_BUFFER, VBO);
                glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

                //glBufferData(GL_ARRAY_BUFFER, sizeof(_vVertices), _vVertices, GL_STATIC_DRAW);
                //glBufferData(GL_ARRAY_BUFFER, sizeof(vVertices), vVertices, GL_STATIC_DRAW);//default
                //glBufferData(GL_ARRAY_BUFFER, sizeof(vVertices), vVertices, GL_DYNAMIC_DRAW);
                //glBufferData(GL_ARRAY_BUFFER, sizeof(_vVertices), _vVertices, GL_DYNAMIC_DRAW);
        
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GLfloat), (GLvoid*)0);
                glEnableVertexAttribArray(0);
        
                glBindBuffer(GL_ARRAY_BUFFER, 0); // ?
                glBindVertexArray(0);

                //delete [] vVertices;
            }

            void DeleteGLTrash()
            {
                glDeleteVertexArrays(1, &VAO);
                glDeleteBuffers(1, &VBO);
            }


            void DoSomething(){
                cout << "Inside namespace vwen of ObjectNode" << endl;
            }
            void Setup(){
                cout << "Inside namespace vwen of ObjectNode" << endl;
            }

            void Render(){
                //cout << "Inside namespace vwen of ObjectNode" << endl;
                glUseProgram(shaderProgram);
                glBindVertexArray(VAO);
                glDrawArrays(GL_TRIANGLES, 0, vertices);
                glBindVertexArray(0);

                //for(int i=0; i<8; i++){
                    //printf(str(vVertices[i]));
                //}
            }

            PolygonGL()
            {
                
                //GLfloat Vertices[] = {0.0f, -0.5f, 0.0f,-0.5f, 0.5f, 0.0f,0.5f, 0.5f, 0.0f};
                float Vertices[] = {0.0f, -0.5f, 0.0f,-0.5f, 0.5f, 0.0f,0.5f, 0.5f, 0.0f};
                //int size =  (sizeof(Vertices)/sizeof(Vertices[0]));
                int len = (sizeof(Vertices)/sizeof(Vertices[0]));
                int size = sizeof(Vertices);
                //std::cout << "Length of array = " <<  (sizeof(Vertices)/sizeof(Vertices[0])) << std::endl;
                std::cout << "Length of array = " <<  sizeof(Vertices) << std::endl;
                OpenGLSet(size,Vertices,len);
                cout << "Setup GL" << endl;
            }
    };
    
}
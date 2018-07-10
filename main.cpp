#include <stdio.h>
#include <stdlib.h>


#include <GL/glew.h>
#include <GL/gl.h>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
#include <ctime>

using namespace glm;

#define GLSL(src) #src

static void error_callback(int error, const char *description) {
  fputs(description, stderr);
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
}

    // Identificar el vertex buffer
    GLuint vertexbuffer;
    GLuint VertexArrayID;
void init(){
    static const GLfloat g_vertex_buffer_data[] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f,
    };
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
// Generar un buffer, poner el resultado en el vertexbuffer que acabamos de crear
    glGenBuffers(1, &vertexbuffer);
// Los siguientes comandos le darán características especiales al 'vertexbuffer'
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
// Darle nuestros vértices a  OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

static void render(GLFWwindow *window, double x) {
  glClear(GL_COLOR_BUFFER_BIT);
    // 1rst attribute buffer : vértices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
            0,                  // atributo 0. No hay razón particular para el 0, pero debe corresponder en el shader.
            3,                  // tamaño
            GL_FLOAT,           // tipo
            GL_FALSE,           // normalizado?
            0,                    // Paso
            (void*)0            // desfase del buffer
    );
// Dibujar el triángulo !
    glDrawArrays(GL_TRIANGLES, 0, 3); // Empezar desde el vértice 0S; 3 vértices en total -> 1 triángulo
    glDisableVertexAttribArray(0);
}

int main() {
  GLFWwindow *window;

  glfwSetErrorCallback(error_callback);

  if (!glfwInit())
    exit(EXIT_FAILURE);

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


  window = glfwCreateWindow(640, 480, "OpenGL Boilerplate", NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  glfwMakeContextCurrent(window);

  glewExperimental = GL_TRUE;
  GLenum  glewInitCode = glewInit();
  if(glewInitCode != GLEW_NO_ERROR){
      std::cout << "GLEW Error: " << glewGetErrorString(glewInitCode) << std::endl;
      exit(EXIT_FAILURE);
  }

  printf("GL Version: %s\n", glGetString(GL_VERSION));
    printf("GL Shader Version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    printf("GL Vendor: %s\n", glGetString(GL_VENDOR));
    printf("GL Renderer: %s\n", glGetString(GL_RENDERER));

  glfwSetKeyCallback(window, key_callback);
  init();
  //double time = 0;
  while (!glfwWindowShouldClose(window)) {
    render(window, time(nullptr));
    //time += 0.5;

    glfwSwapBuffers(window);
    glfwPollEvents();
    //glfwWaitEvents();
  }

  glfwDestroyWindow(window);

  glfwTerminate();
  exit(EXIT_SUCCESS);
}

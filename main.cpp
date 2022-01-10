#include <iostream>
#include <chrono>
#include "glad.c"
#include "glfw3.h"
using namespace std;
using namespace chrono;
void tick(GLFWwindow *window){

    glfwWaitEvents();
    glClearColor(0.0f,0.5f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}
void run(GLFWwindow *window){
    auto startTime = steady_clock::now();
    while(!glfwWindowShouldClose(window)){
        auto endTime = steady_clock::now();
        if(duration_cast<nanoseconds>(endTime-startTime).count()>=16666666L){
            startTime = steady_clock::now();
            tick(window);
        }
    }
}
int start(){

    if(!glfwInit()){
        return 1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *window = glfwCreateWindow(854,480,"opengl", nullptr, nullptr);

    if(!window){
        glfwTerminate();
        return 2;
    }
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glad_glViewport(0,0,854,480);

    run(window);
    return 0;
}
int main() {
   cout<<start();
   glfwTerminate();
}

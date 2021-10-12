#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "initgl.h"
const int WIDTH = 640;
const int HEIGHT = 480;

void render();
void processInput(GLFWwindow *window);


int main(int argc, char** argv) {

    GLFWwindow* window = initWindow(WIDTH, HEIGHT);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
 
    glfwTerminate();
    return 0;
}

void render() {
    glClearColor(1.0,1.0,0.0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

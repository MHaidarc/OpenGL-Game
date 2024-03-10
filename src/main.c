#include <stdio.h>
#include <stdlib.h>

#include <glad/gl.h>

#include <GLFW/glfw3.h>

const GLuint WINDOW_WIDTH = 640, WINDOW_HEIGHT = 480;

static void key_callback(GLFWwindow *window, int key, int scancode, int action,
                         int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void error_callback(int error, const char *description) {
  fprintf(stderr, "Error: %s\n", description);
}

int main(void) {
  if (!glfwInit()) {
    fprintf(stderr, "Failed to initialize GLFW\n");
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window =
      glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "GLFW Window", NULL, NULL);

  glfwMakeContextCurrent(window);

  glfwSetKeyCallback(window, key_callback);
  glfwSetErrorCallback(error_callback);

  if (!window) {
    glfwTerminate();
    return -1;
  }

  gladLoadGL(glfwGetProcAddress);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClear(GL_COLOR_BUFFER_BIT);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // double time = glfwGetTime();

    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}

/*
 * This is a very basic Windows C application for testing GLUT (and compatible
 * implementations such as freeglut). It displays a red square, and exits when
 * the escape key is pressed.
 */

#include <stdlib.h>
#include <stdio.h>
// Always include glew.h before freeglut.h or gl.h
#include <GL/glew.h>
#include <GL/glut.h>
#include "Callbacks.h"

/* Main method */
int main(int argc, char** argv)
{
  glutInit(&argc, argv);

  /* Create a single window with a keyboard and display callback */
  glutCreateWindow("GLUT Test");

  GLenum err = glewInit();
  if (GLEW_OK != err) {
    printf("GLEW init failed: %s\n", glewGetErrorString(err));
    return 1;
  }

  glutKeyboardFunc(&keyboard);
  glutDisplayFunc(&display);

  /* Run the GLUT event loop */
  glutMainLoop();

  return EXIT_SUCCESS;
}

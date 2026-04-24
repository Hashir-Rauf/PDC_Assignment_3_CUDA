#ifndef __PLATFORM_GL_H__
#define __PLATFORM_GL_H__

#ifdef _WIN32
#define GLUT_RGBA      0x0000
#define GLUT_DOUBLE    0x0002
#define GL_DEPTH_TEST  0x0B71
#define GL_COLOR_BUFFER_BIT 0x4000
#define GL_PROJECTION  0x1701
#define GL_MODELVIEW   0x1700
#define GL_RGBA        0x1908
#define GL_FLOAT       0x1406
typedef unsigned int GLenum;
typedef float        GLfloat;
typedef int          GLint;
typedef int          GLsizei;
typedef unsigned int GLbitfield;
inline void glutInit(int*, char**) {}
inline void glutInitWindowSize(int, int) {}
inline void glutInitDisplayMode(unsigned int) {}
inline int  glutCreateWindow(const char*) { return 0; }
inline void glutDisplayFunc(void (*)()) {}
inline void glutKeyboardFunc(void (*)(unsigned char, int, int)) {}
inline void glutMainLoop() {}
inline void glutPostRedisplay() {}
inline void glutSwapBuffers() {}
inline void glViewport(GLint, GLint, GLsizei, GLsizei) {}
inline void glDisable(GLenum) {}
inline void glClearColor(GLfloat, GLfloat, GLfloat, GLfloat) {}
inline void glClear(GLbitfield) {}
inline void glMatrixMode(GLenum) {}
inline void glLoadIdentity() {}
inline void glOrtho(double, double, double, double, double, double) {}
inline void glRasterPos2i(GLint, GLint) {}
inline void glDrawPixels(GLsizei, GLsizei, GLenum, GLenum, const void*) {}
#elif defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#endif


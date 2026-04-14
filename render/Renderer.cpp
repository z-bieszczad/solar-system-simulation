#include "Renderer.h"

Renderer::Renderer()
    : _cameraDistance(30.0f),
    _cameraAngleX(0.0f),
    _cameraAngleY(20.0f),
    _lastMouseX(0),
    _lastMouseY(0),
    _mousePressed(false),
    _paused(false),
    _timeScale(1.0f){

    }

Renderer::~Renderer() {
}

void Renderer::init(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Solar System 3D - Simulation");

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    setupLighting();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOV, 1024.0/768.0, NEAR_PLANE, FAR_PLANE);
    glMatrixMode(GL_MODELVIEW);
}
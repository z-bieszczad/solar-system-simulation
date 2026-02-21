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
}
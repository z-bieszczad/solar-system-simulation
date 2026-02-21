#pragma once
#include <GL/glut.h>

class Renderer {
    public:
        Renderer();
        ~Renderer();

        void init(int argc, char** argv);

    private:
        float _cameraDistance;
        float _cameraAngleX;
        float _cameraAngleY;
        int _lastMouseX;
        int _lastMouseY;
        bool _mousePressed;

        bool _paused;
        float _timeScale;

        static constexpr float NEAR_PLANE = 0.1f;
        static constexpr float FAR_PLANE = 1000.0f;
        static constexpr float FOV = 45.0f;
        static constexpr int STAR_COUNT = 1000;
};
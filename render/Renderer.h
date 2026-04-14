#pragma once
#include <GL/glut.h>
#include <vector>
#include "../core/CelestialBody.h"

class Renderer {
    public:
        Renderer();
        ~Renderer();

        void init(int argc, char** argv);

        void render(const std::vector<CelestialBody>& bodies);

        void handleKeyboard(unsigned char key, int x, int y);
        void handleMouse(int button, int state, int x, int y);
        void handleMotion(int x, int y);

        bool isPaused() const { return _paused; }
        float getTimeScale() const { return _timeScale; }

    private:

        void setupLighting();
        void setupCamera();
        void drawStars();
        void drawOrbit(float radious, const Vector3d& color);

        void drawCelestialBody(const CelestialBody& body);
        void drawPlanet(const Vector3d& position, double radius, 
                        const Vector3d& color, double rotationAngle,
                        const Vector3d& rotationAxis);

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
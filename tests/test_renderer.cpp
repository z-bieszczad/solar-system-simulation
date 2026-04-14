#include "../render/Renderer.h"
#include "../core/CelestialBody.h"
#include <vector>

Renderer* g_renderer = nullptr;

void display() {
    if (g_renderer) {
        
        static std::vector<CelestialBody> testBodies;
        if (testBodies.empty()) {
            
            testBodies.push_back(CelestialBody("Sun", 0, 2.5, 
                Vector3d(0,0,0), Vector3d(0,0,0),
                Vector3d(1,1,0), Vector3d(0,1,0), 0, 0));
            
            testBodies.push_back(CelestialBody("Earth", 0, 0.7,
                Vector3d(5,0,0), Vector3d(0,0,1),
                Vector3d(0.2,0.4,1), Vector3d(0,1,0), 0, 0.1));
        }
        g_renderer->render(testBodies);
    }
}

void keyboard(unsigned char key, int x, int y) {
    if (g_renderer) g_renderer->handleKeyboard(key, x, y);
}

void mouse(int button, int state, int x, int y) {
    if (g_renderer) g_renderer->handleMouse(button, state, x, y);
}

void motion(int x, int y) {
    if (g_renderer) g_renderer->handleMotion(x, y);
}

int main(int argc, char** argv) {
    Renderer renderer;
    g_renderer = &renderer;
    
    renderer.init(argc, argv);
    
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    
    glutMainLoop();
    return 0;
}
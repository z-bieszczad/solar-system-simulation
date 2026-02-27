# solar-system-simulation
 **Work in Progress** – This project is currently under active development.
 
Solar System Simulation is a C++ project that visualizes the gravitational dynamics of celestial bodies in 3D space using OpenGL and GLUT. The system implements a classical N-body gravitational model, where each body interacts gravitationally with every other body in the simulation.
The project simulates planetary motion based on Newton’s law of universal gravitation. At each simulation step, gravitational forces are computed between all pairs of bodies, and their motion is integrated over time using Newton’s second law. In addition to orbital motion, each celestial body rotates independently around its own axis, providing a realistic visual representation of planetary spin.

The simulation is implemented in a modular and extensible architecture, making it easy to expand with additional physics features such as improved numerical integrators, collision handling, or tidal interactions. The rendering layer is fully separated from the physics engine, ensuring clean project structure.

# Project Structure
- core/- Contains core physics classes such as CelestialBody and PhysicsSystem
- math/ - Provides mathematical utilities (Vector3d)
- render/ - Handles OpenGL/GLUT rendering, camera setup, lighting, and object drawing
- world/ - Manages simulation state, object initialization, and system updates
- tests/ - Includes unit tests for physics calculations and motion integration


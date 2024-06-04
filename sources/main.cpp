/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          main.cpp                                      ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-06-03                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "raytracer.h"

void errorCallback(int error, const char* description) {
    std::cerr << "Error: " << description << std::endl;
}

int main() {
    // Set GLFW error callback
    glfwSetErrorCallback(errorCallback);

    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its GLFW context
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Ray Tracer", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Poll for and process events
        glfwPollEvents();
	Tuple pos = Tuple::point(0, 1, 0);
	Tuple vel = Tuple::vector(0.707107, 0.707107, 0);
	Tuple grav = Tuple::vector(0, -0.1, 0);
	Tuple wind = Tuple::vector(-0.01, 0, 0);
	Projectile	p = Projectile(pos, vel);
	Environment	e = Environment(grav, wind);
	while (p._position.y() > 0)
	{
		p = tick(p, e);
		std::cout << "Projectile position = x: " << p._position.x() << "; y: " \
			<< p._position.y() << "; z: " << p._position.z() << std::endl;
	}
	break ;
        // Render here
        // You'll add your ray tracing code here

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Clean up
    glfwTerminate();
    return 0;
}

/*int	main(void)
{
	Tuple p = Tuple::point(2.0, 1.0, 3.0);
	Tuple v = Tuple::vector(3.0, 2.0, 1.0);

	std::cout <<
		"Point[x: " << p.x() << ", y: " << p.y()
		<< ", z: " << p.z() << ", w: " << p.w()
		<< "]" << std::endl;
	std::cout <<
		"Vector[x: " << v.x() << ", y: " << v.y()
		<< ", z: " << v.z() << ", w: " << v.w()
		<< "]" << std::endl;

	std::cout << equal(p.x(), v.y()) << std::endl;
	Tuple res = p + v;
	std::cout <<
		"p+v[x: " << res.x() << ", y: " << res.y()
		<< ", z: " << res.z() << ", w: " << res.w()
		<< "]" << std::endl;
	res = p - v;
	std::cout <<
		"Vector[x: " << res.x() << ", y: " << res.y()
		<< ", z: " << res.z() << ", w: " << res.w()
		<< "]" << std::endl;
	Tuple neg = -v;
	std::cout <<
		"-Vector[x: " << neg.x() << ", y: " << neg.y()
		<< ", z: " << neg.z() << ", w: " << neg.w()
		<< "]" << std::endl;
	Tuple mul = v * 3.5;
	std::cout <<
		"Vector[x: " << mul.x() << ", y: " << mul.y()
		<< ", z: " << mul.z() << ", w: " << mul.w()
		<< "]" << std::endl;
	Tuple div = v / 2;
	std::cout <<
		"Vector[x: " << div.x() << ", y: " << div.y()
		<< ", z: " << div.z() << ", w: " << div.w()
		<< "]" << std::endl;
	Tuple mag = Tuple::vector(0, 1.0, 0);
	std::cout << "Magnitude of v: " << magnitude(mag) << std::endl;
	Tuple vn = Tuple::vector(4, 0, 0);
	Tuple norm = normalize(vn);
	std::cout <<
		"Norm[x: " << norm.x() << ", y: " << norm.y()
		<< ", z: " << norm.z() << ", w: " << norm.w()
		<< "]" << std::endl;
	std::cout << "Magnitude of norm: " << magnitude(norm) << std::endl;
	Tuple v1 = Tuple::vector(1, 2, 3);
	Tuple v2 = Tuple::vector(2, 3, 4);
	std::cout << "Dot product of v1 and v2: " << dot(v1, v2) << std::endl;
	Tuple cross1 = cross(v1, v2);
	Tuple cross2 = cross(v2, v1);
	std::cout <<
		"Cross1[x: " << cross1.x() << ", y: " << cross1.y()
		<< ", z: " << cross1.z() << ", w: " << cross1.w()
		<< "]" << std::endl;
	std::cout <<
		"Cross2[x: " << cross2.x() << ", y: " << cross2.y()
		<< ", z: " << cross2.z() << ", w: " << cross2.w()
		<< "]" << std::endl;
	return (0);
}*/


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

int main() {
    Tuple initial_position = Tuple::point(0, 1, 0);  
    Tuple initial_velocity = Tuple::vector(1, 1, 0);  
    initial_velocity.normalized();

	Projectile p(initial_position, initial_velocity);
    
    Tuple gravity = Tuple::vector(0, -0.1, 0);
    Tuple wind = Tuple::vector(-0.01, 0, 0);
    Environment e(gravity, wind);
    
    int ticks = 0;
    
    while (p._position.y() > 0) {
        std::cout << "Tick " << ticks + 1 << ": " 
                  << "Position (" << p._position.x() << ", " << p._position.y() << ", " << p._position.z() << ")" 
                  << std::endl;
        p = tick(p, e);
        ticks++;
    }

    std::cout << "Final Position after " << ticks << " ticks: (" 
              << p._position.x() << ", " << p._position.y() << ", " << p._position.z() << ")" 
              << std::endl;

    return 0;
}


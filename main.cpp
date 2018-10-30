//
// Created by Luke Janusz Opaliński on 25/10/2018.
//

#include <iostream>
#include <cmath>
#include "particle.h"

int main() {
    int t = 0;

    std::vector<Particle> p(2);

//    p[0].m = 1;
//    p[0].id = 0;
//    set_vector_zero(p[0].p); p[0].p.x = 0.5;
//    set_vector_zero(p[0].v);
//    set_vector_zero(p[0].a);
//
//    p[1].m = 1;
//    p[1].id = 1;
//    set_vector_zero(p[1].p); p[1].p.x = -0.5;
//    set_vector_zero(p[1].v);
//    set_vector_zero(p[1].a);

    p[0].m = 5.97237e+24;
    p[0].id = 0;
    set_vector_zero(p[0].p);
    set_vector_zero(p[0].v);
    set_vector_zero(p[0].a);

    p[1].m = 7.342e+22;
    p[1].id = 1;
    set_vector_zero(p[1].p); p[1].p.x = 405400e+3;
    set_vector_zero(p[1].v); p[1].v.y = comp_orbital_velocity(p[0].m, p[1].p.x);
    set_vector_zero(p[1].a);

    std::cout << p[1].v.y << std::endl << std::endl;

    while (t < 2592000) {
        if (p[1].p.y < 1) {
            std::cout << "Time: " << t << "s" << std::endl;
            print_p_stat(p[0]);
            print_p_stat(p[1]);
        }

        update(p, true);
        t += dt;

//        if (p[0].p.x == p[1].p.x) {
//            std::cout << "COLLISION" << std::endl << std::endl;
//            break;
//        }
    }

    std::cout << "Time: " << t << "s" << std::endl;
    print_p_stat(p[0]);
    print_p_stat(p[1]);

    return 0;
}
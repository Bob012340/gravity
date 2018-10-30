//
// Created by Luke Janusz Opaliński on 25/10/2018.
//

#include "particle.h"
#include <vector>
#include <iostream>
#include <cmath>

void set_vector(Vector v, double param[3]) {
    v.x = param[0];
    v.y = param[1];
    v.z = param[2];
}

void set_vector_zero(Vector v) {
    v.x = 0;
    v.y = 0;
    v.z = 0;
}

void update(std::vector<Particle>& p, bool move) {
    for (unsigned long int i = 0; i < p.size(); ++i) {

        p[i].v.x += p[i].a.x * dt;
        p[i].v.y += p[i].a.y * dt;
        p[i].v.z += p[i].a.z * dt;

        set_vector_zero(p[i].a);

        for (unsigned long int j = 0; j < p.size(); ++j) {
            if (i == j)
                continue;

            Vector r;
            r.x = p[i].p.x - p[j].p.x;
            r.y = p[i].p.y - p[j].p.y;
            r.z = p[i].p.z - p[j].p.z;

//            std::cout << r.x << "," << r.y << "," << r.z << std::endl;

            double d3 = pow(sqrt(pow(r.x, 2) + pow(r.y, 2) + pow(r.z, 2)), 3);
            double Gm = G * p[j].m;

//            std::cout << d3 << std::endl << Gm << std::endl;

            p[i].a.x = -(Gm * r.x) / d3;
            p[i].a.y = -(Gm * r.y) / d3;
            p[i].a.z = -(Gm * r.z) / d3;

//            std::cout << p[i].a.x << "," << p[i].a.y << "," << p[i].a.z << std::endl  << std::endl;
        }

        if (move) {
//            std::cout << "Boo Move" << std::endl << std::endl;
            p[i].v.x += p[i].a.x * dt;
            p[i].v.y += p[i].a.y * dt;
            p[i].v.z += p[i].a.z * dt;

            p[i].p.x += p[i].v.x * dt;
            p[i].p.y += p[i].v.y * dt;
            p[i].p.z += p[i].v.z * dt;
        }

    }
}

void print_p_stat(Particle p) {
    using namespace std;
    cout << "          ID:\t" << p.id << endl;
    cout << "        Mass:\t" << p.m << endl;
    cout << "    Position:\t(" << p.p.x << ", " << p.p.y << ", " << p.p.z << ")" << endl;
    cout << "    Velocity:\t(" << p.v.x << ", " << p.v.y << ", " << p.v.z << ")" << endl;
    cout << "Acceleration:\t(" << p.a.x << ", " << p.a.y << ", " << p.a.z << ")" << endl;
    cout << endl;
}

double comp_orbital_velocity(double m, double r) {
    return sqrt((G * m) / r);
}
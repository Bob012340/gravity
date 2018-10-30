//
// Created by Luke Janusz Opaliński on 25/10/2018.
//

#ifndef GRAVITY_PARTICLE_H
#define GRAVITY_PARTICLE_H

#include <vector>

const double dt = 60 * 60 * 60;
const double G = 6.674E-11;

class Vector {
public:
    double x;
    double y;
    double z;
};

class Particle {
public:
    unsigned long id;
    double m;   // Mass
    Vector p;   // Position
    Vector a;   // Acceleration
    Vector v;   // Velocity
};

void set_vector(Vector v, double param[3]);
void set_vector_zero(Vector v);
void update(std::vector<Particle>& p, bool move);
void print_p_stat(Particle p);
double comp_orbital_velocity(double m, double r);

#endif //GRAVITY_PARTICLE_H

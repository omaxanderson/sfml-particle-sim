//
//  Particle.hpp
//  std_test2
//
//  Created by Max Anderson on 9/22/17.
//  Copyright © 2017 Max Anderson. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include <vector>
#include <utility>
#include "BasicConfig.hpp"
using namespace std;

class Particle {
public:
    Particle();
    Particle(float x, float y, float mass = 1);
    int getX();
    int getY();
    void applyForce(vec2 force);
    void update();
    void draw(sf::VertexArray& v);
    vec2 getPos();
    void checkCollisionAndGravitation(vector<Particle> vec);
    vec2 getVelocity();
    
private:
    vec2 pos;
    vec2 vel;
    vec2 acc;
    double mass;
    sf::Color color;
    sf::Vertex vertex;

};

#endif /* Particle_hpp */

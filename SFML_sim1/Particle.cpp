//
//  Particle.cpp
//  std_test2
//
//  Created by Max Anderson on 9/22/17.
//  Copyright © 2017 Max Anderson. All rights reserved.
//

#include "Particle.hpp"
#include <iostream>

Particle::Particle() {
    pos.x = 0;
    pos.y = 0;
    vel.x = 0;
    vel.y = 0;
    acc.x = 0;
    acc.y = 0;
    mass = 1;
    vertex = sf::Vertex(sf::Vector2<float>(0, 0), sf::Color(255, 255, 255));
}

Particle::Particle(float x, float y, float mass) {
    pos.x = x;
    pos.y = y;
    vel.x = 0;
    vel.y = 0;
    acc.x = 0;
    acc.y = 0;
    this->mass = mass;
    int c = rand() % 255;
    color = sf::Color(c, c, c);
    vertex = sf::Vertex(sf::Vector2<float>(x, y), color);
}

vec2 Particle::getPos() {
    return vec2(pos.x, pos.y);
}

int Particle::getX() { return pos.x; }

int Particle::getY() { return pos.y; }

void Particle::applyForce(vec2 force) {
    acc.add(force);
}

void Particle::draw(sf::VertexArray& v) {
    v.append(vertex);
}

void Particle::update() {
    vel.add(acc);
    pos.add(vel);
    
    vertex = sf::Vertex(sf::Vector2<float>(pos.x, pos.y), color);
    acc.mult(0);
}

vec2 Particle::getVelocity() {
    return vec2(vel.x, vel.y);
}

void Particle::checkCollisionAndGravitation(vector<Particle> vec) {
    for (Particle &p : vec) {
        // float px = p.getX();
        // float py = p.getY();
        if (euclideanDist(p.getPos(), pos) < 0.1) {
            applyForce(p.getVelocity().mult(0.01));
            cout << "c";
        }
        
        // applyForce(vec2((pos.x - p.x) * GRAVITATIONAL_CONST / 50000000,
        //                (pos.y - p.y) * GRAVITATIONAL_CONST / 50000000));
    }
}








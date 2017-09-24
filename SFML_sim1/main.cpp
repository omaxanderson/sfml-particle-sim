
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "BasicConfig.hpp"

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "Particle.hpp"
using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const double GRAVITATIONAL_CONST = 0.0667408;
const int NUM_PARTICLES = 10000;
const int NUM_THREADS = 5;

vec2 gravity;
vec2 blackHole;
bool gravityOn = false;
bool attractionOn = false;

vector<Particle> particles;


void initialize() {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles.push_back(Particle(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT));
    }
}

void draw() {
    for (Particle p : particles) {
        p.draw()
    }
}

int main(int, char const**)
{
    // Create the main window
    //sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL");
    glEnable(GL_TEXTURE_2D);

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    case sf::Keyboard::G:
                        cout << "gravity on" << endl;
                        break;
                    default:
                        cout << "unhandled" << endl;
                }
            }
            

            
            
        }

        // Clear screen
        window.clear();

        draw();
        
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}

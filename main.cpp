/************************************************************
 *Name: <Pratush Kc>
 *Course name: <COMP.2040>
 *Assignment: <PS2b: Static N-Body Simulation>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/24/2022>
 *Sources Of Help: <Discussions on Dr. Daly's discord server from other students and Dr. Daly>
 Note: Some sample code was closely borrowed from the sfml tutorial website
 Here are some of the references used: 
 https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Drawable.php
 https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php
 https://www.sfml-dev.org/tutorials/2.5/graphics-text.php
 Font file source:
 https://www.wfonts.com/
 https://www.sfml-dev.org/tutorials/2.5/audio-sounds.php
 https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Sound.php
************************************************************/
#include <iostream>
#include "CelestialBody.h"
#include "Universe.h"
#include <fstream>
#include <string> 

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

int main(int argc, char* argv[]){
    
    if(argc != 3){
        std::cerr << "Incorrect number of command line arguements entered!" << std::endl;
        return -1;
    }
    //start time (0 seconds)
    double t = 0; 

    //simulation time
    double T = std::stod(argv[1]); 

    //change in time 
    double delta_t = std::stod(argv[2]);

    //number of celestial bodies
    int n; 

    //iterator variable
    int i; 

    //radius of universe
    double radius; 

    //height of window (set to 500)
    int window_height = 500; 

    //width of window (set to 500)
    int window_width = 500; 

    //get number of
    std::cin >> n; 
    std::cin >> radius; 

    //declare universe object
    Universe universe(window_height, window_width, radius);

    //read data and load into universe object vector 
    for(i = 0; i < n; i++){
        universe.add_body();
    }

  
    //make window with dimensions of 500 x 500 pixels
    sf::RenderWindow window(sf::VideoMode(window_height, window_width), "The Universe by Pratush Kc");
    //set to 60 frames per second
    window.setFramerateLimit(60);
    
    //holds background imagge
    sf::Image background;

    if(!background.loadFromFile("starfield.jpg")){
        std::cout << "Unable to load background!" << std::endl;
        return -1;
    }

    //get texture from image
    sf::Texture texture_of_background;
    texture_of_background.loadFromImage(background);

    //get sprite from image
    sf::Sprite sprite_of_background;

    //set texture using the background texture
    sprite_of_background.setTexture(texture_of_background);

    //position at the edge of the window (to allow for a full view)
    sprite_of_background.setPosition(sf::Vector2f(0, 0));


    //open window
    while(window.isOpen()){
        
        sf::Event event; 
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                
            }
        }

        //close if time is up
        if(t >= T){
            window.close();
        }

        window.clear();

        //draw background
        window.draw(sprite_of_background);

        //draw all celestial bodies
        universe.draw_universe(window);

        //step 
        universe.step(delta_t);
        t += delta_t; 
        
        window.display();
    }
    
    universe.print_data();

    return 0; 
}
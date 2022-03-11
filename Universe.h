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
#pragma once

#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "CelestialBody.h"
#include <memory>
#include <vector>
#include <math.h>
#include <iomanip>

//inherits members from CelestialBody to make 
class Universe : public CelestialBody{
    public:

    //default constructor
    Universe();

    //constructor which takes the window dimensions and radius
    Universe(double _window_height, double _window_width, double _radius);

    //destructor
    ~Universe();

    //load vector of celestial bodies
    void add_body();

    //draw all celestial bodies taking the target as a parameter
    void draw_universe(sf::RenderWindow& target);

    //move celestial body object with respect to time in seconds
    void step(double seconds);

    //print celestial body information
    void print_data();

    private:

    //vector of pointers to objects
    std::vector<std::unique_ptr<CelestialBody>> c_bodies;

    //height of the window
    double window_height; 

    //width of the window
    double window_width;

    //radius of the window
    double radius; 


};



#endif
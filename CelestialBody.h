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

#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <string.h>
#include <memory>

//inherit from sf::drawable
class CelestialBody : public sf::Drawable{
    public:
        
        //default constructor
        CelestialBody();

        //construct using values scanned from file (Note: all though this constructor exists 
        //as per the assignment specs, it is not used in this program as the overloaded >> operator
        //takes the data and plugs it into a celestial body object)
        CelestialBody(double _xpos, double _ypos, double _xvel, double _yvel, double _mass, std::string _name);

        //destructor
        ~CelestialBody();

        //virtual function to draw celestial body
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        //friend function for loading celestial bodies into object
        friend std::istream& operator>>(std::istream& in, CelestialBody& obj);

        //set dimensions and universe radius
        void set_window_and_radius(double _window_height, double _window_width, double _radius);

        //change velocity 
        void new_velocity(double _xvel, double _yvel);

        //change position
        void new_position(double _xpos, double _ypos);

        //accessor for x position
        double get_xpos() const;

        //accessor for y position
        double get_ypos() const;

        //accessor for x velocity
        double get_xvel() const; 

        //accessor for y velocity
        double get_yvel() const; 

        //accessor for mass
        double get_mass() const; 

        //accessor for name
        std::string get_name() const;

        void update_position();

    private:
    
    //x position of celestial body
    double xpos; 

    //y position of celestial body
    double ypos; 

    //x velocity of celestial body
    double xvel; 

    //y velocity of celestial body
    double yvel; 

    //mass of celestial body
    double mass;

    //name of celestial body
    std::string name; 

    //height of window
    double window_height;

    //width of window
    double window_width;

    //size of the universe (given radius)
    double radius; 

    //contains the image
    sf::Image c_image;

    //texture of celestial body
    sf::Texture c_texture; 

    //mass of celestial body
    sf::Sprite c_sprite; 


};


#endif
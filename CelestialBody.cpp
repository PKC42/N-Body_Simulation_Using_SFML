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

#include "CelestialBody.h"
#include <iostream>

CelestialBody::CelestialBody(){

}

CelestialBody::CelestialBody(double _xpos, double _ypos, double _xvel, double _yvel, double _mass, std::string _name){
    xpos = _xpos; 
    ypos = _ypos; 
    xvel = _xvel;
    yvel = _yvel;
    mass = _mass;
    name = _name; 

    c_texture.loadFromFile(name);
    c_sprite.setTexture(c_texture);
}

CelestialBody::~CelestialBody(){

}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(c_sprite);
}

std::istream& operator>>(std::istream& in, CelestialBody& obj){
    //get data from input stream
    in >> obj.xpos;
    in >> obj.ypos;
    in >> obj.xvel;
    in >> obj.yvel;
    in >> obj.mass;
    in >> obj.name;

     //adjust for window ratios 
    double horizontal_ratio = (obj.window_width/2) / obj.radius; 
    double vertical_ratio = (obj.window_height/2) / obj.radius; 
    
    //update to take window dimensions into account
    double _xpos = (obj.xpos * horizontal_ratio) + (obj.window_width / 2); 
    double _ypos = (obj.ypos * vertical_ratio) + (obj.window_height / 2); 

    //make sprite and load position
    obj.c_image.loadFromFile(obj.name);
    obj.c_texture.loadFromImage(obj.c_image);
    obj.c_sprite.setTexture(obj.c_texture);
    obj.c_sprite.setPosition(_xpos, _ypos);

    return in;
}


void CelestialBody::set_window_and_radius(double _window_height, double _window_width, double _radius){
    window_height = _window_height; 
    window_width = _window_width; 
    radius = _radius;
}

void CelestialBody::new_velocity(double _xvel, double _yvel){
    xvel = _xvel; 
    yvel = _yvel;
}

void CelestialBody::new_position(double _xpos, double _ypos){

    xpos = _xpos; 
    ypos = _ypos; 
}

double CelestialBody::get_xpos() const{
    return xpos; 
}

double CelestialBody::get_ypos() const{
    return ypos; 
}

double CelestialBody::get_xvel() const{
    return xvel; 
}

double CelestialBody::get_yvel() const{
    return yvel; 
}

double CelestialBody::get_mass() const{
    return mass; 
}

std::string CelestialBody::get_name() const{
    return name;
}

void CelestialBody::update_position(){
     //adjust for window ratios 
    double horizontal_ratio = (window_width/2) / radius; 
    double vertical_ratio = (window_height/2) / radius; 
    
    //update to take window dimensions into account
    double _xpos =  (window_width / 2) + (xpos * horizontal_ratio); 
    double _ypos = (window_height / 2) - (ypos * vertical_ratio); 


    c_sprite.setPosition(_xpos, _ypos);
}
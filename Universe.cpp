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

#include "Universe.h"
#include <iostream> 

Universe::Universe(){

}

Universe::Universe(double _window_height, double _window_width, double _radius){
    window_height = _window_height; 
    window_width = _window_width; 
    radius = _radius;
}

Universe::~Universe(){
    //destroy vector
    c_bodies.clear();
}

void Universe::add_body(){
    //create unique pointer
    std::unique_ptr<CelestialBody> p(new CelestialBody());

    //set the window specs and universe specs
    p->set_window_and_radius(window_height, window_width, radius); 

    //insert data from stream into object
    std::cin >> *p; 

    //push into the vector
    c_bodies.push_back(std::move(p));
    
}

void Universe::draw_universe(sf::RenderWindow& target){
    //simply used to fulfill parameter needs
    sf::RenderStates state; 

    //display all celestial bodies
    for(int i = 0; i < (int)c_bodies.size(); i++){
        c_bodies.at(i)->draw(target, state);
    }
}

void Universe::step(double seconds){
    
    //force in x direction and y direction respectively 
    double xF, yF;

    //acceleration in x direaction an dy direction respectively
    double xA, yA; 

    //difference in x and y positions respectively
    double dx_pos, dy_pos;  

    //contains new x and y velocities respectively
    double new_x_vel, new_y_vel; 

    //contains new x and y positions respectively 
    double new_x_pos, new_y_pos; 

    //iterator variables
    int i = 0, j = 0; 

    //radius
    double r;

    //gravitational constant
    const double G = 6.67e-11;

    //Force without components
    double F;


    //iterate through all bodies
    for(i = 0; i < (int)c_bodies.size(); i++){

        //reset components
        xF = 0; 
        yF = 0; 

        //calculate net forces
        for(j = 0; j < (int)c_bodies.size(); j++){
            
            if(c_bodies.at(i) != c_bodies.at(j)){
                //find differences in positions between the two bodies
                dx_pos = c_bodies.at(j)->get_xpos() - c_bodies.at(i)->get_xpos(); 
                dy_pos = c_bodies.at(j)->get_ypos() - c_bodies.at(i)->get_ypos();

                //get distance between bodies  
                r = sqrt(pow(dx_pos, 2) + pow(dy_pos, 2));

                //get force
                F = (G*c_bodies.at(i)->get_mass()*c_bodies.at(j)->get_mass()) / pow(r, 2);

                //split force into components and compile to net forces in each direction
                xF += F * (dx_pos / r);
                yF += F * (dy_pos / r);
            
            }
        }

        //get x and y accelerations respectively
        xA = (xF / c_bodies.at(i)->get_mass());
        yA = (yF / c_bodies.at(i)->get_mass());
        
        //new velocities in x and y direction
        new_x_vel = (c_bodies.at(i)->get_xvel() + (xA * seconds));
        new_y_vel = (c_bodies.at(i)->get_yvel() + (yA * seconds));
        
        //set new velocities by multiplying acceleration by time in seconds
        c_bodies.at(i)->new_velocity(new_x_vel, new_y_vel); 

        //set positions 

        new_x_pos = (c_bodies.at(i)->get_xpos() + (c_bodies.at(i)->get_xvel() * seconds));
        new_y_pos = (c_bodies.at(i)->get_ypos() + (c_bodies.at(i)->get_yvel() * seconds));

        c_bodies.at(i)->new_position(new_x_pos, new_y_pos); 

        //update position of sprite
        c_bodies.at(i)->update_position();

    }

}

void Universe::print_data(){
    std::cout << std::scientific; 
    std::cout << std::setw(20) << std::right << "...xpos..." << std::setw(20) << std::right << "...ypos..." << std::setw(20) << std::right << 
    "...xvel..." << std::setw(20) << std::right << "...yvel..." << 
    std::setw(20) << std::right <<  "...mass..." << std::setw(20) << std::right << "filename" << std::endl;

    for(int i = 0; i < (int)c_bodies.size(); i++){ 
        std::cout <<  std::setw(20) << std::right;
        std::cout << c_bodies.at(i)->get_xpos() << std::setw(20) << std::right;
        std::cout << c_bodies.at(i)->get_ypos() << std::setw(20) << std::right;
        std::cout << c_bodies.at(i)->get_xvel() << std::setw(20) << std::right;
        std::cout << c_bodies.at(i)->get_yvel() << std::setw(20) << std::right;
        std::cout << c_bodies.at(i)->get_mass() << std::setw(20) << std::right;
        std::cout << c_bodies.at(i)->get_name() << std::endl;
        
    }
}
/**********************************************************************
 *  N-Body Simulation ps2b-readme.txt template
 **********************************************************************/

Name:Pratush Kc

Hours to complete assignment:5 Hours
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
In this assignment, the celestial bodies drawn in part 1 were made to move
using mutators and a step function. The step function takes time and essentially
moves each of the celestial bodies to their next location depending on their 
velocties, proximites and their mass. To keep the animation a bit slow, 
the framerate has been adjusted to 60fps. To accomplish all of this, 
I set up a single step function which takes time in seconds as a parameter. 
Mutator functions would modify the velocity and position while accessors return
information from the Celestial Body in question. 

Additionally, to do the calculations, several physics related equations
were used from assignment pdf. 

Lastly, the output is printed out using cout in neat columns similar to that
of the input file (planets.txt).

/**********************************************************************
 *  If you created your own universe for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/
The universe I created can be found in sun_and_asteroids.txt. It can be run 
by the following command:
./NBody 157788000.0 25000.0 < sun_and_asteroids.txt

This universe has a sun and 9 asteroids. What makes this universe "interesting"
is that the asteroids have varying properties so they all behave very differently. 


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
In this project, I have gotten help from the SFML official website along 
with the comments from Dr. Daly and fellow students on Dr.Daly's discord
server. The math concepts were taken from the assignment itself. 

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I had some issues trying to get the planets to travel in a counter clockwise
direction. This was resolved by subtracting half the window height. 

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 For some reason, the music would not play. I attempted to use the 
 2001.wav file provided in the Nbody.zip. However, I only encountered errors. 
 This maybe due to WSL. 
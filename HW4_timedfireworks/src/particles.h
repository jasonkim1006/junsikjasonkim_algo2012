//
//  particles.h
//  HW4_fireworks
//
//  Created by Jun Sik (Jason) Kim on 10/5/12.
//
//

#ifndef __HW4_fireworks__particles__
#define __HW4_fireworks__particles__

#include "ofMain.h"

class particle{
    
    public:
    
    /*JASON ofVec2f = ofPoint
     REMEMBER
     Velocity = Position + Velocity
     Velocity = Velocity + Acceleration
     Force = Mass * Acceleration but because mass is same, Force = Acceleration
     Position = Position + Velocity * Time
     */
    
    ofPoint pos;
    ofPoint vel;
    ofPoint frc; // frc is also know as acceleration (newton says "f=ma")
    
    /*
     particle(); -> constructor      ~particle(){}; -> destructor
     */
    
    particle();
    virtual ~particle(){};
    
    //resets the force. clears the force. force is not accumulating
    void resetForce();
    //add force
    void addForce(float x, float y);
    //damping = friction. amount that pushes from opposite direction. (gravity also)
    void addDampingForce();
    void addDampingForceTwo();
    //initial condition = for a given particle, what is your position & velocity
    //where are you in this world? set the variables! (for things like fireworks)
    //variables -> p = position, v = velocity
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    
    void bounceOffWalls();
    
    //amount of force in opposite direction (easier way is to multiply velocity by number less than 1. (vel *= 0.99)
    float damping;
    float dampingTwo;
    
    float circleRadius;
        
    protected:
    private:
    
    
    
};

#endif /* defined(__HW4_fireworks__particles__) */

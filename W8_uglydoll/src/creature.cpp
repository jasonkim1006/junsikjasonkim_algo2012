//
//  creature.cpp
//  W8_creaaature
//
//  Created by Jun Sik (Jason) Kim on 11/26/12.
//
//

#include "creature.h"

void creature::setup(ofColor color, float size){
    this->color = color;
    this->size = size;
    
    pos.y = ofRandom(0, ofGetHeight()/2);
    pos.x = ofRandom(size,ofGetWidth() - size);
    
    float bodyLength;
    bodyLength = size*2;
    
    sinDiff = ofRandom(0.8, 1.2);
    
    //uglydoll HEAD
    particle *p1 = new particle();
    particle *p2 = new particle();
    particle *p3 = new particle();
    particle *p4 = new particle();
    p1 -> setInitialCondition(pos.x, pos.y, 0, 0);
    p2 -> setInitialCondition(pos.x, pos.y + bodyLength + size/2, 0, 0);
    p3 -> setInitialCondition(pos.x + size, pos.y + bodyLength + size/2, 0, 0);
    p4 -> setInitialCondition(pos.x + size, pos.y, 0, 0);
    particles.push_back(p1);
    particles.push_back(p2);
    particles.push_back(p3);
    particles.push_back(p4);
    
    //head spring
    creatureSpring(p1, p2);
    creatureSpring(p2, p3);
    creatureSpring(p3, p4);
    creatureSpring(p4, p1);
    //head spring cross
    creatureSpring(p2, p4);
    creatureSpring(p1, p3);
    
    //uglydoll BODY
    particle *p5 = new particle();
    particle *p6 = new particle();
    particle *p7 = new particle();
    particle *p8 = new particle();
    p5 -> setInitialCondition(pos.x - bodyLength/4, pos.y + bodyLength, 0, 0);
    p6 -> setInitialCondition(pos.x - bodyLength/4, pos.y + bodyLength*2, 0, 0);
    p7 -> setInitialCondition(pos.x + (bodyLength*3/4), pos.y + bodyLength*2, 0, 0);
    p8 -> setInitialCondition(pos.x + (bodyLength*3/4), pos.y + bodyLength, 0, 0);
    particles.push_back(p5);
    particles.push_back(p6);
    particles.push_back(p7);
    particles.push_back(p8);
    creatureSpring(p5, p6);
    creatureSpring(p6, p7);
    creatureSpring(p7, p8);
    creatureSpring(p8, p5);
    //body spring cross
    creatureSpring(p6, p8);
    creatureSpring(p5, p7);
    
    //head body cross
    creatureSpring(p2, p7);
    creatureSpring(p3, p6);
    creatureSpring(p4, p6);
    creatureSpring(p1, p7);
    
    creatureSpring(p5, p2);
    creatureSpring(p8, p3);
    //until spring 17
    
    //uglydoll left FEET
    particle *p9 = new particle();
    particle *p10 = new particle();
    particle *p11 = new particle();
    particle *p12 = new particle();
    p9 -> setInitialCondition(pos.x - bodyLength/8, pos.y + bodyLength*2, 0, 0);
    p10 -> setInitialCondition(pos.x - bodyLength/8, pos.y + bodyLength*2 + size, 0, 0);
    p11 -> setInitialCondition(pos.x + bodyLength/8, pos.y + bodyLength*2 + size, 0, 0);
    p12 -> setInitialCondition(pos.x + bodyLength/8, pos.y + bodyLength*2, 0, 0);
    particles.push_back(p9);
    particles.push_back(p10);
    particles.push_back(p11);
    particles.push_back(p12);
    creatureSpring(p9, p10);
    creatureSpring(p10, p11);
    creatureSpring(p11, p12);
    creatureSpring(p12, p9);
    //spring cross
    creatureSpring(p10, p12);
    creatureSpring(p9, p11);
    
    //uglydoll right FEET
    particle *p13 = new particle();
    particle *p14 = new particle();
    particle *p15 = new particle();
    particle *p16 = new particle();
    p13 -> setInitialCondition(pos.x + bodyLength*3/8, pos.y + bodyLength*2, 0, 0);
    p14 -> setInitialCondition(pos.x + bodyLength*3/8, pos.y + bodyLength*2 + size, 0, 0);
    p15 -> setInitialCondition(pos.x + bodyLength*5/8, pos.y + bodyLength*2 + size, 0, 0);
    p16 -> setInitialCondition(pos.x + bodyLength*5/8, pos.y + bodyLength*2, 0, 0);
    particles.push_back(p13);
    particles.push_back(p14);
    particles.push_back(p15);
    particles.push_back(p16);
    creatureSpring(p13, p14);
    creatureSpring(p14, p15);
    creatureSpring(p15, p16);
    creatureSpring(p16, p13);
    //body spring cross
    creatureSpring(p14, p16);
    creatureSpring(p13, p15);
    
    //connect both feet to body
    creatureSpring(p9, p8);
    creatureSpring(p12, p5);
    creatureSpring(p6, p10);
    creatureSpring(p11, p13);
    
    creatureSpring(p16, p5);
    creatureSpring(p13, p8);
    creatureSpring(p12, p14);
    creatureSpring(p7, p15);
    //until spring 37
    
    //uglydoll left ARM
    particle *p17 = new particle();
    particle *p18 = new particle();
    p17 -> setInitialCondition(pos.x - bodyLength/2, pos.y + bodyLength + bodyLength/4, 0, 0);
    p18 -> setInitialCondition(pos.x - bodyLength/4, pos.y + bodyLength + bodyLength/4, 0, 0);
    particles.push_back(p17); 
    particles.push_back(p18);
    creatureSpring(p5, p17);
    creatureSpring(p17, p18); //39
    creatureSpring(p18, p5);
    

    //uglydoll left ARM
    particle *p19 = new particle();
    particle *p20 = new particle();
    p19 -> setInitialCondition(pos.x + bodyLength, pos.y + bodyLength + bodyLength/4, 0, 0);
    p20 -> setInitialCondition(pos.x + bodyLength*3/4, pos.y + bodyLength + bodyLength/4, 0, 0);
    particles.push_back(p19);
    particles.push_back(p20);
    creatureSpring(p8, p19);
    creatureSpring(p19, p20); //42
    creatureSpring(p20, p8);

    
    
    //EXTRA SPRINGS for durability
    creatureSpring(p1, p15);
    creatureSpring(p14, p4);
    creatureSpring(p1, p11);
    creatureSpring(p10, p4);
    
    //ARM
    creatureSpring(p18, p8);
    
}

void creature::update() {
    
    //HEAD
    springs[1].distance = size + size/8 * sin(ofGetElapsedTimef()*8 + PI);
    springs[3].distance = size + size/8 * sin(ofGetElapsedTimef()*8 + PI);
    
    //FEET
    springs[18].distance = size + size/2 * sin(ofGetElapsedTimef()*4);
    springs[20].distance = size + size/2 * sin(ofGetElapsedTimef()*4);
    
    springs[24].distance = size + size/2 * sin(ofGetElapsedTimef()*4 + PI);
    springs[26].distance = size + size/2 * sin(ofGetElapsedTimef()*4 + PI);
    
    //ARM
    springs[39].distance = size + size/2 * sin(ofGetElapsedTimef()*4 + PI);
    springs[42].distance = size + size/2 * sin(ofGetElapsedTimef()*4 + PI);
    
    for (int i = 0; i < particles.size(); i++){
		particles[i]->resetForce();
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i]->addForce(0,0.05f);
		particles[i]->addRepulsionForce(mouseX, mouseY, 50, 20);
	}
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i]->bounceOffWalls();
		particles[i]->addDampingForce();
		particles[i]->update();
	}

    
}

void creature::draw() {
    
    
    ofFill();
    ofSetColor(color);

//    for (int i = 0; i < particles.size(); i++){
//        particles[i]->draw();
//    }
//
//    for (int i = 0; i < springs.size(); i++){
//        springs[i].draw();
//    }
    
    //HEAD
    ofBeginShape();
        ofVertex(particles[0]->pos.x, particles[0]->pos.y);
        ofVertex(particles[1]->pos.x, particles[1]->pos.y);
        ofVertex(particles[2]->pos.x, particles[2]->pos.y);
        ofVertex(particles[3]->pos.x, particles[3]->pos.y);
	ofEndShape();
    
    //BODY
    ofBeginShape();
        ofVertex(particles[4]->pos.x, particles[4]->pos.y);
        ofVertex(particles[5]->pos.x, particles[5]->pos.y);
        ofVertex(particles[6]->pos.x, particles[6]->pos.y);
        ofVertex(particles[7]->pos.x, particles[7]->pos.y);
	ofEndShape();
    
    //LEFT FEET
    ofBeginShape();
        ofVertex(particles[8]->pos.x, particles[8]->pos.y);
        ofVertex(particles[9]->pos.x, particles[9]->pos.y);
        ofVertex(particles[10]->pos.x, particles[10]->pos.y);
        ofVertex(particles[11]->pos.x, particles[11]->pos.y);
	ofEndShape();
    
    //RIGHT FEET
    ofBeginShape();
        ofVertex(particles[12]->pos.x, particles[12]->pos.y);
        ofVertex(particles[13]->pos.x, particles[13]->pos.y);
        ofVertex(particles[14]->pos.x, particles[14]->pos.y);
        ofVertex(particles[15]->pos.x, particles[15]->pos.y);
	ofEndShape();
    
    //LEFT ARM
    ofBeginShape();
        ofVertex(particles[16]->pos.x, particles[16]->pos.y);
        ofVertex(particles[17]->pos.x, particles[17]->pos.y);
        ofVertex(particles[4]->pos.x, particles[4]->pos.y);
	ofEndShape();
    
    //RIGHT ARM
    ofBeginShape();
        ofVertex(particles[18]->pos.x, particles[18]->pos.y);
        ofVertex(particles[19]->pos.x, particles[19]->pos.y);
        ofVertex(particles[7]->pos.x, particles[7]->pos.y);
	ofEndShape();
    
    ofPushMatrix();
        ofTranslate(particles[0]->pos.x, particles[0]->pos.y);
            ofPushMatrix();
                ofTranslate(size/2, size+size/2);
                ofSetColor(50,50,50);
                //TEETH
                ofTriangle(-size*3/8, 0, -size/4, size/3, -size/8, 0);
                ofTriangle(size/8,0, size/4, size/3, size*3/8,0);
                ofLine(-size/4, 0, size/4, 0);
            ofPopMatrix();
    ofPopMatrix();

//    ofPopMatrix();
    //    ofPoint righteyes;
    //    righteyes.x = particles[0]->pos.x + size/5;
    //    righteyes.y = particles[0]->pos.y + size/3;
    //
    //    ofPoint lefteyes;
    //    lefteyes.x = particles[3]->pos.x - size/5;
    //    lefteyes.y = particles[3]->pos.y + size/3;
    
    //    ofCircle(righteyes, size/5);
    //    ofCircle(lefteyes, size/6);
    
    
    float myLeftEyeX = (particles[3]->pos.x - particles[0]->pos.x)/4;
    float myLeftEyeY = (particles[1]->pos.y - particles[0]->pos.y)/4;
    
    float myRightEyeX = -(particles[3]->pos.x - particles[0]->pos.x)/4;
    float myRightEyeY = (particles[2]->pos.y - particles[3]->pos.y)/4;
    
    ofSetColor(50,50,50);

    ofPushMatrix();
        ofTranslate(particles[0]->pos.x, particles[0]->pos.y);
        ofCircle(myLeftEyeX, myLeftEyeY, size/5);
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(particles[3]->pos.x, particles[3]->pos.y);
        ofCircle(myRightEyeX, myRightEyeY, size/5);
    ofPopMatrix();

    
}

void creature::creatureSpring(particle *p1, particle *p2) {
    
    spring mySpring;
    mySpring.restLength = (p1 -> pos - p2-> pos).length();
    mySpring.springiness = 0.3f;
    mySpring.particleA = p1;
    mySpring.particleB = p2;
    mySpring.distance = mySpring.restLength;
    springs.push_back(mySpring);
}

//this is needed for x and y value to update to addRepulsionForce
void creature::moveMouse(float x, float y){
    mouseX = x;
    mouseY = y;
}


























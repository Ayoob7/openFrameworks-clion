#include "ofApp.h"
#include <math.h>
#define PI 3.14159265

//--------------------------------------------------------------
void ofApp::setup() {
    ofDisableAlphaBlending();
    ofEnableDepthTest();
    ofBackground(0,0,0);
    ofSetCircleResolution(100);
    ofDisableArbTex();
    ofNoFill();


    //this slows down the rotate a little bit
    dampen = .9;

}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    //translate the view to center
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 100);

    auto axis = glm::axis(curRot);
    //apply the quaternion's rotation to the viewport and draw the sphere
    ofRotateDeg(ofRadToDeg(glm::angle(curRot)), axis.x, axis.y, axis.z);
    /// You can actually use the folling line instead, just showing this other option as example

    int spacing_of_sphere = 50;
    int radius_hex = 30;
    int radius_pent = 20;
    int radius_hex_ud = 10;

    //ofDrawSphere(200);

    //Main Hexagon
    ofDrawSphere((spacing_of_sphere/2)*sqrt(3), (spacing_of_sphere/2), 0, radius_hex);
    ofDrawSphere(-(spacing_of_sphere/2)*sqrt(3), (spacing_of_sphere/2), 0, radius_hex);
    ofDrawSphere((spacing_of_sphere/2)*sqrt(3), -(spacing_of_sphere/2), 0, radius_hex);
    ofDrawSphere(-(spacing_of_sphere/2)*sqrt(3), -(spacing_of_sphere/2), 0, radius_hex);
    ofDrawSphere(0, spacing_of_sphere, 0, radius_hex);
    ofDrawSphere(0, -spacing_of_sphere, 0, radius_hex);

    //Side Pentagon
    ofDrawSphere((spacing_of_sphere/2)*sqrt(3)+(spacing_of_sphere*cos(18*PI/180)), ((spacing_of_sphere/2)+(spacing_of_sphere*sin(18*PI/180))), 0, radius_pent);
    ofDrawSphere((spacing_of_sphere/2)*sqrt(3)+(spacing_of_sphere*cos(18*PI/180)), -((spacing_of_sphere/2)+(spacing_of_sphere*sin(18*PI/180))), 0, radius_pent);
    ofDrawSphere(((spacing_of_sphere/2)*sqrt(3)+(spacing_of_sphere*cos(18*PI/180))-(spacing_of_sphere*sin(54))), ((spacing_of_sphere/2)+(spacing_of_sphere*sin(18*PI/180))+(spacing_of_sphere*cos(54))), 0, radius_pent);

    //Hexagon up and down
    ofDrawSphere(0, spacing_of_sphere+30, 0, radius_hex_ud);
    ofDrawSphere(0, -spacing_of_sphere-30, 0, radius_hex_ud);

    //Pentagon side H atom
    ofDrawSphere(((spacing_of_sphere/2)*sqrt(3)+(spacing_of_sphere*cos(18*PI/180))-(spacing_of_sphere*sin(54)) + 30), ((spacing_of_sphere/2)+(spacing_of_sphere*sin(18*PI/180))+(spacing_of_sphere*cos(54))), 0, radius_hex_ud);

    //Hexagon side up
    ofDrawSphere(-((spacing_of_sphere/2)*sqrt(3)+(35*cos(45*PI/180))), ((spacing_of_sphere/2)+(35*sin(45*PI/180))), 0, radius_hex);
    ofDrawSphere(-((spacing_of_sphere/2)*sqrt(3)+(35*cos(45*PI/180))), -((spacing_of_sphere/2)+(35*sin(45*PI/180))), 0, radius_hex);

    //Pentagon slanted
    ofDrawSphere((spacing_of_sphere/2)*sqrt(3)+(spacing_of_sphere*cos(18*PI/180))+(35*cos(45*PI/180)), ((spacing_of_sphere/2)+(spacing_of_sphere*sin(18*PI/180))+(35*sin(45*PI/180))), 0, radius_pent);



    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    //every time the mouse is dragged, track the change
    //accumulate the changes inside of curRot through multiplication
    glm::vec2 mouse(x,y);
    glm::quat yRot = glm::angleAxis(ofDegToRad(x-lastMouse.x)*dampen, glm::vec3(0,1,0));
    glm::quat xRot = glm::angleAxis(ofDegToRad(y-lastMouse.y)*dampen, glm::vec3(-1,0,0));
    curRot = xRot * yRot * curRot;
    lastMouse = mouse;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //store the last mouse point when it's first pressed to prevent popping
    lastMouse = glm::vec2(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

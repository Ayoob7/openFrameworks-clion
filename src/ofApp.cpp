#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofDisableAlphaBlending();
    ofEnableDepthTest();
    ofBackground(0,0,0);
    ofSetCircleResolution(500);
    ofDisableArbTex();
    ofLoadImage(mTex,"earth.jpg");


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
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 40);

    auto axis = glm::axis(curRot);
    //apply the quaternion's rotation to the viewport and draw the sphere
    ofRotateDeg(ofRadToDeg(glm::angle(curRot)), axis.x, axis.y, axis.z);
    /// You can actually use the folling line instead, just showing this other option as example
    ///	ofRotateRad(glm::angle(curRot), axis.x, axis.y, axis.z);

    mTex.bind();
    sphere.setRadius(200);
    sphere.draw();
    mTex.unbind();


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

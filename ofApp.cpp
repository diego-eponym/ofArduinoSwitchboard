/* ------------------------------------------------------------
PSEUDO-CODE

0- Display Main screen.
1- Receive Data from Arduino and update int array with sensor values.
2- Compare values of sensors 1, 2, 3, 4, 5 against array 0 (Pot).
3- If any sensor value is higher than Pot play video loop from array (1-5) corresponding with sensor number. (Include transition between Main screen and video)
4- While video is playing compare only current sensor value with Pot.
5- Stop video when when sensor value falls below Pot.
6- Return to Main screen
Repeat
 
------------------------------------------------------------ */

#include "ofApp.h"
//#include "ofSensor.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofBackground(255, 0, 130);
    font.loadFont("franklinGothic.otf", 20);
    
    
    csduino.connect("/dev/tty.usbserial-DA00WU7E", 57600);
    
    // call setupArduino()
    ofAddListener(csduino.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino	= false;	// flag so we setup arduino when its ready, you don't need to touch this :)
}

//--------------------------------------------------------------
void ofApp::update(){
    
    updateArduino();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    font.drawString("Pot Reading: " + ofToString(potValue), 10, 20);
    for (int i = 0; i <5 ; i++) {
        font.drawString("Sensor Reading: " + ofToString(photoValue[i]), 10, 20 * (i+2));
    }

}


//--------------------------------------------------------------
// CUSTOM METHODS FOR SWITCHBOARD
//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {
    
// Remove Setup listener
    ofRemoveListener(csduino.EInitialized, this, &ofApp::setupArduino);
    
//    Now that it initialized we can talk to it
    bSetupArduino = true;
    
//    Set analog pins as input
    
    for(int i = 0; i <5; i++){
        csduino.sendAnalogPinReporting(i, ARD_ANALOG);
    }
    
}

void ofApp::updateArduino(){
    csduino.update();
    getValues();
}

void ofApp::getValues(){
    potValue = csduino.getAnalog(0);
    
    for (int i = 0; i < 4; i++) {
        photoValue[i] = csduino.getAnalog(i +1);
                break;
    }
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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

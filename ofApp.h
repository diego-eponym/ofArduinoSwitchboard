#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofTrueTypeFont		font;
    
    // Create Arduino Object
    ofArduino csduino;
    bool bSetupArduino;
    
private:
    
    // Private Arduino Variables & methods
    void setupArduino(const int & version);
    void analogPinChanged(const int & pinNum);
    void updateArduino();
    void getValues();
    
    int potValue;
    int photoValue[4];
		
};

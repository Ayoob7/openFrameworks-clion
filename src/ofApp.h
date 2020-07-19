#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		// Static Methods
        void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// Instance variables
        ofSpherePrimitive sphere;
        ofTexture mTex;


        //current state of the rotation
        glm::quat curRot;

        //a place to store the mouse position so we can measure incremental change
        glm::vec2 lastMouse;

        //slows down the rotation 1 = 1 degree per pixel
        float dampen;
};

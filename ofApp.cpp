#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofColor color;
	float radius = 120;

	for (int x = -180; x <= 180; x += 360) {

		for (int y = -180; y <= 180; y += 360) {

			for (int len = 60; len > 0; len -= 5) {

				vector<glm::vec2> vertices;
				float deg_start = ofRandom(360) + ofGetFrameNum() * ofRandom(3, 10);

				for (float deg = deg_start; deg < deg_start + 45; deg += 1) {

					vertices.push_back(glm::vec2(x + (radius - len * 0.5) * cos(deg * DEG_TO_RAD), y + (radius - len * 0.5) * sin(deg * DEG_TO_RAD)));
				}
				
				int hue = ofMap(len, 0, 60, 0, 255);
				color.setHsb(hue, 180, 255);

				ofFill();
				ofSetColor(color);

				ofBeginShape();
				ofVertex(glm::vec2());
				ofVertices(vertices);
				ofVertex(glm::vec2());
				ofEndShape(true);

				ofNoFill();
				ofSetColor(255);

				ofBeginShape();
				ofVertex(glm::vec2());
				ofVertices(vertices);
				ofVertex(glm::vec2());
				ofEndShape(true);
			}
		}
	}

	/*
	int start = 50;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
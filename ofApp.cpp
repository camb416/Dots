#include "ofApp.h"

#define NUM_DOTS 4096

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i=0;i<NUM_DOTS;i++){
        Dot * d = new Dot();
        d->setup();
        ds.push_back(d);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0;i<NUM_DOTS;i++){
        Dot * d = ds.at(i);
        d->update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(0,0,0,64);
    for(int i=0;i<NUM_DOTS;i++){
        Dot * d = ds.at(i);
        d->draw();
    }
   // ofSaveFrame();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ds.clear();
    setup();
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

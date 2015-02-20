//
//  Dot.cpp
//  dots
//
//  Created by Cameron Browning on 2/8/15.
//
//

#include "Dot.h"



void Dot::setup(){
    tailLength = ofRandom(128)+16;
    p.set(ofGetWidth()/2,ofGetHeight()/2);
    
    r = ofRandom(TWO_PI);
    vF = ofRandom(4.0f);
    
    vR = ofRandom(0.08f)-0.04f;
    aR = ofRandom(0.001f)-0.0005f;
    
    for(int i=0; i<tailLength; i++){
        tail.push_back(p);
    }
    
    
    //v.set(0,0);
}
void Dot::update(){
    vR+=aR;
    vF*=0.995f;
    r+= vR;
    v.set(cos(r)*vF,sin(r)*vF);
    p += v;
    tail.at(0) = p;
    for(int i=(tailLength-1);i>0;i--){
        tail.at(i) = tail.at(i-1);
    }
}
void Dot::draw(){
    ofFill();
    ofSetColor(0);
    ofCircle(p,3.0f*vF);
    ofEnableAlphaBlending();
    ofSetColor(128,128,128,128*vF);
    ofBeginShape();
    ofNoFill();
    for(int i=0; i<tailLength; i++){
        ofPoint p = tail.at(i);
        ofVertex(p);
    //    ofCircle(p,5.0f);
    }
    ofEndShape();
    ofFill();
    ofSetColor(255);
    ofCircle(p,2.0f*vF);
    
    ofFill();
    ofSetColor(0);
    ofCircle(p,1.0f*vF);
    
    ofFill();
    ofSetColor(0);
    ofCircle(tail.at(tailLength-1),1.0f*vF);

}
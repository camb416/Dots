//
//  Dot.cpp
//  dots
//
//  Created by Cameron Browning on 2/8/15.
//
//

#include "Dot.h"

#define TAIL_LENGTH 32


void Dot::setup(){
    p.set(ofGetWidth()/2,ofGetHeight()/2);
    
    r = ofRandom(TWO_PI);
    vF = ofRandom(4.0f);
    
    vR = ofRandom(0.08f)-0.04f;
    
    for(int i=0; i<TAIL_LENGTH; i++){
        tail.push_back(p);
    }
    
    
    //v.set(0,0);
}
void Dot::update(){
    vF*=0.9975f;
    r+= vR;
    v.set(cos(r)*vF,sin(r)*vF);
    p += v;
    tail.at(0) = p;
    for(int i=(TAIL_LENGTH-1);i>0;i--){
        tail.at(i) = tail.at(i-1);
    }
}
void Dot::draw(){
    ofFill();
    ofSetColor(0);
    ofCircle(p,4.0f*vF);
    ofBeginShape();
    ofNoFill();
    for(int i=0; i<TAIL_LENGTH; i++){
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
    ofCircle(tail.at(TAIL_LENGTH-1),2.0f*vF);
    
    ofFill();
    ofSetColor(255);
    ofCircle(tail.at(TAIL_LENGTH-1),1.0f*vF);
}
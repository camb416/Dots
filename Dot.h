//
//  Dot.h
//  dots
//
//  Created by Cameron Browning on 2/8/15.
//
//

#ifndef __dots__Dot__
#define __dots__Dot__

#include "ofMain.h"

#include <stdio.h>



class Dot{
    
public:
    ofPoint p;
    ofPoint v;
    ofPoint a;
    float r;
    float vF;
    float vR;
    float aR;
    
    int tailLength;
    
    void setup();
    void update();
    void draw();
    
    vector<ofPoint> tail;
    
    
private:
    
};

#endif /* defined(__dots__Dot__) */

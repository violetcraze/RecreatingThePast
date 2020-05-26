#pragma once

#include "ofxGui.h"
#include "ofxLaunchControllers.h"
#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
  ofxLaunchControl lc;
  ofxPanel gui;

  ofParameter<bool> showControls;
  ofParameter<bool> showDebug;

  void setup();
  void update();
  void draw();

  void title();
};

#include "ofApp.h"

constexpr const char *PROJECT_NAME = "A la Recherche de Paul Klee";
constexpr const char *CREATOR = "Vera Molnár";
constexpr const char *RECREATOR = "Violet Graham";

void ofApp::setup() {
  ofBackground(255);

  gui.setup();
  gui.add(showControls.set("Show Controls", false));
  gui.add(showDebug.set("Show Grid", false));

  lc.setup();
  lc.toggle(0, showControls);
  lc.toggle(1, showDebug);
}

void ofApp::update() { title(); }

void ofApp::draw() {
  if (showControls) {
    gui.draw();
  }
}

void ofApp::title() {
  stringstream titleStream;
  titleStream << PROJECT_NAME << " - " << CREATOR << " - " << RECREATOR
              << " - FPS: " << static_cast<int>(ofGetFrameRate());
  ofSetWindowTitle(titleStream.str());
}

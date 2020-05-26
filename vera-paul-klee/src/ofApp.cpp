#include "ofApp.h"

constexpr const char *PROJECT_NAME = "A la Recherche de Paul Klee";
constexpr const char *CREATOR = "Vera Molnár";
constexpr const char *RECREATOR = "Violet Graham";

void ofApp::setup() {
  ofBackground(255);

  gui.setup();
  gui.add(showControls.set("Show Controls", false));
  gui.add(showDebug.set("Show Debug", false));

  lc.setup();
  lc.toggle(0, showControls);
  lc.toggle(1, showDebug);

  for (size_t i = 0; i < 2; ++i) {
    vector<Cell> cells;
    generateCells(cells, 15);
    layers.push_back(cells);
  }
}

void ofApp::update() { title(); }

void ofApp::draw() {
  if (showDebug) {
    ofNoFill();

    ofSetColor(0, 0, 255, 50);
    for (const auto &cell : layers[0]) {
      cell.drawDebug();
    }

    ofSetColor(0, 255, 0, 100);
    for (const auto &cell : layers[1]) {
      cell.drawDebug();
    }
  }
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

void ofApp::generateCells(vector<Cell> &cells, int cellNum) {
  const float cellSize = ofGetWidth() / static_cast<float>(cellNum);
  for (int i = 0; i < cellNum; ++i) {
    for (int j = 0; j < cellNum; ++j) {
      cells.emplace_back(
          ofVec2f(i * cellSize + cellSize / 2, j * cellSize + cellSize / 2),
          cellSize);
    }
  }
}

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

  createBlueprints();

  for (size_t i = 0; i < layers[0].size(); ++i) {
    layers[0][i].addDesign0(
        Design(blueprints[int(ofRandom(blueprints.size()))]));
    layers[0][i].addDesign1(
        Design(blueprints[int(ofRandom(blueprints.size()))]));
  }
}

void ofApp::update() { title(); }

void ofApp::draw() {

  ofSetColor(0);
  for (const auto &layer : layers) {
    for (const auto &cell : layer) {
      cell.draw(false);
    }
  }

  if (showDebug) {
    ofNoFill();

    ofSetColor(0, 0, 255, 50);
    for (const auto &cell : layers[0]) {
      cell.draw(true);
    }

    ofSetColor(0, 255, 0, 100);
    for (const auto &cell : layers[1]) {
      cell.draw(true);
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

#define addDiagonalBlueprint(numLines)                                         \
  blueprints.push_back([](float width, float height) {                         \
    for (int i = 0; i < numLines; ++i) {                                       \
      float x = ofLerp(0, width, static_cast<float>(i) / numLines);            \
      float y = ofLerp(0, height, static_cast<float>(i) / numLines);           \
      ofDrawLine(x - width / 2, -height / 2, width / 2, height / 2 - y);       \
    }                                                                          \
  });

void ofApp::createBlueprints() {

  addDiagonalBlueprint(1);
  addDiagonalBlueprint(2);
  addDiagonalBlueprint(3);
  addDiagonalBlueprint(5);
  addDiagonalBlueprint(7);
  addDiagonalBlueprint(11);
}

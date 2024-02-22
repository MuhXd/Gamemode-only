#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/binding/GJBaseGameLayer.hpp>

void Switch(int sender) {
    int tag = sender
	auto playLayer = PlayLayer::get();
    auto player1 = playLayer->m_player1;
    switch(tag) {
        case 0:
        player1->toggleFlyMode(false, false);
        player1->toggleRollMode(false, false);
        player1->toggleBirdMode(false, false);
        player1->toggleDartMode(false, false);
        player1->toggleRobotMode(false, false);
        player1->toggleSpiderMode(false, false);
        player1->toggleSwingMode(false, false);
        break;
        case 1: player1->toggleFlyMode(true, true); break; 
        case 2: player1->toggleRollMode(true, true); break;
        case 3: player1->toggleBirdMode(true, true); break;
        case 4: player1->toggleDartMode(true, true); break;
        case 5: player1->toggleRobotMode(true, true); break;
        case 6: player1->toggleSpiderMode(true, true); break;
        case 7: player1->toggleSwingMode(true, true); break;
	}
}

class $modify(layer, GJBaseGameLayer) {
    void update(float delta) override {
        GJBaseGameLayer::update(delta);
		Switch(0)
	}
}
#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
using namespace geode::prelude;
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/binding/GJBaseGameLayer.hpp>
bool l = true;
void Switch(int gamemode, auto Plr) {
	auto playLayer = PlayLayer::get();
    switch(gamemode) {
        case 0:
        Plr->toggleFlyMode(false, false);
        Plr->toggleRollMode(false, false);
        Plr->toggleBirdMode(false, false);
        Plr->toggleDartMode(false, false);
        Plr->toggleRobotMode(false, false);
        Plr->toggleSpiderMode(false, false);
        Plr->toggleSwingMode(false, false);
        break;
        case 1: Plr->toggleFlyMode(true, true); break; 
        case 2: Plr->toggleRollMode(true, true); break;
        case 3: Plr->toggleBirdMode(true, true); break;
        case 4: Plr->toggleDartMode(true, true); break;
        case 5: Plr->toggleRobotMode(true, true); break;
        case 6: Plr->toggleSpiderMode(true, true); break;
        case 7: Plr->toggleSwingMode(true, true); break;
	}
}

class $modify(layer, GJBaseGameLayer) {
    void update(float delta) {
        GJBaseGameLayer::update(delta);
        if (l) {
	int gamemodeid = Mod::get()->getSettingValue<int64_t>("Gamemode");
		auto playLayer = PlayLayer::get();
		if (Mod::get()->getSettingValue<bool>("Enabled")) {
		Switch(gamemodeid,playLayer->m_player1);
		if (Mod::get()->getSettingValue<bool>("2nd-player")) {
			Switch(gamemodeid,playLayer->m_player2);
		};
		};
	}
        }
};
class $modify(lg, PlayLayer) {
bool init(GJGameLevel* level, bool p1, bool p2) {
        if (!PlayLayer::init(level, p1, p2)) l=false; return false;

        l = true;

        return true;
    }
}
class $modify(PauseLayer) {
void onQuit(CCObject* sender) {
		PauseLayer::onQuit(sender);
		l = false;
	}
}
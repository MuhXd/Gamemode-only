#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/binding/PlayerObject.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/binding/GJBaseGameLayer.hpp>
#include <Geode/binding/GameObject.hpp>
int l = 10;
float y = 0;
bool bump = false;
/*
"Gamemode": {
            "name": "Gamemode",
            "type": "int",
            "default": 0,
            "min": 0,
            "max": 7,
            "control": {
                "slider": false
            }
        }
        */
void Switch(int gamemode, auto Plr) {
    l-=1;
    if (!Mod::get()->getSettingValue<bool>("Enabled")) {
        return;
    };
    if (l > 0) {
        return;
    };
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
        auto playLayer = this;
	int gamemodeid = 0; //
    //int gamemodeid = Mod::get()->getSettingValue<int64_t>("Gamemode");
		Switch(gamemodeid,playLayer->m_player1);
		if (Mod::get()->getSettingValue<bool>("2nd-player")) {
			Switch(gamemodeid,playLayer->m_player2);
		};
	}
};

class $modify(PauseLayer) {
void onQuit(CCObject* sender) {
		PauseLayer::onQuit(sender);
	    l = 10;
	}
};
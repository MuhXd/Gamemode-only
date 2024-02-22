#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/binding/GJBaseGameLayer.hpp>

void Switch(int gamemode, bool Plr) {
	auto playLayer = PlayLayer::get();
	auto player = playLayer->m_player2;
	if (Plr) {
    auto player = playLayer->m_player1;
	};
    switch(gamemode) {
        case 0:
        player->toggleFlyMode(false, false);
        player->toggleRollMode(false, false);
        player->toggleBirdMode(false, false);
        player->toggleDartMode(false, false);
        player->toggleRobotMode(false, false);
        player->toggleSpiderMode(false, false);
        player->toggleSwingMode(false, false);
        break;
        case 1: player->toggleFlyMode(true, true); break; 
        case 2: player->toggleRollMode(true, true); break;
        case 3: player->toggleBirdMode(true, true); break;
        case 4: player->toggleDartMode(true, true); break;
        case 5: player->toggleRobotMode(true, true); break;
        case 6: player->toggleSpiderMode(true, true); break;
        case 7: player->toggleSwingMode(true, true); break;
	}
}

class $modify(layer, GJBaseGameLayer) {
    void update(float delta) {
        GJBaseGameLayer::update(delta);
		if (Mod::get()->getSettingValue<bool>("Enabled")) {
		Switch(Mod::get()->getSettingValue<int64_t>("Gamemode"),true);
		if (Mod::get()->getSettingValue<bool>("2nd-player")) {
			Switch(Mod::get()->getSettingValue<int64_t>("Gamemode"),false);
		};
		};
	}
};
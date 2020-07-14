#include "Player.h"

Player::Player(sf::RenderTexture* t) {
	texture = t;
}

void Player::update() {
	manageControls();
}

void Player::draw() {

}

void Player::manageControls() {
	
}
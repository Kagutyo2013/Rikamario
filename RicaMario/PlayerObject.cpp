#include "PlayerObject.h"

void Player::init(const std::unique_ptr<Root>& root, AssetContainer<asset::Texture>& tex_container, AssetContainer<asset::Sound>& sound_container){
	initPlayerSprite(root, tex_container);
	m_jumpflag = 0;
}

void Player::initPlayerSprite(const std::unique_ptr<Root>& root, AssetContainer<asset::Texture>& tex_container){
	sp_player.reset(new Sprite());
	sp_player->setTexture(tex_container.findAssetByname("Player"));
}

void Player::inputAction(const Controller& controller){
	if (controller.LeftKey->isBeingPressed()){
		m_vx = -2;
	}
	if (controller.RightKey->isBeingPressed()){
		m_vx = +2;
	}

	if (controller.AButton->isPressed()){
		if (m_jumpflag == 0){
			m_jumpflag = 1;
			m_vy = -2;
		}
	}
}

void Player::update(){
	m_x += m_vx;
	m_y += m_vy;
	sp_player->setPosition(m_x, m_y);
}

void Player::setDrawIn(const std::unique_ptr<Root>& root){
	root->layers[0].push_back(sp_player);
}
void Player::setDrawOut(const std::unique_ptr<Root>& root){
	root->layers[0].remove(sp_player);
}

const int Player::getPosition(int& select)const{
	if (select == 0){
		return m_x;
	}
	if (select == 1){
		return m_y;
	}
	return -1;
}

void Player::setPosition(const int& select, const int& arg){
	if (select == 0){
		m_x = arg;
	}
	if (select == 1){
		m_y = arg;
	} 
}

const int  Player::getFlag(int& select)const{
	if (select == 0){
		return m_jumpflag;
	}
	return -1;
}

void  Player::setFlag(const int& select, const int& arg){
	if (select == 0){
		m_jumpflag = arg;
	}
}
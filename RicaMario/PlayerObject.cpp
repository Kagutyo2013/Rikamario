#include "PlayerObject.h"
#define SCREEN_XSIZE 640
#define SCREEN_YSIZE 480


void Player::init(const std::unique_ptr<Root>& root, AssetContainer<asset::Texture>& tex_container, AssetContainer<asset::Sound>& sound_container){
	initPlayerSprite(root, tex_container);
	m_vx_max = 10;
	m_vy_max = 10;
	m_ax = 2;
	m_ay = 20;
	m_jumpflag = 0;
}

void Player::initPlayerSprite(const std::unique_ptr<Root>& root, AssetContainer<asset::Texture>& tex_container){
	sp_player.reset(new Sprite());
	sp_player->setTexture(tex_container.findAssetByname("Player"));
}

void Player::inputAction(const Controller& controller){
	if (controller.LeftKey->isBeingPressed()){
		m_vx -= m_ax;
	}
	if (controller.RightKey->isBeingPressed()){
		m_vx += m_ax;
	}
	if (!controller.RightKey->isBeingPressed() && !controller.LeftKey->isBeingPressed()){
		if (m_vx > 0){
			m_vx -= 1;
		}
		if (m_vx < 0){
			m_vx += 1;
		}
	}

	if (controller.AButton->isBeingPressed()&&m_jumpflag==0){
		m_vy = -m_ay;
		m_jumpflag = 1;
	}
}

void Player::update(){
	if (m_vx > m_vx_max){
		m_vx = m_vx_max;
	}
	if (m_vx < -1*m_vx_max){
		m_vx = -1*m_vx_max;
	}
	if (m_y <= 480 - 16 && m_y >= 16){
		m_vy += 1;
	}
	m_x += m_vx;
	m_y += m_vy;
	if (m_x < sp_player->getXSize()/2){
		m_x = sp_player->getXSize() / 2;
	}
	if (m_x > SCREEN_XSIZE - sp_player->getXSize() / 2){
		m_x = SCREEN_XSIZE - sp_player->getXSize() / 2;
	}
	if (m_y < sp_player->getYSize() / 2){
		m_y = sp_player->getYSize() / 2;
	}
	if (m_y > SCREEN_YSIZE - sp_player->getYSize() / 2){
		m_y = SCREEN_YSIZE - sp_player->getYSize() / 2;
	}
	if (m_y == SCREEN_YSIZE - sp_player->getYSize() / 2&&m_jumpflag==1){
		m_jumpflag = 0;
	}
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
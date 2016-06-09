#include "PlayerObject.h"
#define SCREEN_XSIZE 640
#define SCREEN_YSIZE 480


void Player::init(){
	m_vx_max_walk = 5;
	m_vx_max_dash = 10;
	m_vy_max = 10;
	m_ax = 1;
	m_ay = 20;
	m_jumpflag = 0;
	m_dashflag = 0;
}

void Player::loadTexture(const std::unique_ptr<Root>& root){
	//主人公の画像データ
	auto new_tex = assetfactory::TextureFactory::createFromFile("image/char.bmp");
	root->tex_container.registerObject(new_tex, "Player");
}

void Player::setPlayerSprite(const std::unique_ptr<Root>& root){
	sp_player.reset(new Sprite());
	sp_player->setTexture(root->tex_container.findAssetByname("Player"));
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

	if (controller.AButton->isPressed()&&m_jumpflag==0){
		m_vy = -m_ay;
		m_jumpflag = 1;
	}
	if (controller.BButton->isBeingPressed()){
		m_dashflag = 1;
	}
	else{
		m_dashflag = 0;
	}
}

void Player::update(){
	if (m_dashflag == 0){
		if (m_vx > m_vx_max_walk){
			m_vx -= 1;
		}
		if (m_vx < -1 * m_vx_max_walk){
			m_vx += 1;
		}
	}
	if (m_dashflag == 1){
		if (m_vx > m_vx_max_dash){
			m_vx -= 1;
		}
		if (m_vx < -1 * m_vx_max_dash){
			m_vx += 1;
		}
	}
	
	if (m_y <= SCREEN_YSIZE - sp_player->getYSize() / 2 && m_y >= sp_player->getYSize() / 2){
		m_vy += 1;
	}

	m_x += m_vx;
	m_y += m_vy;

	if (m_x < sp_player->getXSize() / 2){
		m_x = sp_player->getXSize() / 2;
		m_vx = 0;
	}

	if (m_x > SCREEN_XSIZE - sp_player->getXSize() / 2){
		m_x = SCREEN_XSIZE - sp_player->getXSize() / 2;
		m_vx = 0;
	}

	if (m_y < sp_player->getYSize() / 2){
		m_y = sp_player->getYSize() / 2;
		m_vy = 0;
	}

	if (m_y > SCREEN_YSIZE - sp_player->getYSize() / 2){
		m_y = SCREEN_YSIZE - sp_player->getYSize() / 2;
		m_vy = 0;
	}

	if (m_y == SCREEN_YSIZE - sp_player->getYSize() / 2 && m_jumpflag == 1){
		m_jumpflag = 0;
	}

	sp_player->setPosition(m_x, m_y);
}

void Player::setDrawIn(const std::unique_ptr<Root>& root){
	root->layers[1].push_back(sp_player);
}
void Player::setDrawOut(const std::unique_ptr<Root>& root){
	root->layers[1].remove(sp_player);
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
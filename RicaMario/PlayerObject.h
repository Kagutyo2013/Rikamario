#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include "OperableObject.h"
#include "TextureFactory.h"
#include "SoundFactory.h"
#include "Sprite.h"
#include "Root.h"
#include "AssetContainer.h"
#include "Texture.h"
#include "Sound.h"

class Player:public component::OperableObject{
private:
	
	//座標
	int m_x;
	int m_y;

	int m_vx;
	int m_vy;
	int m_vx_max_walk;
	int m_vx_max_dash;
	int m_vy_max;

	int m_ax;
	int m_ay;

	int m_timer_x;
	int m_timer_y;

	//各種フラグ
	int m_jumpflag;
	int m_dashflag;

	//プレイヤーのスプライト
	std::shared_ptr<Sprite> sp_player;
public:
	//初期化系
	void init(const std::unique_ptr<Root>& root, AssetContainer<asset::Texture>& tex_container, AssetContainer<asset::Sound>& sound_container);

	//プレイヤースプライトのセット
	void initPlayerSprite(const std::unique_ptr<Root>& root, AssetContainer<asset::Texture>& tex_container);

	//更新系
	void inputAction(const Controller& controller)override;

	void update();

	//取得・設定系
	void setDrawIn(const std::unique_ptr<Root>& root);

	void setDrawOut(const std::unique_ptr<Root>& root);

	const int getPosition(int& select)const;

	void setPosition(const int& select, const int& arg);

	const int getFlag(int& select)const;

	void setFlag(const int& select, const int& arg);
};
#endif 
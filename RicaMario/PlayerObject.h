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
	
	//���W
	int m_x;
	int m_y;

	//�v���C���[�̃X�v���C�g
	std::shared_ptr<Sprite> m_player;
public:
	//�������n
	void init(const std::unique_ptr<Root>& root, AssetContainer<asset::Texture>& tex_container, AssetContainer<asset::Sound>& sound_container);

	//�v���C���[�X�v���C�g�̃Z�b�g
	void initPlayerSprite(const std::unique_ptr<Root>& root, AssetContainer<asset::Texture>& tex_container);

	//�X�V�n
	void inputAction(const Controller& controller)override;

	void update();

	//�擾�E�ݒ�n
	void setDrawIn(const std::unique_ptr<Root>& root);

	void setDrawOut(const std::unique_ptr<Root>& root);

	const int getPosition(int& select)const;

	void setPosition(const int& select, const int& arg);
};
#endif 
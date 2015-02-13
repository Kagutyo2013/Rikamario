#include "GameScene.h"

scene::Game::Game() :now_state(new Load()){

}

//���[�h�X�e�[�g
void scene::Game::Load::update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root){
	loadingTextures(parent.m_tex_container);
	loadingSounds(parent.m_sound_container);

	//�ǂݍ��݂Ɏ��s�����ꍇ�̓��b�Z�[�W��\��
	if (parent.m_tex_container.includeInvalidObject()){
		MessageBox(nullptr, "�e�N�X�`���t�@�C���̓ǂݍ��݂Ɏ��s���܂����B", "�G���[", MB_ICONERROR | MB_OK);
		new_state.reset(nullptr);
		return;
	}

	if (parent.m_sound_container.includeInvalidObject()){
		MessageBox(nullptr, "�T�E���h�t�@�C���̓ǂݍ��݂Ɏ��s���܂����B", "�G���[", MB_ICONERROR | MB_OK);
		new_state.reset(nullptr);
		return;
	}

	new_state.reset(new Init());
}

void scene::Game::Load::loadingTextures(AssetContainer<asset::Texture>& container){
	//��l���̉摜�f�[�^
	auto new_tex = assetfactory::TextureFactory::createFromFile("image/char.bmp");
	container.registerObject(new_tex, "Player");
}

void scene::Game::Load::loadingSounds(AssetContainer<asset::Sound>& container){

}

//�������X�e�[�g
void scene::Game::Init::update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root){
	root->layers.resize(3);
	parent.m_player.reset(new Player());
	parent.m_player->init(root, parent.m_tex_container, parent.m_sound_container);
	parent.m_player->setPosition(0, 16);
	parent.m_player->setPosition(1, 480-16);
	parent.m_player->setDrawIn(root);
	SetDrawBright(255, 255,255);
	new_state.reset(new Play());
}

//�v���C�X�e�[�g
void scene::Game::Play::update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root){
	parent.m_player->update();
	m_time++;
}

void scene::Game::update(std::unique_ptr<Base>& new_scene, const std::unique_ptr<Root>& root){
	now_state->update(*this, now_state, root);
	if (now_state == nullptr){
		new_scene.reset(nullptr);
		return;
	}
}
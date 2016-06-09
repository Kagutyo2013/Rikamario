#include "GameScene.h"

scene::Game::Game() :now_state(new Init()){

}

//初期化ステート
void scene::Game::Init::update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root){
	root->layers.resize(3);
	parent.m_player.reset(new Player());
	parent.m_player->init();
	parent.m_map.reset(new MapClass());
	parent.m_map->init();
	new_state.reset(new Load());
}

//ロードステート
void scene::Game::Load::update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root){
	parent.m_player->loadTexture(root);
	parent.m_map->loadTexture(root);

	//読み込みに失敗した場合はメッセージを表示
	if (root->tex_container.includeInvalidObject()){
		MessageBox(nullptr, "テクスチャファイルの読み込みに失敗しました。", "エラー", MB_ICONERROR | MB_OK);
		new_state.reset(nullptr);
		return;
	}

	if (root->sound_container.includeInvalidObject()){
		MessageBox(nullptr, "サウンドファイルの読み込みに失敗しました。", "エラー", MB_ICONERROR | MB_OK);
		new_state.reset(nullptr);
		return;
	}

	new_state.reset(new Set());
}

//設定ステート
void scene::Game::Set::update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root){
	//プレイヤーの設定
	parent.m_player->setPlayerSprite(root);
	parent.m_player->setPosition(0, 16);
	parent.m_player->setPosition(1, 480 - 16);
	parent.m_player->update();
	parent.m_player->setDrawIn(root);
	root->controller_factory.find(1)->push_back(parent.m_player);

	//マップの設定
	parent.m_map->set(root);
	parent.m_map->update();
	parent.m_map->setDrawIn(root);
	SetDrawBright(255, 255, 255);
	new_state.reset(new Play());
}

//プレイステート
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
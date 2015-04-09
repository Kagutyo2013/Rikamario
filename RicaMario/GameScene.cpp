#include "GameScene.h"

scene::Game::Game() :now_state(new Init()){

}

//初期化ステート
void scene::Game::Init::update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root){
	parent.m_mapdata.resize(MAP_YSIZE);
	for (int i = 0; i < MAP_YSIZE; i ++ ){
		parent.m_mapdata.at(i).resize(MAP_XSIZE);
	}
	new_state.reset(new Load());
}

//ロードステート
void scene::Game::Load::update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root){
	loadingTextures(parent.m_tex_container);
	loadingSounds(parent.m_sound_container);

	//読み込みに失敗した場合はメッセージを表示
	if (parent.m_tex_container.includeInvalidObject()){
		MessageBox(nullptr, "テクスチャファイルの読み込みに失敗しました。", "エラー", MB_ICONERROR | MB_OK);
		new_state.reset(nullptr);
		return;
	}

	if (parent.m_sound_container.includeInvalidObject()){
		MessageBox(nullptr, "サウンドファイルの読み込みに失敗しました。", "エラー", MB_ICONERROR | MB_OK);
		new_state.reset(nullptr);
		return;
	}

	new_state.reset(new Set());
}

void scene::Game::Load::loadingTextures(AssetContainer<asset::Texture>& container){
	//主人公の画像データ
	auto new_tex = assetfactory::TextureFactory::createFromFile("image/char.bmp");
	container.registerObject(new_tex, "Player");
}

void scene::Game::Load::loadingSounds(AssetContainer<asset::Sound>& container){

}

//設定ステート
void scene::Game::Set::update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root){
	root->layers.resize(3);
	setMap(parent.m_mapdata);
	parent.m_player.reset(new Player());
	parent.m_player->init(root, parent.m_tex_container, parent.m_sound_container);
	parent.m_player->setPosition(0, 16);
	parent.m_player->setPosition(1, 480 - 16);
	parent.m_player->update();
	parent.m_player->setDrawIn(root);
	root->controller_factory.find(1)->push_back(parent.m_player);
	SetDrawBright(255, 255, 255);
	new_state.reset(new Play());
}

void scene::Game::Set::setMap(std::vector<std::vector<int>>& mapdata){
	for (int i = 0; i < MAP_YSIZE; i++){
		for (int j = 0; j < MAP_XSIZE; j++){
			mapdata.at(i).at(j) = 0;
		}
	}
	for (int j = 0; j < MAP_XSIZE; j++){
		mapdata.at(MAP_YSIZE-1).at(j) = 1;
	}
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
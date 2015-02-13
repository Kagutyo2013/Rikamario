#include "GameManager.h"

//#define DEBUG

int GameManager::update(){
	
	if (ProcessMessage() != 0){
		return -1;
	}
	fps_mgr->update();
	if (now_scene == nullptr){
		fps_mgr->wait();
		return -1;
	}
	else{
		// InputManagerを実行
		root->input_mgr.exec();
		// ゲームの更新処理を書く
		now_scene->update(now_scene, root);
		for (const auto& obj : root->update_list){
			obj->update();
		}
	}
	fps_mgr->wait();
	return 0;
}

int GameManager::draw() const{
	if (ClearDrawScreen() != 0){
		return -1;//画面クリア処理がエラーなら-1を返す
	}
	for (const auto& layer : root->layers){
		for (const auto& obj : layer){
			obj->draw();
		}
	}
#ifdef DEBUG
	fps_mgr->draw();
#endif
	ScreenFlip();//裏画面反映
	return 0;
}

int GameManager::initialize(){
	ChangeWindowMode(TRUE);//ウィンドウモード
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//初期化と裏画面化
	SetWindowText("ＲｉｋａＭａｒｉｏ");
	SetTransColor(0, 0, 0); //指定した色を透明色とする
	SetDrawBright(0,0,0);//輝度を0にセット
	root->input_mgr.push_back(root->controller_factory.find(1));
	root->layers.resize(3);
	return 0;
}

int GameManager::run(){
	if (update() != 0) return -1; // 更新処理が失敗なら-1を返す
	if (draw() != 0) return -1; // 描画処理が失敗なら-1を返す
	return 0;
}

void GameManager::terminate(){
	DxLib_End();//ＤＸライブラリ終了処理
}

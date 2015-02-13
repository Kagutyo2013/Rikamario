#ifndef _GAME_SCENE_H
#define _GAME_SCENE_H

#define MAP_XSIZE 32
#define MAP_YSIZE 24

#include "SceneBase.h"
#include "State.h"
#include "Sprite.h"
#include "TextureFactory.h"

namespace scene{
	class Game :public scene::Base{
	private:

		//変数

		//ポインタ
		std::unique_ptr<State<scene::Game>> now_state;

		//クラス

	public:
		Game();
		void update(std::unique_ptr<Base>& new_scene, const std::unique_ptr<Root>& root)override;
	};
}

#endif
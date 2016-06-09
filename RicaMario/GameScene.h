#ifndef _GAME_SCENE_H
#define _GAME_SCENE_H

#include "SceneBase.h"
#include "State.h"
#include "Sprite.h"
#include "TextureFactory.h"
#include "PlayerObject.h"
#include "MapClass.h"

namespace scene{
	class Game :public scene::Base{
	private:

		//変数


		//ポインタ
		std::unique_ptr<State<scene::Game>> now_state;
		std::shared_ptr<Player> m_player;
		std::unique_ptr<MapClass> m_map;

		//クラス
		//初期化ステート
		class Init :public State < Game > {
		private:

		public:
			void update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root)override;
		};
		//ロードステート
		class Load :public State<Game>{
		private:
		public:
			void update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root)override;
		};
		//設定ステート
		class Set :public State < Game > {
		private:
		public:
			void update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root)override;
		};
		//プレイステート
		class  Play :public State<Game>{
		private:
			int m_time = 0;
		public:
			void update(Game& parent, std::unique_ptr<State<Game>>& new_state, const std::unique_ptr<Root>& root)override;
		};

	public:
		Game();
		void update(std::unique_ptr<Base>& new_scene, const std::unique_ptr<Root>& root)override;
	};
}

#endif
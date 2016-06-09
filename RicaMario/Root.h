#ifndef _ROOT_H
#define _ROOT_H

#include "Component.h"
#include "InputManager.h"
#include "ControllerFactory.h"
#include "AssetContainer.h"
#include "Texture.h"
#include "Sound.h"

class Root{
public:
	std::list<std::shared_ptr<component::UpdateObject>> update_list;

	std::vector<std::list<std::shared_ptr<component::DrawableObject>>> layers;

	InputManager input_mgr;

	ControllerFactory controller_factory;

	//テクスチャコンテナ
	AssetContainer<asset::Texture> tex_container;

	//サウンドコンテナ
	AssetContainer<asset::Sound> sound_container;
};

#endif
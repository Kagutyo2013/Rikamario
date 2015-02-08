#ifndef _SCENE_BASE_H
#define _SCENE_BASE_H

#include "Root.h"
#include "State.h"
#include "AssetContainer.h"
#include "Texture.h"
#include "Sound.h"

namespace scene{
	class Base{
	protected:
		//�e�N�X�`���R���e�i
		AssetContainer<asset::Texture> m_tex_container;

		//�T�E���h�R���e�i
		AssetContainer<asset::Sound> m_sound_container;
	public:
		virtual ~Base(){}
		// �V�[����ύX�������Ƃ���new_scene��ς���
		virtual void update(std::unique_ptr<Base>& new_scene,const std::unique_ptr<Root>& root) = 0;
	};
}

#endif
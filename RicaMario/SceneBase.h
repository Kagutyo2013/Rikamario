#ifndef _SCENE_BASE_H
#define _SCENE_BASE_H

#include "Root.h"
#include "State.h"

namespace scene{
	class Base{
	public:
		virtual ~Base(){}
		// シーンを変更したいときはnew_sceneを変える
		virtual void update(std::unique_ptr<Base>& new_scene,const std::unique_ptr<Root>& root) = 0;
	};
}

#endif
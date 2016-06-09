#ifndef _SCENE_BASE_H
#define _SCENE_BASE_H

#include "Root.h"
#include "State.h"

namespace scene{
	class Base{
	public:
		virtual ~Base(){}
		// ƒV[ƒ“‚ğ•ÏX‚µ‚½‚¢‚Æ‚«‚Ínew_scene‚ğ•Ï‚¦‚é
		virtual void update(std::unique_ptr<Base>& new_scene,const std::unique_ptr<Root>& root) = 0;
	};
}

#endif
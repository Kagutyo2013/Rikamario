#ifndef _OPERABLE_OBJECT_H
#define _OPERABLE_OBJECT_H

#include "Controller.h"

namespace component{
	class OperableObject{
	public:
		virtual ~OperableObject() = default;
		// �R���g���[���[�I�u�W�F�N�g���󂯎���đΉ�����������s��
		virtual void inputAction(const Controller& controller) = 0;
		// �}�E�X�̈ʒu�Ȃǂ�m��K�v������ꍇ�A�ʓr�֐���p�ӂ���
		// virtual void mouseAction(const input::Mouse& mouse){}
	};
}
#endif
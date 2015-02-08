#include "Controller.h"
#include "OperableObject.h"

input::KeyBoard* Controller::Button::p_keyboard = nullptr;
input::Mouse* Controller::Button::p_mouse = nullptr;

void Controller::exec(const std::unique_ptr<input::KeyBoard>& keyboard, const std::unique_ptr<input::Mouse>& mouse){
	// �{�^���̍X�V
	Button::Update(keyboard, mouse);
	//���X�g�Ɋ܂܂��S�I�u�W�F�N�g�ɑ΂��Ď����̏�Ԃ�n���ăI�u�W�F�N�g�𑀍삷��
	for (const auto& obj : *this){
		obj->inputAction(*this);
	}
}
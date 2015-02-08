#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "Input.h"

namespace component{
	class OperableObject;
}

class Controller : public std::list<std::shared_ptr<component::OperableObject>>{
public:
	// �{�^���N���X
	class Button{
	private:
		static input::KeyBoard* p_keyboard;
		static input::Mouse* p_mouse;
	protected:
		// �{�^���ɑΉ�����L�[�{�[�h�̃L�[ID
		unsigned int m_keyboard_key;
		// �{�^���ɑΉ�����}�E�X�̃{�^��ID
		//unsigned int m_mouse_button;
	public:
		// �{�^���̍X�V���s��
		static void Update(const std::unique_ptr<input::KeyBoard>& keyboard, const std::unique_ptr<input::Mouse>& mouse){
			p_keyboard = keyboard.get();
			p_mouse = mouse.get();
		}
		Button(unsigned int keyboad_key = 0) : m_keyboard_key(keyboad_key){}
		inline bool isPressed() const{
			return p_keyboard->isPressed(m_keyboard_key);
		}
		inline bool isBeingPressed() const{
			return p_keyboard->isBeingPressed(m_keyboard_key);
		}
		inline bool isReleased() const{
			return p_keyboard->isReleased(m_keyboard_key);
		}
	};

	// 6�̃{�^��
	std::unique_ptr<Button> AButton;
	std::unique_ptr<Button> BButton;
	std::unique_ptr<Button> CButton;
	std::unique_ptr<Button> DButton;
	std::unique_ptr<Button> EButton;
	std::unique_ptr<Button> FButton;
	// �\���L�[
	std::unique_ptr<Button> UpKey;
	std::unique_ptr<Button> RightKey;
	std::unique_ptr<Button> DownKey;
	std::unique_ptr<Button> LeftKey;
	// ����ȃ{�^��
	std::unique_ptr<Button> SelectButton;
	std::unique_ptr<Button> StartButton;

	virtual ~Controller() = default;

	// ����\�I�u�W�F�N�g�𑀍삷��
	void exec(const std::unique_ptr<input::KeyBoard>& keyboard, const std::unique_ptr<input::Mouse>& mouse);
};

#endif

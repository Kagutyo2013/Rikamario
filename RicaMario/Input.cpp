#include "Input.h" 

input::KeyBoard::KeyBoard(){
	// �o�b�t�@�̏�����
	ZeroMemory(pre_buffer, sizeof(char)* 256);
	ZeroMemory(now_buffer, sizeof(char)* 256);
}

void input::KeyBoard::acquireState(){
	// ���݂̃L�[�̏�Ԃ��擾
	GetHitKeyStateAll(now_buffer);
}

void input::KeyBoard::end(){
	// ���݂̃L�[�̏�Ԃ�pre_buffer�ɃR�s�[����
	memcpy_s(pre_buffer, sizeof(char)* 256, now_buffer, sizeof(char)* 256);
}

void input::Mouse::acquireState(){
	// �ʒu���擾
	GetMousePoint(&x, &y);
	// �ǂ̃{�^���������ꂽ���擾
	now_buffer = 0xffffffff;
	now_buffer &= GetMouseInput();
}

void input::Mouse::end(){
	// ���݂̏�Ԃ�pre_buffer�Ɉڂ�
	pre_buffer = now_buffer;
}

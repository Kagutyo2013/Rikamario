#include "AppManager.h"
#include "GameManager.h"

void AppManager::run(){
	if (p_game->initialize() != 0) return; // �����������s�����ꍇ���̏�ŏI��
	while (p_game->run() == 0); // ���[�v�������������Ă���܂Ŗ������[�v
	p_game->terminate(); // �f�o�C�X���̉��(�㏈��)
}

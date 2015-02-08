// define�͓�d�C���N���[�h�h�~�̂���
#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include "FpsManager.h"
#include "Root.h"
#include "SceneBase.h"

class GameManager{
private:
	std::unique_ptr<scene::Base> now_scene;
	const std::unique_ptr<FpsManager> fps_mgr;
	const std::unique_ptr<Root> root;
	// �Q�[���̍X�V
	int update();
	// �Q�[���̕`��
	int draw() const;
public:
	/*
	@param first_scene �A�v���J�n��̃V�[��
	*/
	GameManager(scene::Base* first_scene) :root(new Root), fps_mgr(new FpsManager), now_scene(first_scene){}
	~GameManager() = default;
	// ��Ƀ��C�u�����̏��������s�� ����ɏ������ł�����0��Ԃ�
	int initialize();
	// ���C�u�����̉�����s��
	void terminate();
	// �Q�[�������s���� ����ɓ��삵�Ă���Ƃ�0��Ԃ�
	int run();
};
#endif
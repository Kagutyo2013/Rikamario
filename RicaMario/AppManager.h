class GameManager;

class AppManager{
private:
	const std::unique_ptr<GameManager> p_game;

public:
	/*
	@param game_mgr �Q�[���}�l�[�W���N���X�̃|�C���^
	*/
	AppManager(GameManager* game_mgr) : p_game(game_mgr){}
	// �A�v���𓮂���
	void run();
};
#include "ControllerFactory.h"
#include "Controller.h"

Controller* ControllerFactory::create(const unsigned int& player_number){
	Controller* controller = new Controller();
	if (player_number == 1){
		controller->AButton.reset(new Controller::Button(KEY_INPUT_A));
		controller->BButton.reset(new Controller::Button(KEY_INPUT_S));
		controller->CButton.reset(new Controller::Button(KEY_INPUT_D));
		controller->DButton.reset(new Controller::Button(KEY_INPUT_Z));
		controller->EButton.reset(new Controller::Button(KEY_INPUT_X));
		controller->FButton.reset(new Controller::Button(KEY_INPUT_C));

		controller->UpKey.reset(new Controller::Button(KEY_INPUT_UP));
		controller->RightKey.reset(new Controller::Button(KEY_INPUT_RIGHT));
		controller->DownKey.reset(new Controller::Button(KEY_INPUT_DOWN));
		controller->LeftKey.reset(new Controller::Button(KEY_INPUT_LEFT));

		controller->StartButton.reset(new Controller::Button(KEY_INPUT_RETURN));
		controller->SelectButton.reset(new Controller::Button(KEY_INPUT_SPACE));
	}
	return controller;
}

ControllerFactory::ControllerFactory()
{
	// 1つ分のコントローラーを確保しておく
	controllers.resize(4);
}

std::shared_ptr<Controller> ControllerFactory::find(const unsigned int& player_number){
	// 目的のコントローラーが存在しない場合
	if (controllers.at(player_number - 1) == nullptr)
	{
		// コントローラーを作成する
		controllers.at(player_number - 1).reset(create(player_number));
	}
	// コントローラーオブジェクトを返す
	return controllers.at(player_number - 1);
}

#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() { delete modelEffect_; }

void GameScene::Initialize() {
	modelEffect_ = Model::CreateFromOBJ("board");

	camera_.Initialize();

	effect_ = new Effect();
	effect_->Initialize(modelEffect_);
}

void GameScene::Update() { effect_->Update(); }

void GameScene::Drow() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());
	effect_->Drow(camera_);

	Model::PostDraw();
}

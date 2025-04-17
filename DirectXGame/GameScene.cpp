#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {
	delete modelParticle_;

}


void GameScene::Initialize() {
	modelParticle_ = Model::CreateSphere(4, 4);

	camera_.Initialize();

	particle_ = new Particle();
	particle_->Initialize(modelParticle_);

}

void GameScene::Update() { 
	particle_->Update();

}

void GameScene::Drow() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());
	particle_->Drow(camera_);


	Model::PostDraw();
}

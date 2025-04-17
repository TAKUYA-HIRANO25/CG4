#include "GameScene.h"

using namespace KamataEngine;
using namespace MathUtility;

GameScene::GameScene() {}

GameScene::~GameScene() {
	delete modelParticle_;

}


void GameScene::Initialize() {
	modelParticle_ = Model::CreateSphere(4, 4);

	camera_.Initialize();

	for (int i = 0; i < 150; i++) {
		Particle* particle = new Particle();
		Vector3 position = {0.5f * i, 0.0f, 0.0f};

		particle->Initialize(modelParticle_, position);
		particles_.push_back(particle);
	}

}

void GameScene::Update() { 
	for (Particle* particle : particles_) {
		particle->Update();
	}

}

void GameScene::Drow() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	for (Particle* particle : particles_) {
		particle->Drow(camera_);
	}


	Model::PostDraw();
}

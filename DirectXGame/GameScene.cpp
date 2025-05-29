#include "GameScene.h"
#include <random>

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);
std::uniform_real_distribution<float> scaleYDist(2.0f, 4.0f);
std::uniform_real_distribution<float> rotZDist(0.0f, 3.14f);

using namespace KamataEngine;

GameScene::GameScene() {}


GameScene::~GameScene() { 
	delete modelEffect_;
	delete effect_;
}

void GameScene::Initialize() {
	modelEffect_ = Model::CreateFromOBJ("board",true);

	camera_.Initialize();

	Vector3 scale = {0.3f, scaleYDist(randomEngine), 1.0f};
	Vector3 rotation = {0.0f, 0.0f, rotZDist(randomEngine)};

	effect_ = new Effect();
	effect_->Initialize(modelEffect_, scale, rotation);
}

void GameScene::Update() { effect_->Update(); }

void GameScene::Drow() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());
	effect_->Drow(camera_);

	Model::PostDraw();
}

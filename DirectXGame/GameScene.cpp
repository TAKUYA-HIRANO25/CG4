#include "GameScene.h"
#include <random>
#include<numbers>

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);
std::uniform_real_distribution<float> scaleYDist(2.0f, 4.0f);
std::uniform_real_distribution<float> rotZDist(0.0f, 3.14f);
std::uniform_real_distribution<float> colorDist(0.0f, 1.0f);

using namespace KamataEngine;
using namespace MathUtility;

GameScene::GameScene() {}


GameScene::~GameScene() { 
	delete modelEffect_;
	for (Effect* effect : effects_) {
		delete effect;
	}
	effects_.clear();
}

void GameScene::Initialize() {
	modelEffect_ = Model::CreateFromOBJ("board",true);

	camera_.Initialize();

	srand((unsigned)time(NULL));

}

void GameScene::Update() { 

	if (rand() % 10 == 0) {
		
		Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};

		EffectBorn(position);
	}

	for (Effect* effect : effects_) {
		effect->Update();
	}

	effects_.remove_if([](Effect* effect) {
		if (effect->IsFinished()) {
			delete effect;
			return true;
		}
		return false;
	});

}

void GameScene::Drow() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());
	for (Effect* effect : effects_) {
		effect->Drow(camera_);
	}

	Model::PostDraw();
}

void GameScene::EffectBorn(KamataEngine::Vector3 position) {
	int effectCount = 10;
	Vector4 color = {colorDist(randomEngine), colorDist(randomEngine), colorDist(randomEngine), 1};

	for (int i = 0; i < effectCount; i++) {

		Effect* effect = new Effect();

		float baseAngle = (360.0f / effectCount) * i;

		float finalAngle = baseAngle + rotZDist(randomEngine);

		float angleRad = float(finalAngle * std::numbers::pi / 180.0f);

		Vector3 scale = {1.0f, scaleYDist(randomEngine), 0.3f};

		Vector3 rotation = {0.0f, angleRad, 0.0f};

		effect->Initialize(modelEffect_, scale, rotation, position,color);

		effects_.push_back(effect);
	}
}

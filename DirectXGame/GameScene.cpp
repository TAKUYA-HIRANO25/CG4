#include "GameScene.h"
#include <random>
#include<numbers>

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);
std::uniform_real_distribution<float> scaleYDist(2.0f, 4.0f);
std::uniform_real_distribution<float> rotZDist(0.0f, 3.14f);

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

	int effectCount = 10;

	// エフェクトの生成
	for (int i = 0; i < effectCount; i++) {
		// 生成
		Effect* effect = new Effect();

		// 放射状の基準角度
		float baseAngle = (360.0f / effectCount) * i;

		// ランダムなオフセットを加える
		float finalAngle = baseAngle + rotZDist(randomEngine);

		// ラジアンに変換
		float angleRad = float(finalAngle * std::numbers::pi / 180.0f);

		// サイズ
		Vector3 scale = {0.3f, scaleYDist(randomEngine), 1.0f};
		// 角度
		Vector3 rotation = {0.0f, 0.0f, angleRad};
		// 初期化
		effect->Initialize(modelEffect_, scale, rotation);
		// リストに追加
		effects_.push_back(effect);
	}
}

void GameScene::Update() { 

	for (Effect* effect : effects_) {
		effect->Update();
	}
}

void GameScene::Drow() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());
	for (Effect* effect : effects_) {
		effect->Drow(camera_);
	}

	Model::PostDraw();
}

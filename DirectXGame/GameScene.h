#pragma once
#include "KamataEngine.h"
#include "Effect.h"
class GameScene {
public:
	GameScene();

	~GameScene();

	void Initialize();

	void Update();

	void Drow();

private:
	KamataEngine::Model* modelEffect_ = nullptr;

	KamataEngine::Camera camera_;

	Effect* effect_ = nullptr;
};

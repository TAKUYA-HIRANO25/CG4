#pragma once
#include "KamataEngine.h"
#include "Parrticle.h"
class GameScene {
public:
	GameScene();

	~GameScene();

	void Initialize();

	void Update();

	void Drow();

private:
	KamataEngine::Model* modelParticle_ = nullptr;

	KamataEngine::Camera camera_;

		std::list<Particle*> particles_;
};
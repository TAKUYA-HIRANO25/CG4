#pragma once
#include <KamataEngine.h>

class Effect {
public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 scale, KamataEngine::Vector3 rotate);

	void Update();

	void Drow(KamataEngine::Camera& camera);

private:
	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Model* model_ = nullptr;

	KamataEngine::Vector3 scale_;
	KamataEngine::Vector3 rotation_;
};


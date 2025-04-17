#pragma once
#include <KamataEngine.h>

class Particle {
public:

	void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 position, KamataEngine::Vector3 velocity);

	void Update();

	void Drow(KamataEngine::Camera& camera);

private:

	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Model* model_ = nullptr;

	KamataEngine::ObjectColor objectColor_;
	KamataEngine::Vector4 color_;

	KamataEngine::Vector3 velocity_;
};

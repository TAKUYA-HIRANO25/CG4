#pragma once
#include <KamataEngine.h>

class Particle {
public:

	void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 position, KamataEngine::Vector3 velocity);

	void Update();

	void Drow(KamataEngine::Camera& camera);

	bool IsFinished() { return isFinished_; }

private:

	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Model* model_ = nullptr;

	KamataEngine::ObjectColor objectColor_;
	KamataEngine::Vector4 color_;

	KamataEngine::Vector3 velocity_;

	bool isFinished_ = false;

	float counter_ = 0.0f;
	const float kDurtion_ = 1.0f;

};

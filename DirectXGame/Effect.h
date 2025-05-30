#pragma once
#include <KamataEngine.h>

class Effect {
public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 scale, KamataEngine::Vector3 rotate, KamataEngine::Vector3 position, KamataEngine::Vector4 color);

	void Update();

	void Drow(KamataEngine::Camera& camera);

	bool IsFinished() { return isFinished_; }

private:
	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Model* model_ = nullptr;
	
	KamataEngine::ObjectColor objectColor_;
	
	KamataEngine::Vector4 color_;

	
	bool isFinished_ = false;
	
	float counter_ = false;
	
	const float kDuration = 1.0f;
};


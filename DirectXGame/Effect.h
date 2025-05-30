#pragma once
#include <KamataEngine.h>

class Effect {
public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 scale, KamataEngine::Vector3 rotate);

	void Update();

	void Drow(KamataEngine::Camera& camera);

	bool IsFinished() { return isFinished_; }

private:
	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Model* model_ = nullptr;

	KamataEngine::Vector3 scale_;
	KamataEngine::Vector3 rotation_;

	
	KamataEngine::ObjectColor objectColor_;
	
	KamataEngine::Vector4 color_;

	
	bool isFinished_ = false;
	
	float counter_ = false;
	
	const float kDuration = 1.0f;
};


#include "Effect.h"
#include "algorithm"

using namespace KamataEngine;
using namespace MathUtility;

void Effect::Initialize(Model* model, Vector3 scale, Vector3 rotate, Vector3 position) {
	assert(model);

	model_ = model;

	scale_ = scale;
	rotation_ = rotate;

	worldTransform_.Initialize();

	objectColor_.Initialize();
	color_ = {1, 1, 1, 1};
}

void Effect::Update() { 
	worldTransform_.scale_ = scale_;
	worldTransform_.rotation_ = rotation_;

	if (isFinished_) {
		return;
	}
	counter_ += 1.0f / 60.0f;

	if (counter_ >= kDuration) {
		counter_ = kDuration;
		isFinished_ = true;
	}

	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);
	
	worldTransform_.UpdateMatrix();

	objectColor_.SetColor(color_);
}

void Effect::Drow(Camera& camera) { 
	model_->Draw(worldTransform_, camera, &objectColor_); 
}

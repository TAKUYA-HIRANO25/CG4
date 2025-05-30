#include "Effect.h"
#include "algorithm"

using namespace KamataEngine;
using namespace MathUtility;

void Effect::Initialize(Model* model, Vector3 scale, Vector3 rotate, Vector3 position, Vector4 color) {
	assert(model);

	model_ = model;

	worldTransform_.Initialize();

	worldTransform_.scale_ = scale;
	worldTransform_.rotation_ = rotate;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;

	objectColor_.Initialize();
	color_ = color;
}

void Effect::Update() { 
	worldTransform_.translation_.y -= 0.1f;
	worldTransform_.scale_.y -= 0.05f;

	if (isFinished_) {
		return;
	}
	counter_ += 1.0f / 60.0f;

	if (counter_ >= kDuration) {
		counter_ = kDuration;
		isFinished_ = true;
	}
	
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);
	
	worldTransform_.translation_.y -= 0.1f;

	worldTransform_.UpdateMatrix();

	objectColor_.SetColor(color_);
}

void Effect::Drow(Camera& camera) { 
	model_->Draw(worldTransform_, camera, &objectColor_); 
}

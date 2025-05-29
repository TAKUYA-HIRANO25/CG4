#include "Effect.h"
using namespace KamataEngine;
using namespace MathUtility;

void Effect::Initialize(Model* model,Vector3 scale, Vector3 rotate) {
	assert(model);

	model_ = model;

	scale_ = scale;
	rotation_ = rotate;

	worldTransform_.Initialize();
}

void Effect::Update() { 
	worldTransform_.scale_ = scale_;
	worldTransform_.rotation_ = rotation_;

	worldTransform_.UpdateMatrix();
}

void Effect::Drow(Camera& camera) { model_->Draw(worldTransform_, camera); }

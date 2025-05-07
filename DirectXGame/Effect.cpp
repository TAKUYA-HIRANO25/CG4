#include "Effect.h"
using namespace KamataEngine;
using namespace MathUtility;

void Effect::Initialize(Model* model) {
	assert(model);

	model_ = model;

	worldTransform_.Initialize();
}

void Effect::Update() { worldTransform_.TransferMatrix(); }

void Effect::Drow(Camera& camera) { model_->Draw(worldTransform_, camera); }

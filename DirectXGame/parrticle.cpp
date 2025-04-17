#include "Parrticle.h"

using namespace KamataEngine;
using namespace MathUtility;

void Particle::Initialize(Model* model) { 
	assert(model);

	model_ = model;

	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	worldTransform_.Initialize();

}

void Particle::Update() { 
	objectColor_.SetColor(color_);

	worldTransform_.translation_ += {0.0f, 0.1f, 0.0f};

	worldTransform_.TransferMatrix(); 

	worldTransform_.UpdateMatrix();
}

void Particle::Drow(Camera& camera) {

	model_->Draw(worldTransform_, camera, &objectColor_);

}

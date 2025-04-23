#include "Parrticle.h"

using namespace KamataEngine;
using namespace MathUtility;

void Particle::Initialize(Model* model, KamataEngine::Vector3 position, KamataEngine::Vector3 velocity) { 
	assert(model);

	model_ = model;

	velocity_ = velocity;

	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};
	
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;

	worldTransform_.scale_ = {0.2f, 0.2f, 0.2f};

}

void Particle::Update() { 
	
	objectColor_.SetColor(color_);

	worldTransform_.translation_ += velocity_;

	worldTransform_.TransferMatrix(); 

	worldTransform_.UpdateMatrix();
}

void Particle::Drow(Camera& camera) {

	model_->Draw(worldTransform_, camera, &objectColor_);

}

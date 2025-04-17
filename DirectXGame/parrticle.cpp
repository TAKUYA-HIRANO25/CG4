#include "Parrticle.h"

using namespace KamataEngine;
using namespace MathUtility;

void Particle::Initialize(Model* model) { 
	assert(model);

	model_ = model;

	worldTransform_.Initialize();

}

void Particle::Update() { 
	
	worldTransform_.TransferMatrix(); 

}

void Particle::Drow(Camera& camera) {

	model_->Draw(worldTransform_, camera);

}

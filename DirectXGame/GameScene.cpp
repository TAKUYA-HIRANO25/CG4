#include "GameScene.h"
#include <random>
using namespace KamataEngine;
using namespace MathUtility;

std::random_device seedgenertor;
std::mt19937 randomEngine(seedgenertor());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

GameScene::GameScene() {}

GameScene::~GameScene() { 

	delete modelParticle_; 

	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();
}

void GameScene::Initialize() {

	modelParticle_ = Model::CreateSphere(4, 4);


	for (int i = 0; i < 150; i++) {
		Particle* particle = new Particle();
		Vector3 position = {0.0f, 0.0f, 0.0f};
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;
		particle->Initialize(modelParticle_, position,velocity);
		particles_.push_back(particle);
	}

	camera_.Initialize();


}

void GameScene::Update() {

	for (Particle* particle : particles_) {
		particle->Update();
	}


}

void GameScene::Drow() { 
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

for (Particle* particle : particles_) {
		particle->Drow(camera_);
	}

	Model::PostDraw();

}

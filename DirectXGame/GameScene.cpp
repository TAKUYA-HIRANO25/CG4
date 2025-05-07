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
	srand((unsigned)time(NULL));
	camera_.Initialize();


}

void GameScene::Update() {

	if (rand() % 20 == 0) {
		Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};
		ParticleBorm(position);
	}

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

void GameScene::ParticleBorm(Vector3 position) {

	for (int i = 0; i < 150; i++) {
		Particle* particle = new Particle();
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;
		particle->Initialize(modelParticle_, position, velocity);
		particles_.push_back(particle);
	}
	particles_.remove_if([](Particle* particle) {
		if (particle->IsFinished()) {
			delete particle;
			return true;
		}
		return false;
	});
}


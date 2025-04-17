#pragma once
#include <KamataEngine.h>

class Particle {
public:

	void Initialize(KamataEngine::Model* model);

	void Update();

	void Drow(KamataEngine::Camera& camera);

private:

	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Model* model_ = nullptr;

};

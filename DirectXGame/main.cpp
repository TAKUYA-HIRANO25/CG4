#pragma once
#include <Windows.h>
#include "GameScene.h"
#include "KamataEngine.h"

using namespace KamataEngine;
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	KamataEngine::Initialize(L"LE3C_20_ヒラノ_タクヤ_CG4");
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	GameScene* gamescene = new GameScene();

	gamescene->Initialize();

	while (true) {

		if (KamataEngine::Update()) {
			break;
		}

		gamescene->Update();

		dxCommon->PreDraw();

		gamescene->Drow();

		dxCommon->PostDraw();
	}

	delete gamescene;

	gamescene = nullptr;

	KamataEngine::Finalize();
	return 0;
}

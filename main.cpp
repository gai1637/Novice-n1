#include <Novice.h>
#include"ClassMain.h"
#include"GamePlay.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	/*ClassMain *classmain = new ClassMain;*/
	GamePlay* game = new GamePlay;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		/*classmain->Update(keys, preKeys);*/
		game->Update();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		/*classmain->Draw();*/
		game->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	/*delete classmain;*/
	delete game;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

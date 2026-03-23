#include <memory>

#include "raylib.h"

#include "level.h"
#include "sprite.h"

int main() {
    constexpr int kScreenWidth = 800;
    constexpr int kScreenHeight = 600;
    constexpr int kSpriteCount = 20;
    constexpr float kMaxSpeed = 3.0f;

    InitWindow(kScreenWidth, kScreenHeight, "Task 8 - Level Class");
    SetTargetFPS(60);

    // Texture loaded after InitWindow
    Texture2D shared_texture = LoadTexture("assets//graphics/ghibli_art.png");

    game::Level level;

    // b: add 20 sprites via for-loop
    for (int i = 0; i < kSpriteCount; ++i) {
        auto sprite = std::make_shared<game::Sprite>(0, 0, shared_texture);

        // c: give sprite a random velocity
        sprite->velocity_.x =
            static_cast<float>(GetRandomValue(-kMaxSpeed, kMaxSpeed));
        sprite->velocity_.y =
            static_cast<float>(GetRandomValue(-kMaxSpeed, kMaxSpeed));

        level.sprites_.push_back(sprite);
    }

    level.PositionRandomly();

    while (!WindowShouldClose()) {
        level.Update();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        level.DrawSprites();
        EndDrawing();
    }

    level.sprites_.clear();
    UnloadTexture(shared_texture);
    CloseWindow();

    return 0;
}
#include "Level.h"

#include "raylib.h"

namespace game {

    void Level::DrawSprites() {
        for (const auto& sprite : sprites_) {
            DrawTexture(sprite->texture_,
                sprite->pos_x_, sprite->pos_y_, WHITE);
        }
    }

    void Level::PositionRandomly() {
        for (auto& sprite : sprites_) {
            sprite->pos_x_ = GetRandomValue(0, GetScreenWidth() - sprite->texture_.width);
            sprite->pos_y_ = GetRandomValue(0, GetScreenHeight() - sprite->texture_.height);
        }
    }

    void Level::Update() {
        for (auto& sprite : sprites_) {
            sprite->Update();

            // Wrap around screen edges
            if (sprite->pos_x_ < 0) {
                sprite->pos_x_ = GetScreenWidth();
            }
            else if (sprite->pos_x_ > GetScreenWidth()) {
                sprite->pos_x_ = 0;
            }

            if (sprite->pos_y_ < 0) {
                sprite->pos_y_ = GetScreenHeight();
            }
            else if (sprite->pos_y_ > GetScreenHeight()) {
                sprite->pos_y_ = 0;
            }
        }

        // Check each pair once -> avoid reversing velocities twice
        for (size_t i = 0; i < sprites_.size(); ++i) {
            for (size_t j = i + 1; j < sprites_.size(); ++j) {
                if (CheckCollisionRecs(sprites_[i]->GetBoundingBox(),
                    sprites_[j]->GetBoundingBox())) {
                    sprites_[i]->velocity_.x *= -1.0f;
                    sprites_[i]->velocity_.y *= -1.0f;
                    sprites_[j]->velocity_.x *= -1.0f;
                    sprites_[j]->velocity_.y *= -1.0f;
                }
            }
        }
    }

}
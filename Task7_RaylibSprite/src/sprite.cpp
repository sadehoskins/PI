#include "Sprite.h"

namespace game {

    Sprite::Sprite(int pos_x, int pos_y, Texture2D texture)
        : pos_x_(pos_x),
        pos_y_(pos_y),
        texture_(texture),
        velocity_({ 0.0f, 0.0f }) {
    }

    Sprite::Sprite(int pos_x, int pos_y, const std::string& texture_file)
        : pos_x_(pos_x),
        pos_y_(pos_y),
        velocity_({ 0.0f, 0.0f }) {
        texture_ = LoadTexture(texture_file.c_str());
    }

    Sprite::~Sprite() {
        UnloadTexture(texture_);
    }

    void Sprite::Update() {
        pos_x_ += static_cast<int>(velocity_.x);
        pos_y_ += static_cast<int>(velocity_.y);
    }

    Rectangle Sprite::GetBoundingBox() const {
        return { static_cast<float>(pos_x_),
                static_cast<float>(pos_y_),
                static_cast<float>(texture_.width),
                static_cast<float>(texture_.height) };
    }

}

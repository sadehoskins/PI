#include "Sprite.h"

namespace game {

    Sprite::Sprite(int pos_x, int pos_y, Texture2D texture)
        : pos_x_(pos_x), pos_y_(pos_y), texture_(texture) {
    }

    Sprite::Sprite(int pos_x, int pos_y, const std::string& texture_file)
        : pos_x_(pos_x), pos_y_(pos_y) {
        texture_ = LoadTexture(texture_file.c_str());
    }

    Sprite::~Sprite() {
        UnloadTexture(texture_);
    }

}
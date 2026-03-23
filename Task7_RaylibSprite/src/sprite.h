#ifndef GAME_SPRITE_H_
#define GAME_SPRITE_H_

#include <string>
#include "raylib.h"

namespace game {

	class Sprite {
	public:
		Sprite(int pos_x, int pos_y, Texture2D texture);
		Sprite(int pos_x, int pos_y, const std::string& texture_file);
		~Sprite();

		Sprite(const Sprite&) = delete;
		Sprite& operator=(const Sprite&) = delete;
		Sprite(Sprite&&) = delete;
		Sprite& operator=(Sprite&&) = delete;

		Sprite() = delete;

		int pos_x_;
		int pos_y_;
		Texture2D texture_;
	};

}	//	namespace game

#endif  // GAME_SPRITE_H_
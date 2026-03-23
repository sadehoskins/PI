#ifndef GAME_LEVEL_H_
#define GAME_LEVEL_H_

#include <memory>
#include <vector>

#include "Sprite.h"

namespace game {

	class Level {
	public:
		
		void DrawSprites();

		
		void PositionRandomly();

		// Moves sprites, wraps screen edges, resolves collisions
		void Update();

		std::vector<std::shared_ptr<game::Sprite>> sprites_;
	};

}

#endif  // GAME_LEVEL_H_

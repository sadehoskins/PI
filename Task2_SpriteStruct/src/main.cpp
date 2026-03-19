#include <iostream>
#include <vector>

#include <frame.h>
#include <sprite.h>
#include <sprite_type.h>


void PrintSprite(const Sprite& sprite) {
	std::cout << "Positiion: ("
		<< sprite.position.x << ", "
		<< sprite.position.y << ", "
		<< sprite.position.z << ")\n";
	std::cout << "Drawable: "
		<< (sprite.drawable ? "true" : "false") << "\n";
	std::cout << "Animation frame: "
		<< sprite.current_frame << " of " << sprite.animation_frames << "\n";
	std::cout << "Type: " << static_cast<int>(sprite.type) << "\n";
}

int main() {
	std::vector<Frame> frame_data(4);

	Sprite player_sprite{
		.position = {100.0f, 200.0f, 0.0f},
		.drawable = true,
		.animation_frames = 4,
		.width = 64,
		.height = 64,
		.current_frame = 0,
		.frames = &frame_data,
		.type = SpriteType::kCharacter
	};

	PrintSprite(player_sprite);

	return 0;
}
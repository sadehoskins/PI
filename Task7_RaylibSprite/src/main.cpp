#include "Sprite.h"

#include "raylib.h"

int main() {
    InitWindow(800, 600, "Task 7 - Sprite Class");
    SetTargetFPS(60);

    // loads texture from file
    game::Sprite sprite_from_file(50, 50, "assets//graphics/ghibli_art.png");

    //takes an already loaded texture
    Texture2D pre_loaded = LoadTexture("assets//graphics/ghibli_art.png");
    game::Sprite sprite_from_data(50, 50, pre_loaded);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(sprite_from_file.texture_,
            sprite_from_file.pos_x_,
            sprite_from_file.pos_y_, WHITE);
        DrawTexture(sprite_from_data.texture_,
            sprite_from_data.pos_x_,
            sprite_from_data.pos_y_, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
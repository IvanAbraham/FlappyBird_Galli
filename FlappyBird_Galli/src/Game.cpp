#include "Game.h"
namespace Game
{
    void Game::Update(program::Screens& actualScreen)
    {
        static player::Player player;
        static obstacle::Obstacle obstacle[2];
        static float scrollingBack = 0.0f;
        static float scrollingMid = 0.0f;
        static float scrollingFore = 0.0f;

        player::Movement(player);

        obstacle::Movement(obstacle);

        if (col::rectToRect(player.position, player.size, obstacle[0].position, { 40,(float)program::screenHeight }) ||
            col::rectToRect(player.position, player.size, obstacle[1].position, { 40,(float)program::screenHeight }) ||
            player.position.y + player.size.y >= program::screenHeight)
        {
            player.position.y = 0;
            obstacle[0].position.x = 0 - 40;
            obstacle[1].position.x = 0 - 40;
        }
        if (IsKeyPressed(KEY_ESCAPE))
        {
            actualScreen = program::Screens::Menu;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangleV(player.position, player.size, BLACK);

        DrawRectangleV(obstacle[0].position, { 40,(float)program::screenHeight }, BLACK);
        DrawRectangleV(obstacle[1].position, { 40,(float)program::screenHeight }, BLACK);

        DrawText("0.3", 5, 5, 10, BLACK);

        EndDrawing();
    }
}
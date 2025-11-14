#include "Game.h"
namespace Game
{

    bool twoPlayers = false;
    bool gameOver = false;

    static void DrawBackGround(float& scrollingBack, float& scrollingMid, float& scrollingFore)
    { 
        DrawRectangleV({ scrollingBack,0 }, { program::screenWidth,program::screenHeight }, GRAY);
        DrawRectangleV({ scrollingMid,program::screenHeight * 0.3 }, { program::screenWidth,program::screenHeight }, DARKGRAY);
        DrawRectangleV({ scrollingFore,program::screenHeight * 0.5 }, { program::screenWidth,program::screenHeight }, RED);
    }

    void Game::Update(program::Screens& actualScreen)
    {
        static player::Player player;
        static player::Player player2;

        static obstacle::Obstacle obstacle[2];

        static float scrollingBack = 0.0f;
        static float scrollingMid = 0.0f;
        static float scrollingFore = 0.0f;

        scrollingBack -= 5.0f * GetFrameTime();
        scrollingMid -= 20.0f * GetFrameTime();
        scrollingFore -= 40.0f * GetFrameTime();

        if (scrollingBack <= -program::screenWidth)
        {
            scrollingBack = 0;
        }
        if (scrollingMid <= -program::screenWidth)
        {
            scrollingMid = 0;
        }
        if (scrollingFore <= -program::screenWidth)
        {
            scrollingFore = 0;
        }

        player::Movement(player);

        if (twoPlayers)
        {

            player::MovmentP2(player2);
       
        }

        obstacle::Movement(obstacle);

        if (twoPlayers)
        {

            if (col::rectToRect(player.position, player.size, obstacle[0].position, { 40,(float)program::screenHeight }) ||
                col::rectToRect(player.position, player.size, obstacle[1].position, { 40,(float)program::screenHeight }) ||
                player.position.y + player.size.y >= program::screenHeight)
            {
                
                player.isAlive = false;

            }

            if (col::rectToRect(player2.position, player2.size, obstacle[0].position, { 40,(float)program::screenHeight }) ||
                col::rectToRect(player2.position, player2.size, obstacle[1].position, { 40,(float)program::screenHeight }) ||
                player2.position.y + player2.size.y >= program::screenHeight)
            {

                player2.isAlive = false;

            }

        }

        else if (!twoPlayers && col::rectToRect(player.position, player.size, obstacle[0].position, { 40,(float)program::screenHeight }) ||
            col::rectToRect(player.position, player.size, obstacle[1].position, { 40,(float)program::screenHeight }) ||
            player.position.y + player.size.y >= program::screenHeight)
        {
            
            player.isAlive = false;

        }

        if (twoPlayers)
        {

            if (!player.isAlive && !player2.isAlive)
            {

                gameOver = true;

            }

        }

        else if (!twoPlayers && !player.isAlive)
        {

            gameOver = true;

        }

        if (gameOver)
        {

            player.position.y = 0;
            player2.position.y = 0;

            obstacle[0].position.x = 0 - 40;
            obstacle[1].position.x = 0 - 40;
            
            gameOver = false;
            player.isAlive = true;
            player2.isAlive = true;
            
            actualScreen = program::Screens::Menu;

        }
        
        if (IsKeyPressed(KEY_ESCAPE))
        {
            player.position.y = 0;
            player2.position.y = 0;

            obstacle[0].position.x = 0 - 40;
            obstacle[1].position.x = 0 - 40;

            gameOver = false;
            player.isAlive = true;
            player2.isAlive = true;

            actualScreen = program::Screens::Menu;
        }

        BeginDrawing();

        ClearBackground(WHITE);

        DrawBackGround(scrollingBack, scrollingMid, scrollingFore);

        DrawRectangleV(player.position, player.size, BLACK);

        if (twoPlayers)
        {

            DrawRectangleV(player2.position, player2.size, WHITE);
        
        }

        DrawRectangleV(obstacle[0].position, { 40,(float)program::screenHeight }, BLACK);
        DrawRectangleV(obstacle[1].position, { 40,(float)program::screenHeight }, BLACK);

        DrawText("0.3", 5, 5, 10, BLACK);

        EndDrawing();
    }
}
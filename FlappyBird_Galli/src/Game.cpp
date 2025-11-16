#include "Game.h"
namespace Game
{
    bool twoPlayers = false;
   

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

        static bool gameOver = false;
        static bool isPaused = false;

        static float scrollingBack = 0.0f;
        static float scrollingMid = 0.0f;
        static float scrollingFore = 0.0f;

        if (!gameOver && !isPaused)
        {


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

                    player.position.y = program::screenHeight * 2;

                }

                if (col::rectToRect(player2.position, player2.size, obstacle[0].position, { 40,(float)program::screenHeight }) ||
                    col::rectToRect(player2.position, player2.size, obstacle[1].position, { 40,(float)program::screenHeight }) ||
                    player2.position.y + player2.size.y >= program::screenHeight)
                {

                    player2.isAlive = false;

                    player2.position.y = program::screenHeight * 2;

                }

            }

            else if (!twoPlayers)
            {

                if (col::rectToRect(player.position, player.size, obstacle[0].position, { 40,(float)program::screenHeight }) ||
                    col::rectToRect(player.position, player.size, obstacle[1].position, { 40,(float)program::screenHeight }) ||
                    player.position.y + player.size.y >= program::screenHeight)
                {

                    player.isAlive = false;

                    player.position.y = program::screenHeight * 2;

                }
                   

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
      
            if (IsKeyPressed(KEY_ESCAPE))
            {
               
                isPaused = true;

            }
        
        }

        if (gameOver)
        {

            if (IsKeyPressed(KEY_R))
            {

                player.position.y = 0;
                player2.position.y = 0;

                obstacle[0].position.x = 0 - 40;
                obstacle[1].position.x = 0 - 40;

                gameOver = false;
                player.isAlive = true;
                player2.isAlive = true;

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

        }

        if (isPaused)
        {

            if (IsKeyPressed(KEY_SPACE))
            {

                isPaused = false;

            }

            else if (IsKeyPressed(KEY_R))
            {

                player.position.y = 0;
                player2.position.y = 0;

                obstacle[0].position.x = 0 - 40;
                obstacle[1].position.x = 0 - 40;

                gameOver = false;
                isPaused = false;
                player.isAlive = true;
                player2.isAlive = true;

            }

        }

        BeginDrawing();

        if (gameOver)
        {

            ClearBackground(LIGHTGRAY);

            program::Button gameOverTxt;

            gameOverTxt.text = "GAME OVER\n press R to retry.\n press ESC to go back to menu";
            gameOverTxt.textLength = static_cast<float>(MeasureText(gameOverTxt.text, static_cast<int>(gameOverTxt.fontSize)));

            DrawText(gameOverTxt.text, static_cast<int>(program::screenWidth * 0.5) - static_cast<int>(gameOverTxt.textLength / 2), static_cast<int>(program::screenHeight * 0.5), static_cast<int>(program::screenHeight * 0.05), RED);
        }

        if (isPaused)
        {

            ClearBackground(LIGHTGRAY);

            DrawText("PAUSED", static_cast<int>(program::screenWidth * 0.5), static_cast<int>(program::screenHeight * 0.5), static_cast<int>(program::screenHeight * 0.05), BLACK);

        }

        else if (!gameOver && !isPaused)
        {

            ClearBackground(WHITE);

            DrawBackGround(scrollingBack, scrollingMid, scrollingFore);

            DrawRectangleV(player.position, player.size, BLACK);

            if (twoPlayers)
            {

                DrawRectangleV(player2.position, player2.size, WHITE);

            }

            DrawRectangleV(obstacle[0].position, { obstacle->size.x, obstacle->size.y}, BLACK);
            DrawRectangleV(obstacle[1].position, { obstacle->size.x, obstacle->size.y}, BLACK);

        }

        EndDrawing();
    }
}
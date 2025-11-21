    #include "Game.h"
    namespace Game
    {
        bool twoPlayers = false;
        
        static const int maxBuildings = 4;
        static const int maxCities = 6;
        const float farSpeed = -20.0f;
        const float middleSpeed = -50.0f;
        const float closeSpeed = -100.0f;

        static float buildingPositions[maxBuildings];
        static float faarbuildPositions[maxBuildings + 2];
        static float cityPositions[maxCities];

        static bool positionsInitialized = false;

        static Texture2D player1Texture;
        static Texture2D player1TextureAlt;
        
        static Texture2D player2Texture;
        static Texture2D player2TextureAlt;
        
        static Texture2D backgroundTexture;
        static Texture2D pause;
        static Texture2D gOver;

        static Texture2D building;
        static Texture2D city;

        static bool texturesLoaded = false;

        static void LoadGameTextures()
        {
            player1Texture = LoadTexture("res/Textures/Players/P1player1.png");
            player1TextureAlt = LoadTexture("res/Textures/Players/P1player2.png");
        
            player2Texture = LoadTexture("res/Textures/Players/P2player1.png");
            player2TextureAlt = LoadTexture("res/Textures/Players/P2player2.png");

            backgroundTexture = LoadTexture("res/Textures/GameBGround/Background1.png");

            pause = LoadTexture("res/Textures/GOver&Pause/Pause1.png");
            gOver = LoadTexture("res/Textures/GOver&Pause/GameOver.png");

            building = LoadTexture("res/Textures/GameBGround/BgCloseBuild.png");
            city = LoadTexture("res/Textures/GameBGround/FarCity.png");

            texturesLoaded = true;
        }

        void UnloadGameTextures()
        {
            if (texturesLoaded)
            {
                UnloadTexture(player1Texture);
                UnloadTexture(player1TextureAlt);
                UnloadTexture(player2Texture);
                UnloadTexture(player2TextureAlt);
                UnloadTexture(backgroundTexture);
                UnloadTexture(pause);
                UnloadTexture(gOver);
                UnloadTexture(building);
                UnloadTexture(city);

                texturesLoaded = false;
            }
        }

        static void DrawBackGround()
        {
            Rectangle bGroundSource = { 0, 0, static_cast<float>(backgroundTexture.width), static_cast<float>(backgroundTexture.height) };
            Rectangle bGroundDest = { 0, 0, static_cast<float>(program::screenWidth), static_cast<float>(program::screenHeight) };
            Vector2 standardOrigin = { 0, 0 };

            DrawTexturePro(backgroundTexture, bGroundSource, bGroundDest, standardOrigin, 0.0f, WHITE);

            Rectangle citySource = { 0, 0, static_cast<float>(city.width), static_cast<float>(city.height) };
           
            float farParallY = program::screenHeight * 0.63f;
            
            float midParallY = program::screenHeight * 0.8f;


            for (int i = 0; i < maxCities; i++)
            {
                cityPositions[i] += farSpeed * GetFrameTime();

                if (cityPositions[i] + city.width < 0)
                {
                    cityPositions[i] = program::screenWidth;
                }

                Rectangle cityDest = { cityPositions[i], farParallY, static_cast<float>(city.width), static_cast<float>(city.height) };
                
                DrawTexturePro(city, citySource, cityDest, standardOrigin, 0.0f, WHITE);
            }

            Rectangle buildSource = { 0, 0, static_cast<float>(building.width), static_cast<float>(building.height) };

            for (int i = 0; i < maxBuildings; i++)
            {

                faarbuildPositions[i] += middleSpeed * GetFrameTime();

                if (faarbuildPositions[i] + building.width < 0)
                {
                    faarbuildPositions[i] = program::screenWidth;
                }

                Rectangle buildDest = { faarbuildPositions[i] * 4.0f,midParallY , static_cast<float>(building.width * 0.5f), static_cast<float>(building.height * 0.5f) };

                DrawTexturePro(building, buildSource, buildDest, standardOrigin, 0.0f, WHITE);

            }

            for (int i = 0; i < maxBuildings; i++)
            {
                
                buildingPositions[i] += closeSpeed * GetFrameTime();

                if (buildingPositions[i] + building.width < 0)
                {
                    buildingPositions[i] = program::screenWidth;
                }

                Rectangle buildDest = { buildingPositions[i] * 4.0f, static_cast<float>(program::screenHeight - building.height), static_cast<float>(building.width), static_cast<float>(building.height)};
                
                DrawTexturePro(building, buildSource, buildDest, standardOrigin, 0.0f, WHITE);
            }
        }

        static void InitBgPositions()
        {

            float buildScale = static_cast<float>(program::screenHeight) * 0.5f / building.height;
            float buildWidth = building.width * buildScale;

            for (int i = 0; i < maxBuildings; i++)
            {
                buildingPositions[i] = i * buildWidth;
            }

            float cityScale = static_cast<float>(program::screenHeight) * 0.3f / city.height;
            float cityWidth = city.width * cityScale;

            for (int i = 0; i < maxCities; i++)
            {
                cityPositions[i] = i * cityWidth;
            }

            positionsInitialized = true;
        }
        

        static void DrawPause()
        {
            Rectangle source = { 0, 0, static_cast<float>(pause.width), static_cast<float>(pause.height) };
            Rectangle dest = { 0, 0, static_cast<float>(program::screenWidth), static_cast<float>(program::screenHeight) };
            Vector2 origin = { 0, 0 };

            DrawTexturePro(pause, source, dest, origin, 0.0f, WHITE);
        }

        static void DrawGOver()
        {
            Rectangle source = { 0, 0, static_cast<float>(gOver.width), static_cast<float>(gOver.height) };
            Rectangle dest = { 0, 0, static_cast<float>(program::screenWidth), static_cast<float>(program::screenHeight) };
            Vector2 origin = { 0, 0 };

            DrawTexturePro(gOver, source, dest, origin, 0.0f, WHITE);
        }

        void Game::Update(program::Screens& actualScreen)
        {

            if (!texturesLoaded)
            {
                LoadGameTextures();
            }

            if (!positionsInitialized)
            {
                InitBgPositions();
            }

            static player::Player player;
            static player::Player player2;

            static obstacle::Obstacle obstacle[2];

            static bool gameOver = false;
            static bool isPaused = false;

            if (!gameOver && !isPaused)
            {

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
      
                if (IsKeyReleased(KEY_ESCAPE))
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

                    UnloadGameTextures();

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

                else if (IsKeyPressed(KEY_ESCAPE))
                {

                    player.position.y = 0;
                    player2.position.y = 0;

                    obstacle[0].position.x = 0 - 40;
                    obstacle[1].position.x = 0 - 40;

                    gameOver = false;
                    isPaused = false;
                    player.isAlive = true;
                    player2.isAlive = true;

                    UnloadGameTextures();

                    actualScreen = program::Screens::Menu;
                }

            }

            BeginDrawing();

            if (gameOver)
            {
                ClearBackground(LIGHTGRAY);

                program::Button gameOverTxt;

                DrawGOver();
            }

            if (isPaused)
            {
                ClearBackground(LIGHTGRAY);

                DrawPause();
            }

            else if (!gameOver && !isPaused)
            {
                ClearBackground(BLACK);
                DrawBackGround();

                Texture2D currentTexture1 = (player.acceleration < 0) ? player1TextureAlt : player1Texture;

                Rectangle source1 = { 0, 0, (float)currentTexture1.width, (float)currentTexture1.height };
                Rectangle dest1 = { player.position.x, player.position.y, player.size.x, player.size.y };
                Vector2 origin1 = { 0, 0 };

                DrawTexturePro(currentTexture1, source1, dest1, origin1, 0.0f, WHITE);

                if (twoPlayers)
                {
                    Texture2D currentTexture2 = (player2.acceleration < 0) ? player2TextureAlt : player2Texture;

                    Rectangle source2 = { 0, 0, static_cast<float>(currentTexture2.width), static_cast<float>(currentTexture2.height) };
                    Rectangle dest2 = { player2.position.x, player2.position.y, player2.size.x, player2.size.y };
                    Vector2 origin2 = { 0, 0 };

                    DrawTexturePro(currentTexture2, source2, dest2, origin2, 0.0f, WHITE);

                }

                DrawRectangleV(obstacle[0].position, { obstacle->size.x, obstacle->size.y }, BLACK);
                DrawRectangleV(obstacle[1].position, { obstacle->size.x, obstacle->size.y }, BLACK);
            }

        

            EndDrawing();
        }

    }
#include "raylib.h"
#include <array>

using namespace std;

// -----------------------------
// 설정
// -----------------------------
constexpr int SQUARE_SIZE = 20;
constexpr int GRID_HORIZONTAL_SIZE = 12;
constexpr int GRID_VERTICAL_SIZE = 20;

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 450;
constexpr int FALL_FRAMES = 18;

// -----------------------------
// 색상
// -----------------------------
const Color BG_COLOR = { 255, 255, 255, 255 };   // 흰색 배경
const Color WALL_COLOR = { 255, 228, 235, 255 };   // 연한 분홍 벽
const Color GRID_LINE = { 245, 235, 240, 255 };   // 아주 연한 격자선

// 블록 타입
enum class BlockType
{
    I, O, T, L, S
};

// 칸 상태
enum class GridSquare
{
    EMPTY,
    FULL,
    BLOCK
};

// 블록별 연한색(쌓인 뒤)
Color GetFixedColor(BlockType type)
{
    switch (type)
    {
    case BlockType::I: return { 190, 225, 255, 255 }; // 하늘
    case BlockType::O: return { 255, 245, 186, 255 }; // 노랑
    case BlockType::T: return { 220, 208, 255, 255 }; // 라벤더
    case BlockType::L: return { 255, 218, 185, 255 }; // 피치
    case BlockType::S: return { 189, 236, 220, 255 }; // 민트
    }
    return WHITE;
}

// 블록별 진한색(내려오는 중)
Color GetMovingColor(BlockType type)
{
    switch (type)
    {
    case BlockType::I: return { 120, 190, 245, 255 }; // 진한 하늘
    case BlockType::O: return { 245, 215, 90, 255 };  // 진한 노랑
    case BlockType::T: return { 170, 140, 235, 255 }; // 진한 보라
    case BlockType::L: return { 255, 170, 120, 255 }; // 진한 피치
    case BlockType::S: return { 120, 210, 170, 255 }; // 진한 민트
    }
    return WHITE;
}

// -----------------------------
// Tetromino
// -----------------------------
class Tetromino
{
public:
    array<array<int, 4>, 4> shape{};
    BlockType type = BlockType::O;

    void Clear()
    {
        for (auto& row : shape)
        {
            for (auto& cell : row)
            {
                cell = 0;
            }
        }
    }

    void GenerateRandom()
    {
        Clear();

        int r = GetRandomValue(0, 4);
        type = static_cast<BlockType>(r);

        switch (type)
        {
        case BlockType::O:
            shape[1][1] = 1; shape[2][1] = 1;
            shape[1][2] = 1; shape[2][2] = 1;
            break;

        case BlockType::I:
            shape[0][1] = 1; shape[1][1] = 1;
            shape[2][1] = 1; shape[3][1] = 1;
            break;

        case BlockType::T:
            shape[1][0] = 1;
            shape[0][1] = 1; shape[1][1] = 1; shape[2][1] = 1;
            break;

        case BlockType::L:
            shape[1][0] = 1;
            shape[1][1] = 1;
            shape[1][2] = 1; shape[2][2] = 1;
            break;

        case BlockType::S:
            shape[1][1] = 1; shape[2][1] = 1;
            shape[0][2] = 1; shape[1][2] = 1;
            break;
        }
    }

    void RotateClockwise()
    {
        array<array<int, 4>, 4> temp{};

        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                temp[x][y] = shape[x][y];
            }
        }

        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                shape[x][y] = temp[y][3 - x];
            }
        }
    }
};

// -----------------------------
// Game
// -----------------------------
class Game
{
private:
    GridSquare grid[GRID_HORIZONTAL_SIZE][GRID_VERTICAL_SIZE]{};
    Color colorGrid[GRID_HORIZONTAL_SIZE][GRID_VERTICAL_SIZE]{};

    Tetromino currentPiece;
    int posX = 4;
    int posY = 0;

    int frameCounter = 0;
    bool gameOver = false;

private:
    void InitWalls()
    {
        for (int x = 0; x < GRID_HORIZONTAL_SIZE; x++)
        {
            for (int y = 0; y < GRID_VERTICAL_SIZE; y++)
            {
                if (x == 0 || x == GRID_HORIZONTAL_SIZE - 1 || y == GRID_VERTICAL_SIZE - 1)
                {
                    grid[x][y] = GridSquare::BLOCK;
                }
                else
                {
                    grid[x][y] = GridSquare::EMPTY;
                }

                colorGrid[x][y] = BLANK;
            }
        }
    }

    bool CheckCollision(int nextX, int nextY, const Tetromino& piece) const
    {
        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                if (piece.shape[x][y] == 0) continue;

                int boardX = nextX + x;
                int boardY = nextY + y;

                if (boardX < 0 || boardX >= GRID_HORIZONTAL_SIZE ||
                    boardY < 0 || boardY >= GRID_VERTICAL_SIZE)
                {
                    return true;
                }

                if (grid[boardX][boardY] != GridSquare::EMPTY)
                {
                    return true;
                }
            }
        }

        return false;
    }

    void SpawnPiece()
    {
        currentPiece.GenerateRandom();
        posX = 4;
        posY = 0;

        if (CheckCollision(posX, posY, currentPiece))
        {
            gameOver = true;
        }
    }

    void FixPiece()
    {
        Color fixedColor = GetFixedColor(currentPiece.type);

        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                if (currentPiece.shape[x][y] == 1)
                {
                    int gx = posX + x;
                    int gy = posY + y;

                    grid[gx][gy] = GridSquare::FULL;
                    colorGrid[gx][gy] = fixedColor;
                }
            }
        }
    }

    void ClearLines()
    {
        for (int y = GRID_VERTICAL_SIZE - 2; y >= 0; y--)
        {
            bool fullLine = true;

            for (int x = 1; x < GRID_HORIZONTAL_SIZE - 1; x++)
            {
                if (grid[x][y] != GridSquare::FULL)
                {
                    fullLine = false;
                    break;
                }
            }

            if (fullLine)
            {
                for (int pullY = y; pullY > 0; pullY--)
                {
                    for (int x = 1; x < GRID_HORIZONTAL_SIZE - 1; x++)
                    {
                        grid[x][pullY] = grid[x][pullY - 1];
                        colorGrid[x][pullY] = colorGrid[x][pullY - 1];
                    }
                }

                for (int x = 1; x < GRID_HORIZONTAL_SIZE - 1; x++)
                {
                    grid[x][0] = GridSquare::EMPTY;
                    colorGrid[x][0] = BLANK;
                }

                y++;
            }
        }
    }

public:
    Game()
    {
        Init();
    }

    void Init()
    {
        InitWalls();
        frameCounter = 0;
        gameOver = false;
        SpawnPiece();
    }

    void Update()
    {
        if (gameOver)
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                Init();
            }
            return;
        }

        if (IsKeyPressed(KEY_LEFT) && !CheckCollision(posX - 1, posY, currentPiece))
        {
            posX--;
        }

        if (IsKeyPressed(KEY_RIGHT) && !CheckCollision(posX + 1, posY, currentPiece))
        {
            posX++;
        }

        if (IsKeyPressed(KEY_UP))
        {
            Tetromino rotated = currentPiece;
            rotated.RotateClockwise();

            if (!CheckCollision(posX, posY, rotated))
            {
                currentPiece = rotated;
            }
        }

        bool fastDrop = IsKeyDown(KEY_DOWN);
        frameCounter++;

        int targetFrames = fastDrop ? 3 : FALL_FRAMES;

        if (frameCounter >= targetFrames)
        {
            frameCounter = 0;

            if (!CheckCollision(posX, posY + 1, currentPiece))
            {
                posY++;
            }
            else
            {
                FixPiece();
                ClearLines();
                SpawnPiece();
            }
        }
    }

    void Draw()
    {
        BeginDrawing();
        ClearBackground(BG_COLOR);

        int offsetX = 220;
        int offsetY = 30;

        for (int x = 0; x < GRID_HORIZONTAL_SIZE; x++)
        {
            for (int y = 0; y < GRID_VERTICAL_SIZE; y++)
            {
                int drawX = offsetX + x * SQUARE_SIZE;
                int drawY = offsetY + y * SQUARE_SIZE;

                if (grid[x][y] == GridSquare::EMPTY)
                {
                    DrawRectangleLines(drawX, drawY, SQUARE_SIZE, SQUARE_SIZE, GRID_LINE);
                }
                else if (grid[x][y] == GridSquare::BLOCK)
                {
                    DrawRectangle(drawX, drawY, SQUARE_SIZE, SQUARE_SIZE, WALL_COLOR);
                }
                else if (grid[x][y] == GridSquare::FULL)
                {
                    DrawRectangle(drawX, drawY, SQUARE_SIZE, SQUARE_SIZE, colorGrid[x][y]);
                    DrawRectangleLines(drawX, drawY, SQUARE_SIZE, SQUARE_SIZE, WHITE);
                }
            }
        }

        Color movingColor = GetMovingColor(currentPiece.type);

        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                if (currentPiece.shape[x][y] == 1)
                {
                    int drawX = offsetX + (posX + x) * SQUARE_SIZE;
                    int drawY = offsetY + (posY + y) * SQUARE_SIZE;

                    DrawRectangle(drawX, drawY, SQUARE_SIZE, SQUARE_SIZE, movingColor);
                    DrawRectangleLines(drawX, drawY, SQUARE_SIZE, SQUARE_SIZE, WHITE);
                }
            }
        }

        DrawText("SPRING TETRIS", 480, 80, 24, { 210, 130, 170, 255 });
        DrawText("LEFT / RIGHT : MOVE", 480, 130, 18, { 170, 150, 170, 255 });
        DrawText("UP : ROTATE", 480, 160, 18, { 170, 150, 170, 255 });
        DrawText("DOWN : FAST DROP", 480, 190, 18, { 170, 150, 170, 255 });

        if (gameOver)
        {
            DrawText("GAME OVER", 470, 260, 28, { 220, 100, 140, 255 });
            DrawText("PRESS ENTER TO RESTART", 430, 300, 20, { 180, 140, 160, 255 });
        }

        EndDrawing();
    }
};

// -----------------------------
// main
// -----------------------------
int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Spring Tetris");
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose())
    {
        game.Update();
        game.Draw();
    }

    CloseWindow();
    return 0;
}

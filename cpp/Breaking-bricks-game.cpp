#include <SDL.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// 전역 상수
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int PADDLE_WIDTH = 100;
const int PADDLE_HEIGHT = 20;
const int BALL_SIZE = 15;
const int BRICK_WIDTH = 60;
const int BRICK_HEIGHT = 30;
const int NUM_LEVELS = 3;
const int MAX_LIVES = 3;

// 공 구조체 정의
struct Ball {
    SDL_Rect rect;
    int velX;
    int velY;
};

// 전역 변수
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Rect paddle;
std::vector<Ball> balls;
std::vector<SDL_Rect> bricks;
std::vector<bool> bricksVisible;
std::vector<SDL_Color> brickColors;
std::vector<SDL_Rect> items;
std::vector<int> itemTypes;
bool keys[SDL_NUM_SCANCODES] = { false };
int level = 0;
int lives = MAX_LIVES;
bool enlargePaddle = false;
bool slowBall = false;
int itemEffectTime = 0;
SDL_Color paddleColor = { 255, 255, 255, 255 };  // 초기 패들 색상
SDL_Color bgColor = { 0, 0, 0, 255 };  // 초기 배경 색상

// 함수 선언
bool init();
void close();
void createBricks(int level);
void addBall();
void moveBalls();
void moveItems();
void render();
bool checkCollision(SDL_Rect a, SDL_Rect b);

int main(int argc, char* args[]) {
    srand(static_cast<unsigned>(time(0)));

    if (!init()) {
        printf("초기화 실패!\n");
        return -1;
    }

    bool quit = false;
    SDL_Event e;

    paddle = { SCREEN_WIDTH / 2 - PADDLE_WIDTH / 2, SCREEN_HEIGHT - 40, PADDLE_WIDTH, PADDLE_HEIGHT };
    addBall();
    createBricks(level);

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN) {
                keys[e.key.keysym.scancode] = true;
            }
            else if (e.type == SDL_KEYUP) {
                keys[e.key.keysym.scancode] = false;
            }
        }

        if (keys[SDL_SCANCODE_LEFT]) {
            paddle.x -= 5;
            if (paddle.x < 0) paddle.x = 0;
        }
        if (keys[SDL_SCANCODE_RIGHT]) {
            paddle.x += 5;
            if (paddle.x > SCREEN_WIDTH - paddle.w) paddle.x = SCREEN_WIDTH - paddle.w;
        }

        moveBalls();
        moveItems();
        render();
        SDL_Delay(16);

        // 레벨 완료 검사
        if (std::all_of(bricksVisible.begin(), bricksVisible.end(), [](bool v) { return !v; })) {
            level = (level + 1) % NUM_LEVELS;
            createBricks(level);
            addBall();
        }
    }

    close();
    return 0;
}

bool init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL 초기화 실패! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("창의적인 벽돌깨기 게임", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("창 생성 실패! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("렌더러 생성 실패! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    return true;
}

void close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;

    SDL_Quit();
}

void createBricks(int level) {
    bricks.clear();
    bricksVisible.clear();
    brickColors.clear();

    // 레벨에 따라 벽돌 모양을 설정합니다.
    std::vector<std::vector<int>> levelShapes = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
         1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
         1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Level 1 (simple block)
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
         1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
         1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         0, 1, 1, 1, 1, 1, 1, 1, 1, 0}, // Level 2 (diamond)
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
         0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
         1, 1, 1, 0, 0, 0, 0, 1, 1, 1,
         0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
         0, 0, 1, 1, 1, 1, 1, 1, 0, 0}  // Level 3 (하트)
    };

    std::vector<int> shape = levelShapes[level];
    for (int i = 0; i < shape.size(); ++i) {
        if (shape[i] == 1) {
            int row = i / 10;
            int col = i % 10;
            SDL_Rect brick = { col * BRICK_WIDTH, row * BRICK_HEIGHT, BRICK_WIDTH - 2, BRICK_HEIGHT - 2 };
            bricks.push_back(brick);
            bricksVisible.push_back(true);

            SDL_Color color = { static_cast<Uint8>(rand() % 256), static_cast<Uint8>(rand() % 256), static_cast<Uint8>(rand() % 256), 255 };
            brickColors.push_back(color);
        }
    }

    // 레벨에 따른 배경 색상 설정
    SDL_Color levelColors[NUM_LEVELS] = {
        {0, 0, 0, 255}, // 레벨 1: 검은색
        {50, 50, 50, 255}, // 레벨 2: 회색
        {100, 100, 100, 255} // 레벨 3: 밝은 회색
    };
    bgColor = levelColors[level];
}

void addBall() {
    Ball newBall = { {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, BALL_SIZE, BALL_SIZE}, -3, -3 };
    balls.push_back(newBall);
}

void moveBalls() {
    for (size_t i = 0; i < balls.size(); ++i) {
        balls[i].rect.x += balls[i].velX;
        balls[i].rect.y += balls[i].velY;

        if (balls[i].rect.x <= 0 || balls[i].rect.x >= SCREEN_WIDTH - BALL_SIZE) {
            balls[i].velX = -balls[i].velX;
        }

        if (balls[i].rect.y <= 0) {
            balls[i].velY = -balls[i].velY;
        }

        if (balls[i].rect.y >= SCREEN_HEIGHT) {
            // 공이 바닥에 닿으면 목숨이 줄어들고 공을 삭제합니다.
            lives--;
            if (lives == 0) {
                printf("게임 오버!\n");
                close();
                exit(0);
            }
            balls.erase(balls.begin() + i);
            addBall(); // 새로운 공을 추가
        }

        if (checkCollision(balls[i].rect, paddle)) {
            balls[i].velY = -balls[i].velY;

            // 패들 색상 변경
            paddleColor.r = static_cast<Uint8>(rand() % 256);
            paddleColor.g = static_cast<Uint8>(rand() % 256);
            paddleColor.b = static_cast<Uint8>(rand() % 256);

            if (enlargePaddle) {
                paddle.w = PADDLE_WIDTH * 1.5;
            }
            else {
                paddle.w = PADDLE_WIDTH;
            }
            if (slowBall) {
                balls[i].velX = balls[i].velX < 0 ? -2 : 2;
                balls[i].velY = balls[i].velY < 0 ? -2 : 2;
            }
            else {
                balls[i].velX = balls[i].velX < 0 ? -3 : 3;
                balls[i].velY = balls[i].velY < 0 ? -3 : 3;
            }
        }

        for (size_t j = 0; j < bricks.size(); ++j) {
            if (bricksVisible[j] && checkCollision(balls[i].rect, bricks[j])) {
                balls[i].velY = -balls[i].velY;
                bricksVisible[j] = false;

                if (rand() % 2 == 0) {
                    SDL_Rect item = { bricks[j].x + bricks[j].w / 2 - 10, bricks[j].y + bricks[j].h / 2 - 10, 20, 20 };
                    items.push_back(item);
                    itemTypes.push_back(rand() % 2); // 0: enlarge paddle, 1: slow ball
                }
            }
        }

        if (itemEffectTime > 0) {
            --itemEffectTime;
            if (itemEffectTime == 0) {
                enlargePaddle = false;
                slowBall = false;
                paddle.w = PADDLE_WIDTH;
                balls[i].velX = balls[i].velX < 0 ? -3 : 3;
                balls[i].velY = balls[i].velY < 0 ? -3 : 3;
            }
        }
    }
}

void moveItems() {
    for (size_t i = 0; i < items.size(); ) {
        items[i].y += 3;
        if (checkCollision(items[i], paddle)) {
            if (itemTypes[i] == 0) {
                enlargePaddle = true;
                itemEffectTime = 300;
            }
            else if (itemTypes[i] == 1) {
                slowBall = true;
                itemEffectTime = 300;
            }
            items.erase(items.begin() + i);
            itemTypes.erase(itemTypes.begin() + i);
        }
        else if (items[i].y > SCREEN_HEIGHT) {
            items.erase(items.begin() + i);
            itemTypes.erase(itemTypes.begin() + i);
        }
        else {
            ++i;
        }
    }
}

void render() {
    SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, paddleColor.r, paddleColor.g, paddleColor.b, 255);
    SDL_RenderFillRect(renderer, &paddle);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (size_t i = 0; i < balls.size(); ++i) {
        SDL_RenderFillRect(renderer, &balls[i].rect);
    }

    for (size_t i = 0; i < bricks.size(); ++i) {
        if (bricksVisible[i]) {
            SDL_SetRenderDrawColor(renderer, brickColors[i].r, brickColors[i].g, brickColors[i].b, 255);
            SDL_RenderFillRect(renderer, &bricks[i]);
        }
    }

    for (size_t i = 0; i < items.size(); ++i) {
        if (itemTypes[i] == 0) {
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        }
        else if (itemTypes[i] == 1) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        }
        SDL_RenderFillRect(renderer, &items[i]);
    }

    // 목숨 표시
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i < lives; ++i) {
        SDL_Rect lifeRect = { 10 + i * 20, 10, 15, 15 };
        SDL_RenderFillRect(renderer, &lifeRect);
    }

    SDL_RenderPresent(renderer);
}

bool checkCollision(SDL_Rect a, SDL_Rect b) {
    if (a.x + a.w <= b.x || a.x >= b.x + b.w || a.y + a.h <= b.y || a.y >= b.y + b.h) {
        return false;
    }
    return true;
}

# 창의적인 벽돌깨기 게임

#### 이 게임은 C++와 SDL라이브러리를 이용한 벽돌깨기 게임입니다. 이 게임이 다른 벽돌깨기 게임과 달리 여러 요소들이 추가되어 있습니다. 대표적인 예시로 레벨, 목숨, 레벨에 따른 공의 수, 패들의 색 변경, 벽돌의 색, 아이템 등이 있습니다. 
---------------------------------------



## 헤더 파일
:게임 화면의 크기, 패들 크기, 공 크기, 벽돌 크기, 레벨 수, 최대 목숨 수를 정의합니다.

- SDL.h: SDL 라이브러리를 사용하기 위해 포함.
- stdio.h: 표준 입출력 함수 사용을 위해 포함.
- vector: 벡터 사용을 위해 포함.
- cstdlib: 랜덤 함수와 srand를 사용하기 위해 포함.
- ctime: 시간 관련 함수 사용을 위해 포함.
- algorithm: 알고리즘 함수 사용을 위해 포함.


## 전역 상수
:SDL 창과 렌더러를 위한 변수, 패들과 공의 위치와 크기를 저장하는 SDL_Rect 구조체, 공의 속도, 벽돌과 관련된 벡터, 키 입력 상태를 추적하는 배열, 현재 레벨과 목숨 수, 파워업 상태를 나타내는 부울 변수, 패들 색상과 배경 색상

- `SCREEN_WIDTH`, `SCREEN_HEIGHT`: 게임 화면의 너비와 높이입니다.
- `PADDLE_WIDTH`, `PADDLE_HEIGHT`: 패들의 너비와 높이입니다.
- `BALL_SIZE`: 공의 크기입니다.
- `BRICK_WIDTH`, `BRICK_HEIGHT`: 벽돌의 너비와 높이입니다.
- `NUM_LEVELS`: 게임의 레벨 수입니다.
- `MAX_LIVES`: 플레이어의 최대 목숨 수입니다.


## 전역 변수

- SDL_Window* window, SDL_Renderer* renderer: SDL 윈도우와 렌더러
- SDL_Rect paddle: 패들의 위치와 크기
- std::vector<Ball> balls: 공의 목록
- std::vector<SDL_Rect> bricks: 벽돌의 목록
- std::vector<bool> bricksVisible: 벽돌의 가시성 목록
- std::vector<SDL_Color> brickColors: 벽돌의 색상 목록
- std::vector<SDL_Rect> items: 아이템의 목록
- std::vector<int> itemTypes: 아이템의 종류
- bool keys[SDL_NUM_SCANCODES]: 키보드 입력 상태를 저장하는 배열
- int level: 현재 레벨
- int lives: 남은 목숨 수
- bool enlargePaddle, bool slowBall: 아이템 효과 여부
- int itemEffectTime: 아이템 효과 지속 시간
- SDL_Color paddleColor: 패들의 색상
- SDL_Color bgColor: 배경 색상


## 사용 함수
- <init() 함수>
  - SDL 초기화 및 창과 렌더러 생성. 실패 시 오류 메시지를 출력하고 false를 반환.
- <close() 함수>
  - SDL 렌더러와 창을 파괴하고 SDL을 종료.
- <createBricks() 함수>
  - 주어진 레벨에 따라 벽돌을 생성합니다. 벽돌 배열과 색상, 배경 색상을 설정합니다.
- <moveBall() 함수>
  - 공의 위치를 업데이트하고 벽, 패들, 벽돌과의 충돌을 처리합니다. 아이템을 생성하고 파워업 상태를 관리합니다.
- <moveItems() 함수>
  - 아이템을 아래로 움직이고 패들과의 충돌을 체크합니다. 충돌 시 파워업을 적용하고 화면 밖으로 나간 아이템은 제거합니다.
- <render() 함수>
  - 화면을 렌더링합니다. 배경, 패들, 공, 벽돌, 아이템, 목숨을 그립니다.
- <checkCollision() 함수>
  - 두 SDL_Rect 객체가 충돌하는지 체크합니다.
- <메인 함수>
  - DL 초기화, 창과 렌더러 생성
  - 패들, 공, 벽돌 초기화
  - 게임 루프: 이벤트 처리, 키보드 입력 처리, 공과 아이템 이동 화면 렌더링
  - 게임 종료 시 자원 해제

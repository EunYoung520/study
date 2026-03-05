#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 20
#define MAX_TRIES 3

int main() {
    char *fruits[] = {"apple", "pear", "banana", "orange", "kiwi", "grape", "strawberry"};
    int num_fruits = sizeof(fruits) / sizeof(fruits[0]);
    int num, len, tries = 0;
    char guess[MAX_LEN];
    srand(time(NULL));  // 시드값 설정

    // 랜덤하게 과일 선택
    num = rand() % num_fruits;
    printf("7개의 과일(apple, pear, banana, orange, kiwi, grape, strawberry) 중 하나를 선택하였습니다. 알파벳을 하나씩 맞춰보세요!\n");
    len = strlen(fruits[num]);

    // 숨겨진 단어 배열
    char revealed[MAX_LEN];
    memset(revealed, ' ', len);
    revealed[len] = '\0';

    while (1) {
        // 틀린 횟수가 일정 횟수 이상일 때 '*' 표시
        if (tries >= MAX_TRIES) {
            printf("모든 기회를 사용하였습니다.\n", len);
            printf("정답: %s\n", fruits[num]);
            printf("다시 도전하시겠습니까? (y/n): ");
            char choice;
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                tries = 0;
                num = rand() % num_fruits;
                len = strlen(fruits[num]);
                memset(revealed, '*', len);
                revealed[len] = '\0';
                continue;
            } else {
                printf("게임을 종료합니다.\n");
                break;
            }
        }

        printf("과일: %s\n", revealed);
        printf("남은 기회: %d\n", MAX_TRIES - tries);
        printf("과일의 알파벳을 입력하세요: ");
        scanf(" %c", &guess[0]);

        // 입력한 알파벳이 정답 과일에 있는지 확인
        int found = 0;
        for (int i = 0; i < len; i++) {
            if (fruits[num][i] == guess[0]) {
                revealed[i] = guess[0];
                found = 1;
            }
        }

        // 틀렸을 경우
        if (!found) {
            printf("틀렸습니다. 다시 시도해보세요.\n");
            tries++;
        }

        // 모든 알파벳을 맞히면 정답 출력
        if (strcmp(revealed, fruits[num]) == 0) {
            printf("축하합니다! 정답입니다.: %s\n", fruits[num]);
            break;
        }
    }
    return 0;
}
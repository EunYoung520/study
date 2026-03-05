#include <stdio.h>

typedef struct {
  char name[100];
  char student_id[20];
  int score1;
  int score2;
} Student;

int main() {
  FILE *fp = fopen("sj.txt", "w");
  if (fp == NULL) {
    printf("파일이 없습니다\n");
    return 1;
  }

  Student students[3];

  for (int i = 0; i < 3; i++) {
    printf("학생 %d의 이름: ", i + 1);
    scanf("%s", students[i].name);
    printf("학생 %d의 학번: ", i + 1);
    scanf("%s", students[i].student_id);
    printf("학생 %d의 첫 번째 과목 점수: ", i + 1);
    scanf("%d", &students[i].score1);
    printf("학생 %d의 두 번째 과목 점수: ", i + 1);
    scanf("%d", &students[i].score2);
    fprintf(fp, "%s %s %d %d\n", students[i].name, students[i].student_id,
            students[i].score1, students[i].score2);
  }

  fclose(fp);
  printf("정보를 저장했습니다.\n");
  return 0;
}
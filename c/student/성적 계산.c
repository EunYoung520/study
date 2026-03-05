#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[50];
  char student_id[20];
  int score1;
  int score2;
} Student;

int main() {
  FILE *file;
  Student students[3];
  int count = 0;
  double sum_score1 = 0, sum_score2 = 0;

  file = fopen("sj.txt", "r");
  if (file == NULL) {
    perror("파일을 열 수 없습니다.");
    return EXIT_FAILURE;
  }

  while (fscanf(file, "%s %s %d %d", students[count].name,
                students[count].student_id, &students[count].score1,
                &students[count].score2) != EOF) {
    sum_score1 += students[count].score1;
    sum_score2 += students[count].score2;
    count++;
  }
  fclose(file);

  double avg_score1 = sum_score1 / count;
  double avg_score2 = sum_score2 / count;

  printf("학생별 평균:\n");
  for (int i = 0; i < count; i++) {
    double avg = (students[i].score1 + students[i].score2) / 2.0;
    printf("%s (%s): 평균 = %.2f\n", students[i].name, students[i].student_id,
           avg);
  }

  printf("\n과목 1 평균: %.2f\n", avg_score1);
  printf("과목 2 평균: %.2f\n", avg_score2);
}
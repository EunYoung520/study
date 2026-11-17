# 빅데이터분석입문 · 과제 2

도서 대출 기록을 Pandas로 정리하고, NumPy를 이용해 간단한 신경망 순전파를 계산한 수업 과제입니다.

## 실습 내용

1. CSV의 첫 5행, 전체 행 수, 열별 결측값과 중복 행 수 확인
2. 완전히 중복된 행 제거 및 빈 `분류`를 `미분류`로 대체
3. `반납상태` 또는 `예정일_경과일`이 누락된 기록 확인
4. 미반납이면서 예정일을 1일 이상 지난 대출 기록을 경과일 내림차순으로 정리하고 `overdue_loans.csv`로 저장
5. 월·화·수 대출 건수 `[12, 15, 9]`와 주어진 가중치를 이용해 은닉층 시그모이드 및 출력층 항등함수 계산

## 파일

- [bigdata_intro_assignment_02.py](./bigdata_intro_assignment_02.py): 노트북의 풀이를 실행 가능한 Python 스크립트로 정리한 파일

## 실행

```bash
pip install pandas numpy
python bigdata_intro_assignment_02.py
```


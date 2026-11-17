"""빅데이터분석입문 과제 2: 도서 대출 데이터 정리 및 순전파 실습.

필요 파일: library_loans.csv (실행 디렉터리에 위치)
필요 패키지: pandas, numpy
"""

import pandas as pd
import numpy as np


# 1. 원본 데이터 점검
loans = pd.read_csv("library_loans.csv", encoding="utf-8")
print(loans.head(5))
print(f"원본 행: {len(loans)}")
print("열별 결측값 수")
print(loans.isna().sum())
print(f"중복 행 수: {loans.duplicated().sum()}")


# 2. 중복 행 제거 및 분류 결측값 채우기
copy_loans = loans.drop_duplicates().copy()
copy_loans["분류"] = copy_loans["분류"].fillna("미분류")

print(f"정리 전 행 수: {len(loans)}")
print(f"정리 후 행 수: {len(copy_loans)}")


# 3. 확인이 필요한 기록 추출
check = copy_loans[
    copy_loans["반납상태"].isna() | copy_loans["예정일_경과일"].isna()
]
print(check)
print(f"확인 필요 건수: {len(check)}")


# 4. 반납 안내 명단 생성
# 미반납이면서 예정일을 1일 이상 경과한 기록만 포함합니다.
over = copy_loans[
    (copy_loans["반납상태"] == "미반납")
    & (copy_loans["예정일_경과일"] >= 1)
]
over = over[["대출ID", "도서명", "예정일_경과일"]].sort_values(
    "예정일_경과일", ascending=False
)
print(over)
print(f"반납 안내 대상 건수: {len(over)}")
over.to_csv("overdue_loans.csv", index=False, encoding="utf-8-sig")
# 예정일_경과일이 0인 미반납 기록은 반납 안내 명단에 포함되지 않습니다.


# 5. 신경망 순전파로 목요일 대출 건수 예측
X = np.array([12, 15, 9])
W1 = np.array([[0.05, 0], [0.05, 0.05], [0, 0.05]])
z = X @ W1 + 0
hidden = 1 / (1 + np.exp(-z))
out = (hidden[0] * 6 + hidden[1] * 4) + 5  # 항등함수

print(f"시그모이드 적용 전 값: {z}")
print(f"시그모이드 적용 후 값: {hidden}")
print(f"목요일 예상 대출 건수: {out:.1f}")

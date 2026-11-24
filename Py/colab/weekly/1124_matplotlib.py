# 2026-11-24 | Matplotlib 데이터 시각화
# 설치: python -m pip install matplotlib

import matplotlib.pyplot as plt

plt.rcParams["font.sans-serif"]=["Malgun Gothic"]
plt.rcParams["axes.unicode_minus"]=False

# 1. 기본 선 그래프
x=[1, 2, 3, 4]
y=[10, 15, 12, 20]

plt.figure()
plt.plot(x, y, marker="o")
plt.show()

# 2. 제목 및 축 이름 설정
plt.figure()
plt.plot(x, y, marker="o")
plt.title("월별 매출")
plt.xlabel("월")
plt.ylabel("매출(만 원)")
plt.show()

# 3. 눈금, 범례 및 격자 설정
plt.figure()
plt.plot(x, y, marker="o", label="매출")
plt.title("월별 매출")
plt.xlabel("월")
plt.ylabel("매출(만 원)")
plt.xticks(x)
plt.ylim(0, 25)
plt.yticks([0, 5, 10, 15, 20, 25])
plt.legend()
plt.grid(axis="y", alpha=0.3)
plt.show()

# 4. 두 매장의 매출 비교
month=[1, 2, 3, 4, 5, 6]
store_a=[120, 150, 135, 180, 210, 195]
store_b=[100, 125, 145, 160, 190, 205]

plt.figure()
plt.plot(month, store_a, color="navy", linestyle="-", marker="o", label="A 매장")
plt.plot(month, store_b, color="orange", linestyle="--", marker="s", label="B 매장")
plt.xlabel("월")
plt.ylabel("매출(만 원)")
plt.xticks(month)
plt.legend()
plt.grid(axis="y", alpha=0.3)
plt.show()

# 5. 막대그래프
products=["A", "B", "C", "D"]
sales=[35, 50, 28, 42]

plt.figure()
plt.bar(products, sales, color="steelblue", width=0.6)
plt.title("상품별 판매량")
plt.xlabel("상품")
plt.ylabel("매출(만 원)")
plt.ylim(bottom=0)
plt.show()

# 6. 히스토그램
scores=[
    42, 48, 56, 45, 65,
    58, 47, 68, 97, 56,
    69, 98, 87, 66, 57,
    45, 76, 86, 47, 86
]

plt.figure()
plt.hist(
    scores,
    bins=[40, 50, 60, 70, 80, 90, 100],
    edgecolor="black",
    color="skyblue"
)
plt.xlabel("점수")
plt.ylabel("빈도(명)")
plt.title("점수 분포")
plt.show()

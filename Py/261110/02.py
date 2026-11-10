summary=df.groupby("업종")["결제금액"].agg(총결제금액="sum", 결제건수="size", 건당평균="mean")
display(summary.round(2))

print("건수 1위:", summary["결제건수"].idxmax())
print("총액 1위:", summary["총결제금액"].idxmax())

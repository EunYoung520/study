by_date=df.groupby("결제일")["결제금액"].sum()
calendar=pd.date_range("2026-08-01", "2026-10-31")
daily=by_date.reindex(calendar, fill_value=0)
weekday_mean=daily.groupby(daily.index.day_of_week).mean()
weekday_mean.index=["월", "화", "수", "목", "금", "토", "일"]
display(weekday_mean.round(0))

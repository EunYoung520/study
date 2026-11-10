show_chart([("일별 총액", daily)], "일별 소비 추이", "원", [(0,"8/1"), (31,"9/1"), (61, "10/1"), (91, "10/31")])
show_chart([("요일별 평균", weekday_mean)],"요일별 하루 평균", "원", list(enumerate(weekday_mean.index)),
           bars=True)

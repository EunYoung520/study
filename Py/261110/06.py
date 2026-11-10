date=pd.DataFrame({"3일전": daily.shift(3),
                   "2일전": daily.shift(2),
                   "1일전": daily.shift(1),
                   "정답": daily
                   }).dropna()/10_000

X=date[["3일전", "2일전", "1일전"]].to_numpy()
Y=date[["정답"]].to_numpy()
X_train, X_test=X[:71], X[71:]
Y_train, Y_test=Y[:71], Y[71:]

display(date.head(3))
print("학습:", len(X_train), "평가:", len(X_test))

from calendar import calendar
from multiprocessing.reduction import duplicate
from sys import displayhook

import numpy as np
import pandas as pd

from jinja2.utils import missing

df = pd.read_csv("9.card_spending_practice.csv", encoding="utf-8", parse_dates=["결제일"])
display(df.head(2))
missing_counts=df.isna().sum()
display(missing_counts)

duplicate_ids=df["거래ID"].duplicated()
print(f"거래 ID 중복 건수: {len(duplicate_ids)}건")

if duplicate_ids.any():
    display(df.loc[duplicate_ids])

df["가맹점"]=df["가맹점"].fillna("미기재")

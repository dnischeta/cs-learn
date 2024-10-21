from datetime import date

def list_years(l):
    ls = sorted(l)
    for idx, d in enumerate(ls):
        ls[idx] = d.year
    return ls

date1 = date(2019, 2, 3)
date2 = date(2006, 10, 10)
date3 = date(1993, 5, 9)

years = list_years([date1, date2, date3])
print(years)

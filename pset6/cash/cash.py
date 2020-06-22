from cs50 import get_float

num = 0

while True:
    n=get_float("Change owed: ")
    if n > 0:
        while n >= 0.25:
            num += 1
            n = round(n-0.25, 2)
        while n >= 0.10:
            num += 1
            n = round(n-0.10, 2)
        while n >= 0.05:
            num += 1
            n = round(n-0.05, 2)
        while n >= 0.01:
            num += 1
            n = round(n-0.01, 2)
        print(num)
        break
a, b = 0, 1
for i in range(2, 1000000):
    a, b = b, a + b
    if len(str(b)) == 1000:
        print(i)
        break

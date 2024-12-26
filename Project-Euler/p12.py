import sympy
import math

D = 500
for i in range(1, 100000000):
    n = i * (i + 1) // 2
    if len(sympy.divisors(n)) > 500:
        print(n)
        break

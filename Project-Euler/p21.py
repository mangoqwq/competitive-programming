import sympy

def d(n):
    return sum(sympy.divisors(n)) - n

def amicable(a):
    return d(a) != a and d(d(a)) == a

nums = filter(amicable, range(1, 10001))
print(sum(nums))

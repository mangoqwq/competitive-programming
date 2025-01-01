import sympy

nums = range(1, 30000)
abundant = set(filter(lambda n: sympy.divisor_sigma(n, 1) > 2 * n, nums))
sums = set([x + y for x in abundant for y in abundant])
cannot = set(nums).difference(sums)
print(sum(cannot))

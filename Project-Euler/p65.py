N = 100
a = [2, 1, 2]
for i in range(0, N):
	a += [1, 1, 2*i + 4]

num = a[N-1]
denom = 1
for i in range(N-2, -1, -1):
	denom, num = num, denom
	num += denom * a[i]

print(num, denom, num/denom)
ans = sum(map(lambda d: ord(d) - ord("0"), str(num)))
print(ans)

ans = 0
num, denom = 3, 2
for it in range(1000):
	if len(str(num)) > len(str(denom)):
		ans += 1
	num, denom = num + 2 * denom, num + denom
print(ans)

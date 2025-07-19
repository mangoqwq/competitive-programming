ans = 0
for b in range(1, 10):
	for e in range(0, 100):
		if len(str(b**e)) == e:
			ans += 1
print(ans)

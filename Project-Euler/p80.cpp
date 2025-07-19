import decimal

decimal.getcontext().prec = 1000

ans = 0
for n in range(1, 101):
	s = str(decimal.Decimal(n).sqrt())
	if not '.' in s:
		continue
	s = s.replace('.', '')
	ans += sum(map(int, list(s[:100])))
print(ans)

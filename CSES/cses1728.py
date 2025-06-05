from decimal import Decimal

N = int(input())
a = list(map(int, input().split()))

prod = 1
for x in a:
	prod *= x

tot = 0
for i in range(0, N):
	for j in range(i + 1, N):
		p1 = min(a[i], a[j])
		tot += (p1 * (p1 - 1) // 2 + max(0, a[i] - a[j]) * a[j]) * prod // (a[i] * a[j])

tot = Decimal(tot) / prod
print(f"{tot:.6f}")

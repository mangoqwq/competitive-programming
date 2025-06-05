from decimal import Decimal

N, K = map(int, input().split())

ans = 0
for i in range(0, K):
	ans += K ** N - (i + 1) ** N

ans = 1 + Decimal(ans) / K ** N
print(f"{ans:.6f}")

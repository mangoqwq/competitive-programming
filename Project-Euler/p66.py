import math

def solve(D: int) -> tuple[int, int]:
	a = [math.floor(D ** 0.5)]
	b = 1
	c = a[0]
	d = 1
	
	while True:
		# check if convergent is fundamental solution
		x, y = a[-1], 1
		for i in range(len(a) - 2, -1, -1):
			x, y = y, x
			x = x + y * a[i]
			x //= math.gcd(x, y)
			y //= math.gcd(x, y)
			if x * x - D * y * y == 1:
				return x, y
			
		# otherwise generate next convergent
		an = math.floor(d / (b * (D ** 0.5) - c))
		b, c, d = (b * d), (-d * c + an * (b * b * D - c * c)), (b * b * D - c * c)
		g = math.gcd(b, c, d)
		b //= g
		c //= g
		d //= g
		a.append(an)

Ds = [i for i in range(1, 1001) if int(i**0.5) * int(i**0.5) != i]
ans = max(Ds, key=lambda D: solve(D)[0])
print(ans)


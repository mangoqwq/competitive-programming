names = input().replace('"', "").split(",")
ans = 0
for i, name in enumerate(sorted(names)):
    ans += (i + 1) * sum(map(lambda c: ord(c) - ord('A') + 1, name))
print(ans)

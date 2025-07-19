text = list(map(int, input().split(',')))
for c0 in range(26):
	for c1 in range(26):
		for c2 in range(26):
			key = [ord('a') + c0, ord('a') + c1, ord('a') + c2]
			dec = [text[i] ^ key[i % 3] for i in range(len(text))]
			if all(32 <= c <= 126 for c in dec):
				string = ''.join(chr(c) for c in dec)
				if 'extract' in string:
					print(string)
					print(sum(dec))
					exit()

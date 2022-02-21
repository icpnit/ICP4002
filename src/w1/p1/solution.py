a, b = map(int, input().split())

m = int(1e9) + 7
r = 1
while b > 0:
  if b & 1 == 1:
    r = (r * a) % m

  a = (a * a) % m

  b >>= 1

print(r)
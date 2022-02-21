n = int(input())
a = list(map(int, input().split()))

def isPrime(n):
  if n == 1: return False

  i = 2

  while i * i <= n:
    if n % i == 0:
      return False
    i += 1

  return True

for i in range(n):
  if isPrime(a[i]):
    print(i+1)
    break
  elif i == n-1:
    print(-1)
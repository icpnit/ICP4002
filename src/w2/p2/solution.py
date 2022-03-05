n = int(input())

a = list(map(lambda x: int(x) % n, input().split()))
b = [ True for i in range(n) ]

flag = True

for x in a:
  if b[x] == False:
    flag = False
    break
  b[x] = False

print("YES" if flag else "NO")
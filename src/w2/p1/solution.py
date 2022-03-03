st = [] # main stack
hl = [] # helper stack

def show():
  print('', end='/')
  while len(st) > 0:
    t = st.pop()
    hl.append(t)

    if len(st) == 0:
      while len(hl) > 0:
        t = hl.pop()
        print(t, end='')
        if len(hl) > 0:
          print('/', end='')
        st.append(t)
      print()
      return
  print()




for _ in range(int(input())):
  s = input().split()

  if s[0] == 'cd':
    if s[1].startswith('/'):
      st = []
    for x in s[1].split('/'):
      if x == '..':
        if len(st) > 0:
          st.pop()
        else:
          raise Exception('Invalid path')
      elif x == '':
        pass
      else:
        st.append(x)
  elif s[0] == 'pwd':
    show()
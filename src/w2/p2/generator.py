from os import mkdir
import random
import sys

pth = sys.argv[1]

INPUT, OUTPUT = 0, 1

class Gen:

  def __init__(self):
    self.test_num = 1
    self.data_in = []
    self.data_out = []
    try:
      mkdir(pth + "/in")
      mkdir(pth + "/out")
    except:
      pass

  def append(self, ioType, data):
    if ioType == INPUT:
      self.data_in.append(data + "\n")
    if ioType == OUTPUT:
      self.data_out.append(data + "\n")
    
  def save(self):
    fin = open(pth + "/in/input" + str(self.test_num) + ".txt", "w")
    fout = open(pth + "/out/output" + str(self.test_num) + ".txt", "w")
    self.test_num += 1
    
    fin.writelines(self.data_in)
    fout.writelines(self.data_out)

    fin.close()
    fout.close()

    self.data_in.clear()
    self.data_out.clear()

  def generate(self):
    self.makeInitTests()
    self.makeEdgeTests()
    # self.makeAutoTests()

  def makeInitTests(self):
    # Test 1
    self.append(INPUT, "2")
    self.append(INPUT, "1 -2")
    self.append(OUTPUT, "YES")
    self.save()

    # Test 2
    self.append(INPUT, "3")
    self.append(INPUT, "2 23 33")
    self.append(OUTPUT, "NO")
    self.save()

    # Test 3
    self.append(INPUT, "5")
    self.append(INPUT, "19 -8 5 101 8")
    self.append(OUTPUT, "YES")
    self.save()

  def makeEdgeTests(self):
    # Test 4
    n = 10000
    l = [ i for i in range(n) ]
    random.shuffle(l)

    for i in range(n):
      l[i] += (random.randint(1, int(1e9)) // n) * n

      if random.randint(0, 1000) == 0:
        while l[i] > 0:
          l[i] -= n

    self.append(INPUT, str(n))
    self.append(INPUT, " ".join(map(str, l)))
    self.append(OUTPUT, "YES")
    self.save()

    # Test 5
    n = 100000
    l = [ i for i in range(n) ]
    random.shuffle(l)

    for i in range(n):
      l[i] += (random.randint(1, int(1e9)) // n) * n

      if random.randint(0, 1000) == 0:
        while l[i] > 0:
          l[i] -= n
          
    l[0] = l[-1]

    self.append(INPUT, str(n))
    self.append(INPUT, " ".join(map(str, l)))
    self.append(OUTPUT, "NO")
    self.save()

    # Test 6
    n = 200000
    l = [ i for i in range(n) ]
    random.shuffle(l)

    for i in range(n):
      l[i] += (random.randint(1, int(1e9)) // n) * n

      if random.randint(0, 1000) == 0:
        while l[i] > 0:
          l[i] -= n



    self.append(INPUT, str(n))
    self.append(INPUT, " ".join(map(str, l)))
    self.append(OUTPUT, "YES")
    self.save()

    # Test 7
    n = 200000
    l = [ i for i in range(n) ]
    random.shuffle(l)

    for i in range(n):
      l[i] += (random.randint(1, int(1e9)) // n) * n

      if random.randint(0, 1000) == 0:
        while l[i] > 0:
          l[i] -= n

    l[0] = l[-1]

    self.append(INPUT, str(n))
    self.append(INPUT, " ".join(map(str, l)))
    self.append(OUTPUT, "NO")
    self.save()

Gen().generate()
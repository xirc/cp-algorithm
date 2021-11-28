import random

values = [ i for i in range(0, 10_000)]
random.shuffle(values)

print(2 * len(values))
for i in values:
  print("1", i)
for i in range(0, 100_000):
  print("2")
print(300)
for i in range(0, 300):
    for j in range(0, 300):
        if (i == j):
            print("0 ", end='')
        else:
            print("1 ", end='')
    print()
#!/usr/bin/python3

[n, a] = map(int, input().split(" "))
a -= 1
k = int(input())
bs = list(map(lambda s: int(s) - 1, input().split(" ")))

ds = [-1 for i in range(0, n)]
ds[a] = 0
v = a
while k > 0:
    u = bs[v]
    if ds[u] < 0:
        k -= 1
        ds[u] = ds[v] + 1
    else:
        l = ds[v] - ds[u] + 1
        k -= 1
        k %= l
        for i in range(0,n):
            ds[i] = -1
        ds[u] = 0
    v = u
print(v + 1)
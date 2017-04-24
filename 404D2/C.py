import math

def f(i):
    return i*(i+1)//2

def solve(n,m):
    lo = 0
    hi = int(10**18)
    while(lo < hi):
        mid = (lo+hi)//2
        #print("mid " + str(mid))
        if n - m <= f(mid):
            hi = mid
        else:
            lo = mid+1
    return hi + m


def main():
    a = list(map(int,input("").split(" ")))
    n,m = a
    print(min(n,solve(n,m)))
    return

main()

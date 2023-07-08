N = int(input())
prime = []

def Eratos(n: int) -> None:
    isprime = [0 for _ in range(n+1)]
    i = 2
    while(i<=n):
        if(isprime[i]):
            i+=1
            continue
        else:
            isprime[i] = 1
            prime.append(i)
        j = 2
        while(i*j <= n):
            isprime[i*j] = 2
            j+=1
        i+=1
    return

if N == 1: print(0)
else:
    Eratos(N)
    psumarr = [0 for _ in range(N+1)]
    psumarr[0] = prime[0]
    for i in range(1, len(prime)):
        psumarr[i] = prime[i] + psumarr[i-1]
    partialsum = 0
    st = en = cnt = 0 
    while(st < len(prime)):
        while (en < len(prime)):
            partialsum = psumarr[en]-psumarr[st-1] if st > 0 else psumarr[en]
            if(partialsum == N):
                cnt += 1
                break
            elif (partialsum > N):
                break
            en += 1
        st += 1
    print(cnt)
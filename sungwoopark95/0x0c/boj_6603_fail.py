def func(cur):
    if cur == 6:
        for i in range(6):
            print(arr[i], end=' ')
        print('\n')
        return
    
    for i in range(K):
        if isused[i] == 0:
            if (cur>=1) and (arr[cur-1] > seq[i]):
                continue
            arr[cur] = seq[i]
            isused[i] = 1
            func(cur+1)
            isused[i] = 0
        
        
arr = [0 for i in range(20)]
isused = [0 for i in range(20)]
while True:
    seq = input()
    if seq == '0':
        break
    K = int(seq[0])
    seq = sorted([int(item) for item in seq.split(' ')][1:])
    func(0)
    print('')
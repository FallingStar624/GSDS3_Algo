# CFDS0, prof kim.

def merge(L:list, first:int, mid: int, last: int)->None:
    k = first
    sub1 = L[first:mid+1]
    sub2 = L[mid+1:last+1]
    i = j = 0
    while i  < len(sub1) and j < len(sub2):
        if sub1[i] <= sub2[j]:
            L[k] = sub1[i]
            i = i + 1
        else:
            L[k] = sub2[j]
            j = j + 1
        k = k + 1
    if i < len(sub1):
        L[k:last+1] = sub1[i:]
    elif j < len(sub2):
        L[k:last+1] = sub2[j:]


def mergeSortHelp(L:list, first:int, last:int)->None:
    if first == last: # Conditional statement
        return # Base case
    else:
        mid = first + (last - first)//2
        mergeSortHelp(L, first, mid) # recursive call for sublist1
        mergeSortHelp(L, mid+1, last) # recursive call for sublist2
        merge(L, first, mid, last)

def mergeSort(L:list)->None:
    mergeSortHelp(L, 0, len(L)-1)

if __name__ == "__main__":

    L = [5, 2, 3, 4, 1]
    mergeSort(L)
    print(L)


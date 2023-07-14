
class Node:
    def __init__(self, data, next=None) -> None:
        self.data = data
        self.next = next


def print_list(s: Node) -> None:

    if not s:
        return None

    ans = [s.data]
    cur = s
    while cur.next is not None:
        cur = cur.next
        ans.append(cur.data)

    print(ans)
    return

def palindrome(s: Node) -> int:

    if not s:
        return 0

    ans = [s.data]
    cur = s

    while cur.next is not None:
        cur = cur.next
        ans.append(cur.data)

    return int(ans == ans[::-1])

def sub_list(s: Node, t: Node) -> int:

    str_s = [str(s.data)]
    cur = s
    while cur.next is not None:
        cur = cur.next
        str_s.append(str(cur.data))    

    str_t = [str(t.data)]
    cur = t
    while cur.next is not None:
        cur = cur.next
        str_t.append(str(cur.data))    

    str_s, str_t = "".join(str_s), "".join(str_t)
    
    return int(str_t in str_s)


def max_palindromes(s: Node) -> None:

    str_s = [str(s.data)]
    cur = s
    while cur.next is not None:
        cur = cur.next
        str_s.append(str(cur.data))    
    
    s = "".join(str_s)

    def palindrome_str(s: str) -> bool:
        return s[::-1] == s

    ans = []
    for i, ch in enumerate(s):
        for offset in range(len(s), i, -1):
            word = s[i:offset:1]
            if palindrome_str(word):
                if word not in ans:
                    ans.append(word)
                break

    re_ans = []

    for i, word in enumerate(ans):

        isSub = False
        for j, other in enumerate(ans):

            if i == j:
                continue
                
            if word in other:
                isSub = True
                break      
        
        if not isSub:
            re_ans.append(word)

    final_list = []
    for temp_str in re_ans:
        res = [eval(i) for i in temp_str]
        final_list.append(res)

    print(final_list)


# if __name__ == '__main__':
#     # data = [8,1,2,3,3, 2,1,4,9,4, 5,6,7,6,5, 4,1]
#     data = [8,1,2,3,3, 2,1,0,4,9, 1,2,3,3,2,1,9,1]

#     root = Node(data[0])
#     cur = root
#     for i in range(1, len(data)):
#         cur.next = Node(data[i])
#         cur = cur.next

    # print_list(root)

    # s = Node(8)
    # s.next = Node(1)
    # s.next.next = Node(2)
    # s.next.next.next = Node(3)
    # s.next.next.next.next = Node(3)

    # t = Node(3)
    # t.next = Node(7)
    # t.next.next = Node(3)
    # t.next.next.next = Node(8)

    # print_list(s)
    # print(palindrome(s))
    # print(sub_list(s, t))

    # max_palindromes(root)
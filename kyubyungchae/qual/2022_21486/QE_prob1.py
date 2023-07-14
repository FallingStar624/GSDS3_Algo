def getMaxCountChar(count):
	maxCount = 0
	for i in range(26):
		if count[i] > maxCount:
			maxCount = count[i]
			maxChar = chr(i + ord('a'))

	return maxCount, maxChar

# Main function for rearranging the characters


def foo(S):
	N = len(S)

	# if length of string is None return False
	if not N:
		return ""

	# create a hashmap for the alphabets
	count = [0] * 26
	for char in S:
		count[ord(char) - ord('a')] += 1

	maxCount, maxChar = getMaxCountChar(count)

	# if the char with maximum frequency is more than the half of the
	# total length of the string than return False
	if maxCount > (N + 1) // 2:
		return ""

	# create a list for storing the result
	res = [None] * N

	ind = 0

	# place all occurrences of the char with maximum frequency in
	# even positions
	while maxCount:
		res[ind] = maxChar
		ind += 2
		maxCount -= 1

	# replace the count of the char with maximum frequency to zero
	# as all the maxChar are already placed in the result
	count[ord(maxChar) - ord('a')] = 0

	# place all other char in the result starting from remaining even
	# positions and then place in the odd positions
	for i in range(26):
		while count[i] > 0:
			if ind >= N:
				ind = 1
			res[ind] = chr(i + ord('a'))
			ind += 2
			count[i] -= 1

	# convert the result list to string and return
	return ''.join(res)



def bar(s: str) -> str:

    s = ''.join(dict.fromkeys(s))

    return foo(s)


if __name__ == '__main__':
    # s = "abcde"
    s = "abc"
    # s = ""
    # s = "abccde"
    # s = "abcdcef"
    # s = "ab"
    print(foo(s))
    print(bar(s))
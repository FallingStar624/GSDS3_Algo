def index_words_iter(text):
	if text:
		yield 0
	for index, letter in enumerate(text):
		if letter == ' ':
			yield index + 1

# address = 'Four score and seven years ago...'
# iter = index_words_iter(address)
# while iter:
#     print(next(iter))
# print(iter, next(iter), next(iter), next(iter))
# print(type(index_words_iter(address)), index_words_iter(address))
# result = list(index_words_iter(address))
# print(result)

print(range(0, 1), type(range(0,1)))
print(enumerate([0,1]))
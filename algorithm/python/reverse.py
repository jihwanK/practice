from typing import List

def Reverse_0(given: List[str]) -> List[str]:
	original = given[:]
	size = len(given)
	for i in range(size // 2):
		tmp = given[i]
		given[i] = given[size - 1 - i]
		given[size - i - 1] = tmp

	print(given)
	print(original)
	if original[::-1] == given:
		print('true')
	else:
		print('false')

	return given


def Reverse(given: List[str]) -> List[str]:
	left, right = 0, len(given) - 1

	while left < right:
		tmp = given[left]
		given[left] = given[right]
		given[right] = tmp

		left += 1
		right -= 1

	return given

print(Reverse(list('hello')))
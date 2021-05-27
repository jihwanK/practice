def Palindrome_0(given: str) -> None:
	given = given.replace(',', '').replace('.', '').replace(':', '').replace(';', '').replace('\'', '').replace('"', '').replace('\\', '').replace(' ', '')
	if given.isalpha():
		print('it is composed with only alphabet')

	given = given.lower()

	print(given[::-1])
	print(given)

	if given[::-1] == given:
		print('true')
	else:
		print('flase')


import re
def Palindrome(given: str) -> None:
	given = re.sub('[^A-z0-9]', '', given)
	given = given.lower()

	if given[::-1] == given:
		print('true')
	else:
		print('false')



Palindrome('A man, a plan, a canal: Panama')



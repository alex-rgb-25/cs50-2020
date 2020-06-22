from cs50 import get_string


n = get_string("Text: ")
letters = 0
words = 1
sen = 0

for c in n:

    if ord(c) in range(97, 122):
        letters += 1
    if ord(c) in range(65, 90):
        letters += 1
    if ord(c) == 32:
        words += 1
    if ord(c) == 33 or ord(c) == 63 or ord(c) == 46:
        sen += 1

L = letters / words * 100
S = sen / words * 100
CLI = 0.0588 * L - 0.296 * S - 15.8
if round(CLI) < 1:
    print("Before Grade 1")
elif round(CLI) > 16:
    print("Grade 16+")
else:
    print("Grade", round(CLI))

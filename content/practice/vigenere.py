from cs50 import get_string
import sys

if len(sys.argv) != 2:
    sys.exit(1)
key = sys.argv[1]
if not key.isalpha():
    sys.exit(1)

plaintext = get_string("Plaintext: ")
print("ciphertext: ", end="")

key_index = 0
for c in plaintext:
    if c.isalpha():
        if (key[key_index].islower()):
            shift = ord(key[key_index]) - ord('a')
        else:
            shift = ord(key[key_index]) - ord('A')
        key_index = key_index + 1
        if key_index == len(key):
            key_index = 0
        if c.islower():
            ciphered_letter_index = (ord(c) - ord('a') + shift) % 26
            print(chr(ord('a') + ciphered_letter_index), end="")
        else:
            ciphered_letter_index = (ord(c) - ord('A') + shift) % 26
            print(chr(ord('A') + ciphered_letter_index), end="")
    else:
        print(c, end="")
print("")

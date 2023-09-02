import re

text = input("Text: ")
words = text.split()
sentences = re.split(r'[.!?]+', text)

nb_words = len(words)

nb_letters = 0
for word in words:
    for letter in word:
        if letter.isalpha():
            nb_letters += 1

nb_sentences = len(sentences)-1

L = nb_letters / nb_words * 100 
S = nb_sentences / nb_words * 100
index = 0.0588 * L - 0.296 * S - 15.8

print(nb_letters)
print(nb_words)
print(nb_sentences)

if index < 0:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")
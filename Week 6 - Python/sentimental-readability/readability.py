from cs50 import get_string

# Readability (Sentimental)
# Problem Set 6 - Week 6 - Python
# Author: John Serrano

letters = 0
words = 0
sentences = 0

# Text input as string
i = 0
text = get_string("Text: ")
# Analyze the string; search for words, sentences and letters
while (i < len(text)):
    if (text[i].isalpha()):
        letters += 1
    elif (text[i] == " "):
        words += 1
    elif (text[i] == '.' or text[i] == '?' or text[i] == '!'):
        sentences += 1
    i += 1
# Increment words as 1 since a space separates two words
words += 1
print(words)
print(letters)
print(sentences)
# Calcule L and S to use in Coleman-Liau index
L = 100.0 * (letters / words)
S = 100.0 * (sentences / words)
# Use both L and S and apply Coleman-Liau index
index = 0.0588 * L - 0.296 * S - 15.8
# Round Coleman-Liau index to get the final grade
final_index = round(index)
# Output print, depending on the grade
if (final_index < 1):
    print("Before Grade 1")
elif (final_index > 1 and final_index < 16):
    print("Grade", final_index)
elif (final_index >= 16):
    print("Grade 16+")

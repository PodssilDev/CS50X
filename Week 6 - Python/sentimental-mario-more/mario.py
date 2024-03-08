from cs50 import get_int

height = 0
while height < 1 or height > 8:
    height = get_int("Height: ")

spaces = height - 1  # number of spaces to print
blocks = 1  # number of "blocks" to print

while spaces >= 0:  # while spaces aren't less than 0 (piramid completed)
    for i in range(0, spaces):
        print(" ", end="")  # print the left side spaces
    for j in range(0, blocks):
        print("#", end="")  # print the left side "blocks"
    print("  ", end="")  # print the two spaces between sides
    for k in range(0, blocks):
        print("#", end="")  # print the right side blocks
    print("")  # print the newline so piramid can grow

    blocks += 1  # blocks increase with each new line
    spaces -= 1  # spaces decrease with each new line

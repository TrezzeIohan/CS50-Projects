# TODO

height = 0
# Prompting the user. This only catches one error.
# The other ones are based in the trust system.
# I wonder if recursivness could solve this...
while height <= 0 or height > 8:
    try:
        height = int(input("Height: "))
    except ValueError:
        print("Oops, not an int! Type an int, please:")
        height = int(input("Height: "))

# Loops to make the drawing
for i in range(0, height):
    for j in range(0, height + i + 3):
        if (j == height or j == height + 1 or i + j < height - 1):
            print(" ", end="")
        elif j == i + height + 2:
            print("#")
        else:
            print("#", end="")


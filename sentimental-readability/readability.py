# TODO


def main():
    # Get the user input
    text = input("Text: ")

    # Declaring variables needed
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # Calculate the values of l and s
    # to use in the Coleman Liau phormula
    l = per_hundred(words, letters)
    s = per_hundred(words, sentences)

    # Apllying the Coleman Liau phormula
    index = coleman_liau_index(l, s)

    # Printing the result
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


# Count the number of letters in the input
def count_letters(text):
    letters = 0
    for letter in text:
        if letter.isalpha() == True:
            letters += 1
    return letters


# Count the number of words in the input.
# It starts at 1, because it use spaces
# to count the number of words.
def count_words(text):
    words = 1
    for letter in text:
        if letter == " ":
            words += 1

    return words


# Count the number of sentences in the input
def count_sentences(text):
    sentences = 0
    for letter in text:
        if letter == "." or letter == "!" or letter == "?":
            sentences += 1

    return sentences


# Function to calculate the per hundred values
def per_hundred(words, value):
    result = (100 * value) / words

    return result


# The Coleman Liau phormula
def coleman_liau_index(l, s):

    calculus = 0.0588 * l - 0.296 * s - 15.8
    index = round(calculus)

    return index


if __name__ == "__main__":
    main()
books = []

# Add three books to our shelf
for i in range(3):
    book = {}
    book["title"] = input("Title: ").strip().capitalize()
    book["author"] = input("Author: ").strip().capitalize()
    books.append(book)

for book in books:
    print(book["title"])
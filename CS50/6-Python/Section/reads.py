import csv

books = []

# Add books to our shelf from books.csv
with open("books.csv") as file:
    file_reader = csv.DictReader(file)
    for book in file_reader:
        books.append(book)

for book in books:
    print(book["title"])
import csv

with open("favorites.csv","r") as file:
    reader = csv.DictReader(file)
    counts = {}
    scratch, c, python = 0, 0, 0
    for row in reader:
        favorite = row["problem"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

for language in sorted(counts, key=lambda problem: counts[problem], reverse=True):
    print(f"{language}: {counts[language]}")
scores = []

for i in range(3):
    score = int(input("Score: "))
    scores += [score]

print(f"Average: {sum(scores) / len(scores)}")
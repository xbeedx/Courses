import csv

from cs50 import SQL

# Open database
db = SQL("sqlite:///roster.db")

# Drop table sif they already exist
try:
    db.execute("DROP TABLE student")
    db.execute("DROP TABLE house")
    db.execute("DROP TABLE assignment")
except:
    pass


db.execute("CREATE TABLE student (id INTEGER,name TEXT,PRIMARY KEY(id))")
db.execute("CREATE TABLE house (id INTEGER,name TEXT, head TEXT, PRIMARY KEY(id))")
db.execute("CREATE TABLE assignment (id INTEGER,id_student INTEGER, id_house INTEGER, FOREIGN KEY (id_student) REFERENCES student(id), FOREIGN KEY (id_house) REFERENCES house(id), PRIMARY KEY(id))")

id_student = 1
with open("students.csv","r") as file:
    reader = csv.DictReader(file)
    for student in reader:
        house_id = db.execute("SELECT id FROM house WHERE name = ?", student['house'])

        # If the house doesn't exist, insert it into the house table
        if not house_id:
            db.execute("INSERT INTO house (name, head) VALUES (?, ?)", student['house'], student['head'])
            house_id = db.execute("SELECT id FROM house WHERE name = ?", student['house'])

        # Insert the student and assignment records
        db.execute("INSERT INTO student (id, name) VALUES (?, ?)", id_student, student['student_name'])
        db.execute("INSERT INTO assignment (id_student, id_house) VALUES (?, ?)", id_student, house_id[0]['id'])

        id_student += 1

print("Students:")
for student in db.execute("SELECT * FROM student"):
    print(student)

print("Houses:")
for house in db.execute("SELECT * FROM house"):
    print(house)
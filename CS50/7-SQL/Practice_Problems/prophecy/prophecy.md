# [Hall of Prophecy](https://cs50.harvard.edu/x/2023/problems/7/prophecy/)


## Background

The keeper of the Hall of Prophecy, whose job entailed labelling records and keeping them up to date, decided to create a SQL database of Hogwarts students. Unfortunately the database was poorly designed! The database, roster.db, contains only one table, students, with the name and head of each of the four Hogwarts Houses.

Stumbling upon this database, you decide it could be better designed. Take a look at roster.db and notice how the name and head of each house repeats over and over. A better design would contain a students table (for only students), a houses table (for only houses), and a table that codifies the relationship between students and houses. This process of changing the “schema” of a database is known as refactoring.


## Implementation Details

You will use the existing data in roster.db to create a new database, one with a table for students, a table for houses, and a table for house assignments. You can do this with individual SQL queries, though we recommend ultimately writing your own Python program to automate the process! Notice we’ve given you the data from the students table of roster.db in CSV format, students.csv, for your convenience.

### Developing a Schema

First, let’s develop a new schema for the database. In schema.sql, document the three CREATE TABLE commands you’ll need to create your three new tables.

Keep in mind you’ll want each table to represent a single entity: that is, your students table should represent only students, your houses table should represent only houses, and your house assignments table should represent only house assignments. You might find it helpful to first consider the pieces of information you’ll need in each table, and then about which SQLite data type best represents that information. For example, this was the CREATE TABLE command for students:

```sql
CREATE TABLE students (
    id INTEGER,
    student_name TEXT,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id)
);
```

Keep in mind that every table should have a primary key: a column that uniquely identifies every row in the table. Some tables may be best designed with foreign keys: columns that reference the primary keys of another table.

When you’re ready to configure your database with your new schema, run your three new CREATE TABLE queries. Type .schema to see your results.

### Inserting Data

After you’ve configured your database with your new schema, you can begin inserting data into your new database (using your new schema!). It’s best to write a Python program here, which can save you the trouble of writing many INSERT queries. Keep in mind that you have students.csv, which contains the data from the previous database’s students table.


## Thought Question

Why do you think it’s considered better design not to repeat information like houses and heads for each student?
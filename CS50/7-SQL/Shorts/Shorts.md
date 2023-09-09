# Shorts

# [SQL](https://youtu.be/AywtnUjQ6X4) 


## What is a database?

- Often times, in order for us to build the most functional website we can, we depend on a database to store information.

- If you've ever used Microsoft Excel or Google Spreadsheets (among others), odds are you're familiar with the notion of a `database`: a hierarchically organized set of tables, each of which contains a set of rows and columns.


## Types of database engines 

- SQL (the Structured Query Language) is a programming  language whose purpose is to query a database.

- MySQL is one open-source platform on which you can establish the type of relational database that SQL is most adept at working with.
    - SQLite is another.  

- Many installations of SQL come with a GUI tool called phpMyAdmin which can be used to execute database queries in a more user-friendly way.


## Creating a table

- After you create a database, the next thing you'll most likely want to do is create a table.
    - The syntax for doing this is actually a bit awkward to do programmatically, at least at the outset, and so this is where phpMyAdmin will come in handy.

- As part of the process of creating a table, you'll be asked to specify all of the columns in that table. 

- Thereafter, all your queries will refer to rows of the table.


## Data types

- Each column of your SQL table is capable of holding data of a particular data type; 

|          |           |         |           |            |
|----------|-----------|---------|-----------|------------|
| INT      | SMALLINT  | TINYINT | MEDIUMINT | BIGINT     |
| DECIMAL  | FLOAT     | BIT     | DATE      | TIME       |
| DATETIME | TIMESTAMP | CHAR    | VARCHAR   | BINARY     |
| BLOB     | TEXT      | ENUM    | GEOMETRY  | LINESTRING |


## varchar vs char

- Unlike in C, the CHAR data type in SQL does not refer to a single character. Rather, it is a fixed-length string.
    - In most relational databases, including MySQL, you actually specify the fixed-length as part of the type definition, e.g. CHAR(10).

- A VARCHAR refers to a variable-length string.
    - VARCHARs also require you to specify the maximum possible length of a string that could be stored in that column, e.g. VARCHAR (99).

- SQLite has these data types as well, but affiliates each with a "type affinity" to simplify things.
|          |           |         |           |            |
|----------|-----------|---------|-----------|------------|
|   NULL   |  INTEGER  |   REAL  |    TEXT   |     BLOB   |


## Primary keys

- One other important consideration when constructing a table in SQL is to choose one column to be your ``primary key``.

- Primary keys enable rows of a table to be uniquely and quickly identified.
    - Choosing your primary key appropriately can make subsequent operations on the table much easier.

- It is also possible to establish a joint primary key - a combination of two columns that is always guaranteed to be unique.


## Operations

- SQL is a programming language, but its vocabulary is fairly limited.

- We will primarily consider just four operations that one may perform on a table.

|          |
|----------|
|  INSERT  |
|  SELECT  |
|  UPDATE  |
|  DELETE  |


## INSERT
      Add information to a table.
```sql
    INSERT INTO
    <table>
    (<columns>)
    VALUES 
    (<values>)
```

### Auto increment

- When defining the column that ultimately ends up being your table's primary key, it's usually a good idea to have that column be an integer.

- Moreover, so as to eliminate the situation where you may accidentally forget to specify a real value for the primary key column, you can configure that column to autoincrement, so it will pre-populate that column for you automatically when rows are added to the table.


## SELECT
      Extract information from a table.
```sql
    SELECT
    <columns>
    FROM
    <table>
    WHERE
    <predicate>
    ORDER BY
    <columns>
    LIMIT
    <limit>
```


### Relational databases

- Databases empower us to organize information into tables 
  efficiently.
    - We don't always need to store every possible relevant piece of information in the same table, but can use relationships across the tables to let us pull information from where we need it.

## SELECT (JOIN)
      Extract information from multiple tables.

```sql
    SELECT
    <columns>
    FROM
    <table1>
    JOIN
    <table2>
    ON
    <predicate>
```

## Update
     Modify information in a table.

```sql
    UPDATE
    <table>
    SET
    <column> = <value>
    WHERE
    <predicate>
```

## Delete
    Remove information from a table.
    
```sql
    DELETE FROM
    <table>
    WHERE
    <predicate>
```

## 

- All of these operations are pretty easy to do in the graphical  interface of phpMyAdmin.

- We want a way to do this programmatically, not just typing SQL commands into the "SQL" tab of phpMyAdmin.

- Fortunately, SQL integrates with other programming languages such as Python or PHP very easily.
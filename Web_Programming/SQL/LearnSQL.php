<?php
/*Basic Concept*/
//數據庫是以便於訪問、高效管理和更新的方式組織的數據集合。
//數據庫由存儲相關信息的表組成。
/*A primary key(資料編號) is a field in the table that uniquely identifies the table records.
The primary key's main features:
- It must contain a unique value for each row.
- It cannot contain NULL values.
- Tables are limited to ONE primary key each.
- The primary key's value must be different for each row.*/
/*SQL stands for Structured Query Language.
SQL is used to access and manipulate a database.
MySQL is a program that understands SQL.
SQL can:
- insert, update, or delete records in a database.
- create new databases, tables, stored procedures and views.
- retrieve data from a database, etc.
SQL 是一個 ANSI（美國國家標準協會）標準，但是 SQL 語言有不同的版本。
除了 SQL 標準之外，大多數 SQL 數據庫程序都有自己的專有擴展，但它們都支持主要命令。 */
//"SHOW DATABASES;"
//the "SHOW DATABASES" command lists the databases managed by the server.
//"SHOW TABLES;"
//The "SHOW TABLES" command is used to display all of the tables in the currently selected MySQL database.
//"SHOW COLUMNS;"
//"SHOW COLUMNS" displays information about the columns in a given table.
/*SHOW COLUMNS displays the following values for each table column:
    Field: column name
    Type: column data type
    Key: indicates whether the column is indexed
    Default: default value assigned to the column
    Extra: may contain any additional information that is available about a given column 
"SHOW COLUMNS FROM customers;"(customer=table name)

//SELECT Statement
The SELECT statement is used to select data from a database.
The result is stored in a result table, which is called the result-set.

"SELECT column_list FROM table_name;"
- column_list includes one or more columns from which data is retrieved
- table-name is the name of the table from which the information is retrieved
//customers table(customers_table.png)

//The following SQL statement selects the FirstName from the customers table:
"SELECT FirstName FROM customers;"*/

/*區分大小寫(Case Sensitivity)*/
//指令無論使用大小寫皆可運行，但It is common practice to write all SQL commands in upper-case. 所以sql是不區分大小寫

/*Syntax Rules(語法規則)*/
/*A single SQL statement can be placed on one or more text lines. 
In addition, multiple SQL statements can be combined on a single text line.
White spaces and multiple lines are ignored in SQL.
For example, the following query is absolutely correct. :
"SELECT        City


FROM customers;"*/

//Selecting Multiple Columns
/*You can select multiple table columns at once.
Just list the column names, separated by commas:
"SELECT FirstName, LastName, City 
FROM customers;"
Do not put a comma after the last column name. */

//Selecting All Columns
/*To retrieve all of the information contained in your table, 
    place an asterisk (*) sign after the SELECT command, 
    rather than typing in each column names separately. :
"SELECT * FROM customers; "*/

//The DISTINCT Keyword
/*在表中有多個重複記錄的情況下，只返回唯一記錄而不是獲取重複記錄可能更有意義。 
SQL DISTINCT 關鍵字與 SELECT 結合使用以消除所有重複記錄並僅返回唯一記錄。
"SELECT DISTINCT column_name1, column_name2
FROM table_name;"

//original customer table: customers_table_distinct.png
Note that there are duplicate City names. 
The following SQL statement selects only distinct values from the City column:
"SELECT DISTINCT City FROM customers; "
This would produce the following result. Duplicate entries have been removed:
    customers_table_distinct_removeDuplicate.png*/

//The LIMIT Keyword: 只取n筆資料
/*默認情況下，返回所有滿足 SQL 語句中指定條件的結果。
然而，有時我們只需要檢索記錄的一個子集。在 MySQL 中，這是通過使用 LIMIT 關鍵字來完成的。
"SELECT column list
FROM table_name
LIMIT [number of records];" 

For example, we can retrieve the first five records from the customers table: 
"SELECT ID, FirstName, LastName, City
FROM customers LIMIT 5;"
//output: customers_table_limit.png

//The OFFSET Keyword: 指定從哪一筆資料開始
You can also pick up a set of records from a particular offset.
In the following example, we pick up four records, starting from the third position:
"SELECT ID, FirstName, LastName, City
FROM customers OFFSET 3 LIMIT 4;"
//output: customers_table_offset.png
//MySQL starts counting from zero, meaning that the offset of the first row is 0, not 1.
EX: show 12 results, starting from fifth:
    SELECT id, name FROM customers LIMIT 4, 12*/

/*For Example(order by, limit): class_practice_1.png

"SELECT name, year FROM movies WHERE name='Shrek';
SELECT count(*) FROM movies WHERE year>=1980 AND year<1990; //count(): how many data limited by order
SELECT * FROM movies ORDER BY rank DESC LIMIT 3;  "
//DESC:descending //Remember that don't add 'WHERE'('where' is a filter)

*/

/*Fully Qualified Names

"SELECT City FROM customers;
SELECT customers.City FROM customers;"
//The term for the above-mentioned syntax is called the "fully qualified name" of that column.*/

/*Order By
ORDER BY is used with SELECT to sort the returned data.
"SELECT * FROM customers
ORDER BY FirstName; "
//By default, the ORDER BY keyword sorts the results in ascending order.
//If you want to sort the results in descending order: add 'DESC'

//Sorting Multiple Columns
"SELECT * FROM customers 
ORDER BY LastName, Age;"
//The ORDER BY command starts ordering in the same sequence as the columns. 
    It will order by the first column listed, then by the second, and so on.*/


/*Filtering, Functions, Subqueries*/
/*The WHERE Statement
The WHERE clause is used to extract only those records that fulfill a specified criterion.
"SELECT column_list 
FROM table_name
WHERE condition;"

//EX: SELECT a specific record
"SELECT * FROM customers
WHERE ID = 7;"
//WHERE 子句用於僅提取那些滿足指定條件的記錄。

//SQL Operators: sql_operator.png
//The BETWEEN Operator
"SELECT column_name(s)
FROM table_name
WHERE column_name BETWEEN value1 AND value2;"

//Text Values
//如果您的文本包含撇號（單引號），您應該使用兩個單引號字符來轉義撇號。例如：'Can''t'.

//Logical Operators: logical_operator.png
//EX:
"SELECT ID, FirstName, LastName, Age
FROM customers
WHERE Age >= 30 AND Age <= 40;"

//The IN Operator
The IN operator is used when you want to compare a column with more than one value.
If you use 'or' to compare many columns:
"SELECT * FROM customers 
WHERE City = 'New York'
OR City = 'Los Angeles'
OR City = 'Chicago';"
If you use 'in' to compare many columns:
"SELECT * FROM customers 
WHERE City IN ('New York', 'Los Angeles', 'Chicago');"

//The NOT IN Operator
The NOT IN operator allows you to exclude a list of specific values from the result set.
"SELECT * FROM customers 
WHERE City NOT IN ('New York', 'Los Angeles', 'Chicago');"
The NOT IN operator allows you to exclude a list of specific values from the result set.

//The CONCAT Function
The CONCAT function is used to concatenate two or more text values and returns the concatenating string.
Let's concatenate the FirstName with the City, separating them with a comma:
"SELECT CONCAT(FirstName, ', ' , City) FROM customers;" :concate.png

//The AS Keyword
A concatenation results in a new column. The default column name will be the CONCAT function.
"SELECT CONCAT(FirstName,', ', City) AS new_column 
FROM customers;

//Arithmetic Operators
//The example below adds 500 to each employee's salary and selects the result:
"SELECT ID, FirstName, LastName, Salary+500 AS Salary
FROM employees;"

//The UPPER Function
The UPPER function converts all letters in the specified string to uppercase.
The LOWER function converts the string to lowercase.
"SELECT FirstName, UPPER(LastName) AS LastName 
FROM employees;"
If there are characters in the string that are not letters, this function will have no effect on them.

//SQRT and AVG
SQRT():參數中給定值的平方根:
"SELECT Salary, SQRT(Salary) 
FROM employees;"
Another way to do the SQRT is to use POWER with the 1/2 exponent. However, SQRT seems to work faster than POWER in this case.

AVG(): the AVG function returns the average value of a numeric column:
"SELECT AVG(Salary) FROM employees;"

//The SUM function
"SELECT SUM(Salary) FROM employees;"

//Subqueries
A subquery is a query within another query.
EX:We might need the list of all employees whose salaries are greater than the average.
"SELECT AVG(Salary) FROM employees;"
As we already know the average, 
    we can use a simple WHERE to list the salaries that are greater than that number.
"SELECT FirstName, Salary FROM employees 
WHERE  Salary > 3100
ORDER BY Salary DESC;"
The DESC keyword sorts results in descending order.
ASC sorts the results in ascending order.

A single subquery will return the same result more easily.
"SELECT FirstName, Salary FROM employees 
WHERE  Salary > (SELECT AVG(Salary) FROM employees) 
ORDER BY Salary DESC;"

//The Like Operator
The LIKE keyword is useful when specifying a search condition within your WHERE clause.
"SELECT column_name(s)
FROM table_name
WHERE column_name LIKE pattern;"
SQL 模式匹配使您可以使用“_”匹配任何單個字符，使用“%”匹配任意數量的字符（包括零個字符）。
例如，要選擇 FirstNames 以字母 A 開頭的員工，您可以使用以下查詢：
"SELECT * FROM employees 
WHERE FirstName LIKE 'A%';"
選擇姓氏以字母“s”結尾的所有員工：
"SELECT * FROM employees 
WHERE LastName LIKE '%s';"
% 通配符可以在同一模式中多次使用。

//The MIN Function
know the minimum salary among the employees: 
"SELECT MIN(Salary) AS Salary FROM employees;"
*/


/*JOIN, Table Operations
//Joining Tables
"joining tables" means combining data from two or more tables. 
    A table join creates a temporary table showing the data from the joined tables.
Rather than storing the customer name in both tables, 
    the orders table contains a reference to the customer ID that appears in the customers table.
"SELECT customers.ID, customers.Name, orders.Name, orders.Amount
FROM customers, orders
WHERE customers.ID=orders.Customer_ID
ORDER BY customers.ID;"
也可將table名稱簡寫:
"SELECT c.ID, c.Name, o.Name, o.Amount
FROM customers c, orders o
WHERE c.ID=o.Customer_ID
ORDER BY c.ID;"

//Custom Names(自定義名稱)
Custom names can be used for tables as well. 
    You can shorten the join statements by giving the tables "nicknames":
"SELECT ct.ID, ct.Name, ord.Name, ord.Amount
FROM customers AS ct, orders AS ord
WHERE ct.ID=ord.Customer_ID
ORDER BY ct.ID;"

//Types of Join
The following are the types of JOIN that can be used in MySQL:
- INNER JOIN
- LEFT JOIN
- RIGHT JOIN

//INNER JOIN (Intersection)等同於 JOIN。當表之間存在匹配項時，它會返回行。
"SELECT column_name(s)
FROM table1 INNER JOIN table2 
ON table1.column_name=table2.column_name;"
請注意用於指定內部連接條件的 ON 關鍵字。

//LEFT JOIN (left table)
LEFT JOIN 返回左表中的所有行，即使右表中沒有匹配項。
這意味著如果右側表中的 ON 子句沒有匹配項，連接仍將在結果中返回第一個表中的行。
"SELECT table1.column1, table2.column2...
FROM table1 LEFT OUTER JOIN table2
ON table1.column_name = table2.column_name;"
OUTER 關鍵字是可選的，可以省略。
EX:
"SELECT customers.Name, items.Name 
FROM customers LEFT OUTER JOIN items 
ON customers.ID=items.Seller_id;"
結果集包含左表中的所有行和右表中的匹配數據。
如果未找到特定行的匹配項，則返回 NULL。

//RIGHT JOIN
The RIGHT JOIN returns all rows from the right table, even if there are no matches in the left table.
"SELECT table1.column1, table2.column2...
FROM table1 RIGHT OUTER JOIN table2
ON table1.column_name = table2.column_name;"
EX:
"SELECT customers.Name, items.Name FROM customers
RIGHT JOIN items ON customers.ID=items.Seller_id;"
The RIGHT JOIN returns all the rows from the right table (items), 
    even if there are no matches in the left table (customers).

//Set Operation
有時，您可能需要將多個表中的數據組合成一個綜合數據集。
這可能適用於同一數據庫中具有相似數據的表，或者可能需要跨數據庫甚至跨服務器組合相似數據。
UNION combines multiple datasets into a single dataset, and removes any existing duplicates.
UNION ALL combines multiple datasets into one dataset, but does not remove duplicate rows.
***UNION ALL is faster than UNION, as it does not perform the duplicate removal operation over the data set.

//UNION
The UNION operator is used to combine the result-sets of two or more SELECT statements.
All SELECT statements within the UNION must have the same number of columns. 
    The columns must also have the same data types. 
    Also, the columns in each SELECT statement must be in the same order.
"SELECT column_name(s) FROM table1
UNION
SELECT column_name(s) FROM table2;"
EX:
"SELECT ID, FirstName, LastName, City FROM First
UNION
SELECT ID, FirstName, LastName, City FROM Second;"
the duplicates have been removed.
//TIP:
If your columns don't match exactly across all queries, you can use a NULL (or any other) value such as:
"SELECT FirstName, LastName, Company FROM businessContacts
UNION
SELECT FirstName, LastName, NULL FROM otherContacts;"
The UNION operator is used to combine the result-sets of two or more SELECT statements.

//UNION ALL
UNION ALL selects all rows from each table and combines them into a single table.
"SELECT ID, FirstName, LastName, City FROM First
UNION ALL
SELECT ID, FirstName, LastName, City FROM Second;"

//Inserting Data (data)
SQL tables store data in rows, one row after another. 
    The INSERT INTO statement is used to add new rows of data to a table in the database.
    The SQL INSERT INTO syntax is as follows:
"INSERT INTO table_name
VALUES (value1, value2, value3,...);"
When inserting records into a table using the SQL INSERT statement, 
    you must provide a value for every column that does not have a default value, 
    or does not support NULL.
EX:
You plan to add two more vehicles to your garage:
6, 'Mercedes-Benz', 'G 63', 2020
7, 'Porsche', 'Panamera', 2020
Write a query to insert the new cars into your table named 'Garage'. 
    Then show the table with the added records:
"INSERT INTO Garage 
VALUES(6, 'Mercedes-Benz', 'G 63', 2020);
INSERT INTO Garage 
VALUES(7, 'Porsche', 'Panamera', 2020);
SELECT * FROM Garage;"
//you can specify the table's column names in the INSERT INTO statement:
"INSERT INTO table_name (column1, column2, column3, ...,columnN)  
VALUES (value1, value2, value3,...valueN);"
EX:
"INSERT INTO Employees (ID, FirstName, LastName, Age)
VALUES (8, 'Anthony', 'Young', 35);"
You can specify your own column order, as long as the values are specified in the same order as the columns.
//insert data into specific columns only:
"INSERT INTO Employees (ID, FirstName, LastName) 
VALUES (9, 'Samuel', 'Clark');
SELECT * from Employees;"
The Age column for that row automatically became 0, as that is its default value.

//Updating Data(data)
The UPDATE statement allows us to alter data in the table.
The basic syntax of an UPDATE query with a WHERE clause is as follows:
"UPDATE table_name
SET column1=value1, column2=value2, ...
WHERE condition;"
You specify the column and its new value in a comma-separated list after the SET keyword.
如果省略 WHERE 子句，表中的所有記錄都會被更新！
EX:To update John's salary, we can use the following query:
"UPDATE Employees 
SET Salary=5000
WHERE ID=1;
SELECT * from Employees;"
//Updating Multiple Columns
"UPDATE Employees 
SET Salary=5000, FirstName='Robert'
WHERE ID=1;"
您可以在 SET 子句中以任何您喜歡的方式指定列順序。

//Deleting Data
The DELETE statement is used to remove data from your table. DELETE queries work much like UPDATE queries.
"DELETE FROM table_name
WHERE condition; "
EX:
"DELETE FROM Employees
WHERE ID=1;
"
If you omit the WHERE clause, all records in the table will be deleted!
    The DELETE statement removes the data from the table permanently.

//Creating a Table
"CREATE TABLE table_name
(
column_name1 data_type(size),
column_name2 data_type(size),
column_name3 data_type(size),
....
columnN data_type(size)
);"
- The column_names specify the names of the columns we want to create.
- The data_type parameter specifies what type of data the column can hold. 
    For example, use int for whole numbers.
- The size parameter specifies the maximum length of the table's column.
EX:
Assume that you want to create a table called "Users" that consists of four columns: 
UserID, LastName, FirstName, and City:
"CREATE TABLE Users
(
   UserID int,
   FirstName varchar(100), 
   LastName varchar(100),
   City varchar(100)
); "
varchar is the datatype that stores characters. 
    You specify the number of characters in the parentheses after the type. 
    So in the example above, our fields can hold max 100 characters long text.

//Data Types
The most common data types:
    Numeric:
        INT -A normal-sized integer that can be signed or unsigned.
        FLOAT(M,D) - A floating-point number that cannot be unsigned. 
                    You can optionally define the display length (M) and the number of decimals(小數位數) (D).
        DOUBLE(M,D) - A double precision floating-point number that cannot be unsigned. 
                    You can optionally define the display length (M) and the number of decimals (D).

    Date and Time:
        DATE - A date in YYYY-MM-DD format.
        DATETIME - A date and time combination in YYYY-MM-DD HH:MM:SS format.
        TIMESTAMP - A timestamp, calculated from midnight, January 1, 1970
        TIME - Stores the time in HH:MM:SS format.

    String Type:
        CHAR(M) - Fixed-length character string. Size is specified in parenthesis. Max 255 bytes.
        VARCHAR(M) - Variable-length character string. Max size is specified in parenthesis.
        BLOB - "Binary Large Objects" and are used to store large amounts of binary data, 
                such as images or other types of files.
        TEXT - Large amount of text data.

//Primary Key
The UserID is the best choice for our Users table's primary key.
"CREATE TABLE Users
(
   UserID int,
   FirstName varchar(100),
   LastName varchar(100),
   City varchar(100),
   PRIMARY KEY(UserID)
); "

//SQL Constraints
SQL constraints are used to specify rules for table data.
The following are commonly used SQL constraints:
NOT NULL - Indicates that a column cannot contain any NULL value.
UNIQUE - Does not allow to insert a duplicate value in a column. 
            The UNIQUE constraint maintains the uniqueness of a column in a table. 
            More than one UNIQUE column can be used in a table.
PRIMARY KEY - Enforces the table to accept unique data for a specific column and 
            this constraint create a unique index for accessing the table faster.
CHECK - Determines whether the value is valid or not from a logical expression.
DEFAULT - While inserting data into a table, if no value is supplied to a column, 
            then the column gets the value set as DEFAULT.

//NOT NULL
For example, the following means that the name column disallows NULL values.
"name varchar(100) NOT NULL"

//AUTO INCREMENT
Auto-increment allows a unique number to be generated when a new record is inserted into a table.
Often, we would like the value of the primary key field to be created automatically 
    every time a new record is inserted.
By default, the starting value for AUTO_INCREMENT is 1, and it will increment by 1 for each new record.
"UserID int NOT NULL AUTO_INCREMENT,
PRIMARY KEY (UserID)"
Auto-increment allows a unique number to be generated when a new record is inserted into a table.

//Using Constraints
"CREATE TABLE Users (
id int NOT NULL AUTO_INCREMENT,
username varchar(40) NOT NULL, 
password varchar(10) NOT NULL,
PRIMARY KEY(id)
);"
The following SQL enforces that the "id", "username", and "password" columns do not accept NULL values. 
    We also define the "id" column to be an auto-increment primary key field.
When inserting a new record into the Users table, it's not necessary to specify a value for the id column; 
    a unique new value will be added automatically.

//ALTER TABLE(column)
The ALTER TABLE command is used to add, delete, or modify columns in an existing table.
You would also use the ALTER TABLE command to add and drop various constraints on an existing table.
The following SQL code adds a new column named DateOfBirth ( table called People):
"ALTER TABLE People ADD DateOfBirth date;"
All rows will have the default value in the newly added column, which, in this case, is NULL.

//Dropping(column)
how to delete the column named DateOfBirth in the People table.
"ALTER TABLE People 
DROP COLUMN DateOfBirth;
SELECT * from People;"
To delete the entire table, use the DROP TABLE command:
DROP TABLE People;

//Renaming
//Rename column:
    The ALTER TABLE command is also used to rename columns:
    "ALTER TABLE People
    CHANGE FirstName name datatype;"
//Rename Tables
    "RENAME TABLE People TO Users;"
    This will rename the table People to Users.

//Views
    In SQL, a VIEW is a virtual table that is based on the result-set of an SQL statement.
    A view contains rows and columns, just like a real table. 
        The fields in a view are fields from one or more real tables in the database.
    Views allow us to:
        - Structure data in a way that users or classes of users find natural or intuitive.
        - Restrict access to the data in such a way that a user can see and (sometimes) modify exactly what they need and no more.
        - Summarize data from various tables and use it to generate reports.
    "CREATE VIEW view_name AS
    SELECT column_name(s)
    FROM table_name
    WHERE condition;"
    The SELECT query can be as complex as you need it to be. It can contain multiple JOINS and other commands.

    //Creating Views
    Consider the Employees table, which contains the following records:(create_view.png)
    Let's create a view that displays each employee's FirstName and Salary:
    "CREATE VIEW List AS
    SELECT FirstName, Salary
    FROM  Employees;"
    This would produce the following result:(create_view_result.png)
    視圖(view)始終顯示最新數據！每次用戶查詢視圖時，數據庫引擎都使用視圖的 SQL 語句重新創建數據。

    //Updating a View
    "CREATE OR REPLACE VIEW view_name AS
    SELECT column_name(s)
    FROM table_name
    WHERE condition;"
    //Drop view
    "DROP VIEW List;"
    It is sometimes easier to drop a table and recreate it instead of using the ALTER TABLE statement 
        to change the table’s definition.
*/

/*Connect db
$name = new PDO("dbprogram:dbname=database;host=server", 
username, password);
$name->query("SQL query");
EX:
# connect to world database on local server
$db = new PDO("mysql:dbname=world;host=localhost", "root", "");
$db->query("SELECT * FROM countries WHERE population > 100000000;");
// PDO database library allows you to connect to many 
        different database programs
//query function returns rows that match a query

//display content in query
$db = new PDO("mysql:dbname=world;host=localhost", "traveler", 
"packmybags");
$rows = $db->query("SELECT * FROM countries WHERE population > 
100000000;");
foreach ($rows as $row) {
do something with $row;
}
//• query returns all result rows
    • each row is an associative array of [column name -> value]
    • example: $row["population"] gives the value of 
        the population column
EX:
<?php
$db = new PDO("mysql:dbname=imdb_small", "root", "");
$rows = $db->query("SELECT * FROM actors WHERE last_name LIKE 
'Del%'");
foreach ($rows as $row) {
?>
<li> First name: <?= $row["first_name"] ?>,  //一定要加column name，不能只是$row
Last name: <?= $row["last_name"] ?> </li>   //一定要加column name，不能只是$row
<?php
}
?>

//PDO OBJECT METHODS
query(): performs a SQL SELECT query on the database
exec(): performs a SQL query that modifies the database (INSERT, DELETE, UPDATE, etc.)
getAttribute(),setAttribute(): get/set various DB connection properties
quote(): encodes a value for use within a query

//INSERTING & UPDATING DATA
EX:
$sql = "INSERT INTO users (name, password, email) VALUES ('Bart', 
'password', 'bart@fox.com')";
$effected_number_of_rows = $db->exec($sql);
print "Effected: $effected_number_of_rows rows";
$sql = "UPDATE users SET name='Lisa', email='lisa@fox.com' WHERE 
name='Bart'";
if($db->exec($sql)){
print "Database updated successfully";
}
//exec() returns the number of effected rows

//QUOTING(引用) VARIABLES
# get query parameter for name of movie
$title = $_GET["movietitle"];
$title = $db->quote($title);
$rows = $db->query("SELECT year FROM movies WHERE name = $title");
//•call PDO's quote method on any variable to be 
    inserted
//• quote escapes any illegal chars and surrounds the 
    value with ' quotes
//• prevents bugs and security problems in queries 
    containing user input

//EX:INSERT DATA FROM FORM
<?php
# data from posted "add user" form
$user = $_POST["user"];
$password = $_POST["password"];
$email = $_POST[" email "];
$db = new PDO("mysql:dbname=demo", "root", "");
$user = $db->quote($user);
$password = $db->quote($password);
$email = $db->quote($email);
$sql = "INSERT INTO users (name, password, email) VALUES ($user, 
$password, $email)";
if($db->exec($sql)){ print "user $user added successfully"; }
?>

//EX:USER/PASSWORD VALIDATION
<?php
# data from posted form
$user = $_POST["user"];
$password = $_POST["password"];
$authenticated = false;
$db = new PDO("mysql:dbname=demo", "root", "");
$user = $db->quote($user);
$password = $db->quote($password);
$rows = $db->query("SELECT * FROM users WHERE name=$user AND 
password=$password");
$authenticated = false;
if($rows->rowCount() > 0){
$authenticated = true;
} if($authenticated){
?>
<p><?= "$user logged in"?></p>
<?php } ?>

//EXCEPTIONS FOR ERRORS
$db = new PDO("mysql:dbname=imdb_small", "root", "");
$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$rows = $db->query("SEEELECT * FROM movies WHERE year = 2000");
//• using setAttribute, you can tell PDO to throw (generate) 
    a PDOException when an error occurs
//• the exceptions will appear as error messages on the 
    page output
//• you can catch the exception to gracefully handle the 
    error

//CATCHING AN EXCEPTION
try {
statement(s);
} catch (ExceptionType $name) {
code to handle the error;
}
//• a try/catch statement attempts to run some code, but 
if it throws a given kind of exception, the program 
jumps to the catch block and runs that code to handle 
the error
EX:
<?php
try {
$db = new PDO("mysql:dbname=imdb_small", "root", "");
$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$rows = $db->query("SEEELECT * FROM movies WHERE year = 2000");
foreach ($rows as $row) { ... }
} catch (PDOException $ex) {
?>
<p>Sorry, a database error occurred. Please try again later.</p>
<p>(Error details: <?= $ex->getMessage() ?>)</p>
<?php
}
?>

//LOADING LARGE SQL FILES INTO MYSQL
//• Create a new database first
//• Use command line (find the right folder)
//• mysql -u=username -p new_db_name < file.sql
//• In XAMPP, MySQL username: root, password: empty

//PHP – 使用PDO連資料庫遇到的query()、fatch()、fetchAll的問題
//http://jsnwork.kiiuo.com/archives/921/php-%E4%BD%BF%E7%94%A8pdo%E9%80%A3%E8%B3%87%E6%96%99%E5%BA%AB%E9%81%87%E5%88%B0%E7%9A%84query%E3%80%81fatch%E3%80%81fetchall%E7%9A%84%E5%95%8F%E9%A1%8C-2/


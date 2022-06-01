create database Employee;
-- Query OK, 1 row affected (0.01 sec)
use Employee;
-- Database changed
create table employee(Empid int,Name varchar(20),Age int,Gender varchar(10),City varchar (20),DOJ date,Salary int);
-- Query OK, 0 rows affected (0.04 sec)
create table Department (Did int,DName varchar(20));
-- Query OK, 0 rows affected (0.02 sec)
create table Project (Pid int,PName varchar(20),Location varchar(20));
-- Query OK, 0 rows affected (0.03 sec)
desc employee;
/*
+--------+-------------+------+-----+---------+-------+
| Field | Type | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| Empid | int | YES | | NULL | |
| Name | varchar(20) | YES | | NULL | |
| Age | int | YES | | NULL | |
| Gender | varchar(10) | YES | | NULL | |
| City | varchar(20) | YES | | NULL | |
| DOJ | date | YES | | NULL | |
| Salary | int | YES | | NULL | |
+--------+-------------+------+-----+---------+-------+
7 rows in set (0.01 sec)
*/
desc Department;
/*
+-------+-------------+------+-----+---------+-------+
| Field | Type | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| Did | int | YES | | NULL | |
| DName | varchar(20) | YES | | NULL | |
+-------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)
mysql> desc Project;
+----------+-------------+------+-----+---------+-------+
| Field | Type | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| Pid | int | YES | | NULL | |
| PName | varchar(20) | YES | | NULL | |
| Location | varchar(20) | YES | | NULL | |
+----------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)
*/
insert into employee values (1,'Disha',26,'Female','Varanasi','2012-04-26',55000);
-- Query OK, 1 row affected (0.01 sec)
insert into employee values (2,'Shivam',32,'Male','Delhi','2008-04-12',85000);
-- Query OK, 1 row affected (0.01 sec)
insert into employee values (3,'Ankush',28,'Male','Pune','2015-06-18',65000);
-- Query OK, 1 row affected (0.01 sec)
insert into employee values (4,'Esha',36,'Female','Jaipur','2009-07-08',120000);
-- Query OK, 1 row affected (0.02 sec)
insert into employee values (5,'Vikrant',29,'Male','Noida','2017-06-19',95000);
-- Query OK, 1 row affected (0.01 sec)
select * from employee;
/*
+-------+---------+------+--------+----------+------------+--------+
| Empid | Name | Age | Gender | City | DOJ | Salary |
+-------+---------+------+--------+----------+------------+--------+
| 1 | Disha | 26 | Female | Varanasi | 2012-04-26 | 55000 |
| 2 | Shivam | 32 | Male | Delhi | 2008-04-12 | 85000 |
| 3 | Ankush | 28 | Male | Pune | 2015-06-18 | 65000 |
| 4 | Esha | 36 | Female | Jaipur | 2009-07-08 | 120000 |
| 5 | Vikrant | 29 | Male | Noida | 2017-06-19 | 95000 |
+-------+---------+------+--------+----------+------------+--------+
5 rows in set (0.00 sec)
*/
insert into Department values(1, 'Marketing');
-- Query OK, 1 row affected (0.01 sec)
insert into Department values(2, 'Executive');
-- Query OK, 1 row affected (0.01 sec)
insert into Department values(2, 'Admin');
-- Query OK, 1 row affected (0.01 sec)
select * from Department;
/*
+------+-----------+
| Did | DName |
+------+-----------+
| 1 | Marketing |
| 2 | Executive |
| 2 | Admin |
+------+-----------+
3 rows in set (0.00 sec)
*/
insert into Project values (1,'Product Analysis','Noida');
-- Query OK, 1 row affected (0.01 sec)
insert into Project values (2,'Cloud marketing','Hyderabad');
-- Query OK, 1 row affected (0.01 sec)
insert into Project values (3,'AI chatbot','Jaipur');
-- Query OK, 1 row affected (0.02 sec)
select * from Project;
/*
+------+------------------+-----------+
| Pid | PName | Location |
+------+------------------+-----------+
| 1 | Product Analysis | Noida |
| 2 | Cloud marketing | Hyderabad |
| 3 | AI chatbot | Jaipur |
+------+------------------+-----------+
3 rows in set (0.00 sec)
*/

create database mydb;
-- Query OK, 1 row affected (0.02 sec)
use mydb;
-- Database changed
create table Department(did int primary key, dname varchar(20));
-- Query OK, 0 rows affected (0.05 sec)
create table Employee(empid int primary key auto_increment, ename varchar(20) not null, contactno int unique, salary int, did int, check (salary>15000), foreign key(did) references Department(did));
-- Query OK, 0 rows affected (0.06 sec)
desc Employee;
/*
+-----------+-------------+------+-----+---------+----------------+
| Field | Type | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+----------------+
| empid | int | NO | PRI | NULL | auto_increment |
| ename | varchar(20) | NO | | NULL | |
| contactno | int | YES | UNI | NULL | |
| salary | int | YES | | NULL | |
| did | int | YES | MUL | NULL | |
+-----------+-------------+------+-----+---------+----------------+
5 rows in set (0.01 sec)
*/
drop table employee;
-- Query OK, 0 rows affected (0.03 sec)
create table Employee(empid int primary key auto_increment, enamevarchar(20) not null, contactno int unique, salary int, did int, check (salary>15000), foreign key(did) references Department(did));
-- Query OK, 0 rows affected (0.05 sec)
desc Employee;
/*
+-----------+-------------+------+-----+---------+----------------+
| Field | Type | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+----------------+
| empid | int | NO | PRI | NULL | auto_increment |
| ename | varchar(20) | NO | | NULL | |
| contactno | int | YES | UNI | NULL | |
| salary | int | YES | | NULL | |
| did | int | YES | MUL | NULL | |
+-----------+-------------+------+-----+---------+----------------+
5 rows in set (0.00 sec)
*/
create table Project(Pid int primary key, Pname varchar(20), LocationId int);
-- Query OK, 0 rows affected (0.03 sec)
desc Project;
/*
+------------+-------------+------+-----+---------+-------+
| Field | Type | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| Pid | int | NO | PRI | NULL | |
| Pname | varchar(20) | YES | | NULL | |
| LocationId | int | YES | | NULL | |
+------------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)
*/
alter table Employee add Pid int;
-- Query OK, 0 rows affected (0.03 sec)
-- Records: 0 Duplicates: 0 Warnings: 0
desc Employee;
/*
+-----------+-------------+------+-----+---------+----------------+
| Field | Type | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+----------------+
| empid | int | NO | PRI | NULL | auto_increment |
| ename | varchar(20) | NO | | NULL | |
| contactno | int | YES | UNI | NULL | |
| salary | int | YES | | NULL | |
| did | int | YES | MUL | NULL | |
| Pid | int | YES | | NULL | |
+-----------+-------------+------+-----+---------+----------------+
6 rows in set (0.01 sec)
*/
alter table Employee add foreign key(Pid) references Project(Pid);
-- Query OK, 0 rows affected (0.09 sec)
-- Records: 0 Duplicates: 0 Warnings: 0
desc Employee;
/*
+-----------+-------------+------+-----+---------+----------------+
| Field | Type | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+----------------+
| empid | int | NO | PRI | NULL | auto_increment |
| ename | varchar(20) | NO | | NULL | |
| contactno | int | YES | UNI | NULL | |
| salary | int | YES | | NULL | |
| did | int | YES | MUL | NULL | |
| Pid | int | YES | MUL | NULL | |
+-----------+-------------+------+-----+---------+----------------+
6 rows in set (0.00 sec)
*/
alter table Project drop LocationId;
-- Query OK, 0 rows affected (0.03 sec)
-- Records: 0 Duplicates: 0 Warnings: 0
desc Project;
/*
+-------+-------------+------+-----+---------+-------+
| Field | Type | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| Pid | int | NO | PRI | NULL | |
| Pname | varchar(20) | YES | | NULL | |
+-------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)
*/
alter table Project modify Pname varchar(50);
-- Query OK, 0 rows affected (0.02 sec)
-- Records: 0 Duplicates: 0 Warnings: 0
desc Project;
/*
+-------+-------------+------+-----+---------+-------+
| Field | Type | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| Pid | int | NO | PRI | NULL | |
| Pname | varchar(50) | YES | | NULL | |
+-------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)
*/
create table Emp(empid int, name varchar(20), primary key(empid, name));
-- Query OK, 0 rows affected (0.03 sec)
desc Emp;
/*
+-------+-------------+------+-----+---------+-------+
| Field | Type | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| empid | int | NO | PRI | NULL | |
| name | varchar(20) | NO | PRI | NULL | |
+-------+-------------+------+-----+---------+-------+
2 rows in set (0.00 sec)
*/

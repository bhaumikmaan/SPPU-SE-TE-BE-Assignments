use practice;
-- Database changed

mysql> select *
    -> from employee;
-- +--------+------------+-----------+------------+------+---------+----------+-----------+
-- | emp_id | first_name | last_name | birth_date | sex  | salary  | super_id | branch_id |
-- +--------+------------+-----------+------------+------+---------+----------+-----------+
-- |    100 | David      | Wallace   | 1967-11-17 | M    |  250000 |     NULL |         1 |
-- |    101 | Jan        | Levinson  | 1961-05-11 | F    | 1100000 |      100 |         1 |
-- |    102 | Michael    | Scott     | 1964-03-15 | M    |   75000 |      100 |         2 |
-- |    103 | Angela     | Martin    | 1971-06-25 | F    |   63000 |      102 |         2 |
-- |    104 | Kelly      | Kapoor    | 1980-02-05 | F    |   55000 |      102 |         2 |
-- |    105 | Stanley    | Hudson    | 1958-02-19 | M    |   69000 |      102 |         2 |
-- |    106 | Jost       | Porter    | 1969-09-05 | M    |   78000 |      100 |         3 |
-- |    107 | Andy       | Bernad    | 1969-09-05 | M    |   65000 |      106 |         3 |
-- |    108 | Jim        | Halpert   | 1978-10-01 | M    |   71000 |      106 |         3 |
-- |    109 | Oscar      | Martinez  | 1968-02-19 | M    |   69000 |      106 |         3 |
-- |    110 | Kevin      | Malone    | 1978-02-19 | M    |   69000 |      106 |         3 |
-- +--------+------------+-----------+------------+------+---------+----------+-----------+
-- 11 rows in set (0.01 sec)

mysql> select * 
    -> from employee
    -> where branch_id = 2;
-- +--------+------------+-----------+------------+------+--------+----------+-----------+
-- | emp_id | first_name | last_name | birth_date | sex  | salary | super_id | branch_id |
-- +--------+------------+-----------+------------+------+--------+----------+-----------+
-- |    102 | Michael    | Scott     | 1964-03-15 | M    |  75000 |      100 |         2 |
-- |    103 | Angela     | Martin    | 1971-06-25 | F    |  63000 |      102 |         2 |
-- |    104 | Kelly      | Kapoor    | 1980-02-05 | F    |  55000 |      102 |         2 |
-- |    105 | Stanley    | Hudson    | 1958-02-19 | M    |  69000 |      102 |         2 |
-- +--------+------------+-----------+------------+------+--------+----------+-----------+
-- 4 rows in set (0.01 sec)

mysql> select emp_id, first_name, last_name, salary 
    -> from employee
    -> where sex = 'F';
-- +--------+------------+-----------+---------+
-- | emp_id | first_name | last_name | salary  |
-- +--------+------------+-----------+---------+
-- |    101 | Jan        | Levinson  | 1100000 |
-- |    103 | Angela     | Martin    |   63000 |
-- |    104 | Kelly      | Kapoor    |   55000 |
-- +--------+------------+-----------+---------+
-- 3 rows in set (0.00 sec)

mysql> select *
    -> from employee 
    -> where birth_date between '1950-01-01' and '1970-01-01';
-- +--------+------------+-----------+------------+------+---------+----------+-----------+
-- | emp_id | first_name | last_name | birth_date | sex  | salary  | super_id | branch_id |
-- +--------+------------+-----------+------------+------+---------+----------+-----------+
-- |    100 | David      | Wallace   | 1967-11-17 | M    |  250000 |     NULL |         1 |
-- |    101 | Jan        | Levinson  | 1961-05-11 | F    | 1100000 |      100 |         1 |
-- |    102 | Michael    | Scott     | 1964-03-15 | M    |   75000 |      100 |         2 |
-- |    105 | Stanley    | Hudson    | 1958-02-19 | M    |   69000 |      102 |         2 |
-- |    106 | Jost       | Porter    | 1969-09-05 | M    |   78000 |      100 |         3 |
-- |    107 | Andy       | Bernad    | 1969-09-05 | M    |   65000 |      106 |         3 |
-- |    109 | Oscar      | Martinez  | 1968-02-19 | M    |   69000 |      106 |         3 |
-- +--------+------------+-----------+------------+------+---------+----------+-----------+
-- 7 rows in set (0.00 sec)

mysql> select *
    -> from employee
    -> where first_name like 'A%';
-- +--------+------------+-----------+------------+------+--------+----------+-----------+
-- | emp_id | first_name | last_name | birth_date | sex  | salary | super_id | branch_id |
-- +--------+------------+-----------+------------+------+--------+----------+-----------+
-- |    103 | Angela     | Martin    | 1971-06-25 | F    |  63000 |      102 |         2 |
-- |    107 | Andy       | Bernad    | 1969-09-05 | M    |  65000 |      106 |         3 |
-- +--------+------------+-----------+------------+------+--------+----------+-----------+
-- 2 rows in set (0.01 sec)

mysql> select *
    -> from employee 
    -> where first_name like 'A%' or first_name like 'J%' and salary >80000;
-- +--------+------------+-----------+------------+------+---------+----------+-----------+
-- | emp_id | first_name | last_name | birth_date | sex  | salary  | super_id | branch_id |
-- +--------+------------+-----------+------------+------+---------+----------+-----------+
-- |    101 | Jan        | Levinson  | 1961-05-11 | F    | 1100000 |      100 |         1 |
-- |    103 | Angela     | Martin    | 1971-06-25 | F    |   63000 |      102 |         2 |
-- |    107 | Andy       | Bernad    | 1969-09-05 | M    |   65000 |      106 |         3 |
-- +--------+------------+-----------+------------+------+---------+----------+-----------+
-- 3 rows in set (0.00 sec)

mysql> select avg(salary) as AvgSalary
    -> from employee;
-- +-------------+
-- | AvgSalary   |
-- +-------------+
-- | 178545.4545 |
-- +-------------+
-- 1 row in set (0.00 sec)

mysql> select first_name, length(first_name) as Length
    -> from employee;
-- +------------+--------+
-- | first_name | Length |
-- +------------+--------+
-- | David      |      5 |
-- | Jan        |      3 |
-- | Michael    |      7 |
-- | Angela     |      6 |
-- | Kelly      |      5 |
-- | Stanley    |      7 |
-- | Jost       |      4 |
-- | Andy       |      4 |
-- | Jim        |      3 |
-- | Oscar      |      5 |
-- | Kevin      |      5 |
-- +------------+--------+
-- 11 rows in set (0.00 sec)

mysql> select emp_id, first_name, salary + 30000 as NewSalary 
    -> from employee
    -> where sex = 'M';
-- +--------+------------+-----------+
-- | emp_id | first_name | NewSalary |
-- +--------+------------+-----------+
-- |    100 | David      |    280000 |
-- |    102 | Michael    |    105000 |
-- |    105 | Stanley    |     99000 |
-- |    106 | Jost       |    108000 |
-- |    107 | Andy       |     95000 |
-- |    108 | Jim        |    101000 |
-- |    109 | Oscar      |     99000 |
-- |    110 | Kevin      |     99000 |
-- +--------+------------+-----------+
-- 8 rows in set (0.01 sec)

mysql> select count(emp_id) 
    -> from employee
    -> where sex = 'F';
-- +---------------+
-- | count(emp_id) |
-- +---------------+
-- |             3 |
-- +---------------+
-- 1 row in set (0.00 sec)

mysql> select * 
    -> from employee
    -> where salary > 90000
    -> order by salary;
-- +--------+------------+-----------+------------+------+---------+----------+-----------+
-- | emp_id | first_name | last_name | birth_date | sex  | salary  | super_id | branch_id |
-- +--------+------------+-----------+------------+------+---------+----------+-----------+
-- |    100 | David      | Wallace   | 1967-11-17 | M    |  250000 |     NULL |         1 |
-- |    101 | Jan        | Levinson  | 1961-05-11 | F    | 1100000 |      100 |         1 |
-- +--------+------------+-----------+------------+------+---------+----------+-----------+
-- 2 rows in set (0.00 sec)

mysql> select sex, count(sex)
    -> from employee
    -> group by sex;
-- +------+------------+
-- | sex  | count(sex) |
-- +------+------------+
-- | M    |          8 |
-- | F    |          3 |
-- +------+------------+
-- 2 rows in set (0.00 sec)

mysql> select emp_id, sum(total_sales)
    -> from Works_With
    -> group by emp_id;
-- +--------+------------------+
-- | emp_id | sum(total_sales) |
-- +--------+------------------+
-- |    102 |           282000 |
-- |    105 |           218000 |
-- |    107 |            31000 |
-- |    108 |            34500 |
-- +--------+------------------+
-- 4 rows in set (0.00 sec)

mysql> select first_name, emp_id 
    -> from employee 
    -> where salary > (select avg(salary) from employee);
-- +------------+--------+
-- | first_name | emp_id |
-- +------------+--------+
-- | David      |    100 |
-- | Jan        |    101 |
-- +------------+--------+
-- 2 rows in set (0.00 sec)

mysql> select emp_id, first_name, last_name
    -> from employee 
    -> where salary > (select avg(salary) * 2 from employee) or last_name like 'S%';
-- +--------+------------+-----------+
-- | emp_id | first_name | last_name |
-- +--------+------------+-----------+
-- |    101 | Jan        | Levinson  |
-- |    102 | Michael    | Scott     |
-- +--------+------------+-----------+
-- 2 rows in set (0.01 sec)

mysql> select *
    -> from employee
    -> where salary >= all(select salary from employee);
-- +--------+------------+-----------+------------+------+---------+----------+-----------+
-- | emp_id | first_name | last_name | birth_date | sex  | salary  | super_id | branch_id |
-- +--------+------------+-----------+------------+------+---------+----------+-----------+
-- |    101 | Jan        | Levinson  | 1961-05-11 | F    | 1100000 |      100 |         1 |
-- +--------+------------+-----------+------------+------+---------+----------+-----------+
-- 1 row in set (0.00 sec)

mysql> select * 
    -> from employee natural join branch
    -> where salary >= 80000;
-- +-----------+--------+------------+-----------+------------+------+---------+----------+-------------+--------+----------------+
-- | branch_id | emp_id | first_name | last_name | birth_date | sex  | salary  | super_id | branch_name | mgr_id | mgr_start_date |
-- +-----------+--------+------------+-----------+------------+------+---------+----------+-------------+--------+----------------+
-- |         1 |    100 | David      | Wallace   | 1967-11-17 | M    |  250000 |     NULL | Corporate   |    100 | 2006-02-09     |
-- |         1 |    101 | Jan        | Levinson  | 1961-05-11 | F    | 1100000 |      100 | Corporate   |    100 | 2006-02-09     |
-- +-----------+--------+------------+-----------+------------+------+---------+----------+-------------+--------+----------------+
-- 2 rows in set (0.00 sec

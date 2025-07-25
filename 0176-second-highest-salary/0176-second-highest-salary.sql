# Write your MySQL query statement below
-- select distinct salary as SecondHighestSalary from employee order by salary desc limit 1 offset 1;

select max(salary) as SecondHighestSalary
from employee
where salary < (select max(salary) from employee);
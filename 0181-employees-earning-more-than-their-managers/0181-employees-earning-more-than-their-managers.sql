# Write your MySQL query statement below

-- select e1.name, e1.salary as salary, e2.name as managerName, e2.salary as managerSalary
-- from employee e1
-- join employee e2
-- on e1.managerId = e2.id AND e1.salary > e2.salary;

select e1.name as Employee
from employee e1
join employee e2
on e1.managerId = e2.id AND e1.salary > e2.salary;
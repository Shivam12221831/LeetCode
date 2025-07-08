CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      with CTE as (select id, salary, dense_rank() over(order by salary desc) as rnk from employee)
      select distinct salary as getNthHighestSalary from CTE where rnk = N
  );
END
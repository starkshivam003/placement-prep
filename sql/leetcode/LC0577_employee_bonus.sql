# Write your MySQL query statement below
SELECT e.name AS name,b.bonus AS bonus FROM Employee e LEFT JOIN Bonus b ON e.empId=B.empId WHERE b.bonus<1000 OR b.bonus IS NULL;

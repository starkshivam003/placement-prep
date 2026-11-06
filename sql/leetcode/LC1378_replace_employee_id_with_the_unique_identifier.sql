# Write your MySQL query statement below
SELECT u.unique_id AS unique_id, e.name as name FROM Employees e LEFT JOIN EmployeeUNI u ON e.id=u.id ORDER BY e.name ASC;

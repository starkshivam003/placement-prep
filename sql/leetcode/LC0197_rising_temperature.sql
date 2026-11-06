# Write your MySQL query statement below
SELECT t.id AS id FROM Weather t INNER JOIN Weather y ON DATEDIFF(t.recordDate, y.recordDate) = 1 WHERE t.temperature>y.temperature;

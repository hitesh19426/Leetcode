# Write your MySQL query statement below
SELECT
    e.name as 'Employee'
FROM
    Employee AS e
Join
    Employee AS m
ON
    (e.managerId = m.id and e.salary > m.salary);
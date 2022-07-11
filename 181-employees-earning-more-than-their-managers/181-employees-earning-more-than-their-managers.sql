# Write your MySQL query statement below
SELECT
    e.name as 'Employee'
FROM
    Employee AS e Join Employee AS m
ON
    e.managerId = m.id
WHERE
    e.salary > m.salary;
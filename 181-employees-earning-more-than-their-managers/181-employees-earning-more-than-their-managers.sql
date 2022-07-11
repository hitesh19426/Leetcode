# Write your MySQL query statement below
SELECT
    e.name as 'Employee'
FROM
    Employee AS e,
    Employee AS m
WHERE
    (e.managerId = m.id and e.salary > m.salary);
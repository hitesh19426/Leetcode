# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE p1
FROM Person as P1 JOIN Person as P2 ON (p1.email = p2.email)
WHERE p1.id > p2.id

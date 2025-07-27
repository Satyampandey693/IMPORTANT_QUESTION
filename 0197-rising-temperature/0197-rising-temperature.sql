# Write your MySQL query statement below
-- select id from Weather as w where w.temperature>(select temperature from Weather where recordDate =DATE_SUB(w.recordDate,INTERVAL 1 Day) );
# Write your MySQL query statement below
SELECT W1.id as Id
FROM Weather W1
INNER JOIN Weather W2
WHERE W1.recordDate = DATE_ADD(W2.recordDate, INTERVAL 1 DAY)
     AND W1.temperature > W2.temperature; 
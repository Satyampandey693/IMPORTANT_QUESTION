# Write your MySQL query statement below
select id from Weather as w where w.temperature>(select temperature from Weather where recordDate =DATE_SUB(w.recordDate,INTERVAL 1 Day) );
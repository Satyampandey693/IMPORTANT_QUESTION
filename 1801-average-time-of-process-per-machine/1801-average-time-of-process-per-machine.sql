# Write your MySQL query statement below
SELECT 
    p.machine_id,
    ROUND(AVG(p.task_time), 3) AS processing_time
FROM (
    SELECT 
        a1.machine_id, 
        (a2.timestamp-a1.timestamp) AS task_time
    FROM Activity a1
    INNER JOIN Activity a2 
        ON a1.process_id = a2.process_id and a1.machine_id = a2.machine_id
    WHERE 
        a1.activity_type = 'start' 
        AND a2.activity_type = 'end'
) AS p
GROUP BY p.machine_id;

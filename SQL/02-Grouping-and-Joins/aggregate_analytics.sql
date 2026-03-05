-- AGGREGATE FUNCTIONS
-- Comprehensive statistics for salary 
SELECT MAX(salary) AS Max_Sal, MIN(salary) AS Min_Sal, 
       ROUND(AVG(salary), 2) AS Avg_Sal, SUM(salary) AS Total_Sal, 
       COUNT(*) AS Total_Rows
FROM employees;
 
-- DATA GROUPING AND HAVING CLAUSE
-- Grouping by department and filtering based on group average 
SELECT department_id, job_id, ROUND(AVG(salary)) AS Avg_Dept_Sal
FROM employees
GROUP BY department_id, job_id
HAVING AVG(salary) >= 10000
ORDER BY department_id;

-- NESTED SUBQUERIES
-- Find employees earning more than 'Abel' 
SELECT * FROM employees 
WHERE salary >= (SELECT salary FROM employees WHERE last_name = 'Abel') 
AND last_name <> 'Abel';

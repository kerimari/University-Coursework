-- GROUP FUNCTIONS AND STATISTICS [cite: 53-56]
-- Calculating Min, Max, Avg and Count (Excluding/Including NULLs)
SELECT MAX(salary), MIN(salary), ROUND(AVG(salary), 2), COUNT(*) FROM employees;

-- DATA GROUPING AND HAVING CLAUSE [cite: 57, 62]
-- Group by Department and filter groups with Avg Salary >= 10000
SELECT department_id, job_id, ROUND(AVG(salary))
FROM employees
GROUP BY department_id, job_id
HAVING AVG(salary) >= 10000
ORDER BY department_id;

-- SUBQUERIES (WEEK 06) [cite: 79-84]
-- Find employees earning more than a specific person (e.g., Abel)
SELECT * FROM employees 
WHERE salary >= (SELECT salary FROM employees WHERE last_name = 'Abel') 
AND last_name <> 'Abel';

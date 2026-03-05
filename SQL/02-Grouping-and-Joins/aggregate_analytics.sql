-- ==========================================
-- AGGREGATE FUNCTIONS & GROUPING
-- ==========================================

-- Group by department and filter groups with average salary >= 10000 [cite: 57, 62]
SELECT department_id, MAX(salary), MIN(salary), ROUND(AVG(salary))
FROM employees
GROUP BY department_id
HAVING AVG(salary) >= 10000;

-- ==========================================
-- TABLE JOINS
-- ==========================================

-- Natural Join: Joins tables based on columns with the same name [cite: 71]
SELECT department_id, department_name, city FROM departments NATURAL JOIN locations;

-- Join with ON clause: Explicitly defining the joining columns [cite: 73]
SELECT e.employee_id, d.department_name, l.city 
FROM employees e 
JOIN departments d ON (e.department_id = d.department_id)
JOIN locations l ON (d.location_id = l.location_id);

-- ==========================================
-- SET OPERATORS
-- ==========================================

-- INTERSECT: Returns common records between two queries [cite: 89]
SELECT employee_id FROM employees
INTERSECT
SELECT employee_id FROM job_history;

-- MINUS: Returns records present in the first query but not in the second [cite: 90]
SELECT employee_id FROM employees
MINUS
SELECT employee_id FROM job_history;

-- TABLE RELATIONSHIPS (JOINS)
-- Natural Join: Automatic matching based on same column names 
SELECT department_id, department_name, city FROM departments NATURAL JOIN locations;

-- Multi-table Join using ON clause for clarity 
SELECT e.employee_id, d.department_name, l.city 
FROM employees e 
JOIN departments d ON (e.department_id = d.department_id)
JOIN locations l ON (d.location_id = l.location_id)
WHERE l.city LIKE 'S%';

-- SET OPERATORS
-- INTERSECT: Common records between two tables 
SELECT employee_id FROM employees
INTERSECT
SELECT employee_id FROM job_history;

-- MINUS: Records in the first table but not the second 
SELECT employee_id FROM employees
MINUS
SELECT employee_id FROM job_history;

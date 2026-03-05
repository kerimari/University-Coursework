-- TABLE JOINS (WEEK 05) [cite: 71-77]
-- Natural Join, Using and ON clauses
SELECT department_id, department_name, city FROM departments NATURAL JOIN locations;

-- Multi-table Join with Aliases and Filtering
SELECT e.employee_id, d.department_name, l.city 
FROM employees e 
JOIN departments d ON (e.department_id = d.department_id)
JOIN locations l ON (d.location_id = l.location_id)
WHERE l.city LIKE 'S%';

-- SET OPERATORS (UNIT 9) [cite: 89-93]
-- INTERSECT: Employees who had role changes (Present in both tables)
SELECT employee_id FROM employees INTERSECT SELECT employee_id FROM job_history;

-- MINUS: Employees who never changed their roles
SELECT employee_id FROM employees MINUS SELECT employee_id FROM job_history;

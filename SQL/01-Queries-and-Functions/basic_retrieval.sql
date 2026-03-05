-- BASIC SELECTION AND FILTERING
-- Retrieve all columns from the employees table 
SELECT * FROM employees;
 
-- Filter by specific department ID 
SELECT * FROM employees WHERE department_id = 90;

-- Using Column Aliases and arithmetic operations 
SELECT last_name, salary, salary + 300 AS "New Salary" FROM employees;

-- String Concatenation: Combining name and job title 
SELECT last_name || ' is a ' || job_id AS "Employees" FROM employees;

-- Display unique values (removes duplicates) 
SELECT DISTINCT location_id FROM departments;

-- LOGICAL OPERATORS AND PATTERN MATCHING
-- Filtering with BETWEEN and IN 
SELECT * FROM employees WHERE salary BETWEEN 2500 AND 3500;
SELECT * FROM employees WHERE manager_id IN (100, 101, 201, 123);

-- Pattern matching with LIKE (Case-insensitive approach) 
SELECT * FROM employees WHERE UPPER(first_name) LIKE 'S%';

-- DYNAMIC FILTERING (USER INPUT)
-- Prompting user for input during execution 
ACCEPT employee_num PROMPT 'Please type an employee id:';
SELECT * FROM employees WHERE employee_id = &employee_num;
UNDEFINE employee_num;

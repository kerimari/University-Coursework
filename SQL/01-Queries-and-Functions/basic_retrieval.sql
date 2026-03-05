-- BASIC SELECTION AND FILTERING (WEEK 01-02)
-- Retrieve everything from employees table
SELECT * FROM employees;

-- Filter by specific department
SELECT * FROM employees WHERE department_id = 90;

-- Using Column Aliases and Concatenation
SELECT last_name, salary, salary + 300 AS "New Salary" FROM employees;
SELECT last_name || ' is a ' || job_id AS "Employee Info" FROM employees;

-- Unique values and Table Structure
SELECT DISTINCT location_id FROM departments;
DESC employees;

-- COMPARISON AND LOGICAL OPERATORS (WEEK 03)
SELECT * FROM employees WHERE salary BETWEEN 2500 AND 3500;
SELECT * FROM employees WHERE manager_id IN (100, 101, 201, 123);
SELECT * FROM employees WHERE first_name LIKE 'S%'; -- Starts with 'S'

-- DYNAMIC FILTERING WITH SUBSTITUTION VARIABLES
-- Prompt user for input and define variables
ACCEPT employee_num PROMPT 'Please type an employee id:';
SELECT * FROM employees WHERE employee_id = &employee_num;
UNDEFINE employee_num;

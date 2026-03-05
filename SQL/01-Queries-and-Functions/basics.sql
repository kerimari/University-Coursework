-- ==========================================
-- BASIC SELECTION AND FILTERING
-- ==========================================

-- Retrieve all columns from the employees table
SELECT * FROM employees;

-- Filter employees by a specific department ID
SELECT * FROM employees WHERE department_id = 90;

-- Using Column Aliases and arithmetic operations
SELECT last_name, salary, salary + 300 AS "New Salary" FROM employees;

-- Display unique location IDs (removes duplicates)
SELECT DISTINCT location_id FROM departments;

-- Display table structure and column attributes
DESC employees;

-- ==========================================
-- SINGLE-ROW FUNCTIONS & FORMATTING
-- ==========================================

-- Get the current system date and time from the DUAL table
SELECT sysdate FROM dual;

-- Substring function: Start at index 2 and take 3 characters
SELECT substr('ASKIN', 2, 3) FROM dual;

-- Rounding the number of days between two dates
SELECT last_name, ROUND(sysdate - hire_date) AS days FROM employees;

-- Handling NULL values: Replace NULL with 0 for calculations
SELECT last_name, salary, NVL(commission_pct, 0) FROM employees;

-- Conditional Logic using CASE-WHEN (Similar to switch-case)
SELECT last_name, salary,
  CASE 
    WHEN salary < 5000 THEN 'Low'
    WHEN salary < 10000 THEN 'Medium'
    ELSE 'Excellent'
  END AS "Qualified Salary"
FROM employees;

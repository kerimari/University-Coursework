-- DATA FORMATTING AND FUNCTIONS (WEEK 04)
-- Custom Date Formatting [cite: 13, 14, 40]
ALTER SESSION SET nls_date_format = 'DD.MM.YYYY';
SELECT sysdate FROM dual;
SELECT last_name, TO_CHAR(hire_date, 'fmMM/DD/YYYY') AS "Month Hired" FROM employees;

-- Numeric and Currency Formatting [cite: 38, 44]
-- Rounding worked days and currency formatting with 'L' for local symbol
SELECT last_name, ROUND(sysdate - hire_date) AS days FROM employees;
SELECT last_name, TO_CHAR(salary, '$99,999.00') AS Fmt_Salary FROM employees;

-- NULL HANDLING AND CONDITIONAL LOGIC [cite: 49, 51]
-- Replace NULL commission with 0 for calculations
SELECT last_name, salary, NVL(commission_pct, 0) FROM employees;

-- Advanced Logic: Case-When (Switch-Case equivalent) [cite: 52]
SELECT last_name, salary,
  CASE 
    WHEN salary < 5000 THEN 'Low'
    WHEN salary < 10000 THEN 'Medium'
    WHEN salary <= 17000 THEN 'Good'
    ELSE 'Excellent' 
  END AS "Qualified Salary"
FROM employees;

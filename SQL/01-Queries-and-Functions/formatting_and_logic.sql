-- DATE AND NUMERIC FORMATTING
-- Set custom session date format [cite: 13]
ALTER SESSION SET nls_date_format = 'DD.MM.YYYY';

-- Advanced formatting using TO_CHAR [cite: 40, 44]
SELECT last_name, TO_CHAR(hire_date, 'fmMM/DD/YYYY') AS "Month Hired" FROM employees;
SELECT last_name, TO_CHAR(salary, '$99,999.00') AS Fmt_Salary FROM employees;

-- DATE ARITHMETIC
-- Rounding worked days and weeks since hire date [cite: 38]
SELECT last_name, ROUND(sysdate - hire_date) AS days, 
       ROUND((sysdate - hire_date) / 7) AS weeks 
FROM employees ORDER BY days DESC;

-- NULL HANDLING AND CONDITIONAL LOGIC
-- Replace NULL values with 0 for accurate calculations [cite: 49]
SELECT last_name, salary, NVL(commission_pct, 0) AS Comm_Pct,
       salary * 12 + (salary * 12 * NVL(commission_pct, 0)) AS Annual_Salary
FROM employees;

-- CASE-WHEN Logic (Switch-Case equivalent) [cite: 51]
SELECT last_name, salary,
  CASE 
    WHEN salary < 5000 THEN 'Low'
    WHEN salary < 10000 THEN 'Medium'
    WHEN salary <= 17000 THEN 'Good'
    ELSE 'Excellent' 
  END AS "Qualified Salary"
FROM employees;

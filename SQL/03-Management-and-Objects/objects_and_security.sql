-- DATA DEFINITION (DDL) & DATA MANIPULATION (DML) [cite: 104, 136]
-- Create empty table and set to READ ONLY
CREATE TABLE sales_reps AS SELECT employee_id id, last_name lname FROM employees WHERE 1=2;
ALTER TABLE sales_reps READ ONLY;

-- ADVANCED DATA SYNCHRONIZATION (MERGE) [cite: 272-278]
-- Sync copy_emp3 with employees: Update if matched, Insert if not
MERGE INTO copy_emp3 c USING (SELECT * FROM employees) e
ON (c.employee_id = e.employee_id)
WHEN MATCHED THEN UPDATE SET c.salary = e.salary
WHEN NOT MATCHED THEN INSERT VALUES (e.employee_id, e.first_name, e.last_name, e.salary);

-- CONDITIONAL MULTI-INSERT [cite: 260-261]
-- Distribute data into different tables based on salary criteria
INSERT FIRST 
  WHEN salary < 5000 THEN INTO sal_low VALUES (employee_id, last_name, salary)
  WHEN salary BETWEEN 5000 AND 10000 THEN INTO sal_mid VALUES (employee_id, last_name, salary)
  ELSE INTO sal_high VALUES (employee_id, last_name, salary)
SELECT employee_id, last_name, salary FROM employees;

-- PERMANENT DELETION (TRUNCATE) AND COMMIT [cite: 271, 279]
TRUNCATE TABLE copy_emp3; -- Non-rollbackable delete
COMMIT;

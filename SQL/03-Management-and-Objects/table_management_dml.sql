-- TABLE MANAGEMENT (DDL & DML)
-- Creating a table structure from existing data (Empty) 
CREATE TABLE sales_reps AS 
SELECT employee_id id, last_name lname, salary sal FROM employees WHERE 1=2;
 
-- DATA SYNCHRONIZATION (MERGE)
-- Conditional update or insert 
MERGE INTO sales_reps c 
USING (SELECT * FROM employees) e
ON (c.id = e.employee_id)
WHEN MATCHED THEN 
  UPDATE SET c.sal = e.salary
WHEN NOT MATCHED THEN 
  INSERT (id, lname, sal) VALUES (e.employee_id, e.last_name, e.salary);

-- CONDITIONAL MULTI-INSERT
-- Distributing data into separate tables in one go 
INSERT FIRST 
  WHEN salary < 5000 THEN INTO sal_low VALUES (employee_id, last_name, salary)
  WHEN salary BETWEEN 5000 AND 10000 THEN INTO sal_mid VALUES (employee_id, last_name, salary)
  ELSE INTO sal_high VALUES (employee_id, last_name, salary)
SELECT employee_id, last_name, salary FROM employees;

-- Permanent data cleanup 
TRUNCATE TABLE sales_reps;
COMMIT;

-- DATABASE OBJECTS
-- Create a View for filtered data access 
CREATE OR REPLACE VIEW salvu50 AS 
SELECT employee_id id_number, first_name || ' ' || last_name name, salary * 12 ann_salary 
FROM employees WHERE department_id = 50;
 
-- Performance and Automation: Index and Sequence 
CREATE SEQUENCE emp_seq START WITH 1 INCREMENT BY 1;
CREATE INDEX indx_soyad ON employees (last_name);
CREATE SYNONYM dptb FOR departments; -- Alias for shorter queries 

-- SECURITY AND PRIVILEGES
-- User and Role Management 
CREATE USER demo IDENTIFIED BY demo;
CREATE ROLE developer;
GRANT create session, create table, create view TO developer;
GRANT developer TO demo;

-- Access Control 
GRANT SELECT ON hr.employees TO demo;
REVOKE SELECT, INSERT ON hr.departments FROM demo;

-- RECOVERY AND CATALOG
-- Recovering a dropped table using Flashback 
SELECT original_name, operation FROM recyclebin;
FLASHBACK TABLE dept TO BEFORE DROP;

-- ==========================================
-- DDL & DML OPERATIONS
-- ==========================================

-- Create a new table based on an existing table structure (empty table) [cite: 104, 105]
CREATE TABLE sales_reps AS 
SELECT employee_id AS id, last_name AS lname, salary AS sal 
FROM employees WHERE 1=2;

-- Permanently save changes to the database [cite: 99, 123]
COMMIT;

-- ==========================================
-- DATABASE OBJECTS (VIEW, INDEX, SEQUENCE)
-- ==========================================

-- Create a Virtual Table (View) for specific data access [cite: 140, 142]
CREATE OR REPLACE VIEW salvu50 AS 
SELECT employee_id, last_name, salary FROM employees WHERE department_id = 50;

-- Create an Index to optimize search performance [cite: 230]
CREATE INDEX indx_soyad ON employees (last_name);

-- ==========================================
-- DATABASE SECURITY & PRIVILEGES
-- ==========================================

-- Create a new user with a password [cite: 159]
CREATE USER demo IDENTIFIED BY demo;

-- Granting specific system privileges to a user [cite: 160, 161]
GRANT CREATE SESSION, CREATE TABLE TO demo;

-- Revoking previously granted object privileges [cite: 180]
REVOKE SELECT, INSERT ON hr.departments FROM demo;

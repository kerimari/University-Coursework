# SQL & Database Management Coursework

This directory contains a structured collection of SQL scripts developed during my undergraduate coursework. The focus is on **Oracle SQL**, covering a progression from basic data retrieval to advanced database administration and security.

🚀 Coursework Structure

The project is organized into three modules, each containing specialized scripts:

| Module | Folder | File | Key Topics |
| :--- | :--- | :--- | :--- |
| **01** | **Queries & Functions** | [basic_retrieval.sql](./01-Queries-and-Functions/basic_retrieval.sql) | SELECT, WHERE, LIKE, Substitution Variables (&) |
| | | [formatting_and_logic.sql](./01-Queries-and-Functions/formatting_and_logic.sql) | TO_CHAR, NVL, CASE-WHEN, Date Arithmetic |
| **02** | **Grouping & Joins** | [aggregate_analytics.sql](./02-Grouping-and-Joins/aggregate_analytics.sql) | GROUP BY, HAVING, Subqueries, AVG/SUM/COUNT |
| | | [joins_and_sets.sql](./02-Grouping-and-Joins/joins_and_sets.sql) | Natural Join, ON/USING Clauses, UNION, MINUS |
| **03** | **Management & Objects** | [table_management_dml.sql](./03-Management-and-Objects/table_management_dml.sql) | DDL/DML, MERGE, Conditional Multi-Insert |
| | | [objects_and_security.sql](./03-Management-and-Objects/objects_and_security.sql) | Views, Indexes, Sequences, GRANT/REVOKE, Flashback |

🛠 Technical Highlights

* [cite_start]**Advanced Data Sync:** Implementation of the `MERGE` statement to synchronize data between tables [cite: 272-278].
* [cite_start]**Relational Logic:** Mastery of complex joins and set operators (`INTERSECT`, `MINUS`) for deep data analysis[cite: 71, 89, 90].
* [cite_start]**Conditional Operations:** Efficient data distribution using `INSERT FIRST` for multi-table inserts based on logical conditions [cite: 260-261].
* [cite_start]**Database Administration:** Management of user roles, privileges, and object security[cite: 160, 180].
* [cite_start]**System Recovery:** Utilizing `FLASHBACK` and `RECYCLEBIN` for database maintenance and recovery[cite: 204, 205].

⚙️ Environment

* [cite_start]**Database Engine:** Oracle SQL (Express Edition) [cite: 13, 153]
* [cite_start]**Management Tools:** DBeaver / Oracle SQL Developer [cite: 1, 152]
* **Techniques:** PL/SQL Basics, DDL (Data Definition), DML (Data Manipulation), DCL (Data Control)

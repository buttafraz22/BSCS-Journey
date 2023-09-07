/*DB Lab Tasks*/
Use[northwind]
SELECT TOP(5) [RegNo],[FirstName],[LastName],[GPA]
FROM [northwind].[dbo].[student]
WHERE FirstName LIKE '%r';

SELECT *
FROM student;

SELECT FirstName
FROM student;

SELECT *
FROM student
WHERE GPA <= 3.5;

SELECT *
FROM student
WHERE GPA > 3.5 OR GPA <= 3.5;

SELECT CONCAT([FirstName],' ',[LastName]) AS [COMPLETE NAME]
FROM student;

SELECT DISTINCT TOP (3)[FirstName]
FROM  student;

SELECT ([GPA] * 3) AS [Output]
FROM student;

SELECT *
FROM [Products]
WHERE ProductName LIKE 'A%';

SELECT *
FROM [Products]
WHERE ProductName = 'Aniseed Syrup'

SELECT *
FROM [Products]
WHERE UnitPrice > 5.0 AND UnitsInStock > 30;

SELECT *
FROM [Products]
WHERE UnitPrice > 19.0 OR UnitsInStock > 30;

SELECT *
FROM [Products]
WHERE NOT CategoryID > (5) OR UnitPrice > 21.35;

SELECT * 
From Products
WHERE ProductName LIKE 'T%'
ORDER BY  UnitsInStock ASC;

SELECT * 
From Products
--WHERE ProductName LIKE 'T%'
ORDER BY  ProductName DESC;

SELECT *
From Products
ORDER BY ProductID ASC,UnitsOnOrder DESC;

SELECT TOP(10) *
FROM Products
ORDER BY  ProductName DESC;

SELECT TOP(10) *
FROM Products
ORDER BY  QuantityPerUnit ASC;

SELECT TOP(10) *
FROM Products
ORDER BY  ReorderLevel ASC;


USE [northwind]

-- Self Join
SELECT O.OrderID, OD.OrderID
FROM Orders O, Orders OD

-- Equi join
SELECT *
FROM Orders O
JOIN [Order Details] OD
ON OD.OrderID = O.OrderID;

-- Cross Join two different tables
SELECT *
FROM [Orders] OD
CROSS JOIN [Order Details];

-- Inner join
SELECT *
FROM Orders O
INNER JOIN [Order Details] OD
ON OD.OrderID = O.OrderID;

-- Left Outer Join
SELECT C.City,O.OrderDate
FROM Customers C
LEFT OUTER JOIN Orders O
ON C.CustomerID = O.CustomerID;

-- Right Outer Join
SELECT C.City,O.OrderDate
FROM Customers C
RIGHT OUTER JOIN Orders O
ON C.CustomerID = O.CustomerID;

-- Task 2: Difference between Cross join and Self Cross join
-- Self cross join
SELECT *
FROM [Order Details] OD
CROSS JOIN [Order Details];

-- cross join
SELECT *
FROM [Orders] OD
CROSS JOIN [Order Details];

-- Task 3:  Advanced Tasks

-- Report all customers and their orders, who placed no orders.
SELECT C.CustomerID,O.OrderID,O.OrderDate
FROM Customers C
JOIN Orders O
ON O.CustomerID = C.CustomerID;


-- Generate 5 copies of each employee.
SELECT EmployeeID,FirstName,LastName
FROM Employees
CROSS JOIN (SELECT 1 as tb1 UNION ALL SELECT 2 as tb1
UNION ALL SELECT 3 as tb1
UNION ALL SELECT 4 as tb1 
UNION ALL SELECT 5 as tb1 ) AS tb1;

-- 	Report the total orders of each customer. (customerID, totalorders)
SELECT O.CustomerID,COUNT(O.CustomerID) totalOrders
FROM Orders O
GROUP BY O.CustomerID

-- 	Write a query that returns a row for each employee and day in the range 04-07-1996 through 04-08-1997.
SELECT E.EmployeeID,E.HireDate
FROM Employees E
WHERE E.HireDate BETWEEN CONVERT(datetime,'1996-07-04') AND CONVERT(datetime,'1997-08-04');

-- Return US customers, and for each customer return the total number of orders and total quantities. (CustomerID, Totalorders, totalquantity)
SELECT C.CustomerID,COUNT(O.OrderID) 'Totalorders',SUM(OD.Quantity) 'totalquantity'
FROM Customers C
JOIN Orders O
ON C.CustomerID = O.CustomerID
JOIN [Order Details] OD
ON O.OrderID = OD.OrderID
GROUP BY C.CustomerID,O.OrderID,OD.OrderID

-- Write a query that returns all customers in the output, but matches them with their respective orders 
-- only if they were placed on July 04,1997. (CustomerID, CompanyName, OrderID, Orderdate)

SELECT C.CustomerID,C.CompanyName,O.OrderID,O.OrderDate
FROM Customers C
JOIN Orders O
ON C.CustomerID = O.CustomerID
GROUP BY OrderID,OrderDate,C.CustomerID,C.CompanyName
HAVING OrderDate = CONVERT(datetime,'1997-07-04')

-- Are there any employees who are older than their managers?
SELECT CONCAT(E.FirstName,' ',E.LastName) Employees
FROM Employees E
JOIN Employees EC
ON EC.BirthDate > E.BirthDate AND EC.Title LIKE '%Manager' AND E.Title NOT LIKE '%President%'

-- List that names of those employees and their ages. (EmployeeName, Age, Manager Age)
SELECT CONCAT(E.FirstName,' ',E.LastName) EmployeeName, DATEDIFF(year,E.BirthDate,GETDATE()) Age, DATEDIFF(year,EC.BirthDate,GETDATE()) 'Manager Age'
FROM Employees E
JOIN Employees EC
ON EC.BirthDate > E.BirthDate AND EC.Title LIKE '%Manager' AND E.Title NOT LIKE '%President%'
 
-- List the names of products which were ordered on 8th August 1997. (ProductName, OrderDate)
SELECT P.ProductName ProductName, OrderDate
FROM Products P
JOIN [Order Details] OD
ON OD.ProductID = P.ProductID
JOIN Orders O
ON O.OrderID = OD.OrderID
GROUP BY OrderDate,P.ProductName
HAVING OrderDate = '1997-08-08'

-- List the addresses, cities, countries of all orders which were serviced by Anne and were shipped late. (Address, City, Country)
SELECT O.ShipAddress 'Address', O.ShipCity City, O.ShipCountry Country
FROM Orders O
JOIN Employees E
ON O.EmployeeID = E.EmployeeID AND E.FirstName = 'Anne'
GROUP BY O.ShippedDate,O.RequiredDate,O.ShipAddress,O.ShipCity,O.ShipCountry
HAVING O.ShippedDate > O.RequiredDate

-- List all countries to which beverages have been shipped. (Country)
SELECT O.ShipCountry
FROM Orders O
JOIN [Order Details] OD
ON OD.OrderID = O.OrderID
JOIN Products P
ON OD.ProductID = P.ProductID
JOIN Categories C
ON C.CategoryID = P.CategoryID AND C.CategoryName = 'Beverages'
GROUP BY O.ShipCountry
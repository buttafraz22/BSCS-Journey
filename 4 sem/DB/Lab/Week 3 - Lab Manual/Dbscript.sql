-- TASK 1: Write a query to report orders which were delayed shipped.
SELECT *
FROM Orders
WHERE ShippedDate > RequiredDate;

--Task 2: Our employees belong to how many countries. List the names.
SELECT DISTINCT(Country)
FROM Employees;

-- Task 3:  Is there any employee who is not accountable?
SELECT CONCAT(FirstName,' ',LastName)
FROM Employees
WHERE ReportsTo IS NULL;

--Task 4 : List the names of products which have been discontinued
SELECT *
FROM Products
WHERE Discontinued = 1;

-- Task 5: List the IDs the orders on which discount was not provided.
SELECT OrderID
FROM [Order Details]
WHERE Discount = 0;

-- Task 6: Enlist the customer names who have not specified their region.
SELECT ContactName
FROM Customers
WHERE Region IS NULL;

-- Task 7: Enlist the names of customers along with contact number who either belongs to UK or USA.
SELECT ContactName, Phone
FROM Customers
WHERE Country = 'USA' OR Country = 'UK';

-- Task 8:  Report the names of companies who have provided their web page.
SELECT CompanyName
FROM Suppliers
WHERE HomePage IS NOT NULL;

-- Task 9: In which countries, products were sold in year 1997.
SELECT DISTINCT(ShipCountry)
FROM Orders
WHERE YEAR(OrderDate) = 1997;

-- Task 10: List the ids of customers whose orders were never shipped.
SELECT OrderID
FROM Orders
WHERE ShippedDate IS NULL;

-- Task 11: Write a query to report suppliers with their id, company name and city.
SELECT SupplierID,CompanyName,City
FROM Suppliers;

-- Task 12: Our employees belong to how many countries. List them who are used to live in London. 
SELECT *
FROM Employees
WHERE Country = 'UK' AND City = 'London';

--Task 13:  List the names of products which have not been discontinued. 
SELECT ProductName
FROM Products
WHERE Discontinued = 0;

--Task 14: List the IDs the orders on which discount was 0.1 or less. 
SELECT OrderID
FROM [Order Details]
WHERE Discount <= 0.1;

--Task 15: Enlist the IDS, names of employees and their contact number with extensions who have not specified their 
--		   region. 
SELECT EmployeeID,CONCAT(FirstName,' ',LastName) AS Name, CONCAT(Extension,' ',HomePhone)
FROM Employees
WHERE Region IS NULL;
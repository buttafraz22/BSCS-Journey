Use[northwind]
-- Standard Deviation Applied on Quantity
SELECT STDEV(Quantity)
FROM [Order Details]
GROUP BY OrderID

-- Standard Deviation applied with respect to entire population, NULL values are set as 0
SELECT STDEVP(Quantity) StandardDevP
FROM [Order Details]
GROUP BY OrderID

-- Simple Group by query
SELECT MIN(ProductID) ID
FROM [Order Details]
GROUP BY OrderID

-- Having Clause Demonstration
SELECT OrderID,STDEV(Quantity) STD
FROM[Order Details]
GROUP BY OrderID
HAVING STDEV(Quantity) > 20

-- Aliasing
SELECT Freight FRT
FROM Orders

/* Home Tasks*/
SELECT ProductName, UnitPrice
FROM Products P
WHERE P.UnitPrice > (SELECT AVG(UnitPrice) FROM Products)

SELECT OrderID, FORMAT(ShippedDate,'dd/MM/yyyy') ShipDate 
FROM Orders
WHERE ShippedDate IN (SELECT ShippedDate FROM Orders)

SELECT S.Country SupplierCountry
FROM Suppliers S
GROUP BY S.Country
HAVING COUNT(S.CompanyName) >= 2

SELECT MONTH(ShippedDate) AS NumberMonth, COUNT(*) AS DelayedOrders
FROM Orders 
WHERE ShippedDate > RequiredDate 
GROUP BY MONTH(ShippedDate)

SELECT OrderID, Discount
FROM [Order Details]
WHERE (Discount IS NOT NULL)
	   AND Discount > 0

SELECT ShipCity,COUNT(*) NumberOFOrders
FROM Orders
WHERE ShipCountry = 'USA' AND YEAR(ShippedDate) = 1997
GROUP BY ShipCity

SELECT ShipCountry AS Country, COUNT(*) AS DelayedOrders
FROM Orders 
WHERE ShippedDate > RequiredDate 
GROUP BY ShipCountry

SELECT OrderID, Discount , (Quantity * UnitPrice) TotalPrice
FROM [Order Details]
WHERE (Discount IS NOT NULL)
	   AND Discount > 0

SELECT ShipRegion,ShipCity,COUNT(DISTINCT(OrderID)) CountOrders
FROM Orders
GROUP BY ShipRegion, ShipCity
HAVING ShipRegion IS NOT NULL



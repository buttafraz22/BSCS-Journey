-- Give the list of all stations (Station Name) from where the rides were taken in year 2004.
SELECT Station_ID AS 'Station Name'
FROM Bike_Rentals
WHERE Station_ID IN (SELECT Station_ID FROM Bike_Rentals WHERE Payment_ID IN 
							(SELECT Payment_ID FROM Payments WHERE YEAR(Date_stamp) = 2004))

-- Give the total repairing cost of each bike. Schema should be like this. (Bike Id, Repairing Cost) ERROR IN QUERY.
SELECT B.Bike_ID 'Bike ID',(SELECT SUM(Price) FROM Repairs R WHERE R.B_Status_ID IN (SELECT BS.B_Status_ID FROM Bike_Status BS WHERE BS.Bike_ID IN (SELECT Bike_ID FROM Bikes)) GROUP BY R.B_Status_ID) AS 'Repairing Cost'
FROM Bikes B
WHERE B.Bike_ID IN (SELECT Bike_ID FROM Bike_Status WHERE B_Status_ID = (SELECT B_Status_ID FROM Repairs))

-- Bikes of which station needed most repairing. Give the station name.
SELECT S.Station_ID 'Station Name'
FROM Stations S
WHERE S.Station_ID IN (SELECT Station_ID FROM Bikes WHERE Bike_ID IN (SELECT TOP(10) Bike_ID FROM Bike_Status WHERE B_Status_ID IN (SELECT B_Status_ID FROM Repairs) GROUP BY Bike_ID ORDER BY COUNT(B_Status_ID) DESC))

-- How many bikes are owned by each station? Schema should be (StationName, TotalBikes)
SELECT S.Station_ID 'StationName', (SELECT COUNT(*) FROM Bikes B WHERE B.Station_ID = S.Station_ID ) 'TotalBikes'
FROM Stations S

-- Given the name customers who never rented a bike. Schema is as follow. (CustomerFullName)
SELECT CONCAT(CD.Fname,' ',CD.Lname) CustomerFullName
FROM Customer_Details CD
WHERE CD.Customer_ID IN (SELECT  Customer_ID FROM Customers C WHERE C.Customer_ID NOT IN (SELECT Customer_ID FROM Bike_Rentals))

-- Give the bike ids of those bikes who were renter after year 2016. 
SELECT br.Bike_ID
FROM Bike_Rentals br
WHERE br.Payment_ID NOT IN (SELECT Payment_ID FROM Payments WHERE YEAR(Date_stamp) > 2016)

-- Identify the customers who always pay using mastercard. Give the full name of customers.
SELECT CONCAT(CD.Fname,' ',CD.Lname) CustomerFullName
FROM Customer_Details CD
WHERE CD.Customer_ID IN (SELECT Customer_ID FROM Customers) AND (CD.Customer_ID IN (SELECT Customer_ID FROM Payments WHERE Method_ID IN (SELECT Method_ID FROM Payment_Method WHERE Method = 'mastercard' )))

-- For which station (Station Name) the most bikes are moved using vans in 2015.
SELECT Station_ID, V1.Bikes
FROM Vans V1
WHERE V1.Bikes IN (SELECT MAX(V.Bikes)
FROM Vans V WHERE YEAR(V.Date_stamp) = 2015)

-- Give the average cost of repairing that was spent on each bike.
SELECT BS.Bike_ID,
CASE WHEN (SELECT AVG(Price) FROM Repairs R WHERE R.B_Status_ID = BS.B_Status_ID) IS NULL THEN 0
ELSE (SELECT AVG(Price) FROM Repairs R WHERE R.B_Status_ID = BS.B_Status_ID) END
FROM Bike_Status BS
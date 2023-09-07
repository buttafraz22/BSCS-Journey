CREATE database  Lab2_Home;

CREATE TABLE Student(
	Registration_Number VARCHAR (100) PRIMARY KEY,
	Name VARCHAR (100),
	Department VARCHAR (100),
	Session INT,
	Address VARCHAR (100)
);

CREATE TABLE Course(
	Name VARCHAR (100) PRIMARY KEY,
	Code VARCHAR (100)
);

CREATE TABLE Enrollments(
	StudentRegNo VARCHAR (100),
	CourseName VARCHAR (100),
	PRIMARY KEY (StudentRegNo,CourseName)
);

CREATE TABLE Attendance(
	StudentRegNo VARCHAR (100),
    CourseName VARCHAR (100),
	timeattend DATETIME DEFAULT GETDATE(),
	Status varchar(10) NOT NULL DEFAULT 'A',
	PRIMARY KEY(StudentRegNo,CourseName,Status,timeattend)
);

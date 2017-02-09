-- Item 13. List the IDs of students and the IDs of their Mentors for students who are junior or senior having a GPA above 3.8.  

SELECT StudentID, MentorID 
FROM Student 
WHERE GPA > 3.8 
AND (Classification = 'Junior' or Classification = 'Senior');


-- Item 14. List the distinct course codes and sections for courses that are being taken by sophomore.

SELECT Enrollment.CourseCode, Enrollment.SectionNo 
FROM Enrollment
INNER JOIN Student
ON Enrollment.StudentID = Student.StudentID
WHERE Student.Classification = 'Sophomore';


-- Item 15. List the name and salary for mentors of all freshmen.

select distinct Person.Name, Instructor.Salary
from Instructor
inner join Person
on Instructor.InstructorID = Person.ID
inner join Student
on Instructor.InstructorID = Student.MentorID
where Student.Classification = 'Freshman';


-- Item 16. Find the total salary of all instructors who are not offering any course.

select sum(Instructor.Salary)
from Instructor
where Instructor.InstructorID not in (select Offering.InstructorID from Offering);


-- Item 17. List all the names and DOBs of students who were born in 1976. The expression "Year(x.DOB) = 1976", checks if x is born in the year 1976. 

SELECT Person.Name, Person.DOB
FROM Person
inner join Student
on Person.ID = Student.StudentID
WHERE year(Person.DOB) = 1976;


-- Item 18. List the names and rank of instructors who neither offer a course nor mentor a student.

SELECT Person.Name, Instructor.Rank 
FROM Instructor
inner join Person
on Instructor.InstructorID = Person.ID
WHERE Instructor.InstructorID NOT IN (SELECT Offering.InstructorID FROM Offering) 
AND Instructor.InstructorID NOT IN (SELECT Student.MentorID FROM Student); 


-- Item 19. Find the IDs, names and DOB of the youngest student(s).

SELECT MAX(DOB) as DOB, Person.Name, Person.ID 
FROM Person
INNER JOIN Student
ON Student.StudentID = Person.ID
WHERE Person.DOB = (Select MAX(Person.DOB) FROM Person);


-- Item 20. List the IDs, DOB, and Names of Persons who are neither a student nor a instructor.

SELECT DISTINCT Person.Name, Person.ID, Person.DOB 
FROM Person
WHERE Person.ID NOT IN (SELECT StudentID FROM Student) 
AND Person.ID NOT IN (SELECT InstructorID FROM Instructor); 


-- Item 21. For each instructor list his / her name and the number of students he / she mentors.

SELECT Person.Name, count(*) MentorCount
FROM   Instructor
INNER JOIN Person
	ON Person.ID = Instructor.InstructorID
INNER JOIN Student
	ON Student.MentorID = Instructor.InstructorID
GROUP BY Person.Name;


-- Item 22. List the number of students and average GPA for each classification. Your query should not use constants such as "Freshman".

SELECT Classification, COUNT(*) TotalStudents, AVG(GPA) 
FROM Student 
GROUP BY Classification;


-- Item 23. Report the course(s) with lowest enrollments. You should output the course code and the number of enrollments. 

SELECT Enrollment.CourseCode, COUNT(Enrollment.studentid) Enrolled 
FROM Enrollment
GROUP BY Enrollment.CourseCode
-- NOTE IF YOU ONLY WANT ONE RESULT JUST CHANGE LIMIT TO 1
LIMIT 2; 

-- Item 24. List the IDs and Mentor IDs of students who are taking some course, offered by their mentor. 

SELECT Student.StudentID, Student.MentorID
FROM Student
INNER JOIN Enrollment
ON Student.StudentID = Enrollment.StudentID 
INNER JOIN Offering
ON Offering.InstructorID = Student.MentorID; 

-- Item 25. List the student id, name, and completed credit hours of all freshman born in or after 1976. 

SELECT Person.Name, Student.StudentID, Student.CreditHours
FROM Person
INNER JOIN Student 
ON Student.StudentID = Person.ID 
AND Student.Classification = "Freshman"
AND year(Person.DOB) >= 1976;


-- Item 26. Insert following information in the database: Student name: Briggs Jason; ID: 480293439; address: 215, North Hyland Avenue; date of birth: 15th January 1975. He is a junior with a GPA of 3.48 and with 75 credit hours. His mentor is the instructor with InstructorID 201586985. Jason Briggs is taking two courses CS311 Section 2 and CS330 Section 1. He has an ’A’ on CS311 and ’A-’ on CS330.

INSERT INTO Person (`Name`, `ID`, `Address`, `DOB`) 
VALUES ('Jason Brigs', '480293439', '215, North Hyland Avenue', '1975-01-15 00:00:00'); 

INSERT INTO Student (`StudentID`, `Classification`, `GPA`, `MentorID`, `CreditHours`)
VALUES ('480293439', 'Junior', '3.48', '201586985', '75'); 

INSERT INTO Enrollment (`CourseCode`, `SectionNo`, `StudentID`, `Grade`)
VALUES ('CS311', '2', '480293439', 'A'); 

INSERT INTO Enrollment (`CourseCode`, `SectionNo`, `StudentID`, `Grade`)
VALUES ('CS330', '1', '480293439', 'A-'); 

SELECT * FROM Person; 

-- Item 27. Next, delete the records of students from the database who have a GPA less than 0.5. Note that it is not sufficient to delete these records from Student table; you have to delete them from the Enrollment table first. (Why?) On the  other hand, do not delete these students from the Person table. 

SET SQL_SAFE_UPDATES = 0;

DELETE Enrollment 
FROM Enrollment
INNER JOIN Student 
ON Enrollment.StudentID = Student.StudentID
AND Student.GPA < 0.5;  

DELETE FROM Student 
WHERE Student.GPA < 0.5; 

Select *
From Student S
Where S.GPA < 0.5; 

-- Item 28. In this part you update the Instructor table. To confirm the update, you execute two queries before and after making the update. First, execute the SQL query statements that are given below.

Select P.Name, I.Salary
From Instructor I, Person P
Where I.InstructorID = P.ID
and P.Name = 'Ricky Ponting'; 

Select P.Name, I.Salary
From Instructor I, Person P
Where I.InstructorID = P.ID
and P.Name = 'Darren Lehmann'; 

UPDATE
    Instructor
SET
    Instructor.Salary = (Instructor.Salary + (Instructor.Salary*.1))
WHERE Instructor.InstructorID 
IN (SELECT Student.MentorID FROM Student
WHERE Student.GPA > 3 
AND InstructorID = Student.MentorID
GROUP BY Student.MentorID
HAVING COUNT(*) >= 5 
); 



-- SELECT Person.Name FROM Person 
-- INNER JOIN Instructor 
-- ON Instructor.InstructorID = Person.ID
-- WHERE Instructor.InstructorID
-- IN (
-- SELECT Student.MentorID FROM Student
-- INNER JOIN Instructor 
-- ON Instructor.InstructorID = Student.MentorID 
-- WHERE Student.GPA > 3 
-- GROUP BY Student.MentorID
-- HAVING COUNT(*) >= 5); 


-- Item 29. Insert the following information into the Person table. Name: Trevor Horns; ID: 000957303; Address: 23 Canberra Street; date of birth: 23rd November 1964. Then execute the following query:

INSERT INTO Person (`Name`, `ID`, `Address`, `DOB`) 
VALUES ('Trevor Horns', '000957303', '23 Canberra Street', '1964-11-23 00:00:00'); 

Select *
From Person P
Where P.Name = 'Trevor Horns'; 

-- Item 30. Delete the record for Jan Austin from the Person table. If she is a student or an instructor, you should do the deletion with usual care. Then execute the following query:

DELETE Enrollment 
FROM Enrollment
INNER JOIN Student 
ON Enrollment.StudentID = Student.StudentID
INNER JOIN Person
ON Person.ID = Enrollment.StudentID 
AND Person.Name = 'Jan Austin'; 

DELETE Student 
FROM Student 
INNER JOIN Person
ON Person.ID = Student.StudentID 
AND Person.Name = 'Jan Austin'; 

DELETE FROM Person 
WHERE Person.Name = 'Jan Austin'; 

Select *
From Person P
Where P.Name = 'Jan Austin'

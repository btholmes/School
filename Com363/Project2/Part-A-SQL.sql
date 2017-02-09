use db363houseant; 

drop table if exists Enrollment cascade;
drop table if exists Offering cascade;
drop table if exists Course cascade;
drop table if exists Student cascade;
drop table if exists Instructor cascade;
drop table if exists Person cascade;

-- Item 1. Create a table for person
create table Person (
	ID char (9) not null, 
    Name char (20), 
    Address char (30), 
    DOB date
);
    
-- Item 2. Create a table for instructor
create table Instructor (
	InstructorID char (9) not null,
    Rank char (12), 
    Salary integer
);


-- Item 3. Create a table for student
create table Student (
	StudentID char (9) not null, 
    MentorID char (9) not null,
    Classification char (10), 
    GPA double,
    CreditHours integer
);

-- Item 4. Create a table for a course
create table Course (
	CourseCode char (6) not null,
    CourseName char (50),
    PreReq char(6)
);

-- Item 5. Create a table for an offering
create table Offering (
	CourseCode char (6) not null, 
    SectionNo integer not null, 
    InstructorID char (9) not null
);

-- Item 6. Create a table for enrollment
create table Enrollment (
	CourseCode char(6) not null, 
    SectionNo integer not null, 
    StudentID char(9) not null, 
    Grade char(4) not null
);
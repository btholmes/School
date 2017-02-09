load xml local infile '/Users/btholmes/Documents/github/School/Com363/Project2/UniversityXML/Person.xml' 
into table Person 
rows identified by '<Person>';

load xml local infile '/Users/btholmes/Documents/github/School/Com363/Project2/UniversityXML/Instructor.xml' 
into table Instructor 
rows identified by '<Instructor>';

load xml local infile '/Users/btholmes/Documents/github/School/Com363/Project2/UniversityXML/Student.xml' 
into table Student 
rows identified by '<Student>';

load xml local infile '/Users/btholmes/Documents/github/School/Com363/Project2/UniversityXML/Course.xml' 
into table Course 
rows identified by '<Course>';

load xml local infile '/Users/btholmes/Documents/github/School/Com363/Project2/UniversityXML/Offering.xml' 
into table Offering 
rows identified by '<Offering>';

load xml local infile '/Users/btholmes/Documents/github/School/Com363/Project2/UniversityXML/Enrollment.xml' 
into table Enrollment 
rows identified by '<Enrollment>';
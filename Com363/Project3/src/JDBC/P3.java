package JDBC;
import java.io.PrintWriter;
import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;

public class P3
{
    private static final String query = "select StudentDetails.Name as StudentName, " +
            "InstructorDetails.Name as InstructorName, " +
            "Student.GPA as FinalGPA from Student " +
            "inner join Person as StudentDetails on Student.StudentID = StudentDetails.ID " +
            "inner join Person as InstructorDetails on Student.MentorID = InstructorDetails.ID " +
            "where Student.Classification = \"Senior\" " +
            "order by Student.GPA DESC;";


    public static void main(String[] args) throws Exception {
        // Load and register a JDBC driver
        try {
            // Load the driver (registers itself)
            Class.forName("com.mysql.jdbc.Driver");
//            Class.forName("/Users/btholmes/Downloads/mysql-connector-java-5.1.40/mysql-connector-java-5.1.40-bin.jar!/com/mysql/jdbc/Driver.class");
        } catch (Exception E) {
            System.err.println("Unable to load driver.");
            E.printStackTrace();
        }
        try {
            // Connect to the database
            Connection conn1;
            String dbUrl = "jdbc:mysql://csdb.cs.iastate.edu:3306/db363houseant";
            String user = "dbu363houseant";
            String password = "6sEAaMQk";

            conn1 = DriverManager.getConnection(dbUrl, user, password);
            System.out.println("*** Connected to the database ***");

            // Create Statement and ResultSet variables to use throughout the project
            Statement statement = conn1.createStatement();
            ResultSet rs;


//     ************************************** THIS IS PART A *******************************************************************

            // Create Object of Student Info

            rs = statement.executeQuery("SELECT e.CourseCode, e.StudentID, e.Grade, s.Classification, s.GPA, s.CreditHours " +
                                        "FROM Enrollment e " +
                                        "INNER JOIN Student s " +
                                        "ON s.StudentID = e.StudentID " +
                                        "ORDER By s.StudentID; ");

//            'CS228','466094162','A','Senior','3.89','112'


            HashMap<String, Student> map = new HashMap<String, Student>();

            while (rs.next()) {
                String studentID = rs.getString("StudentID");
                Student studentInfo = new Student(studentID, rs.getString("Classification"),
                        rs.getDouble("GPA"), rs.getInt("CreditHours"));
                studentInfo.addClass(rs.getString("Grade").trim(), rs.getString("CourseCode"));

                if(map != null && map.containsKey(studentID)){
//                    If contains key, just add this additional class into student obj
                    String grade = rs.getString("Grade").trim();
                    String course = rs.getString("CourseCode");
                    Student studObj = map.get(studentID);
                    studObj.addClass(grade, course);
                    map.put(studentID, studObj);
                }else{
//                    Add this new studentInfo object into the Map
                    map.put(studentID, studentInfo);
                }

            }

//            // Iterate through map and update table for each value in map
            for (String key : map.keySet()) {
                statement = conn1.createStatement();

                Student StudentObj = map.get(key);
                String classification = StudentObj.getClassification();
                Double GPA = StudentObj.getGPA();
                Integer credits = StudentObj.getCreditHours();

                String sql = "UPDATE Student set Student.GPA = " + GPA +
                ", Student.Classification =  " + "\"" + classification  + "\"" +
                ", Student.CreditHours = " + credits +
                " WHERE Student.StudentID = " + key;

                statement.executeUpdate(sql);

            }

//  ************************************** THIS IS PART B *******************************************************************

            ArrayList<QueryTuple> programOutput = runDatabaseQuery(conn1);
            WriteToFile(programOutput);




            // Close all statements and connections
            statement.close();
            rs.close();
            conn1.close();

        } catch (SQLException e) {
            System.out.println("SQLException: " + e.getMessage());
            System.out.println("SQLState: " + e.getSQLState());
            System.out.println("VendorError: " + e.getErrorCode());
        }
    }



    private static ArrayList<QueryTuple> runDatabaseQuery(Connection conn1) throws Exception {
        ArrayList<QueryTuple> programOutput = new ArrayList<>();
        double lastGpaRecorded = 0;
        Statement statement = conn1.createStatement();
        ResultSet resultSet = statement.executeQuery(query);

        while(resultSet.next()) {
            String studentName = resultSet.getString("StudentName");
            String instructorName = resultSet.getString("InstructorName");
            double finalGPA = resultSet.getDouble("FinalGPA");

            if(programOutput.size() < 5 || lastGpaRecorded == finalGPA) {
                programOutput.add(new QueryTuple(studentName, instructorName, finalGPA));
                lastGpaRecorded = finalGPA;
            }
            else {
                break;
            }
        }

        statement.close();
        resultSet.close();

        return programOutput;
    }

    private static void WriteToFile(ArrayList<QueryTuple> programOutput) throws Exception {
        PrintWriter writer = new PrintWriter("P3Output.txt", "UTF-8");

        for(QueryTuple qt : programOutput) {
            writer.println(qt.getStudentName() + ", " + qt.getInstructorName() + ", " + qt.getFinalGPA());
        }

        writer.close();
    }





}

class Student{
    String StudentID;
    String Classification;
    Double GPA;
    Integer CreditHours;
    ArrayList<Course> courses;

    Student() {
        this.StudentID = "";
        this.Classification = "";
        this.GPA = 0.0;
        this.CreditHours = 0;

        this.courses = new ArrayList<Course>();
    }

    Student(String StudentID, String Classification, Double GPA, Integer CreditHours){
            this.StudentID = StudentID;
            this.Classification = Classification;
            this.GPA = GPA;
            this.CreditHours = CreditHours;

            this.courses = new ArrayList<Course>();
    }

    public void addClass(String grade, String Course){
//        Adds course, adds 3 to credit hours, updates GPA, then classification
        Course addMe = new Course(grade, Course);
        this.courses.add(addMe);

        Double newClasspoints = getGradePoints(grade);


        this.GPA = (this.GPA*this.CreditHours + newClasspoints*3)/(this.CreditHours + 3.0);
        this.GPA = Math.round(this.GPA*100)/100.0;

        this.CreditHours += 3;
        updateClassification();

    }

    public void updateClassification(){
        if(this.CreditHours >= 0 && this.CreditHours <= 29){
            this.Classification = "Freshman";
        }
        else if(this.CreditHours >= 30 && this.CreditHours <= 59){
            this.Classification = "Sophomore";
        }
        else if(this.CreditHours >= 60 && this.CreditHours <= 89){
            this.Classification = "Junior";
        }
        else if(this.CreditHours >= 90){
            this.Classification = "Senior";
        }
    }

    public Double getGradePoints(String grade){
        Double result = 0.00;

        if(grade.equals("A")){
            result = 4.00;
        }
        else if(grade.equals("A-")){
            result = 3.66;
        }
        else if(grade.equals("B+")){
            result = 3.33;
        }
        else if(grade.equals("B")){
            result = 3.00;
        }
        else if(grade.equals("B-")){
            result = 2.66;
        }
        else if(grade.equals("C+")){
            result = 2.33;
        }
        else if(grade.equals("C")){
            result = 2.00;
        }
        else if(grade.equals("C-")){
            result = 1.66;
        }
        else if(grade.equals("D+")){
            result = 1.33;
        }
        else if(grade.equals("D")){
            result = 1.00;
        }
        return result;
    }

//    Setter Methods
    public void setStudentID(String StudentID){
        this.StudentID = StudentID;
    }
    public void setClassification(String Classification){
        this.Classification = Classification;
    }
    public void setGPA(Double GPA){
        this.GPA = GPA;
    }
    public void setCreditHours(Integer CreditHours){
        this.CreditHours = CreditHours;
    }

//    Getter Methods
    public String getStudentID(){
        return this.StudentID;
    }
    public String getClassification(){
        return this.Classification;
    }
    public Double getGPA(){
        return this.GPA;
    }
    public Integer getCreditHours(){
        return this.CreditHours;
    }


}

class Course{
    String grade;
    String Course;

    Course(String grade, String course){
        this.grade = grade;
        this.Course = course;
    }

    public String getGrade(){
        return this.grade;
    }
    public String getCourse(){
        return this.Course;
    }
}

class QueryTuple {

    private String StudentName;
    private String InstructorName;
    private double FinalGPA;

    public QueryTuple(String studentName, String instructorName, double finalGPA) {
        StudentName = studentName;
        InstructorName = instructorName;
        FinalGPA = finalGPA;
    }

    public String getStudentName() {
        return StudentName;
    }

    public void setStudentName(String studentName) {
        StudentName = studentName;
    }

    public String getInstructorName() {
        return InstructorName;
    }

    public void setInstructorName(String instructorName) {
        InstructorName = instructorName;
    }

    public double getFinalGPA() {
        return FinalGPA;
    }

    public void setFinalGPA(double finalGPA) {
        FinalGPA = finalGPA;
    }
}



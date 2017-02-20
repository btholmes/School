package JDBC;
import java.sql.*;

public class Example
{
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

            // get salaries of all instructors
            rs = statement.executeQuery("select * from Instructor f");

            int totalSalary = 0;
            int salary;

            while (rs.next()) {
                //get value of salary from each tuple
                salary = rs.getInt("Salary");
                totalSalary += salary;
            }
            System.out.println("Total Salary of all faculty: "+totalSalary);

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

}
<?php
/**
 * Created by IntelliJ IDEA.
 * User: btholmes
 * Date: 11/5/16
 * Time: 6:48 PM
 */

//Default root user and password
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "AngularApp";


// Create connection
$conn = new mysqli($servername, $username, $password);

// Check connection
if ($conn->connect_error) {
    echo "Connection failed";
    die("Connection failed: " . $conn->connect_error);
}

mysqli_select_db($conn, $dbname);
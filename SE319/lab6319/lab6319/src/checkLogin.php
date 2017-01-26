<?php
/**
 * Created by IntelliJ IDEA.
 * User: btholmes
 * Date: 10/15/16
 * Time: 8:43 AM
 */
session_start();

$userName = $_POST['userName'];
$pass = $_POST['pass'];
$pass = md5($pass);


require 'connection.php';



$result = mysqli_query ($conn, "select userName, Password, Librarian from users");
$correct = 0;
$isLibrarian = 0;


while ($row = mysqli_fetch_array($result)) {
    if(!strcmp($row['userName'], $userName) && !strcmp($pass, $row['Password'])){
        if($row['Librarian'] == 1){
            $isLibrarian = 1;
        }
        $correct = 1;
        break;
    }
}

if($correct){

    if($isLibrarian){
        echo "Successful Login Librarian";
    }else{
        echo "Successful Login";
    }
    $_SESSION['user'] = $userName;

}else{
    echo "Incorrect User or Pass";
}


$conn->close();
<?php

session_start();

$firstName = trim($_POST["firstName"]);
$lastName = trim($_POST["lastName"]);
$phone = trim($_POST["phone"]);
$email = trim($_POST["email"]);
$userName = trim($_POST["userName"]);
$pass = $_POST["pass"];
$confirmPass = $_POST['confirmPass'];
$librarian = $_POST['librarian'];

require 'connection.php';

if(userName($userName) && email($email) && phone($phone) && checkFirst($firstName) && checkLast($lastName) && checkPasswords($pass, $confirmPass)){
    $result = mysqli_query ($conn, "select userName from users");
    $exists = 0;
    while ($row = mysqli_fetch_array($result)) {
        if(!strcmp($row['userName'], $userName)){
            $exists = 1;
            break;
        }
    }

    if(!$exists){
        $pass = md5($pass);
        $sql = "INSERT INTO `users`(`userName`, `Password`, `Email`, `Phone`, `Librarian`, `FirstName`, `LastName`) 
    VALUES ('$userName', '$pass', '$email', $phone, $librarian, '$firstName', '$lastName')";
        if ($conn->query($sql) === TRUE) {
            echo "Connected successfully \n";
            echo "New record created successfully";
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }


    }else{
        echo "That user already exists";
    }
}


function userName($userName){

    $pattern = '/^[A-Za-z0-9_]+$/';

    if(!preg_match($pattern, $userName) || strlen($userName) == 0){
        echo "error1";
        return 0;
    }
    return 1;

}

function email($email){

    $pattern = '/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/';

    if(!preg_match($pattern, $email) || strlen($email) == 0){
        echo "error2";
        return 0;
    }
    return 1;
}

function phone($phone){

    $pattern = '/^([0-9]{3})[-]?([0-9]{3})[-]?([0-9]{4})$/';

    if(!preg_match($pattern, $phone) || strlen($phone) == 0){
        if(strlen($phone) != 10 || strlen($phone) != 12){
            echo 'error3';
            return 0;
        }
    }
    return 1;
}

function checkFirst($first) {

    if(strlen($first) > 0){
        $pattern = '/^[a-zA-Z]+$/';

        if (!preg_match($pattern, $first) || strlen($first) == 0){
            echo 'error4';
            return 0;
        }
    }else{
        echo 'error4';
        return 0;
    }

    return 1;
}

function checkLast($last) {

    if(strlen($last) > 0){
        $pattern = '/^[a-zA-Z]+$/';

        if (!preg_match($pattern, $last)){
            echo 'error5';
            return 0;
        }
        }else{
        echo 'error5';
        return 0;
    }

    return 1;

}

function checkPasswords($pass, $confirmPass){

    if(strcmp($pass, $confirmPass) || strlen($pass) == 0 || strlen($confirmPass) == 0){
        echo 'error6';
        return 0;
    }
    return 1;
}


$conn->close();

<?php

//THIS IS HOW WE WOULD HAVE DONE IT WITH AN SQL DB, we also would have used encryption for passwords ***********************************
//session_start();
//
//$data = file_get_contents("php://input");
//
//$post = json_decode($data);
//$email = $post->email;
//$pass =  $post->pass;
//$pass = md5($pass);
//
//require 'connection.php';
//
//    $result = mysqli_query ($conn, "select userName from users");
//    $exists = 0;
//    while ($row = mysqli_fetch_array($result)) {
//        if(!strcmp($row['userName'], $email)){
//            $exists = 1;
//            break;
//        }
//    }
//
//    if(!$exists){
//        $pass = md5($pass);
//        $sql = "INSERT INTO `users`(`userName`, `passWord`)
//    VALUES ('$email', '$pass')";
//        if ($conn->query($sql) === TRUE) {
//            echo "Connected successfully \n";
//            echo "New record created successfully";
//        } else {
//            echo "Error: " . $sql . "<br>" . $conn->error;
//        }
//
//    }else{
//        echo "That user already exists";
//    }
//
//
//$conn->close();



//THIS IS HOW WE DID IT TO MAKE IT EASIER TO WORK WITH ON ANYONES COMPUTER ******************************
session_start();

$data = file_get_contents("php://input");
//var_dump($data);
$post = json_decode($data);
$userName = $post->email;
$passWord = $post->pass;



$fileContents = file_get_contents("users.txt");
$comma = ",";

if(!$fileContents){
    $comma = "";
}

echo $fileContents;

if (strpos($fileContents, '"email":' .'"'.$userName . '"') !== false) {
    echo 'That user already exists';
}else{
    $userFile = "users.txt";
    $handle = fopen($userFile, "a+");
    $info = array('email' => $userName, 'pass' => $passWord);
    $info = json_encode($info);
    fwrite($handle, $comma . $info . "\n");
    echo "Added";
}



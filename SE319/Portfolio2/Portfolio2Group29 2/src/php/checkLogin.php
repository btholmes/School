<?php
/**
 * Created by IntelliJ IDEA.
 * User: btholmes
 * Date: 10/15/16
 * Time: 8:43 AM
 */

//THIS IS WHAT WE WOULD HAVE DONE WITH SQL **************************************

////echo "in check";
$data = file_get_contents("php://input");

$post = json_decode($data);
$email = $post->email;
//$pass =  $post->pass;
//$pass = md5($pass);
//
////var_dump($_POST);
////$email = $_POST['email'];
////$pass = $_POST['pass'];
//
//session_start();
//
//
//$pass = md5($pass);
//
//
//require 'connection.php';
//
//
//$result = mysqli_query ($conn, "select userName, passWord from users");
//$correct = 0;
//
//
//while ($row = mysqli_fetch_array($result)) {
//    if(!strcmp($row['userName'], $email) && !strcmp($pass, $row['passWord'])){
//        $correct = 1;
//        break;
//    }
//}
//
//if($correct){
//
//    $_SESSION['user'] = $email;
//    echo "Success";
//
//}else{
//    echo "Incorrect User or Pass";
//}
//
//
//$conn->close();


//THIS IS WHAT WE DID TO MAKE THINGS EASIER TO USE ******************************
session_start();
$_SESSION['user'] =$email;

$info = "[" . file_get_contents("users.txt") . "]";

echo $info;
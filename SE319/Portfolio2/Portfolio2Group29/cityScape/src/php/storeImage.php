<?php
/**
 * Created by IntelliJ IDEA.
 * User: btholmes
 * Date: 10/15/16
 * Time: 1:52 PM
 */
//require "connection.php";

session_start();

define('DIRECTORY', './uploadedImages');


$data = file_get_contents("php://input");
//var_dump($data);
$post = json_decode($data);
$image = $post->item;
$cityState = $post->city;
$desc = $post->description;
$user = $_SESSION['user'];
$dateTime = $post->date;
$id = $post->id;
$fileURL = DIRECTORY ."/$id.jpg";

$image = str_replace('data:image/jpeg;base64,', '', $image);
$image = str_replace('data:image/png;base64,', '', $image);
$image = str_replace('data:image/bmp;base64,', '', $image);
$image = str_replace(' ', '+', $image);


$imageData = base64_decode($image);

file_put_contents($fileURL, $imageData);
//chmod(DIRECTORY, 755);


$fileContents = file_get_contents("images.txt");
$comma = ",";

if(!$fileContents){
    $comma = "";
}


$userFile = "images.txt";
$handle = fopen($userFile, "a+");

$info = array('url' => $fileURL, 'description' => $desc, 'user' => $user, 'city' => $cityState, 'date' => $dateTime);

$info = json_encode($info);


//var_dump($info);

fwrite($handle, $comma . $info . "\n");

//mysqli_query ($conn, "INSERT INTO `Pictures`(`City`, `Description`, `userName`)
//                          VALUES ('$cityState', '$desc','$user')");


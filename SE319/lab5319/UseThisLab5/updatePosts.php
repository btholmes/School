<?php
/**
 * Created by IntelliJ IDEA.
 * User: btholmes
 * Date: 10/15/16
 * Time: 1:52 PM
 */

$subject;
$message;
$time;
$info;
$comma;
$oldMsg;
$newMsg;
$update;
$user;

session_start();

//echo var_dump($_POST);
$update = $_POST['update'];

if($update == 0){

    $user = $_SESSION['name'];
    $subject = $_POST['subject'];
    $message = $_POST['message'];
    $time = $_POST['time'];

    $info = array('subject' => $subject, 'message' => $message, 'time' => $time, 'user' => $user);
    $comma = ",";

}else{

    //oldMsg and newMsg
    $user = $_SESSION['name'];
    $oldMsg = $_POST['oldMsg'];
    $newMsg = $_POST['newMsg'];


}


$fileContents = file_get_contents("/Applications/XAMPP/xamppfiles/htdocs/UseThisLab5/posts.txt");

if(!$fileContents){
    $comma = "";
}

$userFile = '/Applications/XAMPP/xamppfiles/htdocs/UseThisLab5/posts.txt';
$handle = fopen($userFile, "a+");



if($update == 0) {
    fwrite($handle, $comma . json_encode($info) . "\n");
}else {
    //Find the message that needs to be updated, change it, and rewrite all the info to the file
    //open the file with "w+" to erase the contents, then rewrite new contents to it.
    $userFile = '/Applications/XAMPP/xamppfiles/htdocs/UseThisLab5/posts.txt';
    $handle = fopen($userFile, "w+");
    fopen($userFile, "w+");

    $fileContents = "[" . $fileContents . "]";
    $fileContents = json_decode($fileContents);

    $changed = 0;

    for($i = 0; $i < count($fileContents); $i++){
        if(!strcmp($fileContents[$i]->message, $oldMsg) && ((!strcmp($fileContents[$i]->user, $user)))){
            $fileContents[$i]->message = $newMsg;
            echo 1;
            $changed = 1;
        }
    }
    if($changed == 0){
        echo 0;
    }

    $fileContents = json_encode($fileContents);
    $index = strpos($fileContents, "]", 0);
    $result = substr($fileContents, 1, $index-1);

    fwrite($handle, $result);

}
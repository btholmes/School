<?php
/**
 * Created by IntelliJ IDEA.
 * User: btholmes
 * Date: 10/22/16
 * Time: 8:09 PM
 */
require 'connection.php';

$shelfName = $_POST['ShelfName'];
$bookId = $_POST['bookId'];
$userName = $_POST['userName'];
$dueDate = $_POST['dueDate'];
$returnedDate = $_POST['returnedDate'];
$available = $_POST['available'];
$checkout = $_POST['checkOut'];

echo $returnedDate . " " . $checkout . " " . $userName . " " . $bookId ;


//           UPDATE `books` SET `Availability`=0 WHERE BookId = 1
//          INSERT INTO `loanHistory`(`userName`, `BookId`, `DueDate`, `ReturnedDate`) VALUES ('btholmes',0,'2016-11-17','2016-11-17')


$updateBooks = mysqli_query ($conn, "UPDATE `books` SET `Availability`= '$available' WHERE BookId = '$bookId'");

if($checkout){
    $updateLoans = mysqli_query ($conn, "INSERT INTO `loanHistory`(`userName`, `BookId`, `DueDate`, `ReturnedDate`) 
                                            VALUES ('$userName','$bookId','$dueDate','$returnedDate')");
}else{
//    UPDATE `loanHistory` SET `ReturnedDate`= '1111-11-11'
//WHERE userName = 'btholmes' AND ReturnedDate = '0000-00-00'
    $updateLoans = mysqli_query ($conn, "UPDATE `loanHistory` SET `ReturnedDate`= '$returnedDate' 
                            WHERE userName = '$userName' AND ReturnedDate = '0000-00-00' AND BookId = '$bookId'");
}


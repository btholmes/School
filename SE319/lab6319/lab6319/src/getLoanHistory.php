<?php
/**
 * Created by IntelliJ IDEA.
 * User: btholmes
 * Date: 10/22/16
 * Time: 8:09 PM
 */

require 'connection.php';

$bookId = $_POST['bookId'];


$result = mysqli_query ($conn, "SELECT `userName`, `BookId`, `DueDate`, `ReturnedDate` FROM `loanHistory` WHERE BookId = '$bookId'");

$array = array();
while ($row = mysqli_fetch_array($result)) {
    array_push($array, array('userName' => $row['userName'], 'id' => $row['BookId'], 'dueDate' => $row['DueDate'],
            'returnDate' => $row['ReturnedDate'])
    );

}

echo json_encode($array);
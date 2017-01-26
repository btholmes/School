<?php
/**
 * Created by IntelliJ IDEA.
 * User: btholmes
 * Date: 10/22/16
 * Time: 8:09 PM
 */
require 'connection.php';

$name = $_POST['name'];
$author = $_POST['author'];
$shelf = $_POST['shelf'];

$shelfNum = getShelfNum($shelf);

if($shelfNum == 4){
    echo $shelfNum;
}
else{
    $shelfCount = mysqli_query ($conn, "SELECT COUNT(* ) FROM shelves WHERE ShelfName = '$shelf';");
    $shelfCount = mysqli_fetch_array($shelfCount);

    $id = mysqli_query ($conn, "SELECT MAX(BookId) FROM books;");
    $id = mysqli_fetch_array($id);

    checkCountThenInsert($conn, $shelfNum, $shelf, $shelfCount[0], $id[0]+1, $name, $author);
}


function getShelfNum($shelf){
    if(!strcmp($shelf, "Art")){
        return 0;
    }
    else if(!strcmp($shelf, "Science")){
        return 1;
    }
    else if(!strcmp($shelf, "Sports")){
        return 2;
    }
    else if(!strcmp($shelf, "Literature")){
        return 3;
    }
    else{
        return 4;
    }
}

function checkCountThenInsert($conn, $shelfNum, $shelf, $shelfCount, $totalCount, $name, $author){
    if($shelfCount[0] < 20){
        echo "1";
        mysqli_query ($conn, "INSERT INTO `shelves`(`ShelfId`, `ShelfName`, `BookId`) VALUES ('$shelfNum','$shelf','$totalCount')");

        mysqli_query ($conn, "INSERT INTO `books`(`BookId`, `BookTitle`, `Author`, `Availability`) 
                                VALUES ('$totalCount', '$name','$author','1')");

    }
    else{
        echo "0";
    }
}

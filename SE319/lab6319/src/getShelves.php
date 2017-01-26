<?php
/**
 * Created by IntelliJ IDEA.
 * User: btholmes
 * Date: 10/22/16
 * Time: 8:09 PM
 */

require 'connection.php';

$shelfName = $_POST['ShelfName'];

$result = mysqli_query ($conn, "SELECT b.BookId, b.BookTitle, b.Availability, s.ShelfName, l.userName
FROM books b
INNER JOIN shelves s
    on s.BookId = b.BookId
LEFT JOIN loanHistory l 
  on b.BookId = l.BookId
GROUP BY b.BookTitle
ORDER BY b.BookId
");


$array = array();
while ($row = mysqli_fetch_array($result)) {
    if(!strcmp($row['ShelfName'], $shelfName)){
        array_push($array, array('name' => $row['BookTitle'], 'id' => $row['BookId'],
                'presence' => $row['Availability'], 'shelf' => $row['ShelfName'], 'borrowedBy' => $row['userName'])
        );
    }
}

echo json_encode($array);
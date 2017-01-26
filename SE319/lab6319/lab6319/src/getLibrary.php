<?php


require 'connection.php';


$result = mysqli_query ($conn, "SELECT b.BookId, b.BookTitle, b.Author, b.Availability, s.ShelfName, l.userName
FROM books b
INNER JOIN shelves s
    on s.BookId = b.BookId
LEFT JOIN loanHistory l 
  on b.BookId = l.BookId AND  l.ReturnedDate = 0000-00-00 AND b.Availability = 0
GROUP BY b.BookId, b.BookTitle, b.Author, b.Availability
");


$array = array();
while ($row = mysqli_fetch_array($result)) {
        array_push($array, array('name' => $row['BookTitle'], 'id' => $row['BookId'], 'author' => $row['Author'],
            'presence' => $row['Availability'], 'shelf' => $row['ShelfName'], 'borrowedBy' => $row['userName'])
        );

}

echo json_encode($array);
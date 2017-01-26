<?php

include 'book.php';

class Shelf {

    private $id;
    private $books;

    function __construct($id) {

        $this->id = $id;
        $this->books = array();
        $this->set_books();
    }

    public function set_id($id) {
        $this->id = $id;
    }
    public function get_id() {
        return $this->id;
    }

    public function set_books() {
        global $conn;
        include 'connection.php';

        $result = mysqli_query($conn, "SELECT * FROM `shelves` WHERE ShelfId = $this->id");
        while ($row = mysqli_fetch_array($result)) {
            array_push($this->books, array('shelfName' => $row['ShelfName'], 'shelfId' => $row['ShelfId'], 'bookId' => $row['BookId']));
        }
        $conn->close();
    }

}

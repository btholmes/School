<?php
include 'shelf.php';

class Library {

    private $books;
    private $shelves;


    function __construct() {

        $this->set_shelves();
        $this->set_bookList();
    }

    public function set_books() {
        global $conn;
        include 'connection.php';

        $this->books = array();
        $result = mysqli_query($conn, "SELECT BookId from books");
        while ($row = mysqli_fetch_array($result)) {
            $this->books[$row["BookId"]] = new Book($row["BookId"]);
        }
        $conn->close();
    }

    public function set_shelves() {
        global $conn;
        include 'connection.php';

        $this->shelves = array();
        $result = mysqli_query($conn, "SELECT DISTINCT ShelfId from shelves");
        while ($row = mysqli_fetch_array($result)) {
            $this->shelves[$row["ShelfId"]] = new Shelf($row["ShelfId"]);
        }
        $conn->close();
    }


    public function get_books() {
        return $this->books;
    }

}

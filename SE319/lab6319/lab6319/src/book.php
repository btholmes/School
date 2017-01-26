<?php


class Book {

    private $id;
    private $title;
    private $author;
    private $available;

    function __construct($id) {

        $this->bookId = $id;
        $this->set_book($id);
    }

    public function set_title($title) {
        $this->title = $title;
    }
    public function get_title() {
        return $this->title;
    }

    public function set_author($author) {
        $this->author = $author;
    }
    public function get_author() {
        return $this->author;
    }

    public function set_id($id) {
        $this->bookId = $id;
    }

    public function get_id() {
        return $this->id;
    }

    public function set_available($available){
        $this->availabe = $available;
    }

    public function get_available(){
        return $this->available;
    }


    public function set_book($id) {
        global $conn;
        require 'connection.php';

        $result = mysqli_query($conn, "SELECT FROM `books` WHERE BookId = '$id'");

        while ($row = mysqli_fetch_array($result)) {
            $this->set_title($row["BookTitle"]);
            $this->set_author($row["Author"]);
            $this->set_available($row["Availability"]);
        }
        $conn->close();
    }

    public function get_book(){
        $bookArray = array("id" => $this->id,"title" => $this->title,"author" => $this->author, "available" => $this->available);
        return $bookArray;
    }

}

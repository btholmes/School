<?php
include 'library.php';

class Student {

    private $name;

    function __construct($name) {
        $this->name = $name;
    }

    public function get_name() {
        return $this->name;
    }

}


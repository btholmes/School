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
$id = $_POST['id'];

 mysqli_query ($conn, "DELETE FROM `books` WHERE BookId = '$id'");

 mysqli_query ($conn, "DELETE FROM `shelves` WHERE BookId = '$id'");


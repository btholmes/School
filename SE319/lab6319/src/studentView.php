<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Student View</title>

    <!-- Latest compiled and minified CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <link rel = "stylesheet" href = "style.css">

    <!-- jQuery library -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>

    <!-- Latest compiled JavaScript -->
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>


    <script src = "booksLibrary.js"></script>

</head>
<body onload = "init()">
<h1 class = "text-primary text-center">Student View</h1>
<br>
<h4 id = "userWelcome" class = "text-info">Welcome: <?php session_start(); echo $_SESSION['user']; ?></h4>
<button onclick="logOut()" class = "logOutBtn btn btn-warning">Log Out</button>
<br>
<br>

<div class = "bookDetails">
    <div style = "margin-right: 0px; margin-left: 0px" class = "row text-center border-bottom">
        <b class = "bookInfoTitle">Book Info</b>
        <button class = "checkOutButton btn btn-sm btn-danger"></button>
    </div>
    <div style = "margin-right: 0px; margin-left: 0px" class = "row border-bottom">
        <div class = "col-md-5 border-right">
            <b class = "text-muted">ID</b>
        </div>
        <div id = "bookID" class = "col-md-5">

        </div>
    </div>
    <div style = "margin-right: 0px; margin-left: 0px" class = "row border-bottom">
        <div class = "col-md-5 border-right">
            <b class = "text-muted">Title</b>
        </div>
        <div id = "bookTitle" class = "col-md-5">

        </div>

    </div>
    <div style = "margin-right: 0px; margin-left: 0px" class = "row border-bottom">
        <div class = "col-md-5 border-right">
            <b class = "text-muted">Author</b>
        </div>
        <div id = "bookAuthor" class = "col-md-5">

        </div>

    </div>
    <div style = "margin-right: 0px; margin-left: 0px" class = "row border-bottom">
        <div class = "col-md-5 border-right">
            <b class = "text-muted">Shelf</b>
        </div>
        <div id = "bookShelf" class = "col-md-5">

        </div>

    </div>
    <div style = "margin-right: 0px; margin-left: 0px" class = "row border-bottom">
        <div class = "col-md-5 border-right">
            <b class = "text-muted">Available</b>
        </div>
        <div id = "bookAvailable" class = "col-md-5">

        </div>
    </div>

</div>

</body>




</html>
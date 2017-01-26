<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Librarian View</title>

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
<h1 class = "text-primary text-center">Librarian View</h1>
<br>
<h4 id = "userWelcome" class = "text-info">Welcome: <?php session_start(); echo $_SESSION['user']; ?></h4>
<button onclick="logOut()" class = "logOutBtnL btn btn-warning">Log Out</button>
<br>
<br>

<div class = "row">
    <div class="bookName form-group col-md-3">
        <b>Book Name:   </b><p style = "display: inline-block" id = "errorBook" class = "hide text-danger">Enter Book Name</p>
        <input type="text" class="form-control" id="addBook">
    </div>
    <div class="bookID form-group col-md-3">
        <b>Author:   </b> <p style = "display: inline-block" id = "errorAuthor" class = "hide text-danger">Enter Author Name</p>
        <input type="text" class="form-control" id="addAuthor">
    </div>
    <div class="shelfName form-group col-md-3">
        <b>Shelf Name:   </b> <p style = "display: inline-block" id = "errorShelf" class = "hide text-danger">Enter Shelf Name</p>
        <input type="text" class="form-control" id="shelfName">
    </div>
    <div class = "col-md-1 addBookBtn">
        <button type = "button" class = "btn btn-primary addBookBtn" onclick = "addBook()">Add Book</button>
    </div>
    <div class = "col-md-2"></div>
    <br>
</div>


<div class = "bookInfoDetails">


    <div class = "bookInfo">
        <div style = "margin-right: 0px; margin-left: 0px" class = "row text-center border-bottom">
            <b class = "bookInfoTitle text-info">Book Info</b>
            <button onclick="deleteBook()" class = "deleteBtn btn btn-sm btn-danger">Delete</button>
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

    <div class = "borrowDetails">
        <h4 class = "borrowTitle text-info">Borrow Details</h4>
    </div>

</div>





</body>


</html>






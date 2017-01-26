
    function init(){

        $(".borrowTitle").addClass("hide");
        $(".bookInfo").addClass("hide");
         checkLibrary();
    }

    function logOut(){
        $.ajax({
            type: 'POST',
            url: "logOut.php",

            success: function(data){
                localStorage.setItem("user", "");
                window.location.href = "login.html";

            }
        });

    }

    function deleteBook(){
        alert("in delete");
    }
    function addBook(){

        var library = localStorage.getItem("library29");
        library = JSON.parse(library);


        var bookName = $("#addBook").val().trim();
        var bookAuthor = $("#addAuthor").val().trim();
        var shelfName = $("#shelfName").val().trim();


        if($("#addBook").val().trim() == ""){
            $("#errorBook").removeClass("hide");
            $("#errorAuthor").addClass("hide");
            $("#errorShelf").addClass("hide");
        }
        else if($("#addAuthor").val().trim() == ""){
            $("#errorAuthor").removeClass("hide");
            $("#errorShelf").addClass("hide");
            $("#errorBook").addClass("hide");
        }
        else if($("#shelfName").val().trim() == ""){
            $("#errorAuthor").addClass("hide");
            $("#errorBook").addClass("hide");
            $("#errorShelf").removeClass("hide");
        }
        else{
            $("#errorAuthor").addClass("hide");
            $("#errorBook").addClass("hide");
            $("#errorShelf").addClass("hide");
            $("#addBook").val("");
            $("#addAuthor").val("");
            $("#shelfName").val("");

            $.ajax({
                type: 'POST',
                url: "addBook.php",
                data : {
                    name: bookName,
                    author : bookAuthor,
                    shelf : shelfName
                },
                success: function (data) {
                    if(data == 0){
                        alert('That shelf is already Full');
                    }
                    else if(data == 4){
                        alert('That shelf does not exist');
                    }
                    else{
                        checkLibrary();
                    }
                    //In library format name, id, shelf, presence, borrowedBy
                    // data = JSON.parse(data);
                }
            });
        }


    }

    function deleteBook(){

        var bookId = $("#bookID").html();
        var bookName = $("#bookTitle").html();
        var bookAuthor = $("#bookAuthor").html();


        $.ajax({
            type: 'POST',
            url: "deleteBook.php",
            data : {
                name: bookName,
                author : bookAuthor,
                id : bookId
            },
            success: function (data) {
                checkLibrary();
            }
        });

    }


    function checkLibrary(){

        var library;

        $.ajax({
            type: 'POST',
            url: "getLibrary.php",
            success: function (data) {
                //In library format name, id, shelf, presence, borrowedBy

                data = JSON.parse(data);
                library = JSON.parse(JSON.stringify(data));
            }
        }).done(function(){
            if(library.length == 0){
                $(".borrowTitle").addClass("hide");
                $(".bookInfo").addClass("hide");
                alert("The Library is empty right now...");

            }
                displayLibrary(library);

        });

    }

    function getShelves(shelf){

      return  $.ajax({
            type: 'POST',
            url: "getShelves.php",
            data: {
                ShelfName: shelf.shelfName
            },
            success: function (data) {
              // alert(data);
                data = JSON.parse(data);
                shelf.books = JSON.parse(JSON.stringify(data));

            }
        });

    }

    function displayLibrary(library){
        //display existing library
        var Art = new Shelf("Art");
        var Sports = new Shelf("Sports");
        var Science = new Shelf("Science");
        var Literature = new Shelf("Literature");


        //This is a chain to wait for each Ajax call to finish before proceeding.
        var artPromise = getShelves(Art);
        artPromise.then(function(){
            var sportsPromise = getShelves(Sports);
            sportsPromise.then(function(){

                var sciencePromise = getShelves(Science);
                sciencePromise.then(function(){

                    var literaturePromise = getShelves(Literature);
                    literaturePromise.then(function(){

                       // alert("Art is \n" + JSON.stringify(Art.books[0][1]));
                        localStorage.setItem("Art", JSON.stringify(Art));
                        localStorage.setItem("Sports", JSON.stringify(Sports));
                        localStorage.setItem("Science", JSON.stringify(Science));
                        localStorage.setItem("Literature", JSON.stringify(Literature));


                        var user = localStorage.getItem("user");
                        var location = window.location.href;
                        checkPage(user, library, location);

                        //sortShelf(library, Art, Sports, Science, Literature);
                        createTable(library, Art, Sports, Science, Literature);

                    });
                });
            });
        });

    }
    function checkPage(user, library, location){
        if(location.indexOf("studentView.php") > -1 ){
                $(".checkOutButton").html("Check In");

                $(".checkOutButton").removeClass('btn-success');
                $(".checkOutButton").addClass('btn-danger');

                $(".checkOutButton").on('click', checkIn);
        }
    }

    function displayLocalLibrary(library){
        //alert('In local');

        var Art = localStorage.getItem("Art");
        Art = JSON.parse(Art);
        var Sports = localStorage.getItem("Sports");
        Sports = JSON.parse(Sports);
        var Science = localStorage.getItem("Science");
        Science = JSON.parse(Science);
        var Literature = localStorage.getItem("Literature");
        Literature = JSON.parse(Literature);


        //alert(JSON.stringify(Art));
        createTable(library, Art, Sports, Science, Literature);
    }


    function findMax(Art, Sports, Science, Literature){
        var max = Math.max(Art.length, Sports.length);
        max = Math.max(max, Science.length);
        max = Math.max(max, Literature.length);

        return max;
    }

    function createTable(array, Art, Sports, Science, Literature){

        $(".tTable").remove();


        //alert("librar is \n" + JSON.stringify(array));
        localStorage.setItem("library29", JSON.stringify(array));

        var max = findMax(Art.books, Sports.books, Science.books, Literature.books);


        var table = document.createElement('table');
        $(table).addClass('tTable');

        var head = table.createTHead();
        $(head).addClass("header");
        var row = head.insertRow(0);

        var head1 = row.insertCell(0);
        $(head1).addClass("text-center");
        head1.innerHTML = "<b>Art</b>";
        var head2 = row.insertCell(1);
        $(head2).addClass("text-center");
        head2.innerHTML = "<b>Science</b>";
        var head3 = row.insertCell(2);
        $(head3).addClass("text-center");
        head3.innerHTML = "<b>Sports</b>";
        var head4 = row.insertCell(3);
        $(head4).addClass("text-center");
        head4.innerHTML = "<b>Literature</b>";

        for (var i = 0; i < max; i++){

            var tr = document.createElement('tr');

            var td1 = document.createElement('td');
            var td2 = document.createElement('td');
            var td3 = document.createElement('td');
            var td4 = document.createElement('td');

            var text1 = text2 = text3 = text4 = "";

            if(i < Art.books.length){
                text1 = document.createTextNode(Art.books[i].name);
                td1.appendChild(text1);
                $(td1).addClass("hoverMe");
                $(td1).attr("id" , Art.books[i].id);
                if(Art.books[i].presence == 0){
                    $(td1).addClass("checkedOut");
                }else{
                    $(td1).removeClass("checkedOut");
                }
            }
            if(i < Science.books.length){
                text2 = document.createTextNode(Science.books[i].name);
                td2.appendChild(text2);
                $(td2).addClass("hoverMe");
                $(td2).attr("id" , Science.books[i].id);
                if(Science.books[i].presence == 0){
                    $(td2).addClass("checkedOut");
                }else{
                    $(td2).removeClass("checkedOut");
                }
            }
            if(i < Sports.books.length){
                text3 = document.createTextNode(Sports.books[i].name);
                td3.appendChild(text3);
                $(td3).addClass("hoverMe");
                $(td3).attr("id" , Sports.books[i].id );
                if(Sports.books[i].presence == 0){
                    $(td3).addClass("checkedOut");
                }else{
                    $(td3).removeClass("checkedOut");
                }
            }
            if(i < Literature.books.length){
                text4 = document.createTextNode(Literature.books[i].name);
                td4.appendChild(text4);
                $(td4).addClass("hoverMe");
                $(td4).attr("id" , Literature.books[i].id );
                if(Literature.books[i].presence == 0){
                    $(td4).addClass("checkedOut");
                }else{
                    $(td4).removeClass("checkedOut");
                }
            }

            var location = window.location.href;

            $([td1 , td2, td3, td4]).click(function(e){
                    var library = localStorage.getItem("library29");
                    library = JSON.parse(library);

                    showBookInfo(library, e.target.id);
            });


            tr.appendChild(td1);
            tr.appendChild(td2);
            tr.appendChild(td3);
            tr.appendChild(td4);

            table.appendChild(tr);
        }
        document.body.appendChild(table);


    }

    function showBookInfo(library, id){
    //
      //  alert("In show info");
        $(".bookInfo").removeClass("hide");

        var user = localStorage.getItem("user");
        for(var i = 0; i < library.length; i++){
            if(library[i].id == id) {
                $("#bookID").html(id);
                $("#bookTitle").html(library[i].name);
                $("#bookAuthor").html(library[i].author);
                $("#bookAvailable").html(library[i].presence);
                $("#bookShelf").html(library[i].shelf);

                if(library[i].presence == 0 && library[i].borrowedBy == user){
                    $(".checkOutButton").html("Check In");

                    $(".checkOutButton").removeClass('btn-success');
                    $(".checkOutButton").addClass('btn-danger');

                   $(".checkOutButton").off('click').on('click', checkIn);
                   //  $(".checkOutButton").click(function(){
                   //      checkIn(library, id);
                   //  });
                }else{
                    $(".checkOutButton").html("Check Out");

                    $(".checkOutButton").removeClass('btn-danger');
                    $(".checkOutButton").addClass('btn-success');

                    $(".checkOutButton").off('click').on('click',  checkOut);
                    // $(".checkOutButton").click(function(){
                    //     checkOut(library, id);
                    // });
                }
                displayBorrowHistory(id);
                break;
            }

        }

    }

    function displayBorrowHistory(id){
        var location = window.location.href;
        if(location.indexOf("librarian.php") > -1 ){
            $.ajax({
                type: 'POST',
                url: "getLoanHistory.php",
                data: {
                    bookId : id
                },
                success: function (data) {
                    data = JSON.parse(data);
                    // alert(data.length);

                    createBorrowTable(data);
                }
            });

        }
    }

    function createBorrowTable(data){

      // alert(JSON.stringify(data));

        $(".borrowTitle").removeClass("hide");
        $(".borrowTable").remove();

        var table = document.createElement('table');
        $(table).addClass('borrowTable');

        var head = table.createTHead();
        $(head).addClass("header");
        var row = head.insertRow(0);

        var head1 = row.insertCell(0);
        $(head1).addClass("text-center");
        head1.innerHTML = "<b>Name</b>";
        var head2 = row.insertCell(1);
        $(head2).addClass("text-center");
        head2.innerHTML = "<b>BookID</b>";
        var head3 = row.insertCell(2);
        $(head3).addClass("text-center");
        head3.innerHTML = "<b>DueDate</b>";
        var head4 = row.insertCell(3);
        $(head4).addClass("text-center");
        head4.innerHTML = "<b>Returned</b>";

        for (var i = data.length-1; i >= 0; i--){

            var tr = document.createElement('tr');

            var td1 = document.createElement('td');
            var td2 = document.createElement('td');
            var td3 = document.createElement('td');
            var td4 = document.createElement('td');

            var text1 = text2 = text3 = text4 = "";

                text1 = document.createTextNode(data[i].userName);
                td1.appendChild(text1);


                text2 = document.createTextNode(data[i].id);
                td2.appendChild(text2);

                text3 = document.createTextNode(data[i].dueDate);
                td3.appendChild(text3);


                if(data[i].returnDate == "0000-00-00"){
                    text4 = document.createTextNode("Not Returned");
                }else{
                    text4 = document.createTextNode(data[i].returnDate);
                }
            //alert(data[i].returnDate == "0000-00-00");
            // text4 = document.createTextNode(data[i].returnDate);
                td4.appendChild(text4);

            tr.appendChild(td1);
            tr.appendChild(td2);
            tr.appendChild(td3);
            tr.appendChild(td4);

            table.appendChild(tr);
        }
        // var div = document.getElementsByClassName("bookDetails");
        // div.appendChild(table);

        $(".borrowDetails").append(table);
    }

    function checkedOut(library, name){

        var result = 0;
        for(var i = 0; i < library.length; i++){
            if(library[i].name == name && library[i].presence == 0){
                result = 1;
                alert("Book " + name + " is checked out by " + library[i].borrowedBy);
                break;
            }
        }
        return result;
    }
    //
    function checkIn(){

        var id = $("#bookID").html();
        var library = localStorage.getItem("library29");
        library = JSON.parse(library);



        var user = localStorage.getItem("user");
        //alert(library.length);

        for(var i = 0; i < library.length; i++){
            if(library[i].borrowedBy == user && library[i].id == id){

                var shelf = localStorage.getItem(library[i].shelf);
                shelf = JSON.parse(shelf);
             //   alert(JSON.stringify(shelf));

                library[i].borrowedBy = null;
                library[i].presence = 1;

                updateShelf(shelf, id, 0, null);

                break;
            }
        }

       // alert(JSON.stringify(library));

        displayLocalLibrary(library);

    }

    function checkOut(){



      var id = $("#bookID").html();
        var library = localStorage.getItem("library29");
        library = JSON.parse(library);


        var user = localStorage.getItem("user");


        for(var i = 0; i < library.length; i++){
            if(library[i].id == id && library[i].presence == 1){
                 //   $("#" + id).addClass("checkedOut");
                    library[i].presence = 0;
                    library[i].borrowedBy = user;
                    var shelf = localStorage.getItem(library[i].shelf);
                    shelf = JSON.parse(shelf);
                    updateShelf(shelf, id, 1, user);
                break;
            }
            else if(library[i].id == id && library[i].presence == 0){
                var hasIt = library[i].borrowedBy;
                alert(hasIt + " is already checking out " + library[i].name);
                break;
            }

        }

    //    alert(JSON.stringify(library));
        displayLocalLibrary(library);

    }

    //This method also updates the loan history and books tables
    function updateShelf(shelf, id, out, user){


        for(var i = 0; i < shelf.books.length; i++){
            if(shelf.books[i].id == id){
                if(out){
                    shelf.books[i].presence = 0;
                    shelf.books[i].borrowedBy = user;
                }
                else{
                    shelf.books[i].presence = 1;
                    shelf.books[i].borrowedBy = null;
                }
            }
        }
       // alert("shelf in update " + JSON.stringify(shelf));
        localStorage.setItem(shelf.shelfName, JSON.stringify(shelf));

        updateShelfPHP(shelf, id, out, user);

    }

    function updateShelfPHP(shelf, id, out, user){

        var bookIdV = id;

        var due = new Date();
        due.setDate(due.getDate()+14);

        var month = due.getUTCMonth() + 1; //months from 1-12
        var day = due.getUTCDate();
        var year = due.getUTCFullYear();

        var dueDateV = year + '-' + month + '-' + day;

        // alert(dueDateV);

        var now = new Date();
        month = now.getUTCMonth() + 1; //months from 1-12
        day = now.getUTCDate();
        year = now.getUTCFullYear();
        var returnedDateV = year + '-' + month + '-' + day;

        var checkOutV = out;
        var availableV = 1;
        if(out){
            availableV = 0;
            returnedDateV = null;
        }

        var userV = localStorage.getItem("user");

        $.ajax({
            type: 'POST',
            url: "updateLoanHistory.php",
            data: {
                ShelfName: shelf.shelfName,
                bookId : bookIdV,
                userName : userV,
                dueDate : dueDateV,
                returnedDate : returnedDateV,
                available : availableV,
                checkOut : checkOutV
            },
            success: function (data) {
                //alert(data);
                // data = JSON.parse(data);
                //shelf.books = JSON.parse(JSON.stringify(data));

            }
        });

    }

    function getShelf(library, id){
        var result = "";
        for(var i = 0; i < library.length; i++){
            if(library[i].name == id){
                result = library[i].shelf;
                break;
            }
        }

        return result;

    }

    function Shelf(name){
        this.shelfName = name;
        //array of book objects on this shelf
        this.books = [];

    }

    function Book(name, id){
        this.name = name;
        this.id = id;
        this.shelf = "";
        //Use localstorage when presence and borrowedBy change
        this.author = null;
        this.presence = 1;
        this.borrowedBy = null;

    }

(function(){
    'use strict';

    myApp.controller('libraryCtrl', libraryCtrl);

    libraryCtrl.$inject = ['$state', '$scope', '$window'];

    function libraryCtrl($state, $scope, window)
    {

        $scope.library = [];
        $scope.artShelf = [];
        $scope.scienceShelf = [];
        $scope.sportsShelf = [];
        $scope.literatureShelf = [];


        $scope.Shelf = function(name){
            this.shelfName = name;
            //array of book objects on this shelf
            this.books = [];

        };

        $scope.getShelf = function(library, id){
            var result = "";
            for(var i = 0; i < library.length; i++){
                if(library[i].name == id){
                    result = library[i].shelf;
                    break;
                }
            }

            return result;

        }



        $scope.Book = function(name, id){
            this.name = name;
            this.id = id;
            this.shelf = "";
            this.reference = 0;
            this.out = "";
            //Use localstorage when presence and borrowedBy change
            this.presence = 1;
            this.borrowedBy = "Nobody";

        };



        $scope.isNumber = function(n) {
            return /^-?[\d.]+(?:e-?\d+)?$/.test(n);
        };

        $scope.Library = function(book){
            this.books = [];
        };





        $scope.getInfo = function(library, name, shelf, out){

            for(var i = 0; i < library.length; i++){
                //Check it out if nobody has it
                if(library[i].name == name){
                    var type = "book";
                    var inStock = "Checked Out";
                    var hasIt = library[i].borrowedBy;
                    if(library[i].presence)
                        inStock = "Available";
                    if(library[i].reference)
                        type = "reference";

                    alert("Book "  + name + " is " + inStock + "\n" +
                        "It is currently being used by " + hasIt + "\n" +
                        "And it is of type " + type + "\n"
                    );

                    break;
                }

            }
        };

        $scope.logout = function(){
            localStorage.setItem("user", null);
            // $(".tTable").remove();
            $state.go("login");
        };



        $scope.sortShelf = function(array, Art, Sports, Science, Literature){
            //Sorts books according to shelf, and adds them to new Shelf objects which store the arrays of the books
            //they include
            for(var i = 0; i < array.length; i++){

                if(array[i].id % 4 == 0){
                    //art
                    array[i].shelf = "Art";
                    // Art.addBook(array[i]);
                    Art.books.push(array[i]);

                }else if (array[i].id %4 == 1){
                    //science
                    array[i].shelf = "Science";
                    // Science.addBook(array[i]);
                    Science.books.push(array[i]);

                }else if (array[i].id %4 == 2){
                    //sports
                    array[i].shelf = "Sports";
                    // Sports.addBook(array[i]);
                    Sports.books.push(array[i]);

                }else if (array[i].id %4 == 3){
                    //literature
                    array[i].shelf = "Literature";
                    // Literature.addBook(array[i]);
                    Literature.books.push(array[i]);
                }


            }
        }

//Finds shelf with max books
        $scope.findMax = function(Art, Sports, Science, Literature){
            var max = Math.max(Art.length, Sports.length);
            max = Math.max(max, Science.length);
            max = Math.max(max, Literature.length);

            return max;
        }

        $scope.createTable = function(array, Art, Sports, Science, Literature){


            localStorage.setItem("library29", JSON.stringify(array));

            // alert(JSON.stringify(Art));

            $scope.library = array;

            $scope.artShelf = Art.books;
            $scope.scienceShelf = Science.books;
            $scope.sportsShelf = Sports.books;
            $scope.literatureShelf = Literature.books;


        };

        $scope.checkIt = function(event){
            // alert(?);
            var library = localStorage.getItem("library29");
            library = JSON.parse(library);

            if(window.location.href.indexOf("admin") > -1) {
                var shelf = $scope.getShelf(library, event.target.id);
                var out = $scope.checkedOut(library, event.target.id);
                $scope.getInfo(library, event.target.id, shelf, out);

            }else if(window.location.href.indexOf("student") > -1 ){
                if($("#" + event.target.id).hasClass("checkedOut")){
                    $("#" + event.target.id).removeClass("checkedOut");
                    $scope.checkIn(library, event.target.id);
                }else{
                    $scope.checkOut(library, event.target.id);
                }
            }

        };


        $scope.displayLibrary = function(library){
            //display existing library
            var Art = new $scope.Shelf("Art");
            var Sports = new $scope.Shelf("Sports");
            var Science = new $scope.Shelf("Science");
            var Literature = new $scope.Shelf("Literature");

            $scope.sortShelf(library, Art, Sports, Science, Literature);
            $scope.createTable(library, Art, Sports, Science, Literature);

        };
        $scope.populateLibrary = function(){
            var library = new $scope.Library();
            var array = [];
            //For ordinary
            for(var i = 1; i<=20; i++){
                var name = "B" + i;
                var id = Math.floor((Math.random() * 4) + 1);
                var myBook = new  $scope.Book(name, id);
                array.push(myBook);
                library.books.push(myBook);
            }

            //For reference
            for(var i = 1; i <= 5; i++){
                var name = "R" + i;
                var id = Math.floor((Math.random() * 4) + 1);
                var myBook = new $scope.Book(name, id);
                myBook.reference = 1;
                array.push(myBook);
                library.books.push(myBook);
            }
            //The array is an array of books
            //createTable(array);

            $scope.displayLibrary(array);
        }


        $scope.checkLibrary = function(){
            var library = localStorage.getItem("library29");
            library = JSON.parse(library);
            if(library == null){
                $scope.populateLibrary();
            }else{
                $scope.displayLibrary(library);
            }
        };

        $scope.init = function(){

            var user = localStorage.getItem("user");
            $("#userWelcome").html("Welcome: " + user);
            window.location.href = window.location.href;
            $scope.checkLibrary();
        }

        $scope.init();

        $scope.addBook = function(){

            var library = localStorage.getItem("library29");
            library = JSON.parse(library);


            var bookName = $("#bookName").val();
            var bookID = $("#selectedShelf").prop('selectedIndex');
            // bookID = parseInt(bookID);
            var reference = $("#isReference").prop('checked');



            if(bookID < 4 && bookID >= 0 && bookName != ""){

                $("#errorID").removeClass("reveal");
                $("#errorID").addClass("hidden");
                $("#errorBook").removeClass("reveal");
                $("#errorBook").addClass("hidden");


                $("#bookName").val("");
                $("#bookID").val("");

                var myBook = new $scope.Book(bookName, bookID);
                if(reference){
                    myBook.reference = 1;
                }


                library.push(myBook);

                $scope.displayLibrary(library);
            }
            else{
                if((bookID >= 4 || bookID < 0 || !$scope.isNumber(bookID)) && bookName.trim() == ""){
                    $("#errorID").removeClass("hidden");
                    $("#errorID").addClass("reveal");
                    $("#errorBook").removeClass("hidden");
                    $("#errorBook").addClass("reveal");
                }
                else if(bookID >= 4 || bookID < 0 || !$scope.isNumber(bookID)){
                    $("#errorID").removeClass("hidden");
                    $("#errorID").addClass("reveal");
                    $("#errorBook").removeClass("reveal");
                    $("#errorBook").addClass("hidden");

                }
                else if(bookName.trim() == ""){
                    $("#errorBook").removeClass("hidden");
                    $("#errorBook").addClass("reveal");
                    $("#errorID").removeClass("reveal");
                    $("#errorID").addClass("hidden");
                }

            }
        };



        $scope.checkedOut = function(library, name){
            var result = 0;
            for(var i = 0; i < library.length; i++){
                if(library[i].name == name && library[i].presence == 0){
                    result = 1;
                    break;
                }
            }
            return result;
        };

        $scope.checkIn = function(library, name){

            var user = localStorage.getItem("user");

            for(var i = 0; i < library.length; i++){
                if(library[i].borrowedBy == user && library[i].name == name){
                    library[i].borrowedBy = "Nobody";
                    library[i].presence = 1;
                    library[i].out = "";
                    var books = parseInt(localStorage.getItem(user));
                    if(books -1 <= 0){
                        books = 0;
                    }else{
                        books = books - 1;
                    }
                    localStorage.setItem(user, books);
                    break;
                }else if(library[i].name == name && library[i].presence == 0){
                    var hasIt = library[i].borrowedBy;
                    alert(hasIt + " is already checking out " + library[i].name);
                    break;
                }
            }

            $scope.displayLibrary(library);

        };

        $scope.checkOut = function(library, name){

            // alert("in check out");
            for(var i = 0; i < library.length; i++){
                //Check it out if nobody has it
                if(library[i].name == name && library[i].presence == 1){
                    var user = localStorage.getItem("user");
                    var books = parseInt(localStorage.getItem(user));
                    if(books == null || books < 0 || !$scope.isNumber(books)){
                        books = 0;
                    }
                    if(books == 2){
                        alert("Sorry, but you already have 2 books : (");
                    }
                    else if(library[i].reference){
                        alert("Sorry, can't check out a reference book");
                    }else{
                        library[i].presence = 0;
                        library[i].out = "checkedOut";
                        library[i].borrowedBy = user;
                        localStorage.setItem(user, ++books);
                    }
                    break;
                }
                else if(library[i].name == name && library[i].presence == 0){
                    var hasIt = library[i].borrowedBy;
                    alert(hasIt + " is already checking out " + library[i].name);
                    break;
                }

            }

            $scope.displayLibrary(library);

        };




    }

})();
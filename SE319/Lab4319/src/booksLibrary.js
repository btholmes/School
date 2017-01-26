function init(){
	
	var user = localStorage.getItem("user"); 
	$("#userWelcome").html("Welcome: " + user); 
	checkLibrary(); 	
}

function login(){
	var user = $("#user").val(); 
	var pass = $("#pass").val(); 
	
	if(user.match(/admin/) && pass.match(/admin/)){
		window.location.href = "admin.html";  
		localStorage.setItem("user", user); 
	}
	else if(user.match(/^U/)){
		window.location.href = "underGradView.html"; 
		localStorage.setItem("user", user); 
	}
	else{
		alert("That is not a correct user and password"); 
	}		 
}


function checkLibrary(){
	var library = localStorage.getItem("library29"); 
	library = JSON.parse(library); 
	if(library == null){
		populateLibrary();
	}else{
		displayLibrary(library); 
	}
}

function displayLibrary(library){
	//display existing library
	var Art = new Shelf("Art"); 
	var Sports = new Shelf("Sports"); 
	var Science = new Shelf("Science"); 
	var Literature = new Shelf("Literature"); 
	
	sortShelf(library, Art, Sports, Science, Literature); 
	createTable(library, Art, Sports, Science, Literature); 
	
}

function addBook(){
	
	var library = localStorage.getItem("library29"); 
	library = JSON.parse(library); 
	 
	
	var bookName = $("#bookName").val(); 
	var bookID = $("#bookID").val(); 
	bookID = parseInt(bookID); 
	
	
	if(bookID < 4 && bookID >= 0 && bookName != ""){ 
		
	$("#errorID").removeClass("reveal"); 
	$("#errorID").addClass("hidden"); 
	$("#errorBook").removeClass("reveal"); 
	$("#errorBook").addClass("hidden"); 
	
		
	$("#bookName").val(""); 
	$("#bookID").val("");
	
	var myBook = new Book(bookName, bookID); 
	library.push(myBook); 
		
	displayLibrary(library); 
	}
	else{
		if((bookID >= 4 || bookID < 0 || !isNumber(bookID)) && bookName.trim() == ""){
			$("#errorID").removeClass("hidden"); 
			$("#errorID").addClass("reveal"); 
			$("#errorBook").removeClass("hidden"); 
			$("#errorBook").addClass("reveal"); 
		}
		else if(bookID >= 4 || bookID < 0 || !isNumber(bookID)){
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
}

function isNumber(n) { 
	return /^-?[\d.]+(?:e-?\d+)?$/.test(n); 
} 

function Library(book){
	this.books = []; 
}

function populateLibrary(){
	var library = new Library(); 
	var array = []; 
	//For ordinary
	for(var i = 1; i<=20; i++){
		var name = "B" + i; 
		var id = Math.floor((Math.random() * 4) + 1);
		var myBook = new Book(name, id); 
		array.push(myBook); 
		library.books.push(myBook); 
	}
	
	//For reference 
	for(var i = 1; i <= 5; i++){
		var name = "R" + i; 
		var id = Math.floor((Math.random() * 4) + 1);
		var myBook = new Book(name, id); 
		array.push(myBook); 
		library.books.push(myBook); 
	}
	//The array is an array of books
	//createTable(array); 
	
	displayLibrary(array); 
}

function sortShelf(array, Art, Sports, Science, Literature){
	//Sorts books according to shelf, and adds them to new Shelf objects which store the arrays of the books
	//they include 
	for(var i = 0; i < array.length; i++){
		
		if(array[i].id % 4 == 0){
			//art
			array[i].shelf = "Art"; 
			Art.addBook(array[i]);
			
		}else if (array[i].id %4 == 1){
			//science
			array[i].shelf = "Science"; 
			Science.addBook(array[i]);
			
		}else if (array[i].id %4 == 2){
			//sports 
			array[i].shelf = "Sports"; 
			Sports.addBook(array[i]);
			
		}else if (array[i].id %4 == 3){
			 //literature
			array[i].shelf = "Literature"; 
			Literature.addBook(array[i]);
		}
	}
}

//Finds shelf with max books
function findMax(Art, Sports, Science, Literature){
	var max = Math.max(Art.length, Sports.length); 
	max = Math.max(max, Science.length); 
	max = Math.max(max, Literature.length); 

	return max; 	
}

function createTable(array, Art, Sports, Science, Literature){
	
//	alert(JSON.stringify(library)); 
	
	localStorage.setItem("library29", JSON.stringify(array)); 

	$(".tTable").remove(); 
	
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
	    		$(td1).addClass(Art.books[i].id); 
	    		$(td1).attr("id" , Art.books[i].name);
	    	if(Art.books[i].presence == 0){
	    		$(td1).addClass("checkedOut"); 
	    	}
	    }
	    if(i < Science.books.length){
		    text2 = document.createTextNode(Science.books[i].name);
		    td2.appendChild(text2);
	    		$(td2).addClass(Science.books[i].id); 
	    		$(td2).attr("id" , Science.books[i].name);
    		if(Science.books[i].presence == 0){
	    		$(td2).addClass("checkedOut"); 
	    	}
	    }
	    if(i < Sports.books.length){
		    text3 = document.createTextNode(Sports.books[i].name);
		    td3.appendChild(text3);
	    		$(td3).addClass(Sports.books[i].id); 
	    		$(td3).attr("id" , Sports.books[i].name);
    		if(Sports.books[i].presence == 0){
	    		$(td3).addClass("checkedOut"); 
	    	}
	    }
	    if(i < Literature.books.length){
		    text4 = document.createTextNode(Literature.books[i].name);
		    td4.appendChild(text4);
	    		$(td4).addClass(Literature.books[i].id); 
	    		$(td4).attr("id" , Literature.books[i].name);	
    		if(Literature.books[i].presence == 0){
	    		$(td4).addClass("checkedOut"); 
	    	}
	    }   
	   	  
	    var location = window.location.href; 
	    
	    if(location.indexOf("admin.html") > -1){
	    	 $([td1 , td2, td3, td4]).click(function(e){
	 	    	var library = localStorage.getItem("library29"); 
	 	    	library = JSON.parse(library); 
	 	    	var shelf = getShelf(library, e.target.id); 
	 	    	var out = checkedOut(library, e.target.id); 	 	    	
	 	    	if(!out){
	 	    		alert("Book " + e.target.id + " is on shelf " + shelf);
	 	    	}			 
	 		}); 
	    }else if(location.indexOf("underGradView.html") > -1 ){
		   	 $([td1 , td2, td3, td4]).click(function(e){
		 	    	var library = localStorage.getItem("library29"); 
		 	    	library = JSON.parse(library); 
		 	    	if($("#" + e.target.id).hasClass("checkedOut")){
		 	    		$("#" + e.target.id).removeClass("checkedOut");
		 	    		checkIn(library, e.target.id); 
		 	    	}else{		 	
			 	    	checkOut(library, e.target.id); 
		 	    	}
		 		}); 
	    }
	   
	    
	    tr.appendChild(td1);
	    tr.appendChild(td2);
	    tr.appendChild(td3);
	    tr.appendChild(td4);

	    table.appendChild(tr);
	}
	document.body.appendChild(table);
	
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

function checkIn(library, name){
	
	var user = localStorage.getItem("user"); 
	
	for(var i = 0; i < library.length; i++){
		if(library[i].borrowedBy == user && library[i].name == name){
			library[i].borrowedBy = ""; 
			library[i].presence = 1; 
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
	
	displayLibrary(library); 
	
}

function checkOut(library, name){
	
	for(var i = 0; i < library.length; i++){
		//Check it out if nobody has it
		if(library[i].name == name && library[i].presence == 1){
			var user = localStorage.getItem("user"); 
			var books = parseInt(localStorage.getItem(user)); 
			if(books == null || books < 0 || !isNumber(books)){
				books = 0; 
			}
			if(books == 2){
				alert("Sorry, but you already have 2 books : ("); 
			}else{
				library[i].presence = 0; 
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
	
	displayLibrary(library); 
	
}

Shelf.prototype.addBook = function(book){
	this.books.push(book);
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
	this.presence = 1; 
	this.borrowedBy = "Nobody"; 
	
}
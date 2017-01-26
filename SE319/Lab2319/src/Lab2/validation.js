cookie = ""; 

function checkGender() {
	var genderSelect = document.getElementById("gender");
	var gender = genderSelect.options[genderSelect.selectedIndex].text;
	if(gender == "--Gender--"){
		return false; 
	}
	
	cookie = "gender=" + gender; 
	return true; 
}


function checkState() {
	var stateSelect = document.getElementById("state");
	var state = stateSelect.options[stateSelect.selectedIndex].text;
	if(state == "--State--"){
		return false; 
	}
	
	cookie += ": state=" + state;
	return true; 
}

function checkFirst() {
	var first = document.getElementById("firstName").value; 
	if(first.length > 0){
	 	if (!first.match(/^[0-9a-zA-Z]+$/)){
	 		 return false; 
	 	}
	}else{
		return false; 
	}
	
	cookie += ": firstName=" + first;
	return true; 
}

function checkLast() {
	
	
	var last = document.getElementById("lastName").value; 
	if(last.length > 0){
	 	if (!last.match(/^[0-9a-zA-Z]+$/)){
	 		 return false; 
	 	}
	}else{
		return false; 
	}
	
	cookie +=  ": lastName=" + last;
	return true; 
	
}

function checkValues() {
	if(checkGender()){
		$(".rightGender").addClass("show"); 
		$(".wrongGender").removeClass("show");
	}else{
		$(".rightGender").removeClass("show"); 
		$(".wrongGender").addClass("show"); 
	}
	if(checkState()){
		$(".rightState").addClass("show"); 
		$(".wrongState").removeClass("show");
	}else{
		$(".rightState").removeClass("show"); 
		$(".wrongState").addClass("show");
	}
	if(checkFirst()){
		$(".rightFirstName").addClass("show"); 
		$(".wrongFirstName").removeClass("show"); 
	}else{
		$(".rightFirstName").removeClass("show"); 
		$(".wrongFirstName").addClass("show");
	}
	if(checkLast()){
		$(".rightLastName").addClass("show"); 
		$(".wrongLastName").removeClass("show");
	}else{
		$(".rightLastName").removeClass("show"); 
		$(".wrongLastName").addClass("show");
	}	
	
	if(checkGender() && checkState() && checkFirst() && checkLast()){
		document.cookie = cookie; 
		var url = window.location.href;
		var result = url.replace("validation1.html", "validation2.html"); 
		window.location.href = result; 
		
	}
	
	
}
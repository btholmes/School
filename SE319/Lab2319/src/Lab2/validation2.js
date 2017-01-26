function validate(){
	if(email()){
		$(".rightEmail").addClass("show"); 
		$(".wrongEmail").removeClass("show");
	}else{
		$(".rightEmail").removeClass("show"); 
		$(".wrongEmail").addClass("show");
	}
	if(phone()){
		$(".rightPhone").addClass("show"); 
		$(".wrongPhone").removeClass("show"); 
	}else{
		$(".rightPhone").removeClass("show"); 
		$(".wrongPhone").addClass("show");
	}
	if(address()){
		$(".rightAddress").addClass("show"); 
		$(".wrongAddress").removeClass("show");
	}else{
		$(".rightAddress").removeClass("show"); 
		$(".wrongAddress").addClass("show");
	}	
	if(email() && phone() && address()){
		 
		localStorage.setItem("address", document.getElementById("address").value); 
		
        document.cookie = "gender=; expires=Thu, 01 Jan 1970 00:00:00 GMT";   
        document.cookie = "state=; expires=Thu, 01 Jan 1970 00:00:00 GMT";  
        document.cookie = "firstName=; expires=Thu, 01 Jan 1970 00:00:00 GMT";  
        document.cookie = "lastName=; expires=Thu, 01 Jan 1970 00:00:00 GMT";  
        
        var url = window.location.href;
		var result = url.replace("validation2.html", "map.html"); 
		window.location.href = result; 
	}
	
}
function email(){
	var email = document.getElementById("email").value; 
	if(!email.match(/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/)){
		return false; 
	}
	return true; 
}

function phone(){
	var phone = document.getElementById("phone").value; 
	if(!phone.match(/^([0-9]{3})[-]?([0-9]{3})[-]?([0-9]{4})$/)){
		if(phone.length != 10 || phone.length != 12){
			return false; 
		}		
	}
	return true; 
}



function address(){
	var address = document.getElementById("address").value; 
	if(address.match(/^([A-Z]{1})[a-z]+,[ ][A-Z]{2}/)){
		return true; 
	}else{
		return false; 
	}
	
	return true; 
}
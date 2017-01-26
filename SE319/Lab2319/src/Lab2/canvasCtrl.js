var x = 10;
var y = 20; 
var left = false;
var right = true; 
var up = false; 
var down = false; 
var i; 

function begin(){ 
	
	i = setInterval( draw, 38 );
}

function draw(){

	var c = document.getElementById("myCanvas");
	var ctx = c.getContext("2d");
	ctx.beginPath();
	ctx.moveTo(x,y);
	
	if(right){
		x += 1; 
	}
	if(left){
		x -= 1; 
	} 
	if(down){
		y += 1; 
	}
	if(up){
		y -= 1; 
	}	
	ctx.lineTo(x,y);
	ctx.strokeStyle="red";
	ctx.stroke();
}

function turnLeft(){
	if(right){
		up = true;
		right = false; 
	}
	else if(up){
		left = true; 
		up = false; 
	}
	else if(left){
		down = true; 
		left = false; 
	}
	else if(down){
		right = true; 
		down = false; 
	}
}

function turnRight(){
	if(right){
		down = true;
		right = false; 
	}
	else if(up){
		right = true; 
		up = false; 
	}
	else if(left){
		up = true; 
		left = false; 
	}
	else if(down){
		left = true; 
		down = false; 
	}
}

function stop(){
	clearInterval(i); 
}


function toggleButton(){
	var value = document.getElementById("start").innerHTML; 
	if(value == "Stop") {
		 document.getElementById("start").innerHTML = "Start"; 	
		 stop(); 
	}else{
		 document.getElementById("start").innerHTML	= "Stop";
		 begin(); 
    }
	
}
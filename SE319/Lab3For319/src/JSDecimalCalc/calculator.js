function init(){
	var input = document.getElementById('input'), // input/output button
	  number = document.querySelectorAll('.numbers div'), // number buttons
	  operator = document.querySelectorAll('.operators div'), // operator buttons
	  equal = document.getElementById('equal'), // equal button
	  clear = document.getElementById('clear'), // clear button
	  additions = document.querySelectorAll('.additions div'); 
	
	var memory = []; 
	//This handles the Memory functions
	for(var i = 0; i < additions.length; i++){
		additions[i].addEventListener("click", function(e){
			if(e.target.innerHTML == "MS"){
				memory = []; 
				memory.push(parseFloat(input.innerHTML));  
			}
			if(e.target.innerHTML == "MR"){
				input.innerHTML = memory[0];  
			}
			if(e.target.innerHTML == "M+"){
				var result = parseFloat(memory.pop()) + parseFloat(input.innerHTML); 
				input.innerHTML = result; 
				memory = []; 
				memory.push(result); 
			}
			if(e.target.innerHTML == "M-"){
				var result = parseFloat(memory.pop()) - parseFloat(input.innerHTML); 
				input.innerHTML = result;  
				memory = []; 
				memory.push(result);  
			}
			if(e.target.innerHTML == "MC"){
				memory = [];  
			}
			
		})
	}

	for (var i = 0; i < number.length; i++) {
		 
		  number[i].addEventListener("click", function(e) {
			  var string = input.innerHTML; 
			  input.innerHTML += e.target.innerHTML; 			  
		  });
		} 
	
	for (var i = 0; i < operator.length; i++) {
		  operator[i].addEventListener("click", function(e) {
			  var string = input.innerHTML; 
			  input.innerHTML += e.target.innerHTML; 		   
		  });
	}

	equal.addEventListener("click", function() {

		  var string = input.innerHTML;
		  var numbers = string.split(/\+|\-|\x|\%/g);
		  var operators = string.replace(/[0-9]|\./g, "").split("");

		  var divideIndex = operators.indexOf("%");
		  while (divideIndex != -1) {
		    numbers.splice(divideIndex, 2, numbers[divideIndex] / numbers[divideIndex + 1]);
		    console.log(numbers); 
		    operators.splice(divideIndex, 1);		    
		    divideIndex = operators.indexOf("%");
		  }

		  var multiplyIndex = operators.indexOf("x");
		  while (multiplyIndex != -1) {
		    numbers.splice(multiplyIndex, 2, numbers[multiplyIndex] * numbers[multiplyIndex + 1]);
		    operators.splice(multiplyIndex, 1);
		    multiplyIndex = operators.indexOf("x");
		  }

		  var subtractIndex = operators.indexOf("-");
		  while (subtractIndex != -1) {
		    numbers.splice(subtractIndex, 2, numbers[subtractIndex] - numbers[subtractIndex + 1]);
		    operators.splice(subtractIndex, 1);
		    subtractIndex = operators.indexOf("-");
		  }

		  var addIndex = operators.indexOf("+");
		  while (addIndex != -1) {
		    // using parseFloat is necessary, otherwise it will result in string concatenation :)
		    numbers.splice(addIndex, 2, parseFloat(numbers[addIndex]) + parseFloat(numbers[addIndex + 1]));
		    operators.splice(addIndex, 1);
		    addIndex = operators.indexOf("+");
		  }

		  input.innerHTML = numbers[0]; // displaying the output

	});

		// clearing the input on press of clear
	clear.addEventListener("click", function() {
		  input.innerHTML = "";
	})
}


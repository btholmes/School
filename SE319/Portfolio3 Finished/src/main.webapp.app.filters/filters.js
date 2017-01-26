(function() {
	'use strict'; 
	
	angular.module('myApp')
	.filter('dayFilter', function(){
		return function(data, scope) {
			var result = []; 
			for (var i =0; i < data.length; i++) {
            if(data[i].id == scope.vm.daySchedule) 
            { 
            result.push({id: data[i].id, name: data[i].name, status: data[i].status});  
            }
        } 
		scope.vm.theseTasks = result.length; 
			
			  return data.filter(function(element, index, array) {
			      return element.id == scope.vm.daySchedule;
			    });

		}
		
	}); 
	
	
})(); 
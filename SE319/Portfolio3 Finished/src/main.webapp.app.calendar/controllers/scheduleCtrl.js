(function(){
	'use strict'; 
	
	angular.module('myApp')
	.controller('scheduleCtrl', scheduleCtrl); 
	
	scheduleCtrl.$inject = ['$scope']; 
	
	function scheduleCtrl($scope)
	{
		var date = new Date();
		var thisMonth = date.getMonth() + 1; 
		var thisYear = date.getFullYear(); 
		var thisDate = date.getDate(); 
		
		var vm = this; 
		vm.calMonth = thisMonth; 
		vm.calYear = thisYear; 
		vm.theseTasks = 0;
		vm.daySchedule = ""; 
		vm.saved = localStorage.getItem('tasks');
		vm.tasks = []; 
		vm.setEvent = setEvent;
		vm.addTask = addTask; 
		vm.removeTask = removeTask;
		vm.savedDates = savedDates; 

		
		function setEvent(date) {
	        vm.daySchedule = $scope.currentMonth + " " + date + ", " + vm.calYear;
	        $('.active').removeClass('active'); 
	        $('#' + date).addClass('active'); 

	        vm.savedDates(); 
		}
		
//		if(JSON.parse(vm.saved).length == 0); 
//		{
//			vm.saved = null; 
//		}
		

		if (JSON.parse(vm.saved) === null) {
			vm.tasks = [{
				id: "December 15, 2016",
				name: "Practice",
				status: true
			}, {
				id: "December 15, 2016",
				name: "Develop",
				status: true
			}, {
				id: "December 15, 2016",
				name: "Celebrate my Birthday",
				status: false
			}, ];
			
						
		} else {
			vm.tasks = JSON.parse(vm.saved);
		}
		

		localStorage.setItem('tasks', JSON.stringify(vm.tasks));

		function addTask() {

			vm.errorMsg = "";
			var start = vm.daySchedule.indexOf(" ") + 1; 
			var end = vm.daySchedule.indexOf(","); 
			var day = vm.daySchedule.substring(start,end); 
			
			if (!vm.pushTask)
				return;

			if(!$('#' + day).hasClass("storedData"))
				$('#' + day).addClass("storedData");  
			var exists = false;

			if (!exists) {
				vm.tasks.push({
					id: vm.daySchedule,
					name: vm.pushTask,
					status: false
				});
			}
			

			vm.pushTask = "";
			localStorage.setItem('tasks', JSON.stringify(vm.tasks));
			vm.savedDates(); 
		}
		

		function removeTask(x) {
			if((vm.theseTasks -1) <= 0){
				$('.active').removeClass('storedData'); 
			}
 
			vm.theseTasks--; 
			vm.errorMsg = "";
			for(var i = 0; i < vm.tasks.length; i++){
				if(vm.tasks[i].id == vm.daySchedule)
				{   
//					alert(JSON.stringify(vm.tasks[i]));  
					if(x == 0){
						vm.tasks.splice(i, 1);
						break; 
					}
					else{
						x--; 
					}
				}
				
			} 
			localStorage.setItem('tasks', JSON.stringify(vm.tasks));
			savedDates(); 
		}
		
		function savedDates() {
			var idMatch = ""; 
			var month = ""; 
			$('.date').removeClass("storedData"); 
//			alert($scope.days.length); 
			for(var i = 0; i < vm.tasks.length; i++)
			{
				var thisDay = vm.tasks[i].id;  	
				var start = thisDay.indexOf(" ") + 1; 
				var end = thisDay.indexOf(",");
				var day = thisDay.substring(start,end); 
				month = thisDay.substring(0, start-1); 
				var year = thisDay.substring((end+2), thisDay.length);		
				idMatch = day + month + year; 
				
				if( $scope.currentMonth == month && vm.calYear == year){
					$('#'+ day).addClass('storedData');
				}
			}

		}
		
	
	}
	
})(); 


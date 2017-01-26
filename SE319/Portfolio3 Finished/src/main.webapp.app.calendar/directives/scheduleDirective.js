angular.module('myApp')

.directive('wnCalendar', function () {

  return {

    templateUrl: 'main.webapp.app.calendar/views/calendar.html', 
    
    link: function (scope, element, attr) {
    	
      scope.month = new Array();
	      scope.month[0] = "January";
	      scope.month[1] = "February";
	      scope.month[2] = "March";
	      scope.month[3] = "April";
	      scope.month[4] = "May";
	      scope.month[5] = "June";
	      scope.month[6] = "July";
	      scope.month[7] = "August";
	      scope.month[8] = "September";
	      scope.month[9] = "October";
	      scope.month[10] = "November";
	      scope.month[11] = "December";  
    	

     scope.nextMonth = function(){
    	 if(scope.vm.calMonth == 12){
    		 scope.vm.calMonth = 1; 
    		 scope.vm.calYear++;  
    	 }else{
    		 scope.vm.calMonth++; 
    	 }   	 
    	scope.currentMonth = scope.month[scope.vm.calMonth - 1]; 
	    scope.vm.daySchedule = scope.currentMonth + " " + 1 + ', ' + scope.vm.calYear; 
	    scope.vm.setEvent(1);
	    scope.fillDays(); 
     }; 
     
    scope.previousMonth = function(){

    	 if(scope.vm.calMonth == 1){
    		 scope.vm.calMonth = 12; 
    		 scope.vm.calYear--; 
    	 }else{
    		 scope.vm.calMonth--; 
    	 }   	 
    	scope.currentMonth = scope.month[scope.vm.calMonth - 1]; 
	    scope.vm.daySchedule = scope.currentMonth + " " + 1 + ', ' + scope.vm.calYear; 
	    scope.vm.setEvent(1); 
	    scope.fillDays(); 
    }; 
		     
    	

	 scope.dayLabels = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun'];
	     
	 scope.fillDays = function() {

	      var date = new Date(scope.vm.calYear, scope.vm.calMonth, 0);

	      scope.currentMonth = scope.month[scope.vm.calMonth-1]; 

	      var totalDays = date.getDate();
	      var i = 1;
	      scope.days = new Array();
	      
	      // Populate the month itself.
	      while(i <= totalDays) {
	       scope.days.push(i);
	       i++;
	      }
	      
	      // Prefill.
	      var startIndex = new Date(scope.vm.calYear, scope.vm.calMonth-1, 1).getDay();
	 
	      // Deal with sunday being 0 not 7.
	      if(startIndex === 0) {
	         startIndex = 7; 
	      } 
	      
	      var totalDaysInPrevMonth = new Date(scope.vm.calYear, scope.vm.calMonth - 1, 0).getDate();
	      // Store the prev month dates in an array.
	      scope.prevMonthDays = new Array();        
	      if(startIndex > 1) {
	        
	        // Used to count how many days until the current month starts.
	        var j = 1; 
	        
	        // Used to count down from the last day of the month backwards.
	        var lastMonthDate = totalDaysInPrevMonth; 
	        
	        while(j < startIndex) {
	          scope.prevMonthDays.unshift(lastMonthDate);
	          j++;
	          lastMonthDate--;
	        }         
	      }
	
	      
	      // Postfill.
	      var nextMonthDate = 1;      
	      scope.nextMonthDays = new Array();
	      
	      var totalSize =  scope.days.length  + scope.nextMonthDays.length + scope.prevMonthDays.length;
	      	      
	      while(totalSize % 7 !== 0) {
	        scope.nextMonthDays.push(nextMonthDate);
	        nextMonthDate++;
	        totalSize++;
	      }
	  //end of fill days    
	 }
	 scope.fillDays(); 
//	 scope.vm.setEvent(15); 
    }
  };
});
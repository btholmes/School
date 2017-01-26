(function(){
	'use  strict'; 
	
	angular.module("myApp")
	.directive('infowindowunmark', function(){
		var directive = {
				 restrict: 'E',
			     templateUrl: 'main.webapp.app.googleMap/views/infoWindowUnMark.html'
		}; 
		return directive; 
	
	}); 
})(); 
	
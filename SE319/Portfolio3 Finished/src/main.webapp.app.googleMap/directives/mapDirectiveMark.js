(function(){
	'use  strict'; 

	angular.module("myApp")
	.directive('infowindowmark', function(){
		var directive = {
				 restrict: 'E',
			     templateUrl: 'main.webapp.app.googleMap/views/infoWindowMark.html'
		}; 
		return directive; 
	
	}); 
})(); 
	
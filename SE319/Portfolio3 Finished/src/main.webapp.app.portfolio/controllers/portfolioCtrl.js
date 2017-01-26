(function(){
	'use strict';
	
	angular.module("myApp" )
	.controller("portfolioCtrl", portfolioCtrl);  
			
	portfolioCtrl.$inject = ['$state' , '$scope']; 
	
	function portfolioCtrl($state, $scope){
		var vm = this; 
		vm.name = "Portfolio Page"; 
		vm.items = [{name: "Calendar w/ Schedule", href: "schedule", img: "images/calendarImage.png"}, 
		            {name: "Simple Block Game", href: "game", img: "images/gameImage1.png"}, 
		            {name: "Google Maps Api", href: "map", img: "images/MapImage.png"},
		            {name: "COM 309 Project", href: "#", img: "images/Comingsoon.png"},
		            {name: "SE 319 Portfolio", href: "#", img: "images/Comingsoon.png"}]; 
 
	}

})(); 
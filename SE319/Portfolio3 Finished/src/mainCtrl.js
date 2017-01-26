(function(){
	'use strict';
		
	angular.module("myApp" )
	.controller("mainCtrl",mainCtrl);  
			
	mainCtrl.$inject = ['$scope', '$timeout'];
	
	function mainCtrl($scope, $timeout){
		var vm = this; 
		$scope.changeUrl = function() {
			
		}
		$scope.changeShow = function() {
			 $timeout(function(){
				 $scope.show = true
				 }, 100);   
		}; 
		$scope.$watch("show", function() {
			var url = window.location.href; 
			if(url.indexOf("portfolio") != -1){
				$scope.changeShow(); 
			}
			else{
				$scope.show = false; 
			}
		});
	}
})(); 
(function(){
		'use strict'; 
		
		angular.module('myApp')
		.controller('contactsCtrl', contactsCtrl); 
		
		contactsCtrl.$inject = ['$document','$scope','$window']; 
		
		function contactsCtrl($document,$scope,$window)
		{
			$scope.submitted = false;
				// function to submit the form after all validation has occurred		
				$scope.submitForm = function(isValid) {
		     
					// check to make sure the form is completely valid
					if (isValid) {
						alert('Sorry, this form does not actually go anywhere');
					}
		      else {
		        /*$("#usrName").addClass("has-error").addClass("has-feedback");
		        $("#error-icon").removeClass("ng-hide");*/
		        $scope.response='please correct fields';
		        $scope.submitted = true;
		      }

				};
		    $scope.callMe = function(val){
		      if(val==null) {
		        //alert("please enter a value");
		        //$document.getElementById('uName').focus();
		        $("#uName").blur();
		        $("#userName").focus();
		      }
		      else{
		      $window.alert(val);
		      }
		    };
		}; 

})(); 
		
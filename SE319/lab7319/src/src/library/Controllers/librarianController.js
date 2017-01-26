//
// Allows JS to be in its own file
// and html to be in its own file.
//
angular.module('library', [])
.controller('librarianController', function($scope, $http){
	$scope.fetchShelves = function() {
		console.log("function hit")
		$http.get('../Models/data.json').
			then(function(response) {
				console.log("Inside funciont#2");
				$scope.shelvesObj = response.data;
				console.log(response.data)
			}, function(){
				$scope.data = "error";
				console.log(response.data)
			});
	}

$scope.shelvesObj = [{lit:"R1", sci:"R3", sport:"B6", art:"B13"},
                     {lit:"B1", sci:"B11", sport:"B7", art:"B14"},
                     {lit:"R2", sci:"B12", sport:"B8", art:"B15"},
                     {lit:"B2", sci:"B4", sport:"B9", art:"B16"},
                     {lit:"B3", sci:"B5", sport:"B10", art:"B17"},
                     {lit:"R5", sci:"R4", sport:"B19", art:"B18"},
                     {lit:"B20"}];

localStorage.setItem("shelvesObj", JSON.stringify($scope.shelvesObj));
alert("Set"); 
});
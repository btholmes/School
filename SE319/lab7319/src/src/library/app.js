/**
 * 	Allows js to be in its own file and
 *  html in its own file
 */

angular.module('myApp', ['ngRoute'])
.config(function ($routeProvider) {
	$routeProvider.when("/Login", {
		controller: "loginController",
		templateUrl: "login.html"
	});
	
	$routeProvider.when("/student", {
		controller: "studentController",
		templateUrl: "student.html"
	});
	
	$routeProvider.when("/librarian", {
		controller: "librarianController",
		templateUrl: "librarian.html"
	});
});

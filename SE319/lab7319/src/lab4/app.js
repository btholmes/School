/**
 * 	Allows js to be in its own file and
 *  html in its own file
 */

angular.module('myApp', ['ngRoute'])
.config(function ($routeProvider) {
	$routeProvider.when("/login", {
		controller: "bookLibrary.js",
		templateUrl: "login.html"
	});
	
	$routeProvider.when("/underGradView", {
		controller: "bookLibrary.js",
		templateUrl: "underGradView.html"
	});
	
	$routeProvider.when("/admin", {
		controller: "booksLibrary.js",
		templateUrl: "admin.html"
	});
});

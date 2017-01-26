(function() {
	'use strict';

	angular.module("myApp")
	.controller("blogCtrl", blogCtrl);
	
//	blogCtrl.$inject['blogService']; 
	
	function blogCtrl() {
		alert("in blog ctrl"); 
		var vm = this;
//		vm.readPosts = readPosts;
//		vm.post = post; 
//		vm.posts = []; 
//		
//		function readPosts() {
////			alert("in read"); 
//		}
//		
//		function post(article) {
//			if(article == ""){
//				alert("you have to type something"); 
//			}else{
//				$(".textArea").val(""); 
//				vm.posts.push(article);
//				article = ""; 
////				alert('in post ' + article); 
//			}
////			blogService.post(article); 
//			
//		}
	}
})();
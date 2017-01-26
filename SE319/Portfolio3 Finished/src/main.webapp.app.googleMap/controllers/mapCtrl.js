(function(){
	'use strict'; 
	
	angular.module("myApp" )
	.controller("mapCtrl",mapCtrl);  
	
	mapCtrl.$inject = ['Map', '$scope']; 
	
	function mapCtrl(Map, $scope){
		var vm = this; 
	    vm.place = {};
	    vm.search = search; 
	    vm.send = send; 
	    vm.nearbyPlaces = nearbyPlaces; 
	    vm.clearRoute = clearRoute; 
	    vm.center = center; 
	    vm.clearUnMarked = clearUnMarked;
	    vm.goHere = goHere; 
	    vm.distance = distance; 
	    vm.mark = mark;
	    vm.unMark = unMark; 
	    vm.index = 0; 
//	    var htmlElement = '<button ng-click="vm.goHere()" class="btn btn-success">Test</button>';
//	    var compiled = $compile(htmlElement);
	
	    
	    $scope.service = Map; 
	    
	    function search() {

	        vm.apiError = false;
	        Map.search(vm.searchPlace)
	        .then(
	            function(res) { // success
	                Map.addHomeMarker(res);
	                vm.place.name = res.name;
	                vm.place.lat = res.geometry.location.lat();
	                vm.place.lng = res.geometry.location.lng();
	                
	                Map.lat = res.geometry.location.lat(); 
	                Map.lng = res.geometry.location.lng(); 
	                 
	            },
	            function(status) { // error
	                vm.apiError = true;
	                vm.apiStatus = status;
	            }
	           
	        );
	    }
	    
	   function send() {
	        alert(vm.place.name + ' : ' + vm.place.lat + ', ' + vm.place.lng);    
	    }
	   
	   function nearbyPlaces(store, radius) {
		   radius = radius * 1609.34; 
		   Map.nearbyPlaces(store, radius); 
	   }
	   
	   function clearRoute() {
		   Map.clearRoute(); 
		    
//		   Map.directionDisplays = null; 
	   }
	   
	   function center() {
		   Map.map.setCenter({lat: Map.lat, lng: Map.lng}); 
	   }
	   
	   function clearUnMarked() {
		   Map.clearUnMarked(); 
	   }
	   
	   function goHere(marker) {
		   clearRoute(); 
		   Map.goHere(marker); 
	   }
	   
	   function distance(marker) {
		   Map.distance(marker); 
	   }
	   
	   function mark(marker) {
		   Map.mark(marker); 
	   }
	   
	   function unMark(marker) {
		   Map.unMark(marker); 
	   }
	   

// 	   $scope.$watch('service.getAllPlacesLength()', function(){
//		   if(Map.getAllPlacesLength() > 0)
//		   {
//			  var place = Map.allPlaces.pop(); 
//			  Map.showMarkers($scope, place); 		   
//		   }
//	   }); 
 	   
 	   $scope.$watch('service.getMarkersLength()', function(){
// 		   alert('in watch  ' + Map.currentMarkers.length); 
		   if(Map.getMarkersLength() > 0)
		   {
				   var marker = Map.currentMarkers.pop(); 
				   Map.showMarkersWithMarker($scope, marker, marker.mark); 
		   }
	   }); 
	   
	   Map.init(); 
	}
	
})(); 

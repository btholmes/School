(function(){
	'use strict'; 
	
	angular.module("myApp")
	.service("Map", Map);  
	
	Map.$inject = ['$http', '$q', 'CONSTANTS', '$rootScope', '$compile']; 
	
	function Map($http, $q, CONSTANTS, $rootScope, $compile){
		var sv = this; 
		sv.init = init; 
		sv.placeMarker = placeMarker; 
		sv.search = search; 
		sv.addHomeMarker = addHomeMarker; 
		sv.openHomeMarkerWindow = openHomeMarkerWindow; 
		sv.getHomeLocation = getHomeLocation;
		sv.fillPlaceInfo = fillPlaceInfo; 
		sv.getLocationInfo = getLocationInfo;
		sv.locationListener = locationListener; 
		sv.clearUnMarked = clearUnMarked; 
		sv.goHere = goHere; 
		sv.makeEndMarker = makeEndMarker; 
		sv.clearRoute = clearRoute; 
		sv.radians = radians; 
		sv.distance = distance; 
		sv.unMarkEndMarker = unMarkEndMarker; 		
		sv.getCoordinates = getCoordinates; 
		sv.nearbyPlaces = nearbyPlaces; 
		sv.setBounds = setBounds; 
		sv.closeWindows = closeWindows;
		sv.addMarked = addMarked; 
		sv.addMarkerEventListener = addMarkerEventListener; 	
		sv.showMarkersWithMarker = showMarkersWithMarker; 
		sv.clearMarkers = clearMarkers; 		
		sv.mark = mark; 
		sv.unMark = unMark; 
		sv.removeFromMarked = removeFromMarked; 
		sv.getMarkersLength = getMarkersLength; 
		
		sv.placeInfo = {}; 	
		sv.allMarkers = []; 
		sv.marked = []; 
		sv.currentMarkers = []; 
		sv.routeLocationMarkers = []; 
		sv.lat = 0; 
		sv.lng = 0; 
		sv.infoWindow; 
		sv.marker; 
		sv.hereWindow;
		sv.places; 
		sv.directionDisplays = null; 
		sv.bounds; 

	    function init() {
			sv.map = new google.maps.Map(document.getElementById('map'), {
			    center: {lat: -34.397, lng: 150.644},
			    zoom: 6
			});
			sv.map.addListener('click', function(e) {
				    placeMarker(e.latLng, sv.map);
			});
	    	getHomeLocation(); 

	    	sv.places = new google.maps.places.PlacesService(sv.map); 
	    }
	    function placeMarker(latLng, map) {
//	    	  var marker = new google.maps.Marker({
//	    	    position: latLng,
//	    	    map: map
//	    	  });
	    }
	    
	   function search(str) {
	        var d = $q.defer();
	        sv.places.textSearch({query: str}, function(results, status) {
	            if (status == 'OK') {
	                d.resolve(results[0]);
	            }
	            else d.reject(status);
	        });
	        return d.promise;
	    }
	    
	    function addHomeMarker(res) {
	    	if(res.hasOwnProperty('geometry')){
	    		sv.lat = res.geometry.location.lat();
	    		sv.lng = res.geometry.location.lng();
	    		res = res.geometry.location; 
	    	}else{
	    		sv.lat = res.lat; 
	    		sv.lng = res.lng; 
	    	}
	    	fillPlaceInfo();
	        if(sv.marker) sv.marker.setMap(null);
	        
	        sv.marker = new google.maps.Marker({
	            map: sv.map,
	            position: res,
	            animation: google.maps.Animation.DROP,
	            icon: 'Google_Maps_Markers/blue_MarkerA.png'
	        });
        
	        openHomeMarkerWindow(); 
	        sv.map.setCenter({lat: sv.lat, lng: sv.lng});    
	    }
	    
	    function fillPlaceInfo() { 
			
		    getLocationInfo().then(function (data) {	
					sv.placeInfo = data.results; 	
					locationListener(); 
		    }); 
		}
	    
	 	    
		function getLocationInfo() { 
			var url = ""; 
			if(getCoordinates()){
				url = CONSTANTS.REVERSE_GEOLOCATION_BEGINNING + sv.lat + ',' + sv.lng + CONSTANTS.REVERSE_GEOLOCATION_ENDING; 
			} 
			
			return $http.get(url)
	        .then(dataObtained)
	        .catch(dataFailed);
			
	        function dataObtained(response) {       	
	        	return response.data; 
	        }
	        function dataFailed(error) {
	        	console.log('Get Data failed.' + error.data);
	        }
		}
		
		function locationListener() {
			
	        sv.infoWindow = new google.maps.InfoWindow();
//	        var service = new google.maps.places.PlacesService(sv.map);        
	        
	        sv.places.getDetails({
	          placeId: sv.placeInfo[0].place_id
	        }, function(place, status) {
	          if (status === google.maps.places.PlacesServiceStatus.OK) {
	            google.maps.event.addListener(sv.marker, 'click', function() {
	              sv.infoWindow.setContent('<div><strong>' + place.name + '</strong><br>' +
//	                'Place ID: ' + place.place_id + '<br>' +
	                place.formatted_address + '</div>');
	              sv.hereWindow.close(); 
	              sv.infoWindow.open(sv.map, this);
	              sv.map.setCenter({lat: sv.lat, lng: sv.lng}); 
	            });
	          }
	        });
		}
	    
		function openHomeMarkerWindow() {
			sv.hereWindow = new google.maps.InfoWindow({
			    content: 'You are here' 
			  });
			sv.hereWindow.open(map, sv.marker);
		}
	    
		function getHomeLocation() {

			if (navigator.geolocation) {
				 navigator.geolocation.getCurrentPosition(function(position) {
				        var pos = {
				            lat: position.coords.latitude,
				            lng: position.coords.longitude
				        };
				        
				        addHomeMarker(pos); 
//				        sv.map.setCenter(pos);
				    }, function() {
				        handleLocationError(true, infoWindow, sv.map.getCenter());
				    });
			} else {
			    handleLocationError(false, infoWindow, sv.map.getCenter());
			}
			function handleLocationError(browserHasGeolocation, infoWindow, pos) {
				var infoWindow = new google.maps.InfoWindow({map: sv.map});
			    infoWindow.setPosition(pos);
			    infoWindow.setContent(browserHasGeolocation ?
			                          'Error: The Geolocation service failed.' :
			                          'Error: Your browser doesn\'t support geolocation.');
			}			
	        
		}
			
		function getCoordinates() {
			if(sv.lat != 0 && sv.lng != 0)
			{
				return true; 
			}
			return false; 
		}
		
	
		function clearUnMarked() {
			var match = false; 
			for(var i = 0; i < sv.allMarkers.length; i++){
				for(var j = 0; j < sv.marked.length; j++){
					if(sv.allMarkers[i].id === sv.marked[j].id){
						match = true; 
					}
				}
				if(match == false){
					sv.allMarkers[i].setMap(null); 
					sv.allMarkers.splice(i, 1); 
					i--; 
				}else{
					match = false;
				}
			}
		}
		
		
		function nearbyPlaces(store, radius) {
			clearMarkers(); 	
//			google.maps.event.clearListeners(sv.map, 'click');
			sv.bounds = new google.maps.LatLngBounds();
            var initialLatLng = new google.maps.LatLng(sv.lat, sv.lng);
            sv.bounds.extend(initialLatLng);
			var request = {
					    location: {lat: sv.lat, lng: sv.lng},
					    radius: radius,
					    type: [store]
					  };
					  sv.places.nearbySearch(request, function(results, status) {  
						    if (status === google.maps.places.PlacesServiceStatus.OK) {
						        for (var i = 0; i < results.length; i++) {
						            var place = results[i];
						        var position = new google.maps.LatLng(
									    	place.geometry.location.lat(),
									    	place.geometry.location.lng());
						  	      var marker = new google.maps.Marker({
								    	id: place.place_id, 
								    	name: place.name,
								    	vicinity: place.vicinity,
								        position: position,
								        animation: google.maps.Animation.DROP,
								        mark: true
//								        map: sv.map
								      }); 
						  	       	addMarked(marker);
						            var myLatLng = new google.maps.LatLng(place.geometry.location.lat(), place.geometry.location.lng());
						            sv.bounds.extend(myLatLng);
						          }
						        sv.map.setCenter({lat: sv.lat, lng: sv.lng});
						        setBounds(sv.bounds);
						        
						    }
						    else{
						    	alert('Nothing found in this area'); 
						    }
					  }); 	
		}
		
		function setBounds(bounds) {	 
//			sv.map.setZoom(15); 
			sv.map.fitBounds(bounds);
		}
		
		function addMarked(marker) {
//			alert('in add marked ' + sv.marked.length); 
			var match = false; 
			for(var i = 0; i < sv.marked.length; i++){
				if(sv.marked[i].id === marker.id){
					match = true; 
				}
			}
			if(match == false){
				marker.setMap(sv.map); 
				sv.allMarkers.push(marker);
				addMarkerEventListener(marker);
			}
		}
		
		function showMarkersWithMarker(scope, marker, mark) {
				
				var  contentString = ""; 
				  if(mark == true){
					  contentString = '<infowindowmark></infowindowmark>';
				  }else{
					  contentString = '<infowindowunmark></infowindowunmark>';
				  }
			      
			      var compiled = $compile(contentString)(scope);

				      google.maps.event.addListener(marker, 'click', (function() {
				          scope.marker = marker; 
				          scope.$apply();
				          closeWindows(); 
				          sv.infoWindow.setContent(compiled[0]);	
				          sv.infoWindow.open(sv.map, marker);
				      }));
		}
		
		function addMarkerEventListener(marker) {
			sv.currentMarkers.push(marker); 
			$rootScope.$apply();
		}
		
		function clearMarkers() {
			var match = false; 
			for(var i = 0; i < sv.allMarkers.length; i++){
				for(var j = 0; j < sv.marked.length; j++){
					if(sv.marked[j].id === sv.allMarkers[i].id){
						match = true; 
					}
				}
				if(match == true){
					match = false; 
				}else{
					sv.allMarkers[i].setMap(null); 
					sv.allMarkers.splice(i, 1); 
					i--; 
				}
			}
			
		}	
		
		function mark(marker) {
//			alert(sv.marked.length); 
			var position = 1; 
			if(sv.marked.length >= 1){
				position = sv.marked.length + 1; 
			}
			
			for(var i = 0; i < sv.allMarkers.length; i++){
				if(sv.allMarkers[i].id === marker.id){
					sv.allMarkers[i].set('icon', 'Google_Maps_Markers/darkgreen_Marker' + position +  '.png' ); 
					sv.marked.push(sv.allMarkers[i]); 
				}
			}
			closeWindows(); 
			marker.set('mark', false); 
			sv.currentMarkers.push(marker); 
			$rootScope.$apply();
		}
		
		function unMark(marker) {
			marker.set('mark', true); 
			marker.set('icon', undefined); 
			removeFromMarked(marker); 
			sv.currentMarkers.push(marker); 
			closeWindows(); 
			$rootScope.$apply();
		}
		
		function removeFromMarked(marker) {
			for(var i = 0; i < sv.marked.length; i++){
				if(sv.marked[i].id === marker.id){
					sv.marked.splice(i, 1); 
					i--; 
				}
			}
		}
		
		function goHere(marker) {
			var rendererOptions = {
				      map: sv.map,
				      suppressMarkers : true
			}; 
			var directionsService = new google.maps.DirectionsService;
			sv.directionDisplays = new google.maps.DirectionsRenderer(rendererOptions);
	        var start = new google.maps.LatLng(
			    	sv.lat,
			    	sv.lng);
	        var end = marker.position; 

	        directionsService.route({
			          origin: start,
			          destination: end,
			          travelMode: 'DRIVING'
			        }, function(response, status) {
			          if (status === 'OK') {
			        	sv.directionDisplays.setDirections(response);
//			        	var distance = sv.directionDisplays.directions.routes[0].legs[0].distance.text; 
//			        	alert(distance); 
			            makeEndMarker(marker);
			          } else {
			            window.alert('Directions request failed due to ' + status);
			          }
			});
	        $rootScope.$apply();
	        
		}
		
		function radians(x) {
			return x * Math.PI / 180;
		}
		
		function distance(markerB) {
			if(markerB.distance !== undefined){
				alert(markerB.distance); 
			}else{
				var markerA = sv.marker; 
				  var R = 6378137; // Earth’s mean radius in meter
				  var dLat = radians(markerB.position.lat() - markerA.position.lat());
				  var dLong = radians(markerB.position.lng() - markerA.position.lng());
				  var a = Math.sin(dLat / 2) * Math.sin(dLat / 2) +
				    Math.cos(radians(markerA.position.lat())) * Math.cos(radians(markerB.position.lat())) *
				    Math.sin(dLong / 2) * Math.sin(dLong / 2);
				  var c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));
				  var d = R * c;
				  var miles = d / 1609.34; 
				  miles = Math.round(miles*10)/10; 
				  markerB.set('distance', miles); 
				  alert(miles + " miles"); 
			}
		}
		
		function clearRoute() {
			if(sv.directionDisplays !== null){
				sv.directionDisplays.setMap(null);
				sv.directionDisplays = null; 
				setBounds(sv.bounds); 
			}
			if(sv.routeLocationMarkers.length > 0){
				var endMarker = sv.routeLocationMarkers.pop(); 
				unMarkEndMarker(endMarker.end); 
			}
			 
		}
		
		function unMarkEndMarker(marker){
//			removeFromMarked(marker); 
			if(marker.mark === true){
				marker.set('icon', undefined); 
//				marker.set('mark', true); 
			}
			sv.currentMarkers.push(marker); 
			closeWindows(); 
//			$rootScope.$apply();
		}
		
		function  makeEndMarker(marker){
			closeWindows(); 
//			removeFromMarked(marker); 
			if(marker.mark === true){
//				marker.set('icon', "Google_Maps_Markers/brown_MarkerB.png" ); 
			}
//			sv.currentMarkers.push(marker); 
//			$rootScope.$apply();
			sv.routeLocationMarkers.push({start: sv.marker, end: marker}); 
		}
		
		function closeWindows() {
			sv.hereWindow.close(); 
            sv.infoWindow.close(); 
		}
		
		
		function getMarkersLength() {
			return sv.currentMarkers.length; 
		}
		
	}

})(); 
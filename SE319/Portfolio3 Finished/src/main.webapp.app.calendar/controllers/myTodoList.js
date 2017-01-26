//angular.module('myApp')
//.controller("myTodoList", function($scope) {
//
//	$scope.saved = localStorage.getItem('tasks');
//	$scope.tasks = [];
//	$scope.begin = 0; 
//	$scope.count = 4; 
//
//
//	if (localStorage.getItem('tasks') === null) {
//		$scope.tasks = [{
//			id: "December 15, 2016",
//			name: "Practice",
//			status: true
//		}, {
//			id: "December 15, 2016",
//			name: "Develop",
//			status: true
//		}, {
//			id: "December 15, 2016",
//			name: "Celebrate my Birthday",
//			status: false
//		}, ];
//	} else {
//		$scope.tasks = JSON.parse($scope.saved);
//	}
//
//	console.log($scope.tasks);
//	localStorage.setItem('tasks', JSON.stringify($scope.tasks));
//
//	$scope.completedTask = function(action) {
//		$scope.completed = 0;
//		$scope.remaining = 0;
//		angular.forEach($scope.tasks, function(v) {
//			if (v.status == true)
//				$scope.completed++;
//			else
//				$scope.remaining++
//		});
//
//		if (action == "completed")
//			return $scope.completed;
//		else
//			return $scope.remaining;
//
//		localStorage.setItem('tasks', JSON.stringify($scope.tasks));
//	}
//
//	$scope.addTask = function() {
//		$scope.errorMsg = "";
//		if (!$scope.pushTask)
//			return;
//
//		var exists = false;
//		angular.forEach($scope.tasks, function(v) {
//			if (v.name == $scope.pushTask) {
//				exists = true
//				$scope.errorMsg = "Already in the List.";
//			}
//		});
//
//		if (!exists) {
//			$scope.tasks.push({
//				id: $scope.daySchedule,
//				name: $scope.pushTask,
//				status: false
//			});
//		}
//
//		$scope.pushTask = "";
//		localStorage.setItem('tasks', JSON.stringify($scope.tasks));
//	}
//
//	$scope.removeTask = function(x) {
//		$scope.errorMsg = "";
//		$scope.tasks.splice(x, 1);
//		localStorage.setItem('tasks', JSON.stringify($scope.tasks));
//	}
//
//	$scope.completeTask = function(x) {
//		$scope.errorMsg = "";
////		var status = $scope.tasks[x].status;	
//
////		if (status)
////			$scope.tasks[x].status = true;
////		else
////			$scope.tasks[x].status = false;
//
//		localStorage.setItem('tasks', JSON.stringify($scope.tasks));
//	}
//});
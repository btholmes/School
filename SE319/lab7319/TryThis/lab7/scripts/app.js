var myApp = angular.module('myApp', ['ui.router']);


myApp.config(function($stateProvider, $urlRouterProvider){

    $urlRouterProvider.otherwise('/login');

    $stateProvider

        .state('login', {
            url: '/login',
            templateUrl : 'login.html',
            controller : 'loginCtrl',
            controllerAs: 'vm'
        })
        .state('admin', {
            url: '/admin',
            templateUrl : 'admin.html',
            controller  : 'libraryCtrl',
            controllerAs: 'vm'
        })
        .state('student', {
            url: '/student',
            templateUrl : 'student.html',
            controller  : 'libraryCtrl',
            controllerAs: 'vm'
        });

});


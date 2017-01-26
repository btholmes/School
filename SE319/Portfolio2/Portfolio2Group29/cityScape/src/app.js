var myApp = angular.module('myApp', ['ui.router', 'ionic']);


myApp.config(function($stateProvider, $urlRouterProvider){

    $urlRouterProvider.otherwise('/login');

    $stateProvider

        .state('login', {
            url: '/login',
            templateUrl : 'login/views/login.html',
            controller : 'loginCtrl',
            controllerAs: 'vm'
        })
        .state('signUp', {
            url: '/signUp',
            templateUrl : 'login/views/signUp.html',
            controller  : 'signUpCtrl',
            controllerAs: 'vm'
        })
        .state('menu', {
            url: '/menu',
            templateUrl: "menu.html",
            controller : 'homeCtrl',
            controllerAs: 'vm'
        })
        .state('menu.home', {
            url: "/home",
            views: {
                'menuContent': {
                    templateUrl: "home/views/home.html",
                    controller : 'homeCtrl',
                    controllerAs: 'vm'
                }
            },
        })
        .state('menu.cities', {
            url: '/viewCities',
            views: {
                'menuContent': {
                    templateUrl: 'cities/views/cities.html',
                    controller  : 'citiesCtrl',
                    controllerAs: 'vm'
                }
            },
        })
        .state('menu.post', {
            url: '/post',
            views: {
                'menuContent': {
                    templateUrl: 'posts/views/posts.html',
                    controller  : 'postCtrl',
                    controllerAs: 'vm'
                }
            },
        });

});


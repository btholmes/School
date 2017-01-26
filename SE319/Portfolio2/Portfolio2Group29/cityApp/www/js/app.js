// Ionic Starter App

// angular.module is a global place for creating, registering and retrieving Angular modules
// 'starter' is the name of this angular module example (also set in a <body> attribute in index.html)
// the 2nd parameter is an array of 'requires'
var myApp = angular.module('myApp', ['ui.router', 'ionic']);

myApp.run(function($ionicPlatform) {
  $ionicPlatform.ready(function() {
    if(window.cordova && window.cordova.plugins.Keyboard) {
      // Hide the accessory bar by default (remove this to show the accessory bar above the keyboard
      // for form inputs)
      cordova.plugins.Keyboard.hideKeyboardAccessoryBar(true);

      // Don't remove this line unless you know what you are doing. It stops the viewport
      // from snapping when text inputs are focused. Ionic handles this internally for
      // a much nicer keyboard experience.
      cordova.plugins.Keyboard.disableScroll(true);
    }
    if(window.StatusBar) {
      StatusBar.styleDefault();
    }
  });
});


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



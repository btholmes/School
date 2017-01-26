// // Ionic Starter App
//
// // angular.module is a global place for creating, registering and retrieving Angular modules
// // 'starter' is the name of this angular module example (also set in a <body> attribute in index.html)
// // the 2nd parameter is an array of 'requires'
// // 'starter.services' is found in services.js
// // 'starter.controllers' is found in controllers.js
// // var myApp = angular.module('myApp', ['ui.router', 'ionic']);
// angular.module('starter', ['ionic', 'starter.controllers', 'starter.services'])
//
// .run(function($ionicPlatform) {
//   $ionicPlatform.ready(function() {
//     // Hide the accessory bar by default (remove this to show the accessory bar above the keyboard
//     // for form inputs)
//     if (window.cordova && window.cordova.plugins && window.cordova.plugins.Keyboard) {
//       cordova.plugins.Keyboard.hideKeyboardAccessoryBar(true);
//       cordova.plugins.Keyboard.disableScroll(true);
//
//     }
//     if (window.StatusBar) {
//       // org.apache.cordova.statusbar required
//       StatusBar.styleDefault();
//     }
//   });
// })
//
// .config(function($stateProvider, $urlRouterProvider) {
//
//   // Ionic uses AngularUI Router which uses the concept of states
//   // Learn more here: https://github.com/angular-ui/ui-router
//   // Set up the various states which the app can be in.
//   // Each state's controller can be found in controllers.js
//   $stateProvider
//
//   // setup an abstract state for the tabs directive
//     .state('tab', {
//     url: '/tab',
//     abstract: true,
//     templateUrl: 'templates/tabs.html'
//   })
//
//   // Each tab has its own nav history stack:
//
//   .state('tab.dash', {
//     url: '/dash',
//     views: {
//       'tab-dash': {
//         templateUrl: 'templates/tab-dash.html',
//         controller: 'DashCtrl'
//       }
//     }
//   })
//
//   .state('tab.chats', {
//       url: '/chats',
//       views: {
//         'tab-chats': {
//           templateUrl: 'templates/tab-chats.html',
//           controller: 'ChatsCtrl'
//         }
//       }
//     })
//     .state('tab.chat-detail', {
//       url: '/chats/:chatId',
//       views: {
//         'tab-chats': {
//           templateUrl: 'templates/chat-detail.html',
//           controller: 'ChatDetailCtrl'
//         }
//       }
//     })
//
//   .state('tab.account', {
//     url: '/account',
//     views: {
//       'tab-account': {
//         templateUrl: 'templates/tab-account.html',
//         controller: 'AccountCtrl'
//       }
//     }
//   });
//
//   // if none of the above states are matched, use this as the fallback
//   $urlRouterProvider.otherwise('/tab/dash');
//
// });


var myApp = angular.module('myApp', ['ui.router', 'ionic']);

myApp.run(function($ionicPlatform) {
  $ionicPlatform.ready(function() {
    // Hide the accessory bar by default (remove this to show the accessory bar above the keyboard
    // for form inputs)
    if (window.cordova && window.cordova.plugins && window.cordova.plugins.Keyboard) {
      cordova.plugins.Keyboard.hideKeyboardAccessoryBar(true);
      cordova.plugins.Keyboard.disableScroll(true);

    }
    if (window.StatusBar) {
      // org.apache.cordova.statusbar required
      StatusBar.styleDefault();
    }
  });
});

myApp.config(function($stateProvider, $urlRouterProvider){

  $urlRouterProvider.otherwise('/login');

  $stateProvider

    .state('login', {
      url: '/login',
      // templateUrl : '../templates/login/views/login.html',
      template: "<h1>Login</h1>",
      controller : 'loginCtrl',
      controllerAs: 'vm'
    })
    .state('signUp', {
      url: '/signUp',
      templateUrl : '../templates/login/views/signUp.html',
      controller  : 'signUpCtrl',
      controllerAs: 'vm'
    });
    // .state('menu', {
    //   url: '/menu',
    //   templateUrl: "menu.html",
    //   controller : 'homeCtrl',
    //   controllerAs: 'vm'
    // })
    // .state('menu.home', {
    //   url: "/home",
    //   views: {
    //     'menuContent': {
    //       templateUrl: "home/views/home.html",
    //       controller : 'homeCtrl',
    //       controllerAs: 'vm'
    //     }
    //   },
    // })
    // .state('menu.cities', {
    //   url: '/viewCities',
    //   views: {
    //     'menuContent': {
    //       templateUrl: 'cities/views/cities.html',
    //       controller  : 'citiesCtrl',
    //       controllerAs: 'vm'
    //     }
    //   },
    // })
    // .state('menu.post', {
    //   url: '/post',
    //   views: {
    //     'menuContent': {
    //       templateUrl: 'posts/views/posts.html',
    //       controller  : 'postCtrl',
    //       controllerAs: 'vm'
    //     }
    //   },
    // });

});


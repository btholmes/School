angular.module("myApp", ['ui.router', 'ngAnimate'])
	.config(function($stateProvider, $urlRouterProvider){
		
		$urlRouterProvider.otherwise('/home'); 
		
		$stateProvider
		.state('home', {			
			name: 'home', 
			url: '/home',
			templateUrl: 'main.webapp.app.home/views/home.html',
			controller: 'myCtrl',
			controllerAs: 'vm'
			
		})
		.state('game', {
			url: '/game',
			templateUrl: 'main.webapp.app.home/views/home-game.html'	
		})
		.state('about', {
			name: 'about', 
			url: '/about', 
			templateUrl: 'main.webapp.app.about/views/about.html', 
			controller: 'aboutCtrl',
			controllerAs: 'vm'
		})
		.state('portfolio', {
			name: 'portfolio', 
			url: '/portfolio', 
			templateUrl: 'main.webapp.app.portfolio/views/portfolio.html', 
			controller: 'portfolioCtrl',
			controllerAs: 'vm'
		})
		.state('blog', {
			name: 'blog', 
			url: '/blog', 
			templateUrl: 'main.webapp.app.blog/views/blog.html',
			controller: 'blogCtrl',
			controllerAs: 'vm'
		})
		.state('contacts', {
			name: 'contacts', 
			url: '/contacts', 
			templateUrl: 'main.webapp.app.contact/views/contacts.html', 
			controller: 'contactsCtrl',
			controllerAs: 'vm'
		}) 
		.state('schedule', {
			name: 'schedule', 
			url: '/schedule', 
			templateUrl: 'main.webapp.app.calendar/views/schedule.html',
			controller: 'scheduleCtrl',
			controllerAs: 'vm'
		})
		.state('map', {
			name: 'map', 
			url: '/map', 
			templateUrl: 'main.webapp.app.googleMap/views/map.html', 
			controller: 'mapCtrl',
			controllerAs: 'vm'
		});
		
	});
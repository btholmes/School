angular.module("myApp", ['ui.router', 'ngAnimate'])
	.config(function($stateProvider, $urlRouterProvider){
		
		$urlRouterProvider.otherwise('/login'); 
		
		$stateProvider		
		.state('login', {
			name: 'login',
			url: '/login', 
			templateUrl: 'main.webapp.app.login/views/login.html',
			controller: 'loginCtrl', 
			controllerAs: 'vm'
		})
		.state('passRecovery', {
			name: 'passRecovery',
			url: '/passRecovery', 
			templateUrl: 'main.webapp.app.login/views/passRecovery.html',
			controller: 'loginCtrl', 
			controllerAs: 'vm'
		})
		.state('home', {			
			name: 'home', 
			url: '/home',
			templateUrl: 'main.webapp.app.home/views/home.html',
//			template: '<h1>Home</h1>',
			controller: 'myCtrl', 
			controllerAs: 'vm'
			
		})
		.state('game', {
			url: '/game',
			templateUrl: 'main.webapp.app.home/views/home-game.html'	
		})
		.state('home.scores', {
			url: '/scores',
			views: {
				'scores@home' : {
					templateUrl: 'main.webapp.app.home/views/home-scores.html'
				}
			}
		})
		.state('about', {
			name: 'about', 
			url: '/about', 
			templateUrl: 'main.webapp.app.about/views/about.html', 
//			template: '<h1>About</h1>',
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
		.state('blog.read', {
			url: '/readBlog',
			views: {
				'read@blog' : {
					templateUrl: 'main.webapp.app.blog/views/readBlog.html'
				}
			}
		})
		.state('blog.write', {
			url: '/writeBlog',
			views: {
				'write@blog' : {
					templateUrl: 'main.webapp.app.blog/views/writeBlog.html'
				}
			}
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
//		.state('optum', {
//			name: 'optum', 
//			url: '/optum', 
//			templateUrl: 'src/main/webapp/app/optum/FrontEnd/chargeback/views/chargebackAnalytics.html', 
//			controller: 'chargebackAnalyticsCtrl',
//	    	controllerAs: 'vm'
//		});
//		.state('schedule.events', {
//			url: '/events', 
//			views: {
//				'events@schedule' : {
//					templateUrl: 'partials/schedule-events.html'
//				}
//			}, 
//			controller: 'scheduleCtrl'
//		}); 
//		
		
	});
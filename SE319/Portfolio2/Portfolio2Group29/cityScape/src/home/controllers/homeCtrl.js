(function(){
    'use strict';

    myApp.controller('homeCtrl', homeCtrl);

    homeCtrl.$inject = ['$state', 'logOutService'];

    function homeCtrl($state, $logOutService)
    {

        var vm = this;
        vm.message = "Home page";
        vm.logOut = logOut;
        vm.goToCities = goToCities;
        vm.user = localStorage.getItem("user");

        if(localStorage.getItem("user") == null){
            logOut();
        }


        function goToCities(){
            $state.go("menu.cities");
            var newImage = localStorage.getItem("newImage");
            if(newImage){
                window.location.href = window.location.href;
                localStorage.setItem("newImage", null);
            }

        }

        function logOut(){

            localStorage.setItem("user", null);
            localStorage.setItem("newImage", null);
            $state.go('login');
            $logOutService.logMeOut()
                .then(function(data) {

                });

        }

    }

})();
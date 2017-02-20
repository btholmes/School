(function(){
    'use strict';

    myApp.controller('loginCtrl', loginCtrl);

    loginCtrl.$inject = ['$state', '$scope'];

    function loginCtrl($state, $scope)
    {
        // var vm = this;
        // vm.login = login;
        // vm.userLogin;
        // vm.userPass;
        alert("in login");

        $scope.login = function(){

            var user = $scope.user;
            var pass = $scope.pass;

            if(user.match(/admin/) && pass.match(/admin/)){
                $state.go("admin");
                localStorage.setItem("user", user);
            }
            else if(user.match(/^U/)){
                $state.go("student");
                localStorage.setItem("user", user);
            }
            else{
                alert("That is not a correct user and password");
            }
        }



    }

})();
(function(){
    'use strict';

    myApp.service("logOutService", logOutService);

    logOutService.$inject = ['$http','CONSTANTS'];

    function logOutService($http, CONSTANTS) {

        var sv = this;
        sv.logMeOut = logMeOut;


        function logMeOut() {
            return $http({
                method: 'POST',
                url: CONSTANTS.log_out_url
            });
        }


    }
})();
(function(){
    'use strict';

    myApp.directive('tableDirective', tableDirective);

    function tableDirective()
    {
        return {

                templateUrl : "table.html"
        };

    };

})();


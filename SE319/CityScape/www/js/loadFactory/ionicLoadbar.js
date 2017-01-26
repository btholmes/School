(function(){
    'use strict';

    myApp.factory("ionicLoadbar", ionicLoadbar);

    ionicLoadbar.$inject = ['$ionicLoading'];

    function ionicLoadbar($ionicLoading) {

        var factory = this;
        factory.showLoadBar = showLoadBar;
        factory.hideLoadBar = hideLoadBar();



        function showLoadBar(){
            $ionicLoading.show({
                content: '<i class="icon ion-loading-c"></i>',
                animation: 'fade-in',
                showBackdrop: false,
                maxWidth: 50,
                showDelay: 0
            });
        }

        function hideLoadBar(){
           $ionicLoading.hide();
        }

        return {
            show: function() {
               return showLoadBar();
            },
            hide: function() {
                return hideLoadBar();
            }
        };

    }

})();
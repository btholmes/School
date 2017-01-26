(function(){
    'use strict';

    myApp.controller('citiesCtrl', citiesCtrl);

    citiesCtrl.$inject = ['getImagesService', 'ionicLoadbar'];

    function citiesCtrl($getImagesService, $ionicLoadbar)
    {

        var vm = this;
        vm.callService = callService;
        vm.init = init;
        vm.slides = [];

        init();

        vm.options = {
            direction: 'vertical',
            slidesPerView: '1',
            paginationClickable: true,
            showNavButtons: false
        };


        function init(){
            callService();

        }
        function callService(){
            $ionicLoadbar.show();
            $getImagesService.getImages()
                .then(function(data) {
                    $ionicLoadbar.hide();
                    vm.slides = data.data.reverse();

                    // alert(JSON.stringify(vm.slides));
                });
        }



    }

})();
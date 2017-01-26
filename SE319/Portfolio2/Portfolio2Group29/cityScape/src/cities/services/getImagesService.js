(function(){
    'use strict';

    myApp.service("getImagesService", getImagesService);

    getImagesService.$inject = ['$http','CONSTANTS'];

    function getImagesService($http, CONSTANTS) {

        var sv = this;
        sv.getImages = getImages;

        function getImages() {
            return $http({
                method: 'POST',
                url: CONSTANTS.get_images_url
            });
        }

    }

})();
(function(){
    'use strict';

    myApp.service("imageService", imageService);

    imageService.$inject = ['$http','CONSTANTS'];

    function imageService($http, CONSTANTS) {

        var sv = this;
        sv.storeImage = storeImage;

        function storeImage(image, cityState, desc, d, uniqueID) {
            return $http({
                method: 'POST',
                url: CONSTANTS.store_image_url,
                // url: "./php/putImageInDirectory.php",
                data: {
                    'item' : image,
                    'city' : cityState,
                    'description' : desc,
                    'date' : d,
                    'id' : uniqueID
                }
            });
        }


    }

})();
(function(){
    'use strict';

    myApp.controller('postCtrl', postCtrl);

    postCtrl.$inject = ['$http', 'imageService','ionicLoadbar'];

    function postCtrl($http, $imageService, $ionicLoadbar)
    {

        var vm = this;
        vm.post = post;
        vm.checkCityState = checkCityState;
        vm.checkDescription = checkDescription;
        vm.checkImage = checkImage;
        vm.createID = createID;
        vm.cityState;
        vm.description;
        vm.uploadMe;
        var now = new Date();
        var month = now.getUTCMonth() + 1; //months from 1-12
        var day = now.getUTCDate();
        var year = now.getUTCFullYear();
        var hours = now.getHours();
        var minutes = now.getMinutes();
        vm.date = year + '-' + month + '-' + day + "-" + hours + ":" + minutes;
        vm.uniqueID;


        function createID(){
            var date = new Date();
            var components = [
                date.getYear(),
                date.getMonth(),
                date.getDate(),
                date.getHours(),
                date.getMinutes(),
                date.getSeconds(),
                date.getMilliseconds()
            ];
            vm.uniqueID = components.join("");
        }



        function post() {
            if(checkCityState() && checkDescription()){
                if(checkImage()){
                    $ionicLoadbar.show();
                    createID();
                    $imageService.storeImage(vm.uploadMe, vm.cityState, vm.description, vm.date.toString(), vm.uniqueID)
                        .then(function(data) {
                            $ionicLoadbar.hide();
                            alert("Posted Successfully");
                            localStorage.setItem("newImage", 1);
                            vm.cityState = "";
                            vm.description = "";
                            vm.uploadMe = "";
                        });
                }else{
                    alert("Plase upload an image in .jpg .bmp or .png format");
                }
            }
        }

        function checkCityState(){
            // if(vm.cityState != undefined && vm.cityState.match(/^([A-Z]{1})[a-z]+,[ ][A-Z]{2}/)){
            //     return true;
            // }else{
            //     alert("Please make sure the city state is in the form 'Ames, IA'");
            //     return false;
            // }
            // if(localStorage.getItem("user") == null){
            //     return false;
            // }
            return true;
        }

        function checkDescription(){

            if(vm.description != undefined){
                return true;
            }
            alert("Please enter a description");
            return false;
        }

        function checkImage(){
            if(vm.uploadMe != undefined){
                return true;
            }

            return false;

        }

    }

})();





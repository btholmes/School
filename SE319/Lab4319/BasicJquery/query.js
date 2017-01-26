function init(){
    // alert("ready");


    // Changes color to red on hover event
    $("#css1").hover(function() {
        $("#css1").css("color", "red");
    });
    // Changes font-size to 30px on hover
    $("#css2").hover(function() {
        $("#css2").css("font-size", "30px");
    });
    // Changes background color to green on hover
    $("#css3").hover(function() {
        $("#css3").css("background-color", "green");
    });
    // Changes border to a 1px solid orange on hover
    $("#css4").hover(function() {
        $("#css4").css("border", "1px solid orange");
    });
    // Changes font to tangerine on hover
    $("#css5").hover(function() {
        $("#css5").css("font-family", "tangerine");
        $("#css5").css("font-size", "50px");
    });


    // Hides div on hover
    $("#effect1").hover(function() {
        $("#effect1").hide();
    });
    // Fades 2nd div out, and first div back in
    $("#effect2").hover(function() {
        $("#effect2").fadeOut(1500);
        $("#effect1").fadeIn(1000);
    });
    // Adds a class to div
    $("#effect3").hover(function() {
        $("#effect3").addClass("weird");
    });
    // Changes text
    $("#effect4").hover(function() {
        $("#effect4").text("I'm Changing");
    });
    // Causes div to slide up on hover
    $("#effect5").hover(function() {
        $("#effect5").slideUp(800);
    });


    // Alerts on click event
    $("#event1").click(function() {
        alert("You clicked the first event");
    });
    // Alerts on mouseover event
    $("#event2").on("mouseover", function() {
        alert("on mouse over event");
    });
    // Alerts on mouse leave event
    $("#event3").on("mouseleave", function() {
        alert("your mouse left the item");
    });
    // Alerts on double click
    $("#event4").on("dblclick", function() {
        alert("you double clicked me");
    });
    // Alerts when mouse enters the div
    $("#event5").on("mouseenter", function() {
        alert("mouse entered");
    });



}
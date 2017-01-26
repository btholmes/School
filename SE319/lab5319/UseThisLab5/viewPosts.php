<html>
<head>
    <title>View Posts</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">

    <!-- jQuery library -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>

    <!-- Latest compiled JavaScript -->
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>

    <link rel = "stylesheet" href = "style.css">
</head>

<body>
<h1 class = 'text-center text-warning'>View Posts</h1>
<button onclick = "goToMessages()" style = "position: absolute; top:25px; right: 110px;" class = "btn btn-lg btn-primary">Messages</button>
<br>
<br>

<h4 style = "margin-left: 10px" class = "text-success">Welcome : <?php session_start(); echo $_SESSION['name']; ?></h4>
<button style = "margin-left: 5px" onclick = "logout()" class = "btn btn-sm btn-success">LogOut</button>
<br>
<br>



<div class = "posts">


    <?php
    /**
     * Created by IntelliJ IDEA.
     * User: btholmes
     * Date: 10/15/16
     * Time: 9:09 AM
     */

            $info = "[" . file_get_contents("/Applications/XAMPP/xamppfiles/htdocs/UseThisLab5/posts.txt") . "]";

            $info = json_decode($info);



    //This for loop loops through the posts, and displays them to the page
        $count = count($info);

         $_SESSION['count'] = $count - 1;

    for($i = $count - 1; $i >= 0; $i--) {

            $item = $info[$i];
            $_SESSION['message'] = $item->message;
            $_SESSION['subject'] = $item->subject;
            $_SESSION['time'] = $item->time;

                    echo " 
                            <div class = 'row'>
                            <div class = 'col-md-2 col-md-offset-1'>
                            <b class = 'text-info'>Subject: </b>
                            <br>
                            
                         ";

                    echo $_SESSION['subject'];


                    echo "    
                         </div>
                         <div  class = 'col-md-5 message' >
                         <b class = 'text-info'>Message</b>                   
                         <p onclick = 'updateMessage(event)' id = $i>
                         
                         ";

                    echo $_SESSION['message'];

                    echo "  
                            </p>
                            <br>
                         ";



                    echo "  
                            </div>
                            <div class = 'col-md-3'>
                            <b class = 'text-info'>Time</b>
                            <br>
                            
                         ";

                    echo $_SESSION['time'];


                    echo "        
                            </div>
                            </div>
                            </div>
                            
                         ";

        }

    ?>




<br>

<div class = "row">
    <div class = "col-md-offset-1 col-md-10">
      <div class = "form-group">
            Subject
            <input id = "subject" type = "text" class = "form-control">
      </div>
    </div>
    <div class = "col-md-1"></div>
</div>
<div class = "row">
    <div class = "col-md-offset-1 col-md-10">
        <div class = "form-group">
            Message
            <textarea id = "message" class = "form-control"></textarea>
        </div>
    </div>
    <div class = "col-md-1"></div>
</div>
<div class = "row">
        <div class = "col-md-1 col-md-offset-10">
            <button onclick = "makePost()" class = "btn btn-primary btn-lg">Post</button>
        </div>
        <div class = "col-md-1"></div>
</div>

</body>
<script>
    function makePost(){
        var subject = $("#subject").val();
        var message = $("#message").val();
        var time = new Date();


        $.ajax({
            type: "POST",
            url: "/UseThisLab5/updatePosts.php",
            data: { subject: subject,
                    message: message,
                    time: time,
                    update: 0
            }
        }).done(function( msg ) {
            //alert( "Data Saved: " + msg );
            //alert(msg);

           addPost(subject, message, time);

            $("#subject").val("");
            $("#message").val("");
        });

    }

    function updateMessage(e){
        var msg = prompt("Please enter the new message", ": )");
        var oldMsg = $("#" + e.target.id).html();

        changeMessage(oldMsg, msg, e.target.id)

    }

    function changeMessage(oldMsg, msg, id){
        $.ajax({
            type: "POST",
            url: "/UseThisLab5/updatePosts.php",
            data: { oldMsg: oldMsg,
                newMsg: msg,
                update: 1
            }
        }).done(function( data ) {
            //alert( "Data Saved: " + msg );
            data = parseInt(data);
            if(data){
                $("#" + id).html(msg);
                alert("Changed successfully");
            }else {
                alert("That's not your message");
            }

        });
    }

    function addPost(subject, message, time){

        <?php
            $_SESSION['count'] = $_SESSION['count'] + 1;
        ?>

        $('.posts').prepend(
            "<div class = 'row'> <div class = 'col-md-2 col-md-offset-1'><b class = 'text-info'>Subject: </b><br>" +
              subject +
            "</div><div  class = 'col-md-5 message' ><b class = 'text-info'>Message</b><p onclick = 'updateMessage(event)' id ="+<?php echo $_SESSION['count'] ?> +">" +
            message +
            "</p><br>" +
            " </div><div class = 'col-md-3'><b class = 'text-info'>Time</b><br>" +
            time +
            "</div></div></div>");
    }

    function goToMessages(){

        window.location.href = "message.php";
    }

    function logout(){
        alert("in logout");
    }


</script>
</html>








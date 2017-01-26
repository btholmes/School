<html>
<head>
    <title>Send Message</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">

    <!-- jQuery library -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>

    <!-- Latest compiled JavaScript -->
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>

    <link rel = "stylesheet" href = "style.css">
</head>


<h1 class = "text-center text-primary">Send Message</h1>
<button style = "margin-left: 10px" onclick = "posts()" class = "btn btn-success">Back To Posts</button>
<br>
<br>

<body>

<?php
$path = '/Applications/XAMPP/xamppfiles/php/phpseclib';
set_include_path($path);
include_once('Crypt/RSA.php');



//Function for decrypting with RSA
function rsa_decrypt($string, $private_key)
{
    //Create an instance of the RSA cypher and load the key into it
    $cipher = new Crypt_RSA();
    $cipher->loadKey($private_key);
    //Set the encryption mode
    $cipher->setEncryptionMode(CRYPT_RSA_ENCRYPTION_PKCS1);
    //Return the decrypted version
    return $cipher->decrypt($string);
}

session_start();

$user = $_SESSION['name'];

$login = "[" . file_get_contents('/Applications/XAMPP/xamppfiles/htdocs/UseThisLab5/users.txt') . "]";
$login = json_decode($login);
$found = 0;
$private_key;

for($i = 0; $i < count($login); $i++) {
    if (!strcmp($login[$i]->name, $user)) {
        $private_key = $login[$i]->private_key;
    }
}



$fileContents = file_get_contents("/Applications/XAMPP/xamppfiles/htdocs/UseThisLab5/messages.txt");

$info = "[" . $fileContents . "]";

$info = json_decode($info);

$count = count($info);

$_SESSION['messageCount'] = $count - 1;

for($i = $count - 1; $i >= 0; $i--) {

    $item = $info[$i];
    $message = $item->message;
    $receiver = $item->receiver;
    $time = $item->time;
    $from = $item->from;


    if(!strcmp($user, $receiver)){

        $message = rsa_decrypt($message, $private_key);

    echo " 
                            <div class = 'row'>
                            <div class = 'col-md-2 col-md-offset-1'>
                            <b class = 'text-info'>From: </b>
                            <br>
                            
                         ";

    echo $from;


    echo "    
                         </div>
                         <div  class = 'col-md-5 message' >
                         <b class = 'text-info'>Message</b>                   
                         <p onclick = 'updateMessage(event)' id = $i>
                         
                         ";

    echo $message;

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

    echo $time;


    echo "        
                            </div>
                            </div>
                            </div>
                            
                         ";

    }

}


?>

<br><br>

<div class = "row">
    <div class = "col-md-offset-1 col-md-10">
        <div class = "form-group">
            Receiver
            <input id = "receiver" type = "text" class = "form-control">
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
        <button onclick = "sendMessage()" class = "btn btn-primary btn-lg">Send</button>
    </div>
    <div class = "col-md-1"></div>
</div>

    <script>
        function sendMessage(){
            var receiver = $("#receiver").val();
            var message = $("#message").val();
            var time = new Date();

            $.ajax({
                type: "POST",
                url: "/UseThisLab5/sendMessage.php",
                data: { receiver: receiver,
                    message: message,
                    time: time
                }
            }).done(function( msg ) {
                var sent = parseInt(msg);
                if(sent){
                    alert("Message Sent Successfully");
                    $("#receiver").val("");
                    $("#message").val("");
                }else{
                    alert("Receiver doesn't exist");
                }

            });
        }

        function posts(){
            window.location.href = "viewPosts.php";
        }

    </script>
    </body>


</html>
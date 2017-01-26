<?php
$path = '/Applications/XAMPP/xamppfiles/php/phpseclib';
set_include_path($path);
include_once('Crypt/RSA.php');
/**
 * Created by IntelliJ IDEA.
 * User: btholmes
 * Date: 10/16/16
 * Time: 6:59 AM
 */

//Function for encrypting with RSA
function rsa_encrypt($string, $public_key)
{
    //Create an instance of the RSA cypher and load the key into it
    $cipher = new Crypt_RSA();
    $cipher->loadKey($public_key);
    //Set the encryption mode
    $cipher->setEncryptionMode(CRYPT_RSA_ENCRYPTION_PKCS1);
    //Return the encrypted version
    return $cipher->encrypt($string);
}



session_start();

$from = $_SESSION['name'];
$receiver = $_POST['receiver'];
$message = $_POST['message'];
$time = $_POST['time'];




$fileContents = file_get_contents("/Applications/XAMPP/xamppfiles/htdocs/UseThisLab5/messages.txt");
$comma = ",";
if(!$fileContents){
    $comma = "";
}

$userFile = '/Applications/XAMPP/xamppfiles/htdocs/UseThisLab5/messages.txt';
$handle = fopen($userFile, "a+");

$receiverPublicKey;

$login = "[" . file_get_contents('/Applications/XAMPP/xamppfiles/htdocs/UseThisLab5/users.txt') . "]";
$login = json_decode($login);
$found = 0;


for($i = 0; $i < count($login); $i++) {
    if (!strcmp($login[$i]->name, $receiver)) {
        $found = 1;
        $receiverPublicKey = $login[$i]->public_key;
        $message = rsa_encrypt($message, $receiverPublicKey);
    }
}

if($found == 0){
    echo 0;
}else{
    $result = array("from" => $from, "receiver" => $receiver, "message" => $message, "time" => $time);
    fwrite($handle, $comma . json_encode($result) . "\n");
    echo 1;
}


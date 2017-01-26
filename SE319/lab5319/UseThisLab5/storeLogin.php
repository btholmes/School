<?php
$path = '/Applications/XAMPP/xamppfiles/php/phpseclib';
set_include_path($path);
include_once('Crypt/RSA.php');

session_start();

$name = $_POST["name"];
$pass = $_POST["pass"];


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

$rsa = new Crypt_RSA();
$rsa->setPrivateKeyFormat(CRYPT_RSA_PRIVATE_FORMAT_PKCS1);
$rsa->setPublicKeyFormat(CRYPT_RSA_PUBLIC_FORMAT_PKCS1);
extract($rsa->createKey(1024)); /// makes $publickey and $privatekey available

//Private key
$private_key = $privatekey;
$public_key = $publickey;

$userFile = '/Applications/XAMPP/xamppfiles/htdocs/UseThisLab5/users.txt';
$handle = fopen($userFile, "a+");
$comma = ",";
$fileContents = file_get_contents("/Applications/XAMPP/xamppfiles/htdocs/UseThisLab5/users.txt");

if(!$fileContents){
    $comma = "";
}

$info = array("name" => $name, "pass" => $pass, "public_key" => $public_key, "private_key" => $private_key);

fwrite($handle, $comma . json_encode($info) . "\n");

echo "<script>window.location.href = '/UseThisLab5/login.html'; </script>";


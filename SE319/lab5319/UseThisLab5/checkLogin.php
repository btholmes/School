<?php
/**
 * Created by IntelliJ IDEA.
 * User: btholmes
 * Date: 10/15/16
 * Time: 8:43 AM
 */
session_start();

$login = "[" . file_get_contents('/Applications/XAMPP/xamppfiles/htdocs/UseThisLab5/users.txt') . "]";
$login = json_decode($login);

$loginName = $_POST['loginName'];
$loginPass = $_POST["loginPass"];

$foundUser = 0;

for($i = 0; $i < count($login); $i++) {
    if (!strcmp($login[$i]->name, $loginName) && !strcmp($loginPass, $login[$i]->pass)) {
        $foundUser = 1;
        $_SESSION['name'] = $loginName;
        $_SESSION['pass'] = $loginPass;
        echo "<script> window.location.href = '/UseThisLab5/viewPosts.php';</script>";
    }
}


if($foundUser == 0){
        //Wrong user or pass error
        echo "<script>alert('wrong user or pass');
        window.location.href = '/UseThisLab5/login.html';
    </script>";
}



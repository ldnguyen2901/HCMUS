<?php
$path = "C:\\xampp\\htdocs\\Hcmus\\Assignment 2\\Requirement\\DataAccountFB.txt";
$myfile = fopen($path, "r") or die("Unable to open File");
//$writefile = fopen($path, "w");
include "src/header.php";
?>

<?php
session_start();
$user_login = '';
$user_pass = '';
$email_register = '';
if (isset($_POST['name'])) {
    $user_login = $_POST['name'];
}
if (isset($_POST['password'])) {
    $user_pass = $_POST['password'];
}
if (isset($_POST['email1'])) {
    $email_register = $_POST['email1'];
}
$_SESSION['temp'] = $_POST['email1'];
?>

<div class="fb-header">
    <div id="img1" class="fb-header"><img src="img/facebook.png" /></div>
    <?php
    $temp_user_login1 = '';
    $temp_user_pass1 = '';
    while (!feof($myfile)) {
        $keyword = fgets($myfile);
        $tach = explode("|", $keyword);
        if ($user_login == $tach[0]) {
            $temp_user_login1 = $tach[0];
            $temp_user_pass1 = $tach[1];
            break 1;
        }
    }
    if ((empty($user_login) or empty($user_pass)) and empty($email_register)) {
        include "src/form_login.php";
    } else if ($user_pass != $temp_user_pass1 or $user_login != $temp_user_login1) {
    } else if (empty($email_register)) {
    }


    ?>
</div>

<div class="fb-body">
    <?php
    fseek($myfile, 0);
    $temp_user_login2 = '';
    $temp_user_pass2 = '';
    while (!feof($myfile)) {
        $keyword = fgets($myfile);
        $tach = explode("|", $keyword);
        if ($user_login == $tach[0]) {
            $temp_user_login2 = $tach[0];
            $temp_user_pass2 = $tach[1];
            break 1;
        }
    }
    if ((empty($user_login) or empty($user_pass)) and empty($email_register)) {
        include "src/form_register.php";
    } else if ($user_pass != $temp_user_pass2 or $user_login != $temp_user_login2) {
        echo "<p align = 'center'>Sorry your login information is wrong.<br>Click <a href='Assignment2.php'> here </a> to login again </p>";
    } else if (!empty($email_register)) {
        echo "<p align = 'center'>Please see your information again above. <br>
        If you make sure, please press <a href='form_welcome_new_user.php'>Confirm</a>";
    } else {
        echo "<p align = 'center'> <b> Welcome $user_login to my facebook" . "<br>";
        echo "Click <a href='Assignment2.php'> here </a> to logout </p>";
    }
    ?>


</div>

<?php
include "src/footer.php";
fclose($myfile);
//fclose($writefile);
?>
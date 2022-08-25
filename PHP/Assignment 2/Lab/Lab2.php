<?php
include "src/header.php";
?>

<?php
$user_login = '';
if (isset($_POST['name'])) {
    $user_login = $_POST['name'];
}
?>

<div class="fb-header">
    <div id="img1" class="fb-header"><img src="img/facebook.png" /></div>
    <?php
    if (empty($user_login)) {
        include "src/form_login.php";
    }
    ?>
</div>

<div class="fb-body">
    <?php
    if (empty($user_login))
        include "src/form_register.php";
    else {
        echo "<p align = 'center'> <b> Welcome $user_login to my facebook" . "<br>";
        echo "Click <a href='Lab2.php'> here </a> to logout </p>";
    }
    ?>
</div>

<?php
include "src/footer.php";
?>
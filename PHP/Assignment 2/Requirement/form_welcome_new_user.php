<!DOCTYPE html>
<html>

<head>
    <link type="text/css" rel="stylesheet" href="css/style.css" />
    <meta name="Description" content="Facebook Style Homepage Design with Login Form registration for using html and CSS" />

    <meta name="Keywords" content="free, tutorial, on, Java programming, jsp, ejb, html, css, xml, java script, jquery, ajax, php, sql, mysql, database, jdbc, 
odbc, spring, struts, hibernate, array, ANT, servlet, awt, code, programe, programming, Latest,facebook script, google script, twitter script,ecommerce,  Technologies, Free,  Tutorials, References, Examples, 
coder glass, coderglas, coder" />

<body>
    <div class="fb-header">
        <div id="img1" class="fb-header"><img src="img/facebook.png" /></div>
    </div>
    <div class="fb-body">
        <?php
        session_start();
        echo "<p align = 'center'> <b> Welcome " . $_SESSION['temp'] . " to my facebook" . "<br>";
        echo "Click <a href='Assignment2.php'> here </a> to logout </p>";
        ?>
    </div>
</body>

</html>
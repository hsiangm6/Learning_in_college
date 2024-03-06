<html>
    <body>
        <!--when we have an HTML form with the action attribute set to our PHP file, 
        we can access the posted form data using the $_POST associative array.-->
        Welcome <?php echo $_POST['name'];?><br />
        Your age: <?php echo $_POST['age']; ?>
    </body>
</html>
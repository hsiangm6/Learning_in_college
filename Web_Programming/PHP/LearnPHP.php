<html>

<body>
    <!--Include & Require-->
    <!--Use require when the file is required for the application to run.
        Use include when the file is not required. The application should continue, 
        even when the file is not found.-->
    <!--Using this approach, we have the ability to include the same header.php file into multiple pages.-->
    <?php include 'LearnPHP_header.php';
    /*The include and require statements allow for the insertion 
    of the content of one PHP file into another PHP file, before the server executes it.*/ ?>
    <hr>
    <p>some text in LearnPHP.php .</p>

    <?php
    //start the session
    session_start(); //??Notice: session_start(): A session had already been started - ignoring in C:\Users\hsian\Documents\GitHub\中山大學課程\web程式設計\PHP\LearnPHP.php on line 16
    echo "Your name is " . $_SESSION['name']; //output: Your name is John
    /*Your session variables remain available in the $_SESSION superglobal until you close your session.
    All global session variables can be removed manually by using session_unset(). 
    You can also destroy the session with session_destroy().
        • session_destroy ends your current session
        • if not destroyed, sessions will time out after a specified 
        time defined in php.in*/
    session_destroy();

    ?>
</body>

</html>
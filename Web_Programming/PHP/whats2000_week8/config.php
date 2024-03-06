<?php
$link = mysqli_connect("localhost", "EL", "1234567", "php_course");

if (!$link) {
    printf("Could not connect : %s\n", mysqli_connect_error());
    exit();
}

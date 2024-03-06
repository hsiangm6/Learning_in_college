<html>

<body>
    <?php include("predefined.php"); ?>
    <h1>Elaine Wei</h1>
    <h3>Year is "<?= $year ?>" </h3>
    <?php $paragraph = explode(" ", $para); ?>
    <h3>3rd word in paragraph is "<?= $paragraph[2] ?>"</h3>
    <h3>Random number from predefined is "<?= $random_number ?>"</h3>
    <h3>String from function getStringValue is "<?= getStringValue() ?>"</h3>



</body>

</html>
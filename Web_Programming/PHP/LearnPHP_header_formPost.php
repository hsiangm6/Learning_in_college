<?php
//Create an example of a form that adds filled-in data to a file.
if (isset($_POST['try_post_text'])) {
    $name = $_POST['try_post_text'];
    $handle = fopen('names.txt', 'a');
    fwrite($handle, $name . "\n");
    fclose($handle);
}
?>

<form method='post'>
    <!--We did not specify an action attribute for the form, so it will submit to itself.-->
    Name: <input type="txt" name="try_post_text" />
    <input type="submit" name="submit" value="Submit" />
</form>
<?php
//Now, each time a name is entered and submitted, it's added to the "names.txt" file, along with a new line.
//The isset() function determined whether the form had been submitted, as well as whether the text contained a value

<?php
$conn = new PDO("mysql:dbname=imdb_assignment;host=localhost", "root", "");
$old_movies = $conn->query("SELECT name, rank, year FROM movies WHERE rank=8 ORDER BY year LIMIT 3"); ?>
<table>
    <tr>
        <th>Name</th>
        <th>Rank</th>
        <th>Year</th>
    </tr>
    <?php
    foreach ($old_movies as $old_movie) { ?>
        <tr>
            <td><?= $old_movie['name']; ?></td>
            <td><?= $old_movie['rank']; ?></td>
            <td><?= $old_movie['year']; ?></td>
        </tr>
    <?php
    } ?>

</table>
<hr>
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $id = $_POST["id"];
    $movie_name = $_POST["movie_name"];
    $movie_name = $conn->quote($movie_name);
    $change_movie = $conn->exec("UPDATE movies SET name=$movie_name WHERE id=$id");
}

$action_movies = $conn->query("SELECT m.id, m.name, mg.genre FROM movies m JOIN movies_genres mg ON id=movie_id WHERE m.id LIKE '%11' && mg.genre='Action' LIMIT 3");

if ($action_movies->rowCount() == 0) {
    echo "no movies match";
} else {
?><table>
        <tr>
            <th>id</th>
            <th>Name</th>
            <th>Genre</th>
        </tr>
        <?php
        foreach ($action_movies as $action_movie) { ?>
            <tr>
                <td><?= $action_movie['id']; ?></td>
                <td><?= $action_movie['name']; ?></td>
                <td><?= $action_movie['genre']; ?></td>
            </tr>
        <?php
        } ?>

    </table>
<?php
}
?>

<form method="POST">
    Change Name of movie with id: <input type='int' name='id' />
    to: <input type='text' name='movie_name' />
    <input type='submit' value='change' />
</form>
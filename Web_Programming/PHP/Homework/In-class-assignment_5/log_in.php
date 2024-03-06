<html>

<head>
    <link href="_log_in.css" type="text/css" rel="stylesheet" />
    <title>Log In</title>
</head>

<body>
    <h1>Wei Elaine</h1>
    <img src="selfie.jpg" height="208px" width="157px" title="Elaine Wei" alt="Selfie" />
    <div class="log_in">
        <?php
        if (!isset($_COOKIE['login'])) {

            if ($_SERVER["REQUEST_METHOD"] == "GET") { ?>

                <form method="post">
                    Username: <input type="text" name="username" /> <br />
                    password: <input type="text" name="password" /> <br />
                    <input type="submit" />
                </form>

                <?php
            } else if ($_SERVER["REQUEST_METHOD"] == "POST") {
                $username = $_POST["username"];
                $password = $_POST["password"];

                if ($username == "web" && $password == "programming") {
                    setcookie("login", "login", time() + 60); ?>
                    <!--設login的變數代表已登入狀態setcookie("變數", "任意字串", cookie存在的時間)-->
                    <p>web logged in</p>

                <?php
                } else { ?>

                    <p class="incorrect">Incorrect login information</p>
                    <form method="post">
                        Username: <input type="text" name="username" /> <br />
                        Password: <input type="password" name="password" /> <br />
                        <input type="submit" />
                    </form>

            <?php
                }
            }
        } else { ?>
            <p>web logged in</p>
        <?php
        } ?>

    </div>
</body>

</html>
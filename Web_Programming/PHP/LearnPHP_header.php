<?php
/*Variables(large title)*/
$variable_name = "value";
$age = 25;
echo $age;

/*define(name, value, case-insensitive) : 創建常量。常量類似於變量，不同之處在於它們在定義後不能更改或取消定義。
name: Specifies the name of the constant;
value: Specifies the value of the constant;
case-insensitive:指定常量名稱是否不區分大小寫，默認為假。
*/
define("MSG", "Hello World!", true);
echo MSG; //outputs: "Hello World!"

$str1 = "hello ";
$str2 = "world";
echo $str1 . $str2; //join two strings together using the dot ( .) concatenation operator.

//integer
$int1 = 42;
$int2 = -42;

//float
$x = 42.168;

//boolean
$x = true;
$y = false;

//PHP automatically converts each variable to the correct data type
$str = "10";
$int = 20;
$sum = $str + $int;
echo ($sum); //outputs: 20 

//variable scope
/*A variable declared outside a function has a global scope(範圍).
A variable declared within a function has a local scope, and can only be accessed within that function.*/
$name = "David";
function getName()
{
    global $name; //如果沒有global $name，function就無法取得global variable
    echo $name;
}
getName(); //outputs: 'David'

//variable variables
$a = "hello";
$hello = "Hi!";
echo $$a; //output: 'Hi'

/*Operators (large title)*/
//Dividion, modulus
$num1 = 8;
$num2 = 6;
echo $num1 / $num2; //output: 1.33333
echo $num1 % $num2; //output: 2(餘數)

//Increment & Decrement
$num1++; //equivalent to $num1=$num1+1
$num2++; //equivalent to $num2=$num2-1
$a = 2;
$b = $a++; //$a=3 $b=2
$a = 2;
$b = ++$a; //$a=3 $b=3
$x = 50;
$x += 100;
echo "x:" . $x; //output: 150

//comparison operators
$x = 3;
$y = 2;
$x == $y; //return true if $x is equal to $y
$x === $y; //return true if $x is equal to $y, and they are of the same type
$x != $y; //return true if $x is not equal to $y
$x <> $y; //return true if $x is not equal to $y
$x !== $y; //return true if $x is not equal to $y or they are not of the same type

//logical operators
$x and $y;
$x && $y; //=and
$x or $y;
$x || $y; //=or
$x xor $y; //true if either $x or $y is true, but not both
!$x; //true if $x is not true


/*Arrays (large title)*/
//Numeric arrays
$myArray[0] = "John";
$myArray[1] = "<strong>PHP</strong>";
$myArray[2] = 21;
echo "$myArray[0] is $myArray[2] and knows $myArray[1]"; //output: John is 21 and knows PHP

//Associative arrays (arrays that use named keys that you assign to them.)
$people = array("David" => "27", "Amy" => "21", "John" => "42");
//or
$people['David'] = "27";
$people['Amy'] = "21";
$people['John'] = "42";
echo $people['David'];


/*Multi-dimensional arrays */
//Arrays more than three levels deep are difficult to manage.
//two-dimensional array
$people = array(
    'online' => array('David', 'Amy'),
    'offline' => array('John', 'Rob', 'Jack'),
    'away' => array('Arthur', 'Daniel')
);
echo $people['online'][0]; //output: David


/*Control Structures (large title)*/
//If else
$x = 10;
$y = 20;
if ($x >= $y) {
    echo $x;
} else {
    echo $y;
} //output: 20

//Elseif
$age = 21;
if ($age <= 13) {
    echo 'child.';
} elseif ($age > 13 && $age < 19) {
    echo 'Teenager';
} else {
    echo 'Adult';
} //ouput: 'Adult'

//while loop
$i = 1;
while ($i < 7) {
    echo "The value is $i <br />";
    $i++;
}

//Do...while loop
//Regardless of whether the condition is true or false, the code will be executed at least once.
$i = 5;
do {
    echo "This number is " . $i . "<br />";
    $i++;
} while ($i <= 7);

//for loop
for ($a = 0; $a < 3; $a++) {
    echo "Value of a: $a <br />";
}

//foreach loop
//The foreach loop works only on arrays, and is used to loop through each key/value pair in an array.
/*foreach (array as $value) {
  code to be executed;
}
//or
foreach (array as $key => $value) {
   code to be executed;
}
第一種形式遍歷數組。在每次迭代中，當前元素的值被分配給 $value，數組指針移動一個，直到它到達最後一個數組元素。
第二種形式將在每次迭代時將當前元素的鍵另外分配給 $key 變量。*/
$names = array('John', 'David', 'Amy');
foreach ($names as $name) {
    echo $name . '<br />';
} //ouput:
//John
//David
//Amy

//switch
$today = 'Tue';
switch ($today) {
    case "Mon":
        echo "Today is Monday.";
        break;
    case "Tue":
        echo "Today is Tuesday.";
        break;
    case "Wed":
        echo "Today is Wednesday.";
        break;
    case "Thu":
        echo "Today is Thursday.";
        break;
    case "Fri":
        echo "Today is Friday.";
        break;
    case "Sat":
        echo "Today is Saturday.";
        break;
    case "Sun":
        echo "Today is Sunday.";
        break;
    default:
        echo "Invalid day.";
}

$day = 'Wed';
switch ($day) {
    case 'Mon':
        echo 'First day of the week';
        break;
    case 'Tue':
    case 'Wed':
    case 'Thu':
        echo 'Working day';
        break;
    case 'Fri':
        echo 'Friday!';
        break;
    default:
        echo 'Weekend!';
} //The example above will have the same output if $day equals 'Tue', 'Wed', or 'Thu'.

//Include & Require
//type in LearnPHP.php


/*Functions(large title)*/
//function parameters
//A function will not execute immediately when a page loads. It will be executed by a call to the function.
function multiplyByTwo($num1, $num2)
{
    $answer = $num1 * 2;
    echo $answer;
    echo "+" . $num2;
}
multiplyByTwo(3, 8); //output: 6+8
//default arguments
function setCounter($num = 10)
{
    echo "Counter is " . $num . "<br />";
    return $num;
}
setCounter(42);  //Counter is 42
setCounter();  //Counter is 10
echo setCounter(); //Counter is 10


/*Predefined variables*/
//$_SERVER Variables: Script Name
/*A superglobal is a predefined variable that is always accessible, 
regardless of scope. You can access the PHP superglobals through any function, class, or file.
PHP's superglobal variables are 
$_SERVER, $GLOBALS, $_REQUEST, $_POST, $_GET, $_FILES, $_ENV, $_COOKIE, $_SESSION.*/
/*$_SERVER
$_SERVER is an array that includes information such as headers, paths, and script locations. 
The entries in this array are created by the web server.
$_SERVER['SCRIPT_NAME'] returns the path of the current script:*/
echo '<br />' . $_SERVER['SCRIPT_NAME']; //output: /LearnPHP.php

//$_SERVER Variables: Host Name
//$_SERVER['HTTP_HOST'] returns the Host header from the current request.
echo '<br />' . $_SERVER['HTTP_HOST']; //output:localhost:3000
/*This method can be useful when you have a lot of images on your server 
    and need to transfer the website to another host. 
    Instead of changing the path for each image, you can do the following:
    Create a config.php file, that holds the path to your images:(in LearnPHP_config.php)
Use the config.php file in your scripts:*/
require 'LearnPHP_config.php';
echo '<img src="' . $image_path_1 . 'header.png" />';
echo '<img src="' . $image_path_2 . 'header.png" />';
//??The image can't display: https://www.sololearn.com/learning/1059/1839/3549/1 
//example: http://localhost:3000/LearnPHP.php
echo '<br />' . $_SERVER['HTTP_HOST']; //ouput:localhost:3000
echo '<br />' . $_SERVER['SERVER_NAME']; //ouput:localhost
echo '<br />' . $_SERVER['REQUEST_URI']; //ouput:/LearnPHP.php (concluding id)
echo '<br />' . $_SERVER['PHP_SELF']; //ouput:/LearnPHP.php
echo '<br />' . $_SERVER['QUERY_STRING']; //ouput: (id, but this page doesn't have id)

//Forms
//The purpose of the PHP superglobals $_GET and $_POST is to collect data that has been entered into a form.
?>
<!--The detail example is In-class-assignment_5-->
<form action="LearnPHP_header_POST.php" method="post">
    <p>Name: <input type="text" name="name" /></p>
    <p>Age: <input type="text" name="age" /></p>
    <p><input type="submit" name="submit" value="Submit" /></p>
</form>
<!-- The action attribute specifies that when the form is submitted, 
        the data is sent to a PHP file named first.php. 
    HTML form elements have names, which will be used when accessing the data with PHP.
    The $_POST superglobal array holds key/value pairs. In the pairs, 
        keys are the names of the form controls and values are the input data entered by the user.
    We used the $_POST array, as the method="post" was specified in the form.-->

<?php
//GET and POST
/*The two methods for submitting forms are GET and POST.
POST:
Information sent from a form via the POST method is invisible to others, 
    since all names and/or values are embedded within the body of the HTTP request. 
Also, there are no limits on the amount of information to be sent.
POST supports advanced functionality such as support 
    for multi-part binary input while uploading files to the server.
However, it is not possible to bookmark the page, as the submitted values are not visible.
POST is the preferred method for sending form data.

GET:
GET method is visible to everyone (all variable names and values are displayed in the URL
GET also sets limits on the amount of information that can be sent - about 2000 characters.
However, because the variables are displayed in the URL, 
    it is possible to bookmark the page, which can be useful in some situations.
***GET should NEVER be used for sending passwords or other sensitive information!*** */
?>
<form action="LearnPHP_header_GET.php" method="get">
    Name: <input type="text" name="name" /><br />
    Age: <input type="text" name="age" /><br />
    <input type="submit" name="submit" value="Submit" />
</form>

<?php
//Session
/*A session is started using the session_start() function.
Use the PHP global $_SESSION to set session variables. */
//start the session
session_start();
/*• session_start signifies your script wants a session with the 
user
    • must be called at the top of your script, before any HTML 
    output is produced
• when you call session_start:
    • if the server hasn't seen this user before, a new session is 
    created
    • otherwise, existing session data is loaded 
    into $_SESSION associative array
    • you can store data in $_SESSION and retrieve it on future 
    pages */
$_SESSION['color'] = "red";
$_SESSION['name'] = "John";
//Now, the color and name session variables are accessible on multiple pages, throughout the entire session.
//The session_start() function must be the very first thing in your document. Before any HTML tags.
//Display in LearnPHP.php

//Cookies
/*Cookies are often used to identify the user. 
A cookie is a small file that the server embeds on the user's computer. 
Each time the same computer requests a page through a browser, it will send the cookie, too. 
With PHP, you can both create and retrieve cookie values.*/
/*Create cookies using the setcookie() function:
setcookie(name, value, expire, path, domain, secure, httponly);
name: Specifies the cookie's name
        The name parameter is the only one that's required. All of the other parameters are optional.
value: Specifies the cookie's value
expire: Specifies (in seconds) when the cookie is to expire.   Cookie的維持時間
        The value: time()+86400*30, will set the cookie to expire in 30 days. If this parameter is omitted or set to 0, the cookie will expire at the end of the session (when the browser closes). Default is 0.
path: Specifies the server path of the cookie. If set to "/", 
            the cookie will be available within the entire domain. 
        If set to "/php/", the cookie will only be available within the php directory 
            and all sub-directories of php. 
        The default value is the current directory in which the cookie is being set.
domain: Specifies the cookie's domain name. 
        To make the cookie available on all subdomains of example.com, set the domain to "example.com".
secure: Specifies whether or not the cookie should only be transmitted over a secure, HTTPS connection. 
        TRUE indicates that the cookie will only be set if a secure connection exists. Default is FALSE.
httponly: If set to TRUE, the cookie will be accessible only through the HTTP protocol 
        (the cookie will not be accessible to scripting languages). 
        Using httponly helps reduce identity theft using XSS attacks. Default is FALSE.
*/
/*The following example creates a cookie named "user" with the value "John". 
The cookie will expire after 30 days, which is written as 86,400 * 30, in which 86,400 seconds = one day. 
The '/' means that the cookie is available throughout the entire website. 
We then retrieve the value of the cookie "user" (using the global variable $_COOKIE). 
We also use the isset() function to find out if the cookie is set:*/
$value = "John";
setcookie("user", $value, time() + (86400 * 30), '/');
/*The setcookie() function must appear BEFORE the <html> tag.
The value of the cookie is automatically encoded when the cookie is sent, 
    and is automatically decoded when it's received. 
***Nevertheless, NEVER store sensitive information in cookies.*** */
if (isset($_COOKIE['user'])) {
    echo "Value is: " . $_COOKIE['user'];
}
//Outputs "Value is: John"

/*sessions vs. cookies:
• a cookie is data stored on the client
• a session's data is stored on the server (only 1 session per 
client)
• Sessions store data on server, so they are safer
• Use for sensitive data
• Cookies are stored on user computers so data can remain after the browser is closed
• Use for keeping data across sessions*/


/*Working with Files(large title)*/
//Writing to a File
//fopen()
/*The fopen() function creates or opens a file. 
PHP offers a number of functions to use when creating, reading, uploading, and editing files.
If you use fopen() with a file that does not exist, the file will be created, 
    given that the file has been opened for writing (w) or appending (a).

Use one of the following modes to open the file.
r: Opens file for read only.
w: Opens file for write only. Erases the contents of the file or creates a new file if it doesn't exist.
a: Opens file for write only.
x: Creates new file for write only.
r+: Opens file for read/write.
w+: Opens file for read/write. Erases the contents of the file or creates a new file if it doesn't exist.
a+: Opens file for read/write. Creates a new file if the file doesn't exist
x+: Creates new file for read/write.*/
$myfile = fopen("file.txt", "w");
//fwrite()
/*The first parameter of fwrite() is the file to write to; 
    the second parameter is the string to be written. */
$txt = "John\n";
fwrite($myfile, $txt);
$txt = "David\n";
fwrite($myfile, $txt);
//Notice that we used the fclose() function to close the file.
//The fclose() function closes an open file and returns TRUE on success or FALSE on failure.
fclose($myfile);
/*File contains:
John
David
*/

//Appending to a File
$myFile = "file.txt";
$fh = fopen($myFile, 'a');
fwrite($fh, "Some text\n");
fclose($fh);
/*When appending to a file using the 'a' mode, the file pointer is placed at the end of the file, 
    ensuring that all new data is added at the end of the file. */

//EXAMPLE: a form that adds filled-in data to a file.
//***Display in LearnPHP_header_formPost.php***


//Reading Files
/*The file() function reads the entire file into an array. 
Each element within the array corresponds to a line in the file:  */
?>
<h1>Reading Files<br /></h1>
<?php
$read = file('names.txt'); //不用fopen()
$count = count($read);
//The $count variable uses the count function to obtain the number of elements in the $read array.
$i = 1;
foreach ($read as $line) {
    echo $line;
    if ($i < $count) { //avoid printing that final comma.
        echo ", ";
    }
    $i++;
}
//This prints all of the lines in the file, and separates them with commas.
//We used the foreach loop, because the $read variable is an array.


/*Object-Oriented PHP (large ttitle)*/
//https://www.sololearn.com/learning/1059/3006/6531/1
class Person
{
    public $age; //property for defining the features of an object
    public function speak()
    { //methods for defining the behavior of an object.
        echo "Hi!";
    }
}
/*Notice the keyword public in front of the speak method; it is a visibility specifier.
The public keyword specifies that the member can be accessed from anywhere in the code. */

//PHP Object
//The process of creating an object of a class is called "instantiation".
//To instantiate an object of a class, use the keyword new, as in the example below:
$bob = new Person(); //$bob is an object of the Person class.
//To access the properties and methods of an object, use the arrow (->) construct, as in:
echo $bob->age; //outputs the value of the age property for $bob. 
//如果要為屬性賦值，請像對任何變量一樣使用賦值運算符 =。
$p1 = new Person(); //instantiate an object
$p1->age = 23; //assignment
echo $p1->age; //output: 23
$p1->speak(); //ouput: Hi!

//$this
//$this 是一個偽變量，它是對調用對象的引用。在方法中工作時，使用 $this 的方式與在類外部使用對象名稱的方式相同。
class Dog
{
    public $legs = 4;
    public function display()
    {
        echo $this->legs;
    }
}
/*Because the display() method uses $this, the legs value referred to the appropriate 
    calling object’s property value. */

$d1 = new Dog();
$d1->display(); //output: 4
$d2 = new Dog();
$d2->legs = 2;
$d2->display(); //output: 2

//Constructor & Destructor
//PHP Class Constructor
/*constructor magic method __construct(), 
    which is called automatically whenever a new object is instantiated. 
The __construct() method is often used for any initialization that the object may need before it is used. 
    Parameters can be included in __construct() to accept values when the object is created.
You can't write multiple __construct() methods with different numbers of parameters. 
    Different constructor behavior must be handled with logic within a single __construct() method.*/
class Constructor_test
{
    public $name;
    public $age;
    public function __construct($name, $age) //construct前是兩條底線
    {
        $this->name = $name;
        $this->age = $age;
    }
}
$p_construct = new Constructor_test("David", 42);
echo "<br />Constructor_test:<br />" . $p_construct->name; //output: David

//PHP Class Destructor
//__destruct(), which is automatically called when an object is destroyed.
class Destructor_test
{
    public function __destruct() //destruct前是兩條底線
    {
        echo "Object Destroyed";
    }
}
$p_destruct = new Destructor_test();
unset($p_destruct);
/*This script creates a new Person object. 
When the script ends the object is automatically destroyed, 
    which calls the destructor and outputs the message "Object destroyed".
To explicitly trigger the destructor, you can destroy the object using the unset() function 
    in a statement similar to: unset($p); 
Destructors are useful for performing certain tasks when the object finishes its lifecycle. 
For example, release resources, write log files, close a database connection, and so on.
PHP releases all resources when a script finishes its execution.*/

//Class Inheritance
/*Classes can inherit the methods and properties of another class.
The class that inherits the methods and properties is called a subclass. 
The class a subclass inherits from is called the parent class. 
Inheritance is achieved using the extends keyword.*/
class Animal
{
    public $name;
    public function hi()
    {
        echo "Hi from Animal";
    }
}
class Cat extends Animal
{
}
$extend_test = new Cat();
$extend_test->hi();
/*Here the Dog class inherits from the Animal class. 
As you can see, all the properties and methods of Animal are accessible to Dog objects. 
Parent constructors are not called implicitly if the subclass defines a constructor. 
However, if the child does not define a constructor then it will be inherited from the parent class 
    if it is not declared private.
Notice all our properties and methods have public visibility.
For added control over objects, declare methods and properties using a visibility keyword. 
This controls how and from where properties and methods can be accessed.*/

//PHP Visibility
/*Visibility controls how and from where properties and methods can be accessed.
There are two more keywords to declare visibility:
protected: Makes members accessible only within the class itself, by inheriting, and by parent classes.
private: Makes members accessible only by the class that defines them.
Class properties must always have a visibility type. 
Methods declared without any explicit visibility keyword are defined as public. 
Protected members are used with inheritance.
Private members are used only internally in a class.*/

//PHP Interfaces
/*An interface specifies a list of methods that a class must implement.
This is an important aspect of interfaces because it allows a method 
    to be handled differently in each class that uses the interface. 
The interface keyword defines an interface.
The implements keyword is used in a class to implement an interface.
For example, AnimalInterface is defined with a declaration for the makeSound() function, 
    but it isn't implemented until it is used in a class:*/
interface AnimalInterface
{
    public function makeSound();
}
class fly implements AnimalInterface
{
    public function makeSound()
    {
        echo "n~ <br />";
    }
}
class tiger implements AnimalInterface
{
    public function makeSound()
    {
        echo "Hoo~<br />";
    }
}
$myObj1 = new fly();
$myObj1->makeSound(); //output: "n~ <br />"
$myObj2 = new tiger();
$myObj2->makeSound(); //output: "Hoo~ <br />"
/*A class can implement multiple interfaces. 
More than one interfaces can be specified by separating them with commas. 
For example: */
// class Demo implements AInterface, BInterface, CInterface {
//     // Functions declared in interfaces must be defined here
//   }
//An interface can be inherit another interface by using the extends keyword.

//PHP Abstract Classes
/*Abstract classes can be inherited but they cannot be instantiated.
They offer the advantage of being able to contain both methods with definitions 
    and abstract methods that aren't defined until they are inherited.
(抽像類可以繼承，但不能實例化。
它們提供的優勢是能夠包含具有定義的方法和在繼承之前未定義的抽象方法。)
A class inheriting from an abstract class must implement all the abstract methods. 
The abstract keyword is used to create an abstract class or an abstract method.
For example:*/
abstract class Fruit
{
    private $color;
    abstract public function eat();
    public function setColor($c)
    {
        $this->color = $c;
    }
}
class Apple extends Fruit
{
    public function eat()
    {
        echo "Apple<br />";
    }
}
$abstract_test = new Apple();
$abstract_test->eat(); //"Apple"
//Abstract functions can only appear in an abstract class.

//Static and final
//A static property/method of a class can be accessed without creating an object of that class.
/*A static property or method is accessed by using the scope resolution operator :: 
    between the class name and the property/method name.*/
//The self keyword is needed to access a static property from a static method in a class definition.
//Objects of a class cannot access static properties in the class but they can access static methods.
class myStaticTest
{
    static $myStaticProperty = 42; //property
    static function myMethod()
    { //method
        echo self::$myStaticProperty;
    }
}
echo myStaticTest::$myStaticProperty;
myStaticTest::myMethod();

//The final keyword
/*The PHP final keyword defines methods that cannot be overridden in child classes. 
Classes that are defined final cannot be inherited.
This example demonstrates that a final method cannot be overridden in a child class:*/
// class myFianlTest {
//     final function myFunction() {
//         echo "Parent";
//     }
// }
// // ERROR because a final method cannot be overridden in child classes.
// class myFianlTest2 extends myFianlTest {
//     function myFunction() { 
//         echo "Child";
//     }
// }
//Unlike classes and methods, properties cannot be marked final.

/* php deal with file
//pathinfo()輕鬆取檔案副檔名、檔案名稱、根目錄相對路徑、資料夾名:
// https://vector.cool/php-pathinfo-get-dirname-basename-extension-filename/
// https://www.geeksforgeeks.org/php-pathinfo-function/

//in_array(): 搜索数组中是否存在指定的值
//https://www.w3school.com.cn/php/func_array_in_array.asp

//uniqid() 函数基于以微秒计的当前时间，生成一个唯一的 ID
//https://www.w3school.com.cn/php/func_misc_uniqid.asp

//move_uploaded_file() 函数将上传的文件移动到新位置
//https://www.w3school.com.cn/php/func_filesystem_move_uploaded_file.asp

*/


/*php connnect sql:
mysqli_connect("主機名稱","帳號","密碼",資料庫名稱")：與資料庫連接
mysqli_query($與資料庫的連接,"select * from 資料庫名稱")：從某資料庫中讀取所有的（*）資料表
mysqli_query($與資料庫的連接,"set names utf8")：從某資料庫中讀取所有的（*）資料表
mysqli_query($與資料庫的連接,"INSERT tableName(name, score) VALUES ('阿寶',87)")：新增資料
mysqli_query()第二個參數帶的是MySQL指令，許多在MySQL上可用的指令都能帶進去。

mysqli_num_rows($讀取資料表結果)：回傳我們的資料有幾列
mysqli_fetch_assoc($讀取資料表結果)：讀取該資料表中列的資料，回傳的是一個陣列資料。
mysqli_close($與資料庫的連接)：斷開與資料庫的連線
//https://ithelp.ithome.com.tw/articles/10222798

*/

/*切割字串、組合字串
explode ( $delimiter , $string)：切割字串並放入Array陣列中
$delimiter：以什麼為分隔字
$string：輸入的字串

implode ( $glue , $pieces )：把數個陣列的值組合成一個字串
$glue：設置數組陣列值之間放置的內容，默認是空字串
$pieces：要結合為字串的陣列的值
//https://ithelp.ithome.com.tw/articles/10157497
*/

/*
upload image:https://www.campcodes.com/tutorials/php-tutorials/image-upload-using-pdo-in-php/

*/

/*
[PHP] glob 函數參數進階應用 – 只列資料夾 | 遞迴取得子資料夾 | 檔名不含路徑
glob可用參數：
GLOB_MARK     - 若檔案為資料夾，在回傳檔案路徑的最後面加上斜線"\"
GLOB_NOSORT   - 保持檔案路徑在原資料夾的出現順序(不重新排序)。※筆者在Win環境看不出差異
GLOB_NOCHECK  - 若找不到匹配的檔案路徑，回傳匹配的條件字串
GLOB_NOESCAPE - 不要將反斜線視為跳脫字元(※筆者在Win環境下看不出差異)
GLOB_BRACE    - 將 {a,b,c} 視為搜尋 'a', 'b', 或 'c'
GLOB_ONLYDIR  - 只列出資料夾路徑
GLOB_ERR      - 發生讀取錯誤時停止動作(像是無法讀取的資料夾)，預設是「忽略錯誤」

//https://code.yidas.com/php-glob-parameters-advanced-guide/
 */

/*Image Upload Using PDO in PHP:
https://www.campcodes.com/tutorials/php-tutorials/image-upload-using-pdo-in-php/ */
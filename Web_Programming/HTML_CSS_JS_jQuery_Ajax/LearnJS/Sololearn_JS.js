/*
#Logging Messages
The console is part of the web browser. 
Logging (writing) messages to the console is a good way to diagnose 
    and troubleshoot minor issues in your code.  */
console.log('All good, no errors');

/*Output: ouput to the document
Heads up!
document.write() should be used only for testing. 
We’ll cover some other output mechanisms real soon.*/
document.write("<h1>Hello world!</h1>");

/*Variables
Heads up!
JavaScript is sensitive, case sensitive that is. 
So variables like lastName and lastname are not the same.
 
Brace yourself for more rules!
- The first character of a variable name must be a letter, underscore (_), 
    or a dollar sign ($) (Subsequent characters can be letters, digits, 
    underscores, or dollar signs).
- The first character of a variable name can’t be a number.
- Variable names can’t include a mathematical or logical operator in their name. 
    For instance, 2*something or this+that;
- Variable names can’t contain spaces.
- You’re not allowed to use any special symbols, like my#num, num%, etc.*/
var x = 10;
document.write(x);
x = 42;
document.write(x);
var price = 5.5;
document.write(price);
var text = "My name is 'John'";
document.write(text);

//Comment

/*Math Operators
Heads up!
You can get the result of a string expression using the eval() function, 
    which takes a string expression argument like eval("10 * 20 + 8") 
    and returns the result. If the argument is empty, it returns undefined. 
    
Heads up!
10 * '5' or '10' * '5' will give the same result(50). 
    But trying to multiply a number with string values that aren’t numbers, 
    like 'sololearn' * 5 will return NaN (Not a Number).

//putstr("Enter a name to search for: ");
//var computers = parseInt(readLine(), 10);
//parseInt() 函式能將輸入的字串轉成整數:
    https://developer.mozilla.org/zh-TW/docs/Web/JavaScript/Reference/Global_Objects/parseInt

//The modulus
Heads up!
In JavaScript, we can use the modulus operator on integers AND on 
    floating point numbers.

//Comparison Operators
Heads up!
One important thing to remember when we use operators, 
    is that they only work when they’re comparing the same data type; 
    numbers with numbers, strings with strings, you get the idea.


//Logical or Boolean Operators
Conditional (Ternary) Operator
Conditional, or Ternary, operators assign a value to a variable, 
    based on some condition:
variable = (condition) ? value1(True): value2(False) 
EX:
var age = 42;
var isAdult = (age < 18) ? "Too young": "Old enough";
document.write(isAdult); //output: old enough

//String Concatenation
var mystring1 = "I am learning ";
var mystring2 = "JavaScript with SoloLearn.";
document.write(mystring1 + mystring2); //output: I am learning JavaScript with SoloLearn.
*/

//# The Object Constructor
// var person = {
//     name: "John", 
//     age: 42, 
//     favColor: "green"
// };
// function person(name, age, color) {
//     this.name = name;
//     this.age = age;
//     this.favColor = color;
// }
/*
The above function (person) is an object constructor, 
    which takes parameters and assigns them to the object properties.
The "this" keyword refers to the current object.
Note that this is not a variable. It is a keyword, and its value cannot be changed.
*/

/*Creating Objects
Once you have an object constructor, 
    you can use the new keyword to create new objects of the same type.
*/
function person(name, age, color) {
    this.name = name;
    this.age = age;
    this.favColor = color;
}

var p1 = new person("John", 42, "green");
var p2 = new person("Amy", 21, "red");

document.write("<br/>" + p1.age);
//p1-->object's name, .age-->property's name
document.write("<br/>" + p2.name);

//# Object Initialization : Create single objects
var John = { name: "John", age: 25 };
var James = { name: "James", age: 21 };
/*Objects consist of properties, which are used to describe an object. 
Values of object properties can either contain primitive data types or other objects.
 */

/*Adding method
Methods are functions that are stored as object properties.
Use the following syntax to create an object method:
methodName = function() { code lines }
Access an object method using the following syntax:
objectName.methodName()
A method is a function, belonging to an object. 
     It can be referenced using the this keyword.*/
function person(name, age) {
    this.name = name;
    this.age = age;
    this.changeName = function (name) {
        this.name = name;
    }
}

var p = new person("David", 21);
p.changeName("John");

document.write("<br />Adding method : " + p.name);

/*Methods
You can also define the function outside of the constructor function and 
    associate it with the object.

function person(name, age) {
  this.name= name;  
  this.age = age;
  this.yearOfBirth = bornYear;
}
function bornYear() {
  return 2016 - this.age;
}
The this keyword is used to access the age 
    property of the object, which is going to call the method.

*/


//# Arrays
var courses = new Array("HTML", "CSS", "JS");
//or var courses = [new Array(]"HTML", "CSS", "JS"]; 
var course = courses[0]; // HTML
courses[1] = "C++"; //Changes the second element 
//The length Property: courses.length
//Combining Arrays:
var c1 = ["HTML", "CSS"];
var c2 = ["JS", "C++"];
var courses = c1.concat(c2);
document.write("<br />" + courses[2]);
document.write("<br />" + courses[3]);
//Associative Arrays:
var person = []; //empty array
person["name"] = "John";
person["age"] = 46;
document.write("<br />Associative Arrays: " + person["age"]);
/*Remember that JavaScript does not support arrays with named indexes.
In JavaScript, arrays always use numbered indexes.
It is better to use an object when you want the index to be a string (text).
Use an array when you want the index to be a number. */

//Math object
//property   description
//E          Euler's constant
//LN2        Natural log of the value 2
//LN10       Natural log of the value 10
//LOG2E      The base 2 log of Euler's constant(E)
//LOG10E     The base 10 log of Euler's constant(E)
//PI         Ruturn the constant PI
document.write("<br />Math.PI: " + Math.PI);
//Math has no constructor. There's no need to create a Math object first.

//Math object Method
//method    description
//abs(x)    Ruturn the absolute value of x
//acos(x)   Ruturn the arccosin of x, in radians
//asin(x)   Ruturn the arcsin of x, in radians
//atan(x)   Ruturn the arctangent of x as a numeric value between -PI/2 and PI/2 radians
//atan2(y,x)   Ruturn the arctangent of the quotient(商) of its arguments
//ceil(x)   Ruturn x, roundedn upwards to the nearest integer(無條件進位)
//cos(x)   Ruturn the cosine of x(x is in radians)
//exp(x)   Ruturns the value of Ex
//floor(x)   Returns x, rounded downwards to the nearest integer(無條件捨去)
//log(x)   Returns the natural logarithm (base E) of x
//max(x,y,z,...,n)   Returns the number with the highest value
//min(x,y,z,...,n)   Returns the number with the lowest value
//pow(x,y)   Returns the value of x to the power of y
//random()   Returns a random number between 0 and 1
//round(x)   Rounds x to the nearest integer(四捨五入)
//sin(x)   Returns the sine of x (x is in radians)
//sqrt(x)   Returns the square root of x (平方根)
//tan(x)   Returns the tangent of an angle
document.write("<br />Math.sqrt(4): " + Math.sqrt(4));


//The Date Object
//setInterval()
//setInterval() 方法以指定的時間間隔（以毫秒為單位）調用函數或計算表達式。
//它將繼續調用該函數，直到調用 clearInterval() 或關閉窗口。
function myAlert() {
    alert("Hi");
}
//setInterval(myAlert, 3000);
//This will call the myAlert function every 3 seconds (1000 ms = 1 second).
//Write the name of the function without parentheses when passing it into the setInterval method.

//Using new Date(), create a new date object with the current date and time
var d = new Date();
/*d stores the current date and time
The other ways to initialize dates allow for the 
     creation of new date objects from the specified date and time
new Date(milliseconds)
new Date(dateString)
new Date(year, month, day, hours, minutes, seconds, milliseconds)
JavaScript dates are calculated in milliseconds from 01 January, 
    1970 00:00:00 Universal Time (UTC). One day contains 86,400,000 millisecond.
//Fri Jan 02 1970 00:00:00
var d1 = new Date(86400000); 

//Fri Jan 02 2015 10:42:00
var d2 = new Date("January 2, 2015 10:42:00");

//Sat Jun 11 1988 11:42:00
var d3 = new Date(88,5,11,11,42,0,0);
JavaScript counts months from 0 to 11. January is 0, and December is 11.
Date objects are static, rather than dynamic. 
    The computer time is ticking, but date objects don't change, once created.
*/

/*
Date Methods
Method             Description
getFullYear()       gets the year
getMonth()          gets the month
getDate()           gets the day of the month
getDay()            gets the day of the week
getHours()          gets the hour
getMinutes()        gets the minutes
getSeconds()        gets the seconds
getMilliseconds()   gets the milliseconds

function printTime() {
    var d = new Date();
    var hours = d.getHours();
    var mins = d.getMinutes();
    var secs = d.getSeconds();
    document.body.innerHTML = hours+":"+mins+":"+secs;
}
setInterval(printTime, 1000);

We declared a function printTime(), which gets the current time from the date object, 
    and prints it to the screen.
We then called the function once every second, using the setInterval method.
The innerHTML property sets or returns the HTML content of an element.
In our case, we are changing the HTML content of our document's body. 
    This overwrites the content every second, instead of printing it repeatedly 
    to the screen.
*/


/* DOM & Events
//The DOM
When you open any webpage in a browser, the HTML of the page 
    is loaded and rendered visually on the screen.
To accomplish that, the browser builds the Document Object Model of that page, 
    which is an object oriented model of its logical structure.
JavaScript can be used to manipulate the DOM of a page dynamically to add, 
    delete and modify elements.

//DOM Tree
The DOM represents a document as a tree structure.
HTML elements become interrelated nodes in the tree.
All those nodes in the tree have some kind of relations among each other.
Nodes can have child nodes. Nodes on the same tree level are called siblings.

//The document Object
There is a predefined document object in JavaScript, 
    which can be used to access all elements on the DOM.
In other words, the document object is the owner (or root) of all objects 
    in your webpage.
So, if you want to access objects in an HTML page, you always start with 
    accessing the document object.
For example:
document.body.innerHTML = "Some text";
As body is an element of the DOM, we can access it using 
    the document object and change the content of the innerHTML property.
The innerHTML property can be used on almost all HTML elements to change its content.

//Selecting Elements
All HTML elements are objects. And as we know every object has properties 
    and methods.
These three methods are the most commonly used for selecting HTML elements:
//finds element by id:
document.getElementById(id) 

//finds elements by class name:
document.getElementsByClassName(name) 

//finds elements by tag name:
document.getElementsByTagName(name)
In the example below, the getElementById method is used to select the 
    element with id="demo" and change its content:
var elem = document.getElementById("demo");
elem.innerHTML = "Hello World!";
(The example above assumes that the HTML contains an 
    element with id="demo", for example <div id="demo"></div>.)

The getElementsByClassName() method returns a collection of all elements 
    in the document with the specified class name.
The following example gets all paragraph elements of the page and 
    changes their content:
<p>hi</p>
<p>hello</p>
<p>hi</p>
<script>
var arr = document.getElementsByTagName("p");
for (var x = 0; x < arr.length; x++) {
  arr[x].innerHTML = "Hi there";
}
</script>
The script will result in the following HTML:
<p>Hi there</p>
<p>Hi there</p>
<p>Hi there</p>


//Working with DOM
Each element in the DOM has a set of properties and methods that 
    provide information about their relationships in the DOM:
element.childNodes: returns an array of an element's child nodes.
element.firstChild: returns the first child node of an element.
element.lastChild: returns the last child node of an element.
element.hasChildNodes: returns true if an element has any child nodes, 
                        otherwise false.
element.nextSibling: returns the next node at the same tree level.
element.previousSibling: returns the previous node at the same tree level.
element.parentNode: returns the parent node of an element.
EX:
function setText() {
    var a = document.getElementById("demo");
     var arr = a.childNodes;
     for(var x=0;x<arr.length;x++) {
       arr[x].innerHTML = "new text";
     }
}
//calling the function with setTimeout to make sure the HTML is loaded
setTimeout(setText, 500); //等待0.5s後，function才會執行


//Changing Attributes
we can change the attributes of elements.
For example, we can change the src attribute of an image:
<img id="myimg" src="orange.png" alt="" />
<script>
var el = document.getElementById("myimg");
el.src = "apple.png";
</script>
Practically all attributes of an element can be changed using JavaScript.


//Changing Style
All style attributes can be accessed using the style object of the element.
//calling the function in window.onload to make sure the HTML is loaded
window.onload = function() {
    var x = document.getElementById("demo");
    x.style.color = '#6600FF';
    x.style.width = '100px';
};
All CSS properties can be set and modified using JavaScript. 
Just remember, that you cannot use dashes (-) in the property names: 
    these are replaced with camelCase versions, where the compound words 
        begin with a capital letter.
For example: the background-color property should be referred to as backgroundColor.


//##Creating Elements
Use the following methods to create new nodes:
###
element.cloneNode() clones an element and returns the resulting node.
document.createElement(element) creates a new element node.
document.createTextNode(text) creates a new text node.
###
For example:
var node = document.createTextNode("Some new text");

This will create a new text node, but it will not appear in the document 
    until you append it to an existing element with one of the following methods:
//##Add elements
###
element.appendChild(newNode): adds a new child node to an element as the last 
                                child node.
element.insertBefore(node1, node2): inserts node1 as a child before node2.
###
Example:
//calling the function in window.onload to make sure the HTML is loaded
window.onload = function() {
    //creating a new paragraph
    var p = document.createElement("p");
    var node = document.createTextNode("Some new text");
    //adding the text to the paragraph
    p.appendChild(node);

    var div = document.getElementById("demo");
    //adding the paragraph to the div
    div.appendChild(p);
};
This creates a new paragraph and adds it to the existing div element on the page.

//##Removing Elements
To remove an HTML element, you must select the parent of the 
    element and use the ###removeChild(node)### method.
For example:
<div id="demo">
    <p id="p1">This is a paragraph.</p>
    <p id="p2">This is another paragraph.</p>
</div>
<script>
    //calling the function in window.onload to make sure the HTML is loaded
    window.onload = function() {
        var parent = document.getElementById("demo");
        var child = document.getElementById("p1");
        parent.removeChild(child);
    };
    //alternative way
    window.onload = function() {
        var child = document.getElementById("p1");
        child.parentNode.removeChild(child);
    };
</script>

//##Replacing Elements
To replace an HTML element, the element.replaceChild(newNode, oldNode)
For example:
<div id="demo">
    <p id="p1">This is a paragraph.</p>
    <p id="p2">This is another paragraph.</p>
</div>
<script>
    //calling the function in window.onload to make sure the HTML is loaded
    window.onload = function() {
        var p = document.createElement("p");
        var node = document.createTextNode("This is new");
        p.appendChild(node);

        var parent = document.getElementById("demo");
        var child = document.getElementById("p1");
        parent.replaceChild(p, child);
    };
</script>

//##Animations
Let's create a simple HTML page with a box element that will be animated using JS.
To create an animation, 
    we need to change the properties of an element at small intervals of time.
We can achieve this by using the setInterval() method, which allows us to 
    create a timer and call a function to change properties repeatedly at defined 
    intervals (in milliseconds).
For example: 
(in html)
//calling the function in window.onload to make sure the HTML is loaded
window.onload = function() {
    var pos = 0; 
   //our box element
   var box = document.getElementById('box');
   var t = setInterval(move, 10); //calls the move() function every 10 milliseconds
 
   function move() {
       if(pos >= 150) {
           clearInterval(t);
       }
       else {
           pos += 1;
           box.style.left = pos+'px';
       }
   }
};



//#Handling Events
//##Events
When an event occurs on a target element, a handler function is executed.
Common HTML events include:
Event            Description
onclick         occurs when the user clicks on an element
onload          occurs when an object has loaded
onunload        occurs once a page has unloaded (for <body>)
onchange        occurs when the content of a form element, the selection, 
                    or the checked state have changed
                    for <input>, <keygen>, <select>, and <textarea>)
onmouseover     occurs when the pointer is moved onto an element, or
                    onto one of its children
onmouseout      occurs when a user moves the mouse pointer out of
                    an element, or out of one of its children
onmousedown     occurs when the user presses a mouse button over an element
onmouseup       occurs when a user releases a mouse button over an element
onblur          occurs when an element loses focus
onfocus         occurs when an element gets focus
Corresponding events can be added to HTML elements as attributes.
For example: <p onclick="someFunc()">some text</p>

//##Handling Events
//###onclick event
//1st way
<button onclick="show();">Click Me</button>
<script>
    function show() {
        alert("Hi there");
    }
</script>
//2nd way
<button id="demo">Click Me</button>
<script>
    //calling the function in window.onload to make sure the HTML is loaded
    window.onload = function() {
        var x = document.getElementById('demo');
        x.onclick = function () {
            document.body.innerHTML = Date();
        }
    };
</script>

//### onload and onunload event
The onload and onunload events are triggered 
    when the user enters or leaves the page.(for <body>)
<body onload="doSomething()">
//or
window.onload = function() {
   //some code
}

//###onchange event
The onchange event is mostly used on textboxes. The event handler gets called 
    when the text inside the textbox changes and focus is lost from the element:
<input type="text" id="name" onchange="change()">
<script>
    function change() {
        var x = document.getElementById('name');
        x.value = x.value.toUpperCase();
    }
</script>

//##Event Listeners
The addEventListener() method attaches an event handler to an element without 
    overwriting existing event handlers. You can add many event handlers to 
    one element.
You can also add many event handlers of the same type to one element, i.e., 
    two "click" events.
### 
element.addEventListener(event, function, useCapture);
###
The first parameter is the event's type (like "click" or "mousedown").
The second parameter is the function we want to call when the event occurs.
The third parameter is a Boolean value specifying whether to use event bubbling 
    or event capturing. This parameter is optional.
//#### Note that you don't use the "on" prefix for this event; 
    use "click" instead of "onclick".

//## Event Propagation
There are two ways of event propagation in the HTML DOM: bubbling and capturing.
If you have a <p> element inside a <div> element, and the user clicks on the <p> element, which element's "click" event should be handled first?

In bubbling, the innermost element's event is handled first and then the outer element's event is handled. 
    The <p> element's click event is handled first, followed by the <div> element's 
    click event.

In capturing, the outermost element's event is handled first and then the inner. 
    The <div> element's click event is handled first, followed by the <p> element's 
    click event.
//#### Capturing goes down the DOM.
        Bubbling goes up the DOM.
###
//Capturing propagation
elem1.addEventListener("click", myFunction, true); 

//Bubbling propagation
elem2.addEventListener("click", myFunction, false);
###
//#### This is particularly useful when you have the same event handled for 
        multiple elements in the DOM hierarchy.

//## Image Slider
Now we can create a sample image slider project. 
The images will be changed using "Next" and "Prev" buttons:
(in html)
*/
var images = [
    'http://www.sololearn.com/uploads/slider/1.jpg',
    'http://www.sololearn.com/uploads/slider/2.jpg',
    'http://www.sololearn.com/uploads/slider/3.jpg'
];
var num = 0;
function next() {
    var slider = document.getElementById('slider');
    num++;
    if (num >= images.length) {
        num = 0;
    }
    slider.src = images[num];
}
function prev() {
    var slider = document.getElementById('slider');
    num--;
    if (num < 0) {
        num = images.length - 1;
    }
    slider.src = images[num];
}
/*
The num variable holds the current image. The next and previous button 
    clicks are handled by their corresponding functions, 
    which change the source of the image to the next/previous image in the array.

//## Form Validation
HTML5 adds some attributes that allow form validation. For example, the required 
    attribute can be added to an input field to make it mandatory to fill in.
More complex form validation can be done using JavaScript.
The form element has an onsubmit event that can be handled to perform validation.
For example, let's create a form with two inputs and one button. 
The text in both fields should be the same and not blank to pass the validation:
(in html)
*/
function validate() {
    var n1 = document.getElementById('num1');
    var n2 = document.getElementById('num2');
    if (n1.value != '' && n2.value != '') {
        if (n1.value == n2.value) {
            return true;
        }
    }
    alert("The values should be equal and not blank");
    return false;
}


/*#ECMAScript 6
ES6 is a superset of JavaScript (ES5). The reason that ES6 became so popular is that 
    it introduced new conventions and OOP concepts such as classes.
ES6 code will run only in browsers that support it. 
    Older devices and browsers that do not support ES6 will return a syntax error.

//## var & let
In ES6 we have three ways of declaring variables:
###
var a = 10;
const b = 'hello';
let c = true;
###
The type of declaration used depends on the necessary scope. Scope is the 
    fundamental concept in all programming languages that defines the visibility 
    of a variable.

var & let & const
Unlike the var keyword, which defines a variable globally, or locally to an entire 
    function regardless of block scope, let allows you to declare variables that are 
    limited in scope to the block, statement, or expression in which they are used.
const variables have the same scope as variables declared using let. The difference 
    is that const variables are immutable - they are not allowed to be reassigned.
For example:
function varTest() {
    var x = 1;
    if (true) {
        var x = 2;  // same variable
        console.log(x);  // 2
    }
    console.log(x);  // 2
}
function letTest() {
    let x = 1;
    if (true) {
        let x = 2;  // different variable
        console.log(x);  // 2
    }
    console.log(x);  // 1
}
varTest();
letTest();
One of the best uses for let is in loops:
for (let i = 0; i < 3; i++) {
    document.write(i);
}
let is not subject to Variable Hoisting, which means that let 
    declarations do not move to the top of the current execution context.
const is not subject to Variable Hoisting too, which means that const 
    declarations do not move to the top of the current execution context.

//## Template Literals in ES6
Template literals are a way to output variables in the string.
ES6 introduces a new way of outputting variable values in strings. 
    The same code above can be rewritten as:
let name = 'David';
let msg = `Welcome ${name}!`;
console.log(msg);
Notice, that template literals are enclosed by the backtick (` `) 
    character instead of double or single quotes.
The ${expression} is a placeholder, and can include any expression, 
    which will get evaluated and inserted into the template literal.
let a = 8;
let b = 34;
let msg = `The sum is ${a+b}`;
console.log(msg);

//## Loops and Functions in ECMAScript 6
In JavaScript we commonly use the for loop to iterate over values in a list:
let arr = [1, 2, 3];
for (let k = 0; k < arr.length; k++) {
    console.log(arr[k]);
}
The for...in loop is intended for iterating over the enumerable keys of an object:
let obj = {a: 1, b: 2, c: 3};
for (let v in obj) {
    console.log(v); //output: a   b   c
}
The for...in loop should NOT be used to iterate over arrays because, 
    depending on the JavaScript engine, it could iterate in an arbitrary order. 
    Also, the iterating variable is a string, not a number, so if you try to do 
    any math with the variable, you'll be performing string concatenation 
    instead of addition.
ES6 introduces the new for...of loop, 
    which creates a loop iterating over iterable objects.
let list = ["x", "y", "z"];
for (let val of list) {
    console.log(val); //output: x   y   z
}
The for...of loop works for other iterable objects as well, including strings
for (let ch of "Hello") {
    console.log(ch); //output: h   e   2 l   o
}
The for...of loop also works on the newly 
    introduced collections (Map, Set, WeakMap, and WeakSet). 

//###Functions in ECMAScript 6
Prior to ES6, a JavaScript function was defined like this:
function add(x, y) {
    var sum = x+y;  
    console.log(sum);
}
add(35, 7);

ES6 introduces a new syntax for writing functions. 
The same function from above can be written as:
const add = (x, y) => {
    let sum = x + y;  
    console.log(sum);
}
add(35, 7);

You can skip typing function and return, as well as some parentheses and braces.
For example:
const greet = x => "Welcome " + x;
alert(greet("David"));

If there are no parameters, an empty pair of parentheses should be used, as in:
const x = () => alert("Hi");
x();

Originally, we use the forEach method of the array to call a function for each element:
var arr = [2, 3, 7, 8];
arr.forEach(function(el) {
    console.log(el * 2);
});
In ES6, the code above can be rewritten as following:
const arr = [2, 3, 7, 8];
arr.forEach(v => {
    console.log(v * 2); //output: 4   6   14   16
});

In ES6, we can put the default values right in the signature of the functions.
For example:
const test = (a, b = 3, c = 42) => {
  return a + b + c;
}
console.log(test(5)); //50 

//##ES6 Objects
JavaScript variables can be Object data types that contain many values 
    called properties.
An object can also have properties that are function definitions called 
    methods for performing actions on the object.
ES6 introduces shorthand notations and computed property names that 
    make declaring and using objects easier to understand.
The new method definition shorthand does not require the colon (:) 
    or function keyword, as in the grow function of the tree object declaration:
let tree = {
    height: 10,
    color: 'green',
    grow() { 
        this.height += 2;
    }
};
tree.grow();
console.log(tree.height); // 12

When creating an object by using duplicate property names, the last property 
    will overwrite the prior ones of the same name.
For Example:
var a = {x: 1, x: 2, x: 3, x: 4};
console.log(a.x); // 4 

//## Computed Property Names
With ES6, you can now use computed property names. 
Using the square bracket notation [], we can use an expression for a 
    property name, including concatenating strings. 
    This can be useful in cases where we want to create certain objects 
    based on user data (e.g. id, email, and so on).
Here are three examples:
Example 1:
let prop = 'name';
let id = '1234';
let mobile = '08923';
let user = {
  [prop]: 'Jack',
  [`user_${id}`]: `${mobile}`
};
console.log(user.name); // Jack
console.log(user.user_1234); // 08923

Example 2:
var i = 0;
var a = {
  ['foo' + ++i]: i,
  ['foo' + ++i]: i,
  ['foo' + ++i]: i
};
console.log(a.foo1); // 1
console.log(a.foo2); // 2
console.log(a.foo3); // 3

Example 3:
var param = 'size';
var config = {
    [param]: 12,
    ['mobile' + param.charAt(0).toUpperCase() + param.slice(1)]: 4
};
//slice():回傳一個新陣列物件，為原陣列選擇的 begin 至 end（不含 end）
            部分的淺拷貝（shallow copy）。原本的陣列將不會被修改。
            slice()有兩個預設參數，第一個參數是要從哪個索引值開始切，
            第二個參數是要在哪一個索引值結束。
            第二個參數如果是三，slice()其實只會取到索引值為二就停止。
            https://ithelp.ithome.com.tw/articles/10224915

console.log(config.mobileSize); // 4

//## Object.assign() in ES6
Object.assign() is also useful for creating a duplicate of an existing object.
Let's look at the following example to see how to combine objects:
let person = {
    name: 'Jack',
    age: 18,
    sex: 'male'
};
let student = {
    name: 'Bob',
    age: 20,
    xp: '2'
};
let newStudent = Object.assign({}, person, student);
console.log(newStudent.name); // Bob
console.log(newStudent.age); // 20
console.log(newStudent.sex); // male
console.log(newStudent.xp); // 2
Here we used Object.assign() where the first parameter is the target object 
    you want to apply new properties to.
Every parameter after the first will be used as sources for the target. 
    There are no limitations on the number of source parameters. However, 
    order is important because properties in the second parameter will be 
    overridden by properties of the same name in third parameter, and so on.

現在，讓我們看看如何使用 assign() 創建一個複制對象而不創建對基礎對象的引用（變異）。
在下面的示例中，賦值用於嘗試生成一個新對象。但是，使用 = 創建對基礎對象的引用。
    由於此引用，針對新對象的更改會改變原始對象：
let person = {
    name: 'Jack',
    age: 18
};
let newPerson = person;
newPerson.name = 'Bob';
console.log(person.name); // Bob
console.log(newPerson.name); // Bob

To avoid this (mutations), use Object.assign() to create a new object.
For example:
let person = {
    name: 'Jack',
    age: 18
};
let newPerson = Object.assign({}, person);
newPerson.name = 'Bob';

console.log(person.name); // Jack
console.log(newPerson.name); // Bob

Finally, you can assign a value to an object property in the 
    Object.assign() statement.
For example:
let person = {
    name: 'Jack',
    age: 18
};
let newPerson = Object.assign({}, person, {name: 'Bob'});
console.log(newPerson.name); // Bob

//## ES6 Destructuring
The destructuring assignment syntax is a JavaScript expression that makes 
    it possible to unpack values from arrays, or properties from objects, 
    into distinct variables.
let arr = ['1', '2', '3'];
let [one, two, three] = arr;
console.log(one); // 1
console.log(two); // 2
console.log(three); // 3

We can use also destructure an array returned by a function.
let a = () => {
    return [1, 3, 2];
};
let [one, , two] = a();
console.log(one); // 1
console.log(two); // 2

The destructuring syntax also simplifies assignment and swapping values:
let a, b, c = 4, d = 8;
[a, b = 6] = [2];
console.log(a); // 2
console.log(b); // 6
[c, d] = [d, c];
console.log(c); // 8
console.log(d); // 4

Object destructuring unpacks properties into distinct variables.
For example:
let obj = {h:100, s: true};
let {h, s} = obj;
console.log(h);
console.log(s);

We can assign without declaration, but there are some syntax requirements for that:
let a, b;
{a, b} = {a: 'Hello ', b: 'Jack'};
console.log(a + b); //Hello Jack

You can also assign the object to new variable names.
For example:
var o = {h: 42, s: true};
var {h: foo, s: bar} = o;
//console.log(h); // Error
console.log(foo); // 42

assign default values to variables, in case the value unpacked from the object is undefined.
For example:
var obj = {id: 42, name: "Jack"};
let {id = 10, age = 20} = obj;
console.log(id); // 42
console.log(age); // 20

//## ES6 Rest Parameters(剩餘參數):取得剩餘的所有參數，並保存在陣列裡
https://ithelp.ithome.com.tw/articles/10214394
Prior to ES6, if we wanted to pass a variable number of arguments 
    to a function, we could use the arguments object, an array-like 
    object, to access the parameters passed to the function.
For example, let's write a function that checks if an array contains 
    all the arguments passed:
function containsAll(arr) {
    for (let k = 1; k < arguments.length; k++) {
        let num = arguments[k];
        if (arr.indexOf(num) === -1) {
            return false;
        }
    }
    return true;
}
let x = [2, 4, 6, 7];
console.log(containsAll(x, 2, 4, 7)); //true
console.log(containsAll(x, 6, 4, 9)); //false

ES6 provides a more readable syntax to achieve variable number of 
    parameters by using a rest parameter:
function containsAll(arr, ...nums) {
    for (let num of nums) {
        if (arr.indexOf(num) === -1) {
            return false;
        }
    }
    return true;
}
let x = [2, 4, 6, 7];
console.log(containsAll(x, 2, 4, 7));
console.log(containsAll(x, 6, 4, 9));
The ...nums parameter is called a rest parameter. It takes all the "extra" 
    arguments passed to the function. The three dots (...) are called the 
    Spread operator.

//## The Spread Operator
It is common to pass the elements of an array as arguments to 
    a function. Before ES6, we used the following method:
function myFunction(w, x, y, z) {
    console.log(w + x + y + z);
}
var args = [1, 2, 3];
myFunction.apply(null, args.concat(4)); //10

ES6 provides an easy way to do the example above with spread operators
const myFunction = (w, x, y, z) => {
    console.log(w + x + y + z);
};
let args = [1, 2, 3];
myFunction(...args, 4);

For example:
var dateFields = [1970, 0, 1];  // 1 Jan 1970
var date = new Date(...dateFields);
console.log(date); //1969-12-31T16:00:00.000Z 

//### Spread in array literals
Before ES6, we used the following syntax to add an item at middle of an array:
var arr = ["One", "Two", "Five"];
arr.splice(2, 0, "Three");
arr.splice(3, 0, "Four");
console.log(arr); ["One", "Two", "Three", "Four", "Five"]

You can use methods such as push, splice, and concat, for example, to 
    achieve this in different positions of the array. 
    However, in ES6 the spread operator lets us do this more easily:
let newArr = ['Three', 'Four']; 
let arr = ['One', 'Two', ...newArr, 'Five'];
console.log(arr);

//### Spread in object literals
const obj1 = { foo: 'bar', x: 42 };
const obj2 = { foo: 'baz', y: 5 };

const clonedObj = { ...obj1 }; // { foo: "bar", x: 42 }
const mergedObj = { ...obj1, ...obj2 }; // { foo: "baz", x: 42, y: 5 }

However, if you try to merge them you will not get the result you expected.
Shallow cloning or merging objects is possible with another operator called 
    Object.assign().

//## ES6 classes
how to create a class that can be used to create multiple 
    objects of the same structure.
For example:
class Rectangle {
    constructor(height, width) {
        this.height = height;
        this.width = width;
  }
}
const square = new Rectangle(5, 5);
const poster = new Rectangle(2, 3); 
console.log(square.height); //5

Class Declarations are not hoisted while Function Declarations are. 
    If you try to access your class before declaring it, ReferenceError 
    will be returned.

You can also define a class with a class expression, 
    where the class can be named or unnamed.
A named class looks like:
var Square = class Rectangle {
    constructor(height, width) {
        this.height = height;
        this.width = width;
  }
};
const square = new Square(5, 5);
const poster = new Square(2, 3); 
console.log(square.height);

In the unnamed class expression, a variable is simply assigned the 
    class definition:
var Square = class {
    constructor(height, width) {
        this.height = height;
        this.width = width;
  }
};
const square = new Square(5, 5);
const poster = new Square(2, 3); 
console.log(square.height);
The constructor is a special method which is used for creating and 
    initializing an object created with a class.
#### There can be only one constructor in each class.

//### Class Methods in ES6
ES6 introduced a shorthand that does not require the keyword function for a 
    function assigned to a method's name. One type of class method is the 
    prototype method, which is available to objects of the class.
For Example:
class Rectangle {
  constructor(height, width) {
    this.height = height;
    this.width = width;
  }
  get area() {
    return this.calcArea();
  }
  calcArea() {
    return this.height * this.width;
  }
}
const square = new Rectangle(5, 5);
console.log(square.area); // 25
In the code above, area() is a getter, calcArea() is a method.

Another type of method is the static method, which cannot be called 
    through a class instance. Static methods are often used to create 
    utility functions for an application.
For Example:
class Point {
  constructor(x, y) {
    this.x = x;
    this.y = y;
  }
  static distance(a, b) {
    const dx = a.x - b.x;
    const dy = a.y - b.y;

    return Math.hypot(dx, dy);
  }
}
const p1 = new Point(7, 2);
const p2 = new Point(3, 8);
console.log(Point.distance(p1, p2)); //p1 is a in distance(), p2 is b in distance()

As you can see, the static distance method is called directly using the class name, without an object.

//## Inheritance in ES6
The extends keyword is used in class declarations or class expressions 
    to create a child of a class. The child inherits the properties and 
    methods of the parent.
For example:
class Animal {
  constructor(name) {
    this.name = name;
  }
  speak() {
    console.log(this.name + ' makes a noise.');
  }
}
class Dog extends Animal {
  speak() {
    console.log(this.name + ' barks.');
  }
}
let dog = new Dog('Rex');
dog.speak(); // Rex barks.
In the code above, the Dog class is a child of 
    the Animal class, inheriting its properties and methods.
If there is a constructor present in the subclass, it needs to first call super() 
    before using this. Also, the super keyword is used to call parent's methods.
For example, we can modify the program above to the following:
class Animal {
  constructor(name) {
    this.name = name;
  }
  speak() {
    console.log(this.name + ' makes a noise.');
  }
}
class Dog extends Animal {
  speak() {
    super.speak(); // Super
    console.log(this.name + ' barks.');
  }
}
let dog = new Dog('Rex');
dog.speak();
// Rex makes a noise.
// Rex barks.
In the code above, the parent's speak() method is called using the super keyword.


//## Map & Set
//### ES6 Map
A Map object can be used to hold key/value pairs. 
    A key or value in a map can be anything (objects and primitive values).
The syntax new Map([iterable]) creates a Map object where iterable is an array 
    or any other iterable object whose elements are arrays (with a key/value pair 
    each).
An Object is similar to Map but there are important differences that make 
    using a Map preferable in certain cases:
*1) The keys can be any type including functions, objects, and any primitive.
2) You can get the size of a Map.
3) You can directly iterate over Map.
4) Performance of the Map is better in scenarios involving frequent addition and 
    removal of key/value pairs.

The size property returns the number of key/value pairs in a map.
For example:
let map = new Map([['k1', 'v1'], ['k2', 'v2']]);
console.log(map.size); // 2

Methods
set(key, value): Adds a specified key/value pair to the map. 
    If the specified key already exists, value corresponding to it is replaced 
    with the specified value.
get(key): Gets the value corresponding to a specified key in the map. 
            If the specified key doesn't exist, undefined is returned.
has(key): Returns true if a specified key exists in the map and false otherwise.
delete(key): Deletes the key/value pair with a specified key from the map and 
                returns true. Returns false if the element does not exist.
clear(): Removes all key/value pairs from map.
keys(): Returns an Iterator of keys in the map for each element.
values(): Returns an Iterator of values in the map for each element.
entries(): Returns an Iterator of array[key, value] in the map for each element.

For example:
let map = new Map();
map.set('k1', 'v1').set('k2', 'v2');

console.log(map.get('k1')); // v1
console.log(map.has('k2')); // true

for (let kv of map.entries())
    console.log(kv[0] + " : " + kv[1]);
//k1 : v1 
//k2 : v2 

//### ES6 Set
A Set object can be used to hold unique values (no repetitions are allowed).不能有重複value
A value in a set can be anything (objects and primitive values).
The syntax new Set([iterable]) creates a Set object where iterable 
    is an array or any other iterable object of values.
The size property returns the number of distinct values in a set:
let set = new Set([1, 2, 4, 2, 59, 9, 4, 9, 1]);
console.log(set.size); // 5

Methods
add(value): Adds a new element with the given value to the Set.
delete(value): Deletes a specified value from the set.
has(value): Returns true if a specified value exists in the set and false otherwise.
clear(): Clears the set.
values(): Returns an Iterator of values in the set.

For example:
let set = new Set();
set.add(5).add(9).add(59).add(9);
console.log(set.has(9)); //true
for (let v of set.values())
    console.log(v); //5  9  99

Set supports different data types i.e. 1 and "1" are two different values.
NaN and undefined can also be stored in Set.

//## ES6 Promises
A Promise is a better way for asynchronous programming 
    when compared to the common way of using a setTimeout() type of method:
setTimeout(function() {
    console.log("Work 1");
    setTimeout(function() {
        console.log("Work 2");
    }, 1000);
}, 1000);
console.log("End");

It prints "End", "Work 1" and "Work 2" in that order (the 
    work is done asynchronously). 
    But if there are more events like this, the code becomes very complex.

ES6 comes to the rescue in such situations. A promise can be created as follows:
###
new Promise(function(resolve, reject) {
    // Work
    if (success)
        resolve(result);
    else
        reject(Error("failure"));
}); 
###
Here, resolve is the method for success and reject is the method for failure.
If a method returns a promise, its calls should use the then method which takes 
    two methods as input; one for success and the other for the failure.
For Example:
function asyncFunc(work) {
    return new Promise(function(resolve, reject) {
        if (work === "")
            reject(Error("Nothing"));
        setTimeout(function() {
            resolve(work);
        }, 1000);
    });
}

asyncFunc("Work 1") // Task 1
.then(function(result) {
    console.log(result);
    return asyncFunc("Work 2"); // Task 2
}, function(error) {
    console.log(error);
})
.then(function(result) {
    console.log(result);
}, function(error) {
    console.log(error);
});
console.log("End");
//End 
//Work 1 
//Work 2

//## Iterators & Generators
Symbol.iterator is the default iterator for an object. 
    The for...of loops are based on this type of iterator.
In the example below, we will see how we should implement it 
    and how generator functions are used.
Example:
let myIterableObj = { 
  [Symbol.iterator] : function* () {
    yield 1; yield 2; yield 3;
  }
};
console.log([...myIterableObj]); // [ 1, 2, 3 ]

First, we create an object, and use the Symbol.iterator 
    and generator function to fill it with some values.
In the second line of the code, we use a * with the function keyword. 
    It's called a generator function (or gen function).
For example, here is a simple case of how gen functions can be useful:

function* idMaker() {
  let index = 0;
  while (index < 5)
    yield index++;
}
var gen = idMaker();

console.log(gen.next().value); //0
console.log(gen.next().value); //1
console.log(gen.next().value); //2
console.log(gen.next().value); //3
console.log(gen.next().value); //4
// Try to add one more console.log, just like the above see what happens.
console.log(gen.next().value); //null

我們可以稍後退出並重新進入生成器函數。它們的變量綁定（上下文）將在重新進入時保存。
    它們是非常強大的異步編程工具，尤其是與 Promises 結合使用時。它們也可用於創建具
    有特殊要求的循環。
我們可以將生成器函數嵌套在彼此內部以創建更複雜的結構並在我們調用它們時向它們傳遞參數。
下面的示例將展示我們如何一起使用生成器函數和 Symbol.iterators 的有用案例。
Example:
const arr = ['0', '1', '4', 'a', '9', 'c', '16'];
const my_obj = {
  [Symbol.iterator]: function*() {
    for(let index of arr) {
      yield `${index}`;
    }
  }
};
const all = [...my_obj] //Here you can replace the '[...my_obj]' with 'arr'. 
.map(i => parseInt(i, 10))
.map(Math.sqrt)
.filter((i) => i < 5) // try changing the value of 5 to 4 see what happens.
.reduce((i, d) => i + d); // comment this line while you are changing the value 
                                of the line above 
console.log(all); //10

We create an object of 7 elements by using Symbol.iterator and generator functions. In the second
     part, we assign our object to a constant all. At the end, we print its value.

//### Modules
使用模塊時的注意事項：
首先要考慮的是可維護性。模塊獨立於其他模塊，可以在不依賴其他模塊代碼的情況下進行
    改進和擴展。

第二個考慮因素是命名空間。在較早的課程中，我們討論了變量和作用域。如您所知，
    變量是全局聲明的，因此命名空間污染很常見，在我們的代碼中可以訪問不相關的變量。
    模塊通過為變量創建私有空間來解決這個問題。

另一個重要的考慮因素是可重用性。當我們編寫可以在其他項目中使用的代碼時，
    模塊可以輕鬆地重用代碼，而無需在新項目中重寫它。
For Example:
// lib/math.js
export let sum = (x, y) => { return x + y; }
export let pi = 3.14;
// app.js
import * as math from "lib/math"
console.log(`2p = + ${math.sum(math.pi, math.pi)}`)

//### Built-in Methods
Array Element Finding
The legacy way to find the 
    first element of an array by its value and a rule was the following:
let res = [4, 5, 1, 8, 2, 0].filter(function (x) {
  return x > 3;
})[0];
console.log(res);

The new syntax is cleaner and more robust:
let res =
[4, 5, 1, 8, 2, 0].find(x => x > 3);
console.log(res); //4

You can also get the index of the item above by using the findIndex() method:
let res =
[4, 5, 1, 8, 2, 0].findIndex(x => x > 3);
console.log(res); //0

Repeating Strings
Before ES6 the following syntax was the correct way to repeat a 
    string multiple times:
console.log(Array(3 + 1).join("foo"));

With the new syntax, it becomes:
console.log("foo".repeat(3)); //foofoofoo

Searching Strings
Before ES6 we only used the indexOf() 
    method to find the position of the text in the string. For example:
console.log("SoloLearn".indexOf("Solo") === 0); // true
console.log("SoloLearn".indexOf("Solo") === (4 - "Solo".length)); // true
console.log("SoloLearn".indexOf("loLe") !== -1); // true
console.log("SoloLearn".indexOf("olo", 1) !== -1); // true
console.log("SoloLearn".indexOf("olo", 2) !== -1); // false

ES6 has replaced this with a version that has cleaner and more simplified syntax:
console.log("SoloLearn".startsWith("Solo", 0)); // true
console.log("SoloLearn".endsWith("Solo", 4)); // true
console.log("SoloLearn".includes("loLe")); // true
console.log("SoloLearn".includes("olo", 1)); // true
console.log("SoloLearn".includes("olo", 2)); // false
*/

/*
jQuery is a fast, small, and feature-rich 
    JavaScript library.
You will learn about the new syntax in the coming 
    lessons, but as you can see, the code is much 
    shorter and easier to understand.
ex
JS:
    var el = document.getElementById("start");
    el.innerHTML = "Go";
jQuery:
    $("#start").html("Go");

//#
It is a good practice to wait for the HTML document to be fully loaded 
    and ready before working with it.
For that we use the ready event of the document object:
$(document).ready(function() {
   // jQuery code goes here
});
This prevents any jQuery code from running before the document is finished loading.
Since the code above is used in almost all cases when using jQuery, 
    there is a handy shortcut for writing it:
$(function() {
   // jQuery code goes here
});
This code performs the same task as the longer code above.
For example: 
(in html)
After the html is loaded, js starts function.
*/
// $(function() {
//     $("#start").html("Go!");
// });
/*
//## Syntax
Basic syntax is: $("selector").action()
- The $ accesses jQuery.
- The (selector) finds HTML elements.
- The action() is then performed on the element(s).
For example:
$("p").hide()  // hides all <p> elements
$(".demo").hide()  // hides all elements with class="demo"
$("#demo").hide()  // hides the element with id="demo"

//## Selector
You can also use the following syntax for selectors:
$("div.menu")  // all <div> elements with class="menu"
$("p:first")  // the first <p> element
$("h1, p") // all <h1> and all <p> elements
$("div p") // all <p> elements that are descendants of a <div> element
$("*")  // all elements of the DOM

Useful Selectors
(<img src="useful_selector.png" />)

//# Attributes and Content
//## Attributes
href, src, id, class, style are all examples of HTML attributes.
The attr() method is used for getting the value of an attribute. For Example:
HTML:
    <a href="www.sololearn.com">
        Click here
    </a> 
*/
// $(function() {
//     var val = $("a").attr("href");
//     alert(val);
// }); 
//or set a value for an attribute by specifying it as the second parameter.
//For example:
// $(function() {
//     $("a").attr("href", "http://www.jquery.com");
// });
/*
In the code above we selected and alerted the value 
    of the href attribute of the <a> element.

//## Removing Attributes
The removeAttr() method is used for removing any attribute of an element. 
    In the example below we remove the border and class attributes of the table:
    (in html:
        <table border="5" class="tbl" >
           <tr>
               <td>one</td>
               <td>two</td>
           </tr>
           <tr>
               <td>three</td>
               <td>four</td>
           </tr>
       </table>
    )
    CSS:
    .tbl {
    background-color:aqua;
    font-weight:bold;
    }
*/
// $(function() {
//     $("table").removeAttr("border");
//     $("table").removeAttr("class"); 
// });
/* 
//## Get Content
The html() method is used to get the content of the selected element, 
    including the HTML markup. For example:
HTML:
<p>
  JQuery is <b>fun</b>
</p>
<script>
$(function() {
    var val = $("p").html();
    alert(val); //JQuery is <b>fun</b>
});
</script>
Notice, that the HTML markup (the <b> tags) is also returned,
If you need only the text content, without the HTML markup, 
    you can use the text() method:
$(function() {
    var val = $("p").text();
    alert(val); //JQuery is fun
});
The html() and text() methods can be used for all HTML elements 
    that can contain content.

//## Set Content
The content to be set is provided as a parameter to the method, for example:
*/
// $(function() {
//     $("#test").text("hello!");
// });
/*
If the content you are setting contains HTML markup, you should 
    use the html() method instead of text().

//## val()
val() method, which allows us to get and set the values of form fields, 
    such as textboxes, dropdowns, and similar inputs. For Example:
HTML:
<input type="text" id="name" value="Your Name">
*/
// $(function() {
//     //alert($("#name").val());
//     $("#name").val("My name"); //change content of value
// });
/*
Similarly, you can set the value for the field by providing it 
    as a parameter to the val() method.

/### Summary
The following jQuery methods are available to get and set content and attributes 
    of selected HTML elements:
text() sets or returns the text content of selected elements.
html() sets or returns the content of selected elements (including HTML markup).
val() sets or returns the value of form fields.
attr() sets or returns the value of attributes.
removeAttr() removes the specified attribute.

//## Adding Content
jQuery has methods that are used to add new content to a selected element 
    without deleting the existing content:
append() inserts content at the end of the selected elements.
prepend() inserts content at the beginning of the selected elements.
after() inserts content after the selected elements.
before() inserts content before the selected elements.
圖解區分function: https://www.dotblogs.com.tw/supershowwei/2022/03/19/122711

The append() method inserts content AT THE END of the selected HTML element. 
For example:
HTML:
<p id="demo">Hi </p>
*/
// $(function() {
//     $("#demo").append("David");
// });
/*
Similarly, the prepend() method inserts content AT THE BEGINNING of 
    the selected element.
You can also use HTML markup for the content.
The jQuery after() and before() methods insert content AFTER and BEFORE 
    the selected HTML element. For example:
*/
// $(function() {
//     $("#demo").before("<i>Some Title</i>");
//     $("#demo").after("<b>Welcome</b>");
// });
/*
//### Adding New Elements
The easiest way of creating a new HTML element with jQuery is the following:
var txt = $("<p></p>").text("Hi"); 
The code above creates a new <p> element, which contains the 
    text Hi and assigns it to a variable called txt.
*/
// $(function() {
//     var txt = $("<p></p>").text("Hi");
//     $("#demo").after(txt);
// });
/*
This will insert the newly created <p> element after the #demo paragraph.
You can also specify multiple elements as arguments for the before(), after(), 
    append(), prepend() methods by separating them using commas: 
    $("#demo").append(var1, var2, var3).

//# Manipulating CSS
//## Manipulating CSS
//### Add class
The addClass( ) method adds one or more classes to the selected elements. 
For example:
The addClass( ) method adds one or more classes to the selected elements. 
For example:
HTML:
<div>Some text</div>
CSS:
.header {
  color: blue;
  font-size:x-large;
}
*/
// $(function() {
//     $("div").addClass("header");
// });
/*
To specify multiple classes within the addClass() method, just separate
    them using spaces. For example, $("div").addClass("class1 class2 class3").
//### Remove Class
*/
// $(function() {
//     $("div").removeClass("header");
// });
/*
The code above removes the class "red" from the div element.
Again, multiple class names can be specified by separating them using spaces.

//### Toggle Class
The toggleClass() method toggles between adding/removing classes from the 
    selected elements, meaning that if the specified class exists for the 
    element, it is removed, and if it does not exist, it is added.
HTML:
<p>Toggle Class</p>
<button>Toggle Class</button>
CSS:
.red { 
  color:red; 
  font-weight: bold;
}
*/
$(function () {
    $("button").click(function () {
        $("p:contains('Toggle')").toggleClass("red");
    });
});
/*
//## CSS Properties
Similar to the html() method, the css() method can be used to get and set 
    CSS property values. For example:
HTML:
<p>CSS Properties</p>
CSS:
p {
  background-color:red;
  color: white;
}
*/
// $(function() {
//     alert($("p:contains('CSS Properties')").css("background-color"));
//     $("p:contains('CSS Properties')").css("background-color", "blue");
// });
/*
The code above alerts the background-color 
    property of the paragraph and then sets it to blue.
Multiple Properties:
css({"property":"value","property":"value",...});
$(function() {
    $("p").css({"background-color": "red", "font-size": "200%"});
});

//## Dimensions
The width() and height() methods can be 
    used to get and set the width and height of HTML elements:
$(function() {
    $("div").css("background-color", "red");
    $("div").width(100);
    $("div").height(100);
});
The width() and height() methods get and set the dimensions without the padding, 
    borders and margins.
The innerWidth() and innerHeight() methods also include the padding.
The outerWidth() and outerHeight() methods include the padding and borders.
Check out this image to understand how they work:
<img src="dimension.png" />

//# Manipulate DOM
The DOM represents a document as a tree structure where HTML elements are 
    interrelated nodes in the tree.
Nodes can have child nodes. Nodes on the same tree level are called siblings.
jQuery traversing is the term used to describe the process of moving through 
    the DOM and finding (selecting) HTML elements based on their relation to 
    other elements.
Structure:
An ancestor is a parent, grandparent, great-grandparent, and so on.
A descendant is a child, grandchild, great-grandchild, and so on.
Siblings share the same parent.

//## DOM Traversal
### parent() method returns the direct parent element of the selected element. 
For example:
HTML:
(in html)
*/
// $(function() {
//     var e = $("p#traversal").parent();
//     e.css("border", "2px solid red");
// });
/*
The parent() method can only traverse a single level up the DOM tree.
Some of the most used traversal methods are presented below:
<img src="traversal_method.png" />

### eq():be used to select a specific element from multiple selected elements.
For example, if the page contains multiple div elements and we want to select 
    the third one:
$("div").eq(2);
The index numbers start at 0, so the first element will have the index number 0.

//## Remove Elements
We remove selected elements from the DOM using the remove() method.
For example:
HTML:
<p style="color:red">Red</p>
<p style="color:green">Green</p>
<p style="color:blue">Blue</p>
$(function() {
    $("p").eq(1).remove();
});
This removes Green, the second paragraph element.
You can also use the remove() method on multiple selected elements, 
    for example $("p").remove() removes all paragraphs.
The jQuery remove() method removes the selected element(s), 
    as well as its child elements.

//## Remove Content
The empty() method is used to remove the child elements of the selected 
    element(s). For example:
HTML:
<div>
   <p style="color:red">Red</p>
   <p style="color:green">Green</p>
   <p style="color:blue">Blue</p>
</div>
CSS:
div {
  background-color: aqua;
  width: 300px;
  height: 200px;
}
JS:
$(function() {
    $("div").empty();
});
This removes all the three child elements of the div, leaving it empty.

//# Events
//## Handling Events
JQuery provides an efficient way to handle events. Events occur when 
    the user performs an action, such as clicking an element, moving the mouse, 
    or submitting a form.
For example:
JS:
window.onload = function() {
    var x = document.getElementById("demo");
    x.onclick = function () {
        document.body.innerHTML = Date();
    }
};
jQuery:
$(function() {
    $("#demo").click(function() {
        $("body").html(Date());
    });
});
The function that is executed when an event is fired is called the event handler.

//## Common Events
The following are the most commonly used events:
Mouse Events:
click(): occurs when an element is clicked.
dblclick(): occurs when an element is double-clicked.
mouseenter(): occurs when the mouse pointer is over (enters) the selected element.
mouseleave(): occurs when the mouse pointer leaves the selected element.
mouseover(): occurs when the mouse pointer is over the selected element.

Keyboard Events:
keydown(): occurs when a keyboard key is pressed down.
keyup(): occurs when a keyboard key is released.

Form Events:
submit(): occurs when a form is submitted.
change(): occurs when the value of an element has been changed.
focus(): occurs when an element gets focus.
blur(): occurs when an element loses focus.

Document Events:
ready(): occurs when the DOM has been loaded.
resize(): occurs when the browser window changes size.
scroll(): occurs when the user scrolls in the specified element.

For example:
HTML:
    <h3>Common Event Example</h3>
    <input type="text" id="keydown_event" />
    <div id="msg"></div>
CSS:
#msg {
    color: blue;
    font-size: 16pt;
    font-weight: bold;
}
JS:
*/
$(function () {
    $("#keydown_event").keydown(function () {
        $("#msg").html($("#keydown_event").val());
    });
});
/*
//## Handleing Events
Another way to handle events in jQuery is by using the on() method.
The on() method is used to attach an event to the selected element.
For example:
*/
$(function () {
    $("#handling_event").on("click", function () {
        alert("clicked");
    });
});
/*
As you can see, the event name is passed as the first argument to the on() method. 
    The second argument is the handler function.
The on() method is useful for binding the same handler function to multiple events. 
    You can provide multiple event names separated by spaces as the first argument. 
For example, you could use the same event handler for the click and dblclick events.

//### off()
remove event handlers using the off() method.
For example:
$(function() {
    $("div").on("click", function() { 
        alert('Hi there!'); 
    }); 
    $("div").off("click");
});
The argument of the off() method is the event name you want to remove 
    the handler for.

//## The Event Object
Every event handling function can receive an event object, 
    which contains properties and methods related to the event:
pageX, pageY: the mouse position (X & Y coordinates) at the time 
                the event occurred, relative to the top left of the page.
type: the type of the event (e.g. "click").
which: the button or key that was pressed.
data: any data that was passed in when the event was bound.
target: the DOM element that initiated the event.
preventDefault(): prevent the default action of the event (e.g., following a link).
                    (阻止事件的默認操作（例如，點擊鏈接）)
stopPropagation(): Stop the event from bubbling up to other elements.
                    (阻止事件冒泡到其他元素)

You can check out our JavaScript course for more information on event properties.
For example, let’s handle the click event on an <a> element and prevent it from 
    following the link provided in the href attribute:
HTML:
<a href="https://www.sololearn.com">The event object</a>
JS:
*/
$(function () {
    $("a").click(function (event) {
        alert(event.pageX);
        event.preventDefault();
    });
});
/*
The code above alerts the mouse position at the time of the 
    click and prevents following the link.
As you can see, the event object is passed to the event handler 
    function as an argument.

//### Trigger Events
We can also trigger events programmatically using the trigger() method. 
    For example, you can trigger a click event without the user actually 
    clicking on an element:
$(function() {
    $("div").click(function () {
        alert("Clicked!");
    });
    $("div").trigger("click");
});
This code triggers the click event for the selected element.
The trigger() method cannot be used to mimic native browser events, 
    such as clicking on a file input box or an anchor tag. 
    Only events in the jQuery event system can be handled.

//## To-Do List
Let's create a To-Do list project using the concepts we have learned.
The To-Do list will be able to add new items to a list, as well as remove existing items.
First, we create the HTML:
HTML: #to_do_list in html
Clicking the button should add the value of the input field to our <ol> list.
*/
$(function () {
    $("#add").on("click", function () {
        //event handler
        var val = $("#to-do-list-input").val();
        if (val !== '') {
            var elem = $("<li></li>").text(val); // creates a new <li> element
            $(elem).append("<button class='rem'>X</button>"); //A button for removing it is added
            $("#mylist").append(elem); //the newly created element is added to the <ol id="mylist"> list
            $("#to-do-list-input").val(""); //clear the input
            //remove the corresponding <li> element from the list
            $(".rem").on("click", function () {
                $(this).parent().remove();
            })
        }
    });

});
/*
//# Effects
//## Hide/Show, Fade, Slide
//### Hide/Show
jQuery has some easy-to-implement effects to create animations.
The hide() and show() methods are used to hide and show the selected elements.
The toggle() method is used to toggle between hiding and showing elements.
For example:
HTML:
    <p class="hide-show">Click to toggle show/hide</p>
    <div class="hide-show">Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
    </div>
CSS:
p.hide-show {
    background-color:grey;
    text-align:center;
    color:white;
    padding:5px;
    cursor:pointer;
}
div.hide-show {
    background-color:grey;
    color:white;
}
JS:
*/
// $(function() {
//     $("p.hide-show").click(function() {
//         $("div.hide-show").toggle();
//     });
// });
/*
The hide/show/toggle methods can take an optional argument, speed, 
    which specifies the animation speed in milliseconds.
For example, let's pass 1000 millisecond as the speed argument 
    to the toggle() method:
*/
$(function () {
    $("p.hide-show").click(function () {
        $("div.hide-show").toggle(1000);
    });
});

/*
The hide/show/toggle methods can also take a second optional parameter 
    callback, which is a function to be executed after the animation completes.

//### Fade
fadeToggle() method fades in and out.
Let's see fadeToggle() in action:
*/
$(function () {
    $("p.fade-animation").click(function () {
        $("div.fade-animation").fadeToggle(1000);
    });
});
/*
Another method used for fading is fadeTo(), which allows fading to a 
    given opacity (value between 0 and 1). For example: $("div").fadeTo(1500, 0.7);

//### Slide Up/Down
The slideUp() and slideDown() methods are used to create a sliding 
    effect on elements.
Again, similar to the previous toggle methods, the slideToggle() 
    method switches between the sliding effects and can take two 
    optional parameters: speed and callback.
For example:
*/
$(function () {
    $("p.sliding-animation").click(function () {
        $("div.sliding-animation").slideToggle(500);
    });
});
/*
//# animate()
The animate() method lets you animate to a set value, or to 
    a value relative to the current value.
You need to define the CSS properties to be animated as 
    its parameter in JSON format ("key":"value" pairs).
The second parameter defines the speed of the animation.
For example, the following code animates the width property 
    of the div in 1 second to the value 250px:
JS:
$(function() {
    $("div").click(function() {
        $("div").animate({width: '250px', height: '250px'}, 1000);
    });
});
You can animate any CSS property using the above 
    mentioned syntax, but there is one important thing to remember: 
    all property names must be camel-cased when used with the animate() 
    method (camelCase is the practice of writing compound words or 
    phrases such that each word or abbreviation begins with a 
    capital letter with the first word in lowercase).
You will need to write paddingLeft instead of padding-left, 
    marginRight instead of margin-right, and so on.
It is also possible to define relative values (the value is 
        then relative to the element's current value). This 
        is done by putting += or -= in front of the value:
$(function() {
    $("div").click(function() {
        $("div").animate({
            width: '+=250px', //每click一次，width會增加250px
            height: '+=250px'
        }, 1000);
    });
});
To stop an animation before it is finished, jQuery provides the stop() method.

//### Animation Queue
By default, jQuery comes with queue functionality for animations.
This means that if you write multiple animate() calls one after another
    , jQuery creates an "internal" queue for these method calls. 
    Then it runs the animate calls one-by-one.
For example:
HTML:
<div id="animation-quene-area">
    <div id="animation-quene"></div>
</div>
CSS:
div#animation-quene{
    background:orange;
    height:80px;width:80px;
    position:absolute;
    border-radius: 50%;
    opacity: 0.5;
}
JS:
*/
$(function () {
    $("#animation-quene").on("click", function () {
        var div = $(this);
        div.animate({ opacity: 1 });
        div.animate({ height: '+=100px', width: '+=100px', top: '+=100px' }, 500);
        div.animate({ height: '-=100px', width: '-=100px', left: '+=100px' }, 500);
        div.animate({ height: '+=100px', width: '+=100px', top: '-=100px' }, 500);
        div.animate({ height: '-=100px', width: '-=100px', left: '-=100px' }, 500);
        div.animate({ opacity: 0.5 });
    })
})
/*
Remember, to manipulate the position of elements, you need to set the CSS position 
    property of the element to relative, fixed, or absolute.
The animate() method, just like the hide/show/fade/slide methods, can take 
    an optional callback function as its parameter, which is executed 
    after the current effect is finished.

//## Creating a Drop-Down Menu
HTML:
<div class="menu">
  <div id="item">Drop-Down</div>
  <div id="submenu">
    <a href="#">Link 1</a>
    <a href="#">Link 2</a>
    <a href="#">Link 3</a>
  </div>
</div>
CSS:
#item {
    background-color: #4CAF50;
    color: white;
    padding: 16px;
    font-size: 16px;
    border: none;
    cursor: pointer;
}
#item:hover, #item:focus {
    background-color: #3e8e41;
}
.menu {
    position: relative;
    display: inline-block;
    //inline-block: https://ytclion.medium.com/css%E6%95%99%E5%AD%B8-%E9%97%9C%E6%96%BCdisplay-inline-inline-block-block%E7%9A%84%E5%B7%AE%E5%88%A5-1034f38eda82
}
#submenu {
    display: none;
    position: absolute;
    background-color: #3e8e41;
    min-width: 160px;
    box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);
}
#submenu a {
    color: white;
    padding: 12px 16px;
    text-decoration: none;
    display: block;
}
#submenu a:hover {
    background-color: #4CAF50
}
*/
$(function () {
    $("#item").click(function () {
        $("#submenu").slideToggle(500);
    });
});


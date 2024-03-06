// function pageLoad(){
//     var okButton=document.getElementById('ok')
//     okButton.onclick=okayClick
// }

// $(document).ready(function(){
//     $("h1").html("Anonymous Function Run");
//     $("#ok").click(function(event){
//         //alert("Anonymous Function");
//         $('h1').addClass("yellow_title");
//         $('h1').fadeOut();
//     });

//     $('a').click(function(event){
//         event.preventDefault();
//         $(this).fadeOut;
//     });
// });

function myFunction() {
    confirm("Everything OK?");
    prompt("Enter your name: ");
}
var rand1to10 = Math.floor(Math.random() * 10_1);
var three = Math.floor(Math.PI);
var a = ["Steve", 'Jason'];
a.push('Brian');
a.unshift('Kelly');
a.pop();
a.shift();
a.sort();
console.log(a);
var s = 'the quick brown fox';
var b = s.split(' ');
b.reverse();
s = b.join('?');
console.log(s);
console.log(b);
function changeText() {
    var textbox = document.getElementById("output");
    textbox.value = "Hello world!";
}
function swapText() {
    var span = document.getElementById("output2");
    var textbox = document.getElementById("textbox2");
    var temp = span.innerHTML;
    span.innerHTML = textbox.value;
    textbox.value = temp;
    textbox.style.color = 'red';
}

//object that have behavior
var pt = {
    x: 3,
    y: 4,
    distanceFromOrigin: function () {
        return Math.sqrt(pt.x * pt.x + pt.y * pt.y);
    }
};
console.log(pt.distanceFromOrigin())

//class constructor
class Book {
    constructor(height, weight) {
        this.height = height;
        this.weight = weight;
    }
    coverSize() {
        return this.height * this.weight;
    }
}
var book1 = new Book(20, 10);
var colorSize = book1.coverSize();
console.log(colorSize);

//date
var today = new Date();
var midTerm = new Date(2022, 5, 25);
console.log(today);
console.log(midTerm);

//attaching an event handler in javascript code
// element.event=function;
// document.getElementById('ok').onclick=okayClick;
// function okayClick(){
//     var clickButton=document.getElementById("clickButton");
//     clickButton.className='highlighted';
// }
// window.onload=okayClick;

//window.onload
// function pageLoad(){
//     document.getElementById('ok').onclick=okayClick;
// }

// function okayClick(){
//     alert("click");
// }
// window.onload=pageLoad;

//**another window.onload**
window.onload = function () {
    document.getElementById('ok').onclick = okayClick;
}
function okayClick() {
    alert("click!");
}

//jquery slider
$(document).ready(function () {
    $("#sliderDemo").slider({
        min: 0,
        max: 200,
        value: 50,
        slide: function (event, ui) {
            $("#sliderValue").html(ui.value);
        }
    });
})

/*將button輸出的data 貼到另一個網頁的modal或同一個網頁的modal-使用在travelblog的post_edit，為了讓article能夠順利edit

//傳輸資料的前提是 input tag內要輸入data-id='<?= $value['id'] data-title='<?= $value['title']?>'...
$('body').on('click', '.edit-article-btn', function(ev) {  // 同一個網頁的modal

        console.log('123');

        $('input[name=article-title]').val($(this).data('title')); // 使用在貼到同一個網頁modal的js

        //$('#add-article-form').modal('show'); //使用在貼到另一個網頁modal的js, #add-article-form: modal id name

        // $.ajax({                    //使用在貼到另一個網頁modal的js
        //     type: 'POST',
        //     url: './add_article_form/add_article_form.php', 
        //     data: {
        //         "id": $(this).data("id"),
        //         "title": $(this).data("id"),
        //         "description": $(this).data("id"),
        //         "picture": $(this).data("id"),
        //         "display": $(this).data("id"),
        //         "position": $(this).data("id"),
        //         "action": "edit"
        //     },
        //     success: function(html) {
        //         alert("hi");
        //         $('#add-article-form').html(html);
        //     }

        // });
        //ev.preventDefault(); */

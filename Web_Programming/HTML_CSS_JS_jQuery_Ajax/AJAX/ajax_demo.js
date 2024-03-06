window.onload = function () {
    //onload: when the whole ajax_demo.html is loaded, this function will change the html 
    // $("h1").html("Changed")
    // alert("Javascript")

    // $.get("get_data.php", function (data) { //connect get_data.php, call back the function
    //     $("h1").html(data);
    // });

    $("#get_data_btn").click(function () {
        //After clicking, "h1" will be changed into below function
        $.get("get_data.php", function (data) { //connect get_data.php, call back the function
            $("h1").html(data);
        });
    })
}
    // var person = {
    //     name: "Philip J. Fry", // string
    //     age: 23, // number
    //     "weight": 172.5, // number
    //     friends: ["Farnsworth", "Hermes", "Zoidberg"], // array
    //     getBeloved: function () { return this.name + " loves Leela"; }
    // };
    // alert(person.age); // 23
    // alert(person["weight"]); // 172.5
    // alert(person.friends[2]); // Zoidberg
    // alert(person.getBeloved()); // Philip J. Fry loves Leela

    //No functions, can have objects within objects
    //PHP JSON METHODS
    // method                 description
    // json_encode(mixed)     converts a PHP mixed type into a JSON string
    // json_decode(string)    returns PHP mixed type from a JSON string
    // <?php
    // $array1 = array("user"=>"john","password"=>"none","age"=>20);
    // $json_data = json_encode($array1); 
    // // {"user":"John","password":"none","age":20}
    // print $json_data; // returned to client
    // ?> 
    // PHP mixed type could be an object, array, or variable

//BROWSER JSON METHODS
//method                     description
// JSON.parse(string)        converts the given string of JSON data into an 
//                              equivalent JavaScript object and returns it
// JSON.stringify(object)    converts the given object into a string of JSON 
//                              data (the opposite of JSON.parse


function email(){
    var passcode=prompt("Enter passcode to show email:")
    while(passcode!="web"){
        alert("Sorry, incorrect passcode.");
        var passcode=prompt("Enter passcode to show email:")
    }
    var button=document.getElementById("button");
    var email=document.getElementById('email');
    email.innerHTML="e910425@gmail.com"//prompt("Enter your email:");
    button.style.display="none";
    

}
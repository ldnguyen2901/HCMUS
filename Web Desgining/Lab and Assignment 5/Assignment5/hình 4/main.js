//     //Xuất đồng hồ dạng digital
function DisplayTime(){
    var time = new Date();
    var hours = time.getHours();
    var minutes = time.getMinutes();
    var seconds = time.getSeconds();

    var hours = (hours > 12) ? hours - 12 : hours;
    var minutes = ((minutes < 10) ? ":0" : ":") + minutes;
    var seconds = ((seconds < 10) ? ":0" : ":") + seconds;

    var display = " " + hours + minutes + seconds + ((hours >12) ? " PM" : " AM");

    document.ClockDiv.ClockText.value = display;
    id = setTimeout("DisplayTime()", 1000)
}

    //Xuất đồng hồ dạng analog
function rClock(){
    clock();
    setInterval(clock, 1000);
}
function clock(){
    var date = new Date();
    var time = [date.getHours(), date.getMinutes(), date.getSeconds()];
    var clockDivs = [document.getElementById("hour"),
                    document.getElementById("min"),
                    document.getElementById("sec")];
    var hour = time[1]/2+time[0]*30;

    clockDivs[0].style.transform = "rotate("+hour +"deg)";
    clockDivs[1].style.transform = "rotate("+time[1]*6 +"deg)";
    clockDivs[2].style.transform = "rotate("+time[2]*6 +"deg)";
}
<?php include('header.php'); ?>

<div class="col-md-12 ">
    <div class="slider">

        <img class="mySlides" src="img/name1.jpg">
        <img class="mySlides" src="img/name2.jpg">
        <img class="mySlides" src="img/name3.jpg">
        <img class="mySlides" src="img/name.jpg">
    </div>

    <script>
        var slideIndex = 0;
        carousel();

        function carousel() {
            var i;
            var x = document.getElementsByClassName("mySlides");
            for (i = 0; i < x.length; i++) {
                x[i].style.display = "none";
            }
            slideIndex++;
            if (slideIndex > x.length) {
                slideIndex = 1
            }
            x[slideIndex - 1].style.display = "block";
            setTimeout(carousel, 2500);
        }
    </script>

    <div>
         <p style="text-align:justify;"><br> BD Train Schedule & Time Table of Bangladesh Railway are most important to it’s passengers.<br>
However Train is an important transport vehicles for any country in the world. A lot of passengers go one place to another by trains because train journey is more safety and low cost then all others vehicles. Everyday a lot of passenger’s trains are running on various train line or route in Bangladesh. 
Each train have a No, Name, off day ,time schedule or time table ,departure railway station and destination station also have departure time and arrival time.<br>
 But Most us do not know these Train Schedule & Time Table as a result most us miss their desired train and fail to go their destination at right time. Dear reader from this concern i decide that i will provides all the  trains time table or time schedule ,train name, departure station and destination station also provides departure time and arrival time so that everyone can go their destination place at right time.
 </p>
    </div>
    <div class="footer col-md-12">
        <center><p> &copy Copy Right Reserve by Fahad & Subrata </p></center>
    </div>
</div>
</div>
</div>
<?php include('footer.php'); ?>
 

       
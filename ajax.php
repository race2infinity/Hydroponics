<?php 
  session_start(); 

  if (!isset($_SESSION['username'])) {
  	$_SESSION['msg'] = "You must log in first";
  	header('location: index.php#join_us');
  }
?>
<!DOCTYPE html>
<html>
<head>
		<title>Sensor Data</title>
		<meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
		<link rel="stylesheet" href="assets/css/font-awesome.min.css">
		<link rel="stylesheet" href="assets/css/main.css" />
</head>
<style>
body {
    background-image: url("/images/bg2.jpg");
}
table,th,td {
  border : 1px solid black;
  border-collapse: collapse;
}
th,td {
  padding: 5px;
}
</style>
<body>
  <?php  if (isset($_SESSION['username'])) : ?>
        <p align="right" >Welcome <strong><?php echo $_SESSION['username']; ?></strong></p>
        <p align="right"> <button type="button"><a href="logout.php" style="color: white;"  >logout</a></button> </p>
  <?php endif ?>
<br><h2 align = "center">Sensor Data</h2></br>
<p align = "center">
<button type="button" onclick="loadDoc()">Display Data</button>
<button type="button"><a href="redirect.php" style="text-decoration : none;">View Graphs</a></button>
</p>
<br><br>
<table id="demo"></table>

<script>
function loadDoc() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      myFunction(this);
    }
  };
  xhttp.open("GET", "http://api.thingspeak.com/channels/593974/feeds.xml", true);
  xhttp.send(null);
}
function myFunction(xml) {
  var i;
  var xmlDoc = xml.responseXML;
  var table="<tr><th>Temperature</th><th>Humidity</th><th>pH</th><th>Water Level</th><th>Water Temp</th><th>Soil Moisture</th></tr>";
  var x = xmlDoc.getElementsByTagName("feed");
  for (i = 0; i <x.length; i++) {
    table += "<tr><td>" +
    x[i].getElementsByTagName("field1")[0].childNodes[0].nodeValue +
    "</td><td>" +
    x[i].getElementsByTagName("field2")[0].childNodes[0].nodeValue +
    "</td><td>" +
    x[i].getElementsByTagName("field3")[0].childNodes[0].nodeValue +
    "</td><td>" +
    x[i].getElementsByTagName("field4")[0].childNodes[0].nodeValue +
    "</td><td>" +
    x[i].getElementsByTagName("field5")[0].childNodes[0].nodeValue +
    "</td><td>" +
    x[i].getElementsByTagName("field6")[0].childNodes[0].nodeValue +
    "</td></tr>";
  }
  document.getElementById("demo").innerHTML = table;
}
</script>


</body>
</html>

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
table,th,td {
  border : 1px solid black;
  border-collapse: collapse;
  align: center;
}
th,td {
  padding: 5px;
  align:center;
}
</style>
<body>
        <!-- <p align="right" >Welcome <strong><?php echo $_SESSION['username']; ?></strong></p> -->
        <p align="right"> <button type="button"><a href="logout.php" style="color: white;">logout</a></button> </p>
<br><h2 align = "center">Sensor Graphs</h2></br>
    <div class="header">
    </div>
    

    <script>
      $(document).ready(function() {

        function RefreshTable() {
            $( "#datacd" ).load( "home.php#mytable" );
        }

        $("#refresh-btn").on("click", RefreshTable);

        // OR CAN THIS WAY
        //
        // $("#refresh-btn").on("click", function() {
        //    $( "#mytable" ).load( "your-current-page.html #mytable" );
        // });


      });
    </script>
    <table border=2 bordercolor="#0000FF" align="center" name="datacd">
      <tr>
        <td colspan="2">
            <h1 align="center" color="#00FFFF">Data Collection Dashboard</h1>
        </td>
      </tr>
      <tr>
        <td align="center">
          <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/593974/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
        </td>
        <td align="center">
          <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/593974/charts/2?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
        </td>
      </tr>
      <tr>
        <td align="center">
          <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/593974/charts/3?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
        </td>
        <td align="center">
          <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/593974/charts/4?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
        </td>
      </tr>
      <tr>
        <td align="center">
          <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/593974/charts/5?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
        </td>
        <td align="center">
          <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/593974/charts/6?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15"></iframe>
        </td>
      </tr>
    </table>

</body>
</html>

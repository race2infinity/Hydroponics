var express = require("express");
var app  = express();
var path = require("path");
var http = require("http").Server(app)
var mongoose = require("mongoose")
var bodyParser = require("body-parser")
var session = require('express-session')
var bcrypt = require("bcryptjs")
var


var conString = "mongodb://localhost:27017/hydroponics";


app.use(express.static(__dirname+'/views'));
//app.use(express.static(__dirname+'scripts'));


app.get('/',function(req,res){
  res.render('index.html');
  //It will find and locate index.html from View or Scripts
});

/*app.get('/about',function(req,res){
  res.sendFile('/about.html');
});
*/
//creating a server
var server = http.listen(3020, () => {
    console.log("Well done, now I am listening on ", server.address())
})

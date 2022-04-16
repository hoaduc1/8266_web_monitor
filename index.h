const char INDEX_1[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <script src="https://code.highcharts.com/highcharts.js"></script>
  <style>
    body {
      min-width: 310px;
    	max-width: 800px;
    	height: 400px;
      margin: 0 auto;
    }
    h2 {
      font-family: Arial;
      font-size: 2.5rem;
      text-align: center;
    }
  </style>
</head>
<body>
  <h2>ESP Weather Station</h2>
  <div id="chart-angle_x" class="container"></div>
  <div id="chart-angle_y" class="container"></div>
  <div id="chart-angle_z" class="container"></div>
</body>
<script>
var chartT = new Highcharts.Chart({
  chart:{ renderTo : 'chart-angle_x' },
  title: { text: 'Angle X' },
  series: [{
    showInLegend: false,
    data: []
  }],
  plotOptions: {
    line: { animation: false,
      dataLabels: { enabled: true }
    },
    series: { color: '#059e8a' }
  },
  xAxis: { type: 'datetime',
    dateTimeLabelFormats: { second: '%H:%M:%S' }
  },
  yAxis: {
    title: { text: 'Angle X (degree)' }
  },
  credits: { enabled: false }
});
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var x = (new Date()).getTime(),
          y = parseFloat(this.responseText);
      //console.log(this.responseText);
      if(chartT.series[0].data.length > 40) {
        chartT.series[0].addPoint([x, y], true, true, true);
      } else {
        chartT.series[0].addPoint([x, y], true, false, true);
      }
    }
  };
  xhttp.open("GET", "/Angle_X", true);
  xhttp.send();
}, 100) ;

var chartH = new Highcharts.Chart({
  chart:{ renderTo:'chart-angle_y' },
  title: { text: 'Angle Y' },
  series: [{
    showInLegend: false,
    data: []
  }],
  plotOptions: {
    line: { animation: false,
      dataLabels: { enabled: true }
    }
  },
  xAxis: {
    type: 'datetime',
    dateTimeLabelFormats: { second: '%H:%M:%S' }
  },
  yAxis: {
    title: { text: 'Angle Y (degree)' }
  },
  credits: { enabled: false }
});
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var x = (new Date()).getTime(),
          y = parseFloat(this.responseText);
      //console.log(this.responseText);
      if(chartH.series[0].data.length > 40) {
        chartH.series[0].addPoint([x, y], true, true, true);
      } else {
        chartH.series[0].addPoint([x, y], true, false, true);
      }
    }
  };
  xhttp.open("GET", "/Angle_Y", true);
  xhttp.send();
}, 100) ;

var chartP = new Highcharts.Chart({
  chart:{ renderTo:'chart-angle_z' },
  title: { text: 'Angle Z' },
  series: [{
    showInLegend: false,
    data: []
  }],
  plotOptions: {
    line: { animation: false,
      dataLabels: { enabled: true }
    },
    series: { color: '#18009c' }
  },
  xAxis: {
    type: 'datetime',
    dateTimeLabelFormats: { second: '%H:%M:%S' }
  },
  yAxis: {
    title: { text: 'Angle Z (degree)' }
  },
  credits: { enabled: false }
});
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var x = (new Date()).getTime(),
          y = parseFloat(this.responseText);
      //console.log(this.responseText);
      if(chartP.series[0].data.length > 40) {
        chartP.series[0].addPoint([x, y], true, true, true);
      } else {
        chartP.series[0].addPoint([x, y], true, false, true);
      }
    }
  };
  xhttp.open("GET", "/Angle_Z", true);
  xhttp.send();
}, 100) ;
</script>
</html>
)rawliteral";

const char INDEX_2[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
  <style>
    html {
     font-family: Arial;
     display: inline-block;
     margin: 0px auto;
     text-align: center;
    }
    h2 { font-size: 3.0rem; }
    p { font-size: 3.0rem; }
    .units { font-size: 1.2rem; }
    .dht-labels{
      font-size: 1.5rem;
      vertical-align:middle;
      padding-bottom: 15px;
    }
  </style>
</head>
<body>
  <h2>ESP8266 DHT Server</h2>
  <p>
    <i class="fas fa-thermometer-half" style="color:#059e8a;"></i> 
    <span class="dht-labels">Temperature</span> 
    <span id="temperature">%TEMPERATURE%</span>
    <sup class="units">&deg;C</sup>
  </p>
  <p>
    <i class="fas fa-tint" style="color:#00add6;"></i> 
    <span class="dht-labels">Humidity</span>
    <span id="humidity">%HUMIDITY%</span>
    <sup class="units">%</sup>
  </p>
</body>
<script>
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temperature").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/temperature", true);
  xhttp.send();
}, 250) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("humidity").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/humidity", true);
  xhttp.send();
}, 500) ;
</script>
</html>)rawliteral";

const char INDEX_3[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {
     font-family: Arial;
     display: inline-block;
     margin: 0px auto;
     text-align: center;
    }
    h2 { font-size: 1.5rem; }
    p { font-size: 1.0rem; }
    .units { font-size: 0.7rem; }
    .dht-labels{
      font-size: 1.0rem;
      vertical-align:middle;
      padding-bottom: 15px;
    }
  </style>
</head>
<body>
  <h2>DRONE SENSOR MONITOR</h2>
  <p>
    <a>
      <span class="dht-labels">Angle X</span> 
      <span class="dht-labels" id="Angle_X">%Angle_X%</span>
      <sup class="units">&deg;</sup>
    </a>
    <a>
      <span class="dht-labels">Angle Y</span>
      <span class="dht-labels" id="Angle_Y">%Angle_Y%</span>
      <sup class="units">&deg;</sup>
    </a>
    <a>
      <span class="dht-labels">Angle Z</span>
      <span class="dht-labels" id="Angle_Z">%Angle_Z%</span>
      <sup class="units">&deg;</sup>
    </a>
  </p>
  <p>
    <a>
      <span class="dht-labels">Gyro X</span> 
      <span class="dht-labels" id="Gyro_X">%Gyro_X%</span>
      <sup class="units">&deg;</sup>
    </a>
    <a>
      <span class="dht-labels">Gyro Y</span>
      <span class="dht-labels" id="Gyro_Y">%Gyro_Y%</span>
      <sup class="units">&deg;</sup>
    </a>
    <a>
      <span class="dht-labels">Gyro Z</span>
      <span class="dht-labels" id="Gyro_Z">%Gyro_Z%</span>
      <sup class="units">&deg;</sup>
    </a>
  </p>
</body>
<script>
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Angle_X").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/Angle_X", true);
  xhttp.send();
}, 100) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Angle_Y").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/Angle_Y", true);
  xhttp.send();
}, 100) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Angle_Z").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/Angle_Z", true);
  xhttp.send();
}, 100) ;
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Gyro_X").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/Gyro_X", true);
  xhttp.send();
}, 100) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Gyro_Y").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/Gyro_Y", true);
  xhttp.send();
}, 100) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("Gyro_Z").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/Gyro_Z", true);
  xhttp.send();
}, 100) ;
</script>
</html>)rawliteral";
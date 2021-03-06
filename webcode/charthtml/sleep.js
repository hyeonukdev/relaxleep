anychart.onDocumentReady(function () {
  
    // JSON data
    var json = {
      // chart settings
      "chart": {
        // chart type
        "type": "pie",
        // chart data
        "data": [
  {"x": "Apples", "value": "128.14", fill: "green"},
  {"x": "Oranges", "value": "128.14", fill: "orange"}
        ],
        // chart container
        "container": "container"
      }
    };
  
    // get JSON data
    var chart = anychart.fromJson(json);
  
    // draw chart
    chart.draw();
  });
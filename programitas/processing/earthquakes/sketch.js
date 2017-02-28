var earth;
function setup(){
    createCanvas(2048, 1025);
    earth = loadImage("assets/earth.jpg");
}

function draw(){
    noLoop();
    //    image(earth, 0, 0);
    // Lat: 6.27053 Lon: -75.57211999999998 Medellín
    var lat = 6.27053;
    var lon = -75.57211999999998;
    // Fórmulas de Mercator para traducir coordenadas a plano.
    lon = radians(lon);
    lat = radians(lat);
    var x = (256/PI)*2*(lon + PI);
    var y = (256/PI)*2*(PI - log(tan(PI/4 + lat/2)));
    // Paint  ellipse in the long, lat coordinates
    fill(255, 0, 0, 200);
    ellipse(x, y, 50, 50);
}

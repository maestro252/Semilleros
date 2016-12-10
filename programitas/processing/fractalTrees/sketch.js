// Gloabl variables.
var segLen = 3;
var d = 15;
var da = 10;

function drawTree(x1, y1, angle, depth){
  if(depth != 0){
    var x2 = x1 + floor((cos(angle) * depth * segLen));
    var y2 = y1 + floor((sin(angle) * depth * segLen));

    line(x1, y1, x2, y2);

    drawTree(x2, y2, angle - da, depth - 1);
    drawTree(x2, y2, angle + da, depth - 1);
  }
}

function setup(){
  createCanvas(2000, 2000);
  background(0, 0, 0);
  angleMode(DEGREES);
}

function draw(){
  noLoop();
  stroke(255);
  strokeWeight(2);
  translate(width/2,height/2);
  drawTree(0, 0, -90, d);
  drawTree(0, 0, -180, d);
  drawTree(0, 0, -270, d);
  drawTree(0, 0, 0, d);
}

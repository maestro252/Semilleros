var tree = [];
var leaves = [];

var count = 0;

function setup() {
	frameRate(1);
  createCanvas(800, 800);
  var a = createVector(width / 2, height);
  var b = createVector(width / 2, height - height / 6);
  var root = new Branch(a, b);

  tree[0] = root;
}

function mousePressed(){
	noLoop();
}

function draw() {
	background(51);
	for (var i = tree.length - 1; i >= 0; i--) {
    if (!tree[i].finished) {
      tree.push(tree[i].branchA());
      tree.push(tree[i].branchB());
    }
    tree[i].finished = true;
  }

  for (var i = 0; i < tree.length; i++) {
    tree[i].show();
  }
}

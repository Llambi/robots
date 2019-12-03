//%import("C:/Users/UO251069/Desktop/BattRack.stl");
module BattRack(){
    
difference(){
    translate([-15,0.75,28])
        cube([30,41.25,20]);
    translate([-12,0,27])
        cube([24,39,22]);
}

translate([15,0.75,28])
cube([13.5,11.25,4]);
translate([-28.5,0.75,28])
cube([13.5,11.25,4]);
}

BattRack();


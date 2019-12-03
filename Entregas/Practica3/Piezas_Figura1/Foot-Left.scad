//%import("C:/Users/UO251069/Desktop/Modelos3D/Figura1/PorHacer/Foot-Left.stl");

module FootLeft(){

hull(){
    translate([24,29,-2.5])
    cylinder(h=6,d=6,$fn=100);
    
    translate([24,29,2])
    sphere(d=6,$fn=100);
    
    translate([-24,-29,-2.5])
    cylinder(h=6,d=6,$fn=100);
    
    translate([-24,-29,2])
    sphere(d=6,$fn=100);
    
    translate([24,-29,-2.5])
    cylinder(h=6,d=6,$fn=100);
    
    translate([24,-29,2])
    sphere(d=6,$fn=100);
    
    translate([-24,29,-2.5])
    cylinder(h=6,d=6,$fn=100);
    
    translate([-24,29,2])
    sphere(d=6,$fn=100);
}   

translate([3,-2.5,0])
cube([5,10,16]);

translate([-25.5,-2.5,5])
cube([5,5,11]);
}

FootLeft();
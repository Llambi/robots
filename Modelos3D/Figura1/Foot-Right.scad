//%import("C:/Users/UO251069/Desktop/Modelos3D/Figura1/PorHacer/Foot-Right.stl");

module FootRight(){

translate([-8,0,0])
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

translate([-16,-2.5,5])
cube([5,10,11]);

translate([12.5,-2.5,0])
cube([5,5,16]);
}

FootRight();
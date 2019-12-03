//%import("C:/Users/UO251069/Desktop/Modelos3D/Figura1/PorHacer/Hip.stl");

module Hip(){

difference(){
    
    hull(){
        
        translate([37,17,1])
        cylinder(h=3.5,d=5,$fn=100);
        translate([37,17,2])
        sphere(d=5,$fn=100);

        translate([-37,-17,1])
        cylinder(h=3.5,d=5,$fn=100);
        translate([-37,-17,2])
        sphere(d=5,$fn=100);

        translate([37,-17,1])
        cylinder(h=3.5,d=5,$fn=100);
        translate([37,-17,2])
        sphere(d=5,$fn=100);

        translate([-37,17,1])
        cylinder(h=3.5,d=5,$fn=100);
        translate([-37,17,2])
        sphere(d=5,$fn=100);
    }

    translate([0,0,-5])
    cylinder(h=10,d=3,$fn=100);
    
    translate([-21.2,-13.8,-5])
    cylinder(h=10,d=1.5,$fn=100);
    
    translate([21.2,-13.8,-5])
    cylinder(h=10,d=1.5,$fn=100);
    
    translate([21.2,13.8,-5])
    cylinder(h=10,d=1.5,$fn=100);
    
    translate([-21.2,13.8,-5])
    cylinder(h=10,d=1.5,$fn=100);
    
    translate([33.3,0,-5])
    cylinder(h=10,d=3,$fn=100);
    
    translate([-33.3,0,-5])
    cylinder(h=10,d=3,$fn=100);

    translate([15,-12,-5])
    cube([12.5,24,10]);

    translate([-27.4,-12,-5])
    cube([12.5,24,10]);
}
}

Hip();
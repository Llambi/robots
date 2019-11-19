%import("C:/Users/UO251069/Desktop/ServoBrace.stl");

difference(){
    translate([-15,-1,0])
    cube([30,2,23.75]);
    
    rotate([90,0,0])
    translate([0,11.875,-3])
    cylinder(h=5,d=3,$fn=100);
}



difference(){
    translate([-37.5,-1,0])
    cube([10,2,23.75]);
    
    rotate([90,0,0])
    translate([-33.5,11.875,-3])
    cylinder(h=5,d=3,$fn=100);
}

difference(){
    translate([27.5,-1,0])
    cube([10,2,23.75]);
    
    rotate([90,0,0])
    translate([33.5,11.875,-3])
    cylinder(h=5,d=3,$fn=100);
}

rotate([0,0,90])
translate([-1,27.5,0])
cube([20.5,2,23.75]);

rotate([0,0,90])
translate([-1,13,0])
cube([20.5,2,23.75]);

rotate([0,0,90])
translate([-1,-15,0])
cube([20.5,2,23.75]);

rotate([0,0,90])
translate([-1,-29.5,0])
cube([20.5,2,23.75]);

translate([13,17.75,0])
cube([16.5,2,23.75]);

translate([-29.5,17.5,0])
cube([16.5,2,23.75]);
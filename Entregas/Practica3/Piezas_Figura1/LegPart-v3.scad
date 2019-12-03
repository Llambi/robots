//%import("C:/Users/UO251069/Desktop/LegPart-v3.stl");

module LegPart(){

difference(){
    translate([-37,26,0])
    cube([40,3,10]);
    rotate([90,0,0])
    translate([-17,5,-30])
    cylinder(h=16,r=2,$fn=100);
    for(i=[-8 : -18 :-26]){
        rotate([90,0,0])
        translate([i,5,-30])
        cylinder(h=16,r=0.5,$fn=100);
    }
}


translate([-37,5.5,5])
rotate([0,90,0])
cylinder(h=3,r=5,$fn=100);


translate([-37,5,0])
cube([3,23,10]);


rotate([0,90,0])
translate([-5,5,-37])
cylinder(h=7.5,r=2.25,$fn=100);

difference(){
hull(){

translate([0,10,0])
cube([3,17,10]);



rotate([0,90,0])
translate([-5,5.5,0])
cylinder(h=3,r=5,$fn=100);
}

rotate([0,90,0])
    translate([-5,5.5,0])
translate([0,-0.5,-0.3])
cylinder(h=4,r=2.5,$fn=100);

for(i=[12 : 6 :18]){
        rotate([0,90,0])
        translate([-5,i,-1])
        cylinder(h=10,r=0.5,$fn=100);
    }

}
}
LegPart();



    



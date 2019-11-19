
%import("C:/Users/UO251069/Desktop/PhoneHolder.stl");

translate([-36.8,-32.5,1])
cube([73.6,14,2]);

rotate([0,90,0])
translate([-111,-20.5,-35])
cube([110,2,70]);

translate([-35,-32.5,3])
cube([70,2,8]);

rotate([0,0,90])
translate([-32.5,-36.8,2.5])
cube([14,2,38.6]);

rotate([0,0,90])
translate([-32.5,34.8,2.5])
cube([14,2,38.6]);

translate([-25,-20,29])
cube([50,4,28.7]);

hull(){
    rotate([0,8.1,90])
    translate([-27.8,22.2,50.8])
    cube([12,3.7,4.1]);

    rotate([0,-9.75,90])
    translate([-13.35,22.2,31.38])
    cube([15,3.8,4]);
}

hull(){
    rotate([0,8.1,90])
    translate([-27.8,-26,50.8])
    cube([12.3,3.7,4.1]);

    rotate([0,-9.75,90])
    translate([-13.35,-26,31.38])
    cube([15,3.8,4]);
}

rotate([9.75,0,0])
translate([-25,-14,31.5])
cube([50,15.7,3]);

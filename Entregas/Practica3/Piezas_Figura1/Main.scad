use <BattRack.scad>
use <Hip.scad>
use <Foot-Left.scad>
use <Foot-Right.scad>
use <LegPart-v3.scad>
use <PhoneHolder.scad>
use <ServoBraze.scad>

translate([30, 0, 0])
FootLeft();
translate([-25, 0, 0])
FootRight();
rotate([90,0,270])
translate([15, 10, 15])
LegPart();
rotate([90,0,270])
translate([15, 10, -25])
LegPart();

translate([0,0,50])
Hip();
rotate([90,0,0])
translate([0,57,-12])
ServoBraze();
translate([0,0,50])
BattRack();

translate([0,-3,50])
PhoneHolder();
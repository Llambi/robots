translate([27.5,32.5,2.5])
import("C:/Users/uo250708/Downloads/MobBob_-_Smart-phone_controlled_desktop_robot/Foot-Left.stl");



%hull(){
    for (i = [4, 51], j = [4, 61]){
        translate([i, j, 0])
        union() {
            alturaCil = 3.5;
            radioCil = 4;
            cylinder(h = alturaCil, r = radioCil);

            translate([0,0, alturaCil])
            sphere(r = radioCil);
        }
    }
}


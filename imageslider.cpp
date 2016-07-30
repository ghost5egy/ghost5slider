/**
# author : ghost5egy
# email : AhmedSaeedRamadan@yahoo.com
# website : www.yasahost.com
# GPL v3

#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.

#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
**/

#include <sstream>
#include <iostream>
#include <fstream>
#include "imageslider.h"

using namespace std;

const string filenameco = "yasa";

imageslider::imageslider(){
        htmlc.erase();
        htmlc = "<div class=\"yasaslider\">\n";
        width.erase();
        height.erase();
        cssc.erase();
        jsc.erase();
        rdirection.erase();
        direction.erase();
}

void imageslider::setwidth(string swidth){
    width.erase();
    width = swidth;
}

void imageslider::setheight(string sheight){
    height.erase();
    height = sheight;
}

void imageslider::insertimage(string imgid,string imgpath,string imgalt){
    htmlc.append("<img id=\"");
    htmlc.append(imgid);
    htmlc.append("\" src=\"");
    htmlc.append(imgpath);
    htmlc.append("\" border=\"0\" ");
    htmlc.append("alt=\"");
    htmlc.append(imgalt);
    htmlc.append("\" />\n");
}

void imageslider::endslider(){
    htmlc.append("</div>");
}

string imageslider::gethtmlcode(){
    return htmlc;
}

string imageslider::getcsscode(){
    cssc.append(".yasaslider {\nwidth:");
    cssc.append(width);
    cssc.append("px;\n");
    cssc.append("height:");
    cssc.append(height);
    cssc.append("px;\noverflow:hidden;\nmargin:30px auto;\nbackground-image:url(\"../img/InProgress.gif\");\nbackground-repeat:no-repeat;\nbackground-position:center;\n}");
    cssc.append("\n\n.yasaslider img{\nwidth:");
    cssc.append(width);
    cssc.append(";\nheight:");
    cssc.append(height);
    cssc.append(";\ndisplay:none;\n}\n");
    return cssc;
}

string imageslider::getjscode(){
    jsc.append("$( window ).load(function(){ \n$(\".yasaslider #1\").show(\"fade\",500);\n$(\".yasaslider #1\").delay(5500).hide(\"slide\",{direction:\"");
    jsc.append(direction);
    jsc.append("\"},500);\n\nvar sc = $(\".yasaslider img\").size();\nvar count = 2;\nsetInterval(function (){\n$(\".yasaslider #\"+count).show(\"slide\",{direction:\"");
    jsc.append(direction);
    jsc.append("\"},500);\n$(\".yasaslider #\"+count).delay(5500).hide(\"slide\",{direction:\"");
    jsc.append(rdirection);
    jsc.append("\"},500);\n\nif(count == sc){\ncount = 1;\n}else{\ncount = count +1;\n}\n},6500);\n});");
    return jsc;
}

void imageslider::setdirection(int direc){
    direction.erase();
    rdirection.erase();
    switch(direc){
        case 0:
            direction = "right";
            rdirection = "left";
            break;
        case 1:
            direction = "left";
            rdirection = "right";
            break;
    }
}


bool imageslider::savetofile(string filename,string filedata){
    ofstream filestr;
    filestr.open(filename.c_str());
    filestr << filedata;
    filestr.close();
    return 1;
}

bool imageslider::writetofile(){
    savetofile(filenameco + ".css",getcsscode());
    savetofile(filenameco + ".html","<link rel=\"stylesheet\" type=\"text/css\" href=\"css/load.css\"></link>\n<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/2.0.0/jquery.min.js\" type=\"text/javascript\"></script>\n<script src=\"https://ajax.googleapis.com/ajax/libs/jqueryui/1.10.3/jquery-ui.min.js\" type=\"text/javascript\"></script>\n<script src=\"js/load.js\" type=\"text/javascript\" ></script>\n" + gethtmlcode());
    savetofile(filenameco + ".js",getjscode());
    return 1;
}

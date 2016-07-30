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

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <getopt.h>
#include <dirent.h>
#include "imageslider.h"

using namespace std;

int main(int argc,char **argv)
{
    int noption = 0;
    const struct option arglong[] = {
        {"width",1,NULL,'w'},
        {"height",1,NULL,'t'},
        {"help",0,NULL,'h'},
        {"count",1,NULL,'c'},
        {"fpath",1,NULL,'p'},
        {"left",1,NULL,'l'},
    };
    const char* const argshort = "w:hc:p:l:t:";
    imageslider ahmed;
    string height;
    string width;
    string count;
    string image;
    int pdi = 0;
    char pds[2];
    int dira = 0;
    if(argc > 1){
        cout<<"Yasa Imageslider creating files\n";
        do{
            noption = getopt_long(argc,argv,argshort,arglong,NULL);
            switch(noption){
                case 'w':
                    cout<<"this is w with value : "<< optarg <<".\n";
                    width = optarg;
                    break;
                case 't':
                    height = optarg;
                    cout<<"this is h : "<< height <<".\n";
                    break;
                case 'c':
                    count = optarg;
                    cout<<"this is c : "<< count <<".\n";
                    break;
                case 'p':
                    cout<<"this is p : "<< optarg <<".\n";
                    DIR *dir;
                    struct dirent *ent;
                    if ((dir = opendir (optarg)) != NULL) {
                        // print all the files and directories within directory
                        while(((ent = readdir (dir))) != NULL) {
                            pdi++;
                            sprintf(pds,"%d",pdi - 2);
                            if(pdi == 1 || pdi == 2){
                                continue;
                            }else{
                                string asd(optarg);
                                asd.append("/");
                                asd.append(ent->d_name);
                                ahmed.insertimage(pds,asd.c_str(),"yasahost");
                            }
                        }
                        closedir (dir);
                    } else {
                        // could not open directory
                        perror ("");
                        return EXIT_FAILURE;
                    }
                    break;
                case 'l':
                    dira = atoi(optarg);
                    cout<<"this is l : "<< dira <<".\n";
                    break;
                case 'h':
                    cout<<"this is yasa image slider by ghost5egy \nthe options :\n\t-w ot --width\tfor width\n\t-t or --height\tfor height\n\t-c or --count\tfor count\n\t-l or --left\tfor direction of photo\n\t-p or --fpath\tfor image directory\n\t-h or --help\tfor this help\t";
                    return 0;
                    break;
                case -1:
                    break;
                default :
                    cout<<"there is no argument called : "<< noption<<endl;
                    return 0;
            }
        }while(noption != -1);
    }else{
        cout << "Hello in Yasa Image Slider..." << endl;
        cout << "Enter width : ";
        cin >>width;
        cout << "Enter height : ";
        cin >> height;
        cout << "Enter image count (the max count is 6) : ";
        cin >> count;
        cout << "Enter dirction (0 for right , 1 for left) : ";
        cin >> dira;
        while((atoi(count.c_str())) > 6 || (atoi(count.c_str())) <= 0){
            cout  << "Renter image count (the max count is 6) : ";
            cin >> count;
        }
        for(int i = 0;i < atoi(count.c_str());i++){
            char ito[2];
            cout  << "Enter image " << i + 1 << " : " ;
            cin >> image;
            sprintf(ito,"%d",i + 1);
            ahmed.insertimage(ito,image,"yasahost");
        }
    }
    ahmed.setheight(height);
    ahmed.setwidth(width);
    ahmed.setdirection(dira);
    ahmed.endslider();
    ahmed.writetofile();
    cout<<"Done .\n";
}

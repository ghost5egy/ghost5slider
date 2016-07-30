#ifndef __IMAGESLIDER_H__
#define __IMAGESLIDER_H__

class imageslider {
        private :
            std::string width;
            std::string height;
            std::string htmlc ;
            std::string cssc;
            std::string jsc;
            std::string direction;
            std::string rdirection;
            bool savetofile(std::string filename,std::string filedata);
        public :
            imageslider();
            void setwidth(std::string swidth);
            void setheight(std::string sheight);
            void insertimage(std::string imgid,std::string imgpath,std::string imgalt);
            void setdirection(int direc);
            void endslider();
            std::string gethtmlcode();
            std::string getcsscode();
            std::string getjscode();
            bool writetofile();
};


#endif

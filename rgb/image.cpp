#include <rgb/image.hpp>

namespace rgb {
    image::image(int w, int h, const color& fill) {
        iwidth = w;
        iheight = h;
        pixels = new color* [iwidth];
        for(int i = 0; i < iwidth; i++){
            pixels[i] = new color[iheight];
            for(int j = 0; j < iheight; j++){
                pixels[i][j] = fill;
            }
        }
    }
    image::~image() {
        for (int i = 0; i < iwidth; ++i) {
            delete [] pixels[i];
        }
        delete [] pixels;
    }

    int image::width() const {
        return iwidth;
    }

    int image::height() const {
        return iheight;
    }

    color& image::at(int x, int y) {
        return pixels[x][y];
    }

    const color& image::at(int x, int y) const {
        return pixels[x][y];
    }

    void image::invert() {
        for(int i = 0; i < iwidth; i++){
            for(int j = 0; j < iheight; j++){
                pixels[i][j].invert();
            }
        }
    }

    void image::to_gray_scale() {
        for(int i = 0; i < iwidth; i++){
            for(int j = 0; j < iheight; j++){
                pixels[i][j].to_gray_scale();
            }
        }
    }

    void image::fill(int x, int y, int w, int h, const color& c) {
        for(int i = x; i < x + w; i++){
            for(int j = y; j < y + h; j++){
                pixels[i][j] = c;
            }
        }
    }

    void image::replace(const color& a, const color& b) {
        for(int i = 0; i < iwidth; i++){
            for(int j = 0; j < iheight; j++){
                if ( pixels[i][j] == a) pixels[i][j] = b;
            }
        }
    }

    void image::add(const image& img, const color& neutral,int x, int y) {

        for(int i = x, k = 0; i < iwidth && k < img.width(); i++, k++){
            for(int j = y, l = 0 ; j < iheight && l < img.height(); j++, l++){
                if(img.at(k,l) != neutral) pixels[i][j] = img.at(k,l);
            }
        }
    }

    void image::crop(int x, int y, int w, int h) {//UNFINISHED
        color **crop;
        crop = new color* [w];

        for(int i = 0,k = x; i < w; i++ , k++){
            crop[i] = new color[h];
            for(int j = 0, l = y; j < h; j++ , l++){
                crop[i][j] = at(k,l);
            }
        }

        for (int i = 0; i < iwidth; i++) {
            delete [] pixels[i];
        }
        delete [] pixels;

        iwidth = w;
        iheight = h;

        pixels = new color* [iwidth];
        for(int i = 0; i < iwidth; i++){
            pixels[i] = new color[iheight];
            for (int j = 0; j < iheight ; j++) {
                pixels[i][j]= crop[i][j];
            }
        }

        for (int i = 0; i < iwidth; ++i) {
            delete [] crop[i];
        }
        delete [] crop;
    }

    void image::rotate_left() {
        color **rotate;
        rotate = new color* [iheight];


        for(int i = 0 ; i < iheight; i++ ){
            rotate[i] = new color[iwidth];
            for(int j = 0, l = iwidth - 1; j < iwidth; j++, l--){
                rotate[i][j] = at(l,i);
            }
        }

        for (int i = 0; i < iwidth; i++) {
            delete [] pixels[i];
        }
        delete [] pixels;

        std::cout << " old width:" << iwidth << " old height:" << iheight << std::endl;

        int temp = iwidth;
        iwidth = iheight;
        iheight = temp;

        std::cout << " new width:" << iwidth << " new height:" << iheight << std::endl;

        pixels = new color* [iwidth];
        for(int i = 0; i < iwidth; i++){
            pixels[i] = new color[iheight];
            for (int j = 0; j < iheight ; j++) {
                pixels[i][j]= rotate[i][j];
            }
        }

        for (int i = 0; i < iwidth; ++i) {
            delete [] rotate[i];
        }
        delete [] rotate;
    }

    void image::rotate_right() {
        color **rotate;
        rotate = new color* [iheight];


        for(int i = 0 , k = iheight - 1; i < iheight; i++, k-- ){
            rotate[i] = new color[iwidth];
            for(int j = 0; j < iwidth; j++){
                rotate[i][j] = at(j,k);
            }
        }

        for (int i = 0; i < iwidth; i++) {
            delete [] pixels[i];
        }
        delete [] pixels;


        int temp = iwidth;
        iwidth = iheight;
        iheight = temp;


        pixels = new color* [iwidth];
        for(int i = 0; i < iwidth; i++){
            pixels[i] = new color[iheight];
            for (int j = 0; j < iheight ; j++) {
                pixels[i][j]= rotate[i][j];
            }
        }

        for (int i = 0; i < iwidth; ++i) {
            delete [] rotate[i];
        }
        delete [] rotate;
    }

    void image::mix(const image& img, int factor) {
        for(int i = 0; i < iwidth; i++){
            for(int j = 0; j < iheight; j++){
                pixels[i][j].mix(img.at(i,j),factor);
            }
        }
    }
}

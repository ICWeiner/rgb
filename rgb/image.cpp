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
    void image::add(const image& img, const color& neutral,
                    int x, int y) {
        for(int i = x; i < iwidth; i++){
            for(int j = y; j < iheight; j++){
                if(pixels[i][j] != neutral) pixels[i][j] = img.at(i,j);
            }
        }
    }
    void image::crop(int x, int y, int w, int h) {//UNFINISHED
        color **crop = new color* [iwidth];
        for(int i = 0,k = x; i < iwidth; i++ , k++){
            crop[i] = new color[iheight];
            for(int j = 0, l = y; j < iheight; j++ , l++){
                crop[i][j] = at(k,l);
            }
        }
    }
    void image::rotate_left() {

    }
    void image::rotate_right() {

    }
    void image::mix(const image& img, int factor) {
        for(int i = 0; i < iwidth; i++){
            for(int j = 0; j < iheight; j++){
                pixels[i][j].mix(img.at(i,j),factor);
            }
        }
    }
}

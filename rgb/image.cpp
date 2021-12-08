#include <rgb/image.hpp>

namespace rgb {
    image::image(int w, int h, const color& fill) {

    }
    image::~image() {

    }
    int image::width() const {
        return -1;
    }
    int image::height() const {
        return -1;
    }
    color& image::at(int x, int y) {
        return pixels[x][y];
    }
    const color& image::at(int x, int y) const {
        return pixels[x][y];
    }
    void image::invert() {

    }
    void image::to_gray_scale() {

    }
    void image::fill(int x, int y, int w, int h, const color& c) {

    }
    void image::replace(const color& a, const color& b) {

    }
    void image::add(const image& img, const color& neutral,
                    int x, int y) {

    }
    void image::crop(int x, int y, int w, int h) {

    }
    void image::rotate_left() {

    }
    void image::rotate_right() {

    }
    void image::mix(const image& img, int factor) {

    }
}

//! @file color.hpp
#ifndef __rgb_color_hpp__
#define __rgb_color_hpp__

#include <iostream>

namespace rgb {
    //!Custom data type for storing color values between 0 and 255
    typedef unsigned char rgb_value;

    //! Class that represents a single pixel
    class color {
    private:
        rgb_value r;//! Red value
        rgb_value g;//! Green value
        rgb_value b;//! Blue value
    public:
        static const color RED;  //!Sets this pixel to the color red
        static const color GREEN;//!Sets this pixel to the color green
        static const color BLUE;//!Sets this pixel to the color blue
        static const color BLACK;//!Sets this pixel to the color black
        static const color WHITE;//!Sets this pixel to the color white
        color();//! Empty constructor
        color(const color &c);//! Copy constructor
        color(rgb_value r, rgb_value g, rgb_value b);//! Manual color constructor
        rgb_value red() const; //!returns red as a constant
        rgb_value& red();//!returns red by reference
        rgb_value green() const;//!returns green as a constant
        rgb_value& green();//!returns green by reference
        rgb_value blue() const;//!returns blue as a constant
        rgb_value& blue();//!returns blue by reference
        color& operator=(const color&c);//! assignment overload
        bool operator==(const color &c) const;//! equals overload
        bool operator!=(const color &c) const;//! different than overload
        void invert();//! inverts color of pixel
        void to_gray_scale();//! sets pixel to gray scale
        void mix(const color& c, int f);/*! Mixes color of pixel with outbound pixel by a factor of f
        * \param color outbound pixel
        * \param f factor of mix, between 0 and 100
        */
    };
}
#endif

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
        //! Red value
        rgb_value r;
        //! Green value
        rgb_value g;
        //! Blue value
        rgb_value b;
    public:
        //!Sets this pixel to the color red
        static const color RED;
        //!Sets this pixel to the color green
        static const color GREEN;
        //!Sets this pixel to the color blue
        static const color BLUE;
        //!Sets this pixel to the color black
        static const color BLACK;
        //!Sets this pixel to the color white
        static const color WHITE;
        //! Empty constructor
        color();
        //! Copy constructor
        color(const color &c);
        //! Manual color constructor
        color(rgb_value r, rgb_value g, rgb_value b);
        //!returns red as a constant
        rgb_value red() const;
        //!returns red by reference
        rgb_value& red();
        //!returns green as a constant
        rgb_value green() const;
        //!returns green by reference
        rgb_value& green();
        //!returns blue as a constant
        rgb_value blue() const;
        //!returns blue by reference
        rgb_value& blue();
        //! assignment overload
        color& operator=(const color&c);
        //! equals overload
        bool operator==(const color &c) const;
        //! different than overload
        bool operator!=(const color &c) const;
        //! inverts color of pixel
        void invert();
        //! sets pixel to gray scale
        void to_gray_scale();
        /*! Mixes color of pixel with another pixel by a factor of f
        * \param color pixel to mix with
        * \param f factor of mix, between 0 and 100
        */
        void mix(const color& c, int f);
    };
}
#endif

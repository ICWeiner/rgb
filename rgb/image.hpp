//! @file image.hpp
#ifndef __rgb_image_hpp__
#define __rgb_image_hpp__
#include <cassert>
#include <rgb/color.hpp>

namespace rgb {
    //! Class that represents an image,pixel by pixel
    class image {
    private:
        //!Width of the image in pixels
        int iwidth;
        //!Height of the image in pixels
        int iheight;
        //!2D array of pixels
        color **pixels;
    public:
        //!Constructor that sets the whole iamge to a single color.
        image(int w, int h, const color& fill = color::WHITE);
        //!Default deconstructor
        ~image();
        //!Returns image width as a constant
        int width() const;
        //!Returns image height as a constant
        int height() const;
        /*! Returns color at the given coordinates
        * \param x
        * \param y
        * \Return A color object reference
        */
        color& at(int x, int y);
        /*! Returns color at the given coordinates
        * \param x
        * \param y
        * \return A color object reference constant
        */
        const color& at(int x, int y) const;
        //!Inverts the colors of the whole image
        void invert();
        //! Gray scales the whole image
        void to_gray_scale();
        /*!Replace every occurrence of a pixel with another one
        * \param a pixel to replace if found
        * \param b new pixel
        */
        void replace(const color& a, const color& b);
        /*!Fill a portion of the image with a set color
        * coordinate (x,y) defines the upper left limit of filling
        * \param x upper left x coordinate
        * \param y upper left y coordinate
        * \param w how much width , in pixels, to fill
        * \param h how much height, in pixels, to fill
        */
        void fill(int x, int y, int w, int h, const color& c);
        /*! Mixes image with another image by a factor of f
        * \param img image to mix with
        * \param f factor of mix, between 0 and 100
        */
        void mix(const image& img, int factor);
        /*! Crops image
        * coordinate (x,y) defines the upper left corner of the resulting image
        * \param x upper left x coordinate
        * \param y upper left y coordinate
        * \param w how much width , in pixels, to keep
        * \param h how much height, in pixels, to keep
        */
        void crop(int x, int y, int w, int h);
        //!Rotates the image counter-clockwise
        void rotate_left();
        //!Rotates image clockwise
        void rotate_right();
        /*!Adds a second image to the original
        * coordinate (x,y) defines the position where adding the image will begin
        * \param img image to add
        * \param x upper left x coordinate
        * \param y upper left y coordinate
        * \param neutral color to ignore in the to-add image
        */
        void add(const image& img, const color& neutral,int x, int y);
    };
}


#endif

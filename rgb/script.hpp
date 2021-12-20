
//! @file script.hpp
#ifndef __rgb_script_hpp__
#define __rgb_script_hpp__

#include <fstream>
#include <rgb/image.hpp>

namespace rgb {
    //! class that executes scripts read from text files to create or modify png images
    class script {
    private:
        //! fills an image with a color read from script
        void fill();
        //! reads an image file with a name read from script
        void open();
        /*! secondary read method, used when two images are required at the same time
        * \param filename name of secondary image to open, obtained from script
        * \return resulting image from opening file
        */
        image* open(std::string filename);
        //! creates a solid color image with both color and dimensions read from script
        void blank();
        //! saves the resulting image from any operations run beforehand
        void save();
        //! applies the corresponding function from the image class
        void to_gray_scale();
        //! applies the corresponding function from the image class
        void invert();
        //! applies the corresponding function from the image class
        void replace();
        //! applies the corresponding function from the image class
        void crop();
        //! applies the corresponding function from the image class
        void rotate_left();
        //! applies the corresponding function from the image class
        void rotate_right();
        //! applies the corresponding function from the image class
        void mix();
        //! applies the corresponding function from the image class
        void add();
    public:
        /*! default constructor
        * \param filename name of script text file
        */
        script(const std::string& filename);
        //! default deconstructor
        ~script();
        //!starts reading script
        void process();
    private:
        //! current image
        image* img;
        //! input stream
        std::ifstream input;
        //! root path
        std::string root_path;
    };
}
#endif


//! @file script.hpp
#ifndef __rgb_script_hpp__
#define __rgb_script_hpp__

#include <fstream>
#include <rgb/image.hpp>

namespace rgb {
    class script {
    private:
        void fill();
        void open();
        image* open(std::string filename);
        void blank();
        void save();
        void to_gray_scale();
        void invert();
        void replace();
        void crop();
        void add();
    public:
        script(const std::string& filename);
        ~script();
        void process();
    private:
        image* img;
        std::ifstream input;
        std::string root_path;
    };
}
#endif

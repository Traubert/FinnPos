%module finnpos
%{
#include "finnpos.h"
%}

%include <std_string.i>

struct Labeler {
    Labeler(void);
    void load_model(std::string filename);
    std::string label(std::string s);
};

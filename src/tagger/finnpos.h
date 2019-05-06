#include <sstream>
#include "Tagger.hh"

struct Labeler
{
    Tagger tagger;
    Labeler(void): tagger(std::cerr) { }
    void load_model(std::string filename);
    std::string label(std::string s);
};

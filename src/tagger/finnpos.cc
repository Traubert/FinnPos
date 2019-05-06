#include <sstream>
#include "Tagger.hh"
#include "finnpos.h"

void Labeler::load_model(std::string filename) {
    std::ifstream model_fstream(filename);
    tagger.load(model_fstream);
}

std::string Labeler::label(std::string s) {
    std::istringstream iss;
    iss.str(s);
    return tagger.label_stream(iss);
}

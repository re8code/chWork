#include "Text.h"
using namespace std;

Text::Text(string _t) : text(_t) {
}

string Text::get() {
    return text;
}

void Text::append(string _extra) {
    text += _extra;
}
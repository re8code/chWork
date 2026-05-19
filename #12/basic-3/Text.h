#include <string>
using namespace std;

class Text {
private:
    string text;
public:
    Text(string _t) : text(_t) {}
    virtual string get() {return text;} /*구현*/
    virtual void append(string _extra) {text += _extra;}
};
#include "Text.h"

class FancyText : public Text {
private:
    string left_brac;
    string right_brac;
    string connector;

public:
    FancyText(string, string, string, string);

    string get() override;
    void append(string) override;
};
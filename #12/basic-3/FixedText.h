#pragma once

#include "Text.h"

class FixedText : public Text {
public:
    FixedText();

    void append(string _extra) override;
};
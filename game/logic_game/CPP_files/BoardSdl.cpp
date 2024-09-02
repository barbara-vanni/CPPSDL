#include <iostream>
#include <string>
#include <SDL.h>


BoardSdl::BoardSdl(int w, int h) : width(w), height(h), title("2048"), closed(false) {}
    if (!init()) {
        closed = true;
    }
}
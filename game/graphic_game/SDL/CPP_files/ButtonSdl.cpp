#include "../HPP_files/ButtonSdl.hpp"
#include <iostream>



/*This class creates Button for the SDL part the front and the logic of if it s clicked or not
 */
ButtonSdl::ButtonSdl()
    : buttonPosX(0), buttonPosY(0), buttonWidth(0), buttonHeight(0), font(nullptr) {
    initFont();
}

ButtonSdl::~ButtonSdl() {
    cleanupFont();
}

void ButtonSdl::initFont() {
    if (TTF_Init() == -1) {
        std::cerr << "Failed to initialize SDL_ttf: " << TTF_GetError() << std::endl;
        return;
    }

    font = TTF_OpenFont("assets/font/minecraft_font.ttf", 24);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }
}

void ButtonSdl::cleanupFont() {
    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }
    TTF_Quit();
}

void ButtonSdl::drawButton(SDL_Renderer* renderer, int x, int y, int w, int h, const std::string& label) {
    buttonPosX = x;
    buttonPosY = y;
    buttonWidth = w;
    buttonHeight = h;

    SDL_SetRenderDrawColor(renderer, 187, 173, 160, 255);
    SDL_Rect buttonRect = {x, y, w, h};
    SDL_RenderFillRect(renderer, &buttonRect);

    if (font && !label.empty()) {
        SDL_Color textColor = {0, 0, 0, 255}; 
        SDL_Surface* textSurface = TTF_RenderText_Blended(font, label.c_str(), textColor);
        if (textSurface) {
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            if (textTexture) {
                int textWidth, textHeight;
                TTF_SizeText(font, label.c_str(), &textWidth, &textHeight);
                SDL_Rect textRect = {x + (w - textWidth) / 2, y + (h - textHeight) / 2, textWidth, textHeight};
                SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                SDL_DestroyTexture(textTexture);
            }
            SDL_FreeSurface(textSurface);
        }
    }
}

bool ButtonSdl::isClicked(const SDL_Event& event, int x, int y, int w, int h) const {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    return (event.type == SDL_MOUSEBUTTONDOWN && mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h);
}
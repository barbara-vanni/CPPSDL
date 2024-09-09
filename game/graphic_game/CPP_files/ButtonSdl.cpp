#include "../HPP_files/ButtonSdl.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

ButtonSdl::ButtonSdl()
    : buttonPosX(0), buttonPosY(0), buttonWidth(0), buttonHeight(0) {}

ButtonSdl::~ButtonSdl() {}

double ButtonSdl::posX()  {
    return buttonPosX;
}

double ButtonSdl::posY()  {
    return buttonPosY;
}

double ButtonSdl::width()  {
    return buttonWidth;
}

double ButtonSdl::height()  {
    return buttonHeight;
}

void ButtonSdl::drawButton(SDL_Renderer* renderer, int x, int y, int w, int h, TTF_Font* font, const std::string& label) {
    // Store the button's position and size
    buttonPosX = x;
    buttonPosY = y;
    buttonWidth = w;
    buttonHeight = h;

    // Set the color for the button background
    SDL_SetRenderDrawColor(renderer, 187, 173, 160, 255);

    // Draw the button rectangle
    SDL_Rect buttonRect = {x, y, w, h};
    SDL_RenderFillRect(renderer, &buttonRect);

    // Render the text label on the button
    if (font && !label.empty()) {
        SDL_Color textColor = {0, 0, 0, 255};  // Black text
        SDL_Surface* textSurface = TTF_RenderText_Blended(font, label.c_str(), textColor);
        
        if (textSurface) {
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            
            if (textTexture) {
                // Get the width and height of the text
                int textWidth, textHeight;
                TTF_SizeText(font, label.c_str(), &textWidth, &textHeight);

                // Center the text inside the button
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

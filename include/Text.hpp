#ifndef TEXT_HPP
#define TEXT_HPP
#define INCLUDE_SDL
#define INCLUDE_SDL_TTF
#include "SDL_include.h"
#include "GameObject.hpp"
#include "Component.hpp"
#include "Resources.hpp"
#include "Camera.hpp"
#include "Timer.hpp"
#include <iostream>
using namespace std;
class Text : public Component{
    public:
        enum TextStyle{SOLID, SHADED, BLENDED};
        Text(GameObject &associated);
        Text(GameObject &associated, string fontFile,int fontSize, TextStyle style, string text, SDL_Color color, float blinkTime);
        ~Text();

        void Update(float dt);
        void Render();
        bool Is(string type);
        void Start();

        void SetText (string text);
        void SetColor (SDL_Color color);
        void SetStyle (TextStyle style);
        void SetFontFile (string fontFile);
        void SetFontSize (int fontSize);
        void RemakeTexture ();
        void NotifyCollision(GameObject& other);
        
    private:
        shared_ptr<TTF_Font> font;
        SDL_Texture* texture;
        string text;
        TextStyle style;
        string fontFile;
        int fontSize;
        float blinkTime;
        Timer *timer;
        SDL_Color color;

};

#endif
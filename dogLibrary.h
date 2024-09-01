#pragma once
#include <raylib.h>

class Dogs
{
private:
    int page;
    Texture textureDog;
private:
    void LoadAndDrawInfor(Font myFont, const char *nameDog, const char* filePath, int posX, int posY);
    void DrawPape1(Font myFont);
    void DrawPape2(Font myFont);
    void DrawPape3(Font myFont);
    void DrawPape4(Font myFont);
   

public:
    Dogs()
    {
        page = 1;
        textureDog = {0};
    }
     ~Dogs()
    {
        if (textureDog.id != 0)
        {
            UnloadTexture(textureDog);
        }
    }
    
    void DrawDogs(Font myFont);
};
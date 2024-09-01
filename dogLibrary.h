#pragma once
#include <raylib.h>

class Dogs
{
private:
    int page;
    Texture textureDog;
private:
    void LoadAndDrawInfor(const char* filePath, int posX, int posY);
    void DrawPape1();
    void DrawPape2();
    void DrawPape3();
    void DrawPape4();
   

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
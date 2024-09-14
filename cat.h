#pragma once
#include <raylib.h>
#include <string>
#include "pet.h"

class Cats : public Pet {
private:
    string specialCharacter;
    string coatColor;
    string hairLossLevel;
    string appearance;
    //----------------------------------------------------------------
    int page;
    Texture textureCat;
private:
    void LoadAndDrawInfor(Font myFont, const char *nameCat, const char* filePath, int posX, int posY);
    void DrawPape1(Font myFont);
    void DrawPape2(Font myFont);
    void DrawPape3(Font myFont);
    void DrawPape4(Font myFont);
   
public:
    Cats()
    {
        page = 1;
        textureCat = {0};
    }
     ~Cats()
    {
        if (textureCat.id != 0)
        {
            UnloadTexture(textureCat);
        }
    }
    
    void DrawCats(Font myFont);
    //----------------------------------------------------------------
    // Cats();
    Cats(string name, string originOfCat, unsigned int averageAge, string furType, unsigned int numberOfCat, unsigned int sellingPrice, unsigned int size, string specialCharacter, string coatColor, string hairLossLevel, string appearance);
    Cats(const Cats& cat);
    // ~Cats();
    void displayInformation();
};
#pragma once
#include <raylib.h>
#include <string>
#include "pet.h"

class Dogs : public Pet {
private:
    string purposeOfRaising;
    string levelOfTraining;
    string needForExercise;
    //----------------------------------------------------------------
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
    //----------------------------------------------------------------
    // Dogs();
    Dogs(string name, string originOfDog, unsigned int averageAge, string furType, unsigned int numberOfDog, unsigned int sellingPrice, unsigned int size, string purposeOfRaising, string levelOfTraining, string needForExercise);
    Dogs(const Dogs& dog);
    // ~Dogs();
    void displayInformation();
};


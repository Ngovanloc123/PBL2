#include <raylib.h>

class Dogs
{
private:
    void LoadAndDrawInfor(const char* filePath, int posX, int posY, int width, int height);
    void DrawDog(const char* imagePath, int gridX, int gridY);
    void DrawAfghanHound();
    void DrawAkita();
    void DrawAlabai();
    void DrawAlaska();
    void DrawAmericanBully();
    void DrawAustralianShepherd();
    void DrawBacHa();
    void DrawBacKinh();
    void DrawBasenji();
    void DrawBassetHound();
    void DrawBeagle();
    void DrawBecgieDuc();
    void DrawBecgieHaLan();
    void DrawBichon();
    void DrawBorderCollie();
    void DrawBostonTerrier();
    void DrawBostonBoxer();
    void DrawBullAnh();
    void DrawBullPhap();
    void DrawBullTerrier();
    void DrawCaucasianShepherd();
    void DrawCavalierKingCharlesSpaniel();
    void DrawChihuahua();
    void DrawChineseCrested();
    void DrawChowChow();
    void DrawCockerSpaniel();
    void DrawDalmatian();
    void DrawDoberman();
    void DrawGermanPinscher();
    void DrawGoldenRetriever();
    void DrawGreatDane();
    void DrawPembrokeWelshCorgi();
public:
    int page;
    Texture textureDog;
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
    void DrawPape1();
    void DrawPape2();
    void DrawPape3();
    void DrawPape4();
};
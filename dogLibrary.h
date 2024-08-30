#include <raylib.h>

class Dogs
{
public:
    int Select;
    Texture textureDog;
    Dogs()
    {
        Select = 0;
        textureDog = {0};
    }
    ~Dogs()
    {
        if (textureDog.id != 0)
        {
            UnloadTexture(textureDog);
        }
    }

    void LoadAndDrawInfor(const char* filePath, int posX, int posY, int width, int height);

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
    void DrawBullAnh();
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
    void DrawHmong();
    void DrawHusky();
    void DrawIcelandicSheepdog();
    void DrawIrishSetter();
};
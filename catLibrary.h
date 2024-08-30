#include <raylib.h>

class Cats
{
public:
    int Select;
    Texture textureMap;
    Cats()
    {
        Select = 0;
        textureMap = {0};
    }
    
    void LoadAndDrawInfor(const char* filePath, int posX, int posY, int width, int height);

    void DrawAbyssiniand();
    void DrawBengal();
    void DrawBirman();

    ~Cats()
    {
        if (textureMap.id != 0)
        {
            UnloadTexture(textureMap);
        }
    }
};
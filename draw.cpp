// // #include "draw.h"
// #include "color.h"
// #include <iostream>
// #include "dog.h"

// using namespace std;

// void Dog::GetImage(const Font &myFont, int gridX, int gridY) {
//     // Nạp và chuyển đổi hình ảnh thành texture
//     Image image = LoadImage(imageAnimal);
//     if (image.width == 0 || image.height == 0)
//     {
//         cout << "Failed to load image!" << endl;
//         return;
//     }
//     texture = LoadTextureFromImage(image);
//     UnloadImage(image);
//     // Vị trí ảnh
//     int posX = gridX * 248 + 8 + 100;
//     int posY = gridY * 270 + 128 + 8;
//     int sizeImage = 240;
//     // Vẽ hình ảnh
//     DrawTexture(texture, posX, posY, WHITE);
    
//     // Tạo khuông chứa hình ảnh
//     Rectangle nameFrame = {(float)posX, (float)(posY + 240), 240, 20};
//     DrawRectangleRounded(nameFrame, 0, 10, WHITE);
//     // Vẽ tên hình ảnh
//     DrawTextEx(myFont, name, (Vector2){nameFrame.x + nameFrame.width / 2 - MeasureTextEx(myFont, name, 30, 2).x / 2, nameFrame.y - 5}, 30, 2, darkGreen);
//     // Vẽ viền khi đưa chuột và không đưa chuột
//     if(!CheckCollisionPointRec(GetMousePosition(), (Rectangle){(float)posX, (float)posY, (float)sizeImage, (float)sizeImage})) {
//         // Viền khi không đưa chuột vào
//         DrawRectangleLines(posX, posY , sizeImage, sizeImage + 20, BLACK);
//     } else {
//         // Viền khi đưa chuột vào
//         DrawRectangleRoundedLines((Rectangle){(float)posX , (float)posY, (float)sizeImage, (float)(sizeImage + 20)}, 0, 10, 5, Cardinal);
//     }
// }

// void Dog::DisplayImage(const Font &myFont)
// {
//     GetImage(myFont, 0, 0); 
// }
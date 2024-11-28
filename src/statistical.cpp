#include "statistical.h"
#include "statistical.h"



// Hàm sắp xếp các thanh theo tháng (tăng dần) bằng Insertion Sort
void Bar::insertionSort(vector<Bar> &bars)
{
    int n = bars.size();
    for (int i = 1; i < n; i++) {
        Bar key = bars[i];
        int j = i - 1;

        // Di chuyển các phần tử của bars[0..i-1], mà lớn hơn key, sang phải
        while (j >= 0 && bars[j].getMonth() > key.getMonth()) {
            bars[j + 1] = bars[j];
            j = j - 1;
        }
        bars[j + 1] = key;
    }
}

Color Bar::GetUniqueColor(int index, int totalParts)
{
    // Sử dụng tỷ lệ để tạo độ Hue (màu sắc) khác biệt
    float hue = (float)index / totalParts;  // Độ Hue từ 0 đến 1
    float saturation = 0.8f;  // Độ bão hòa (Saturation) cao để màu sắc nổi bật
    float value = 0.9f;  // Độ sáng (Value) vừa phải, không quá sáng cũng không quá tối

    // Chuyển từ HSV sang RGB
    float r, g, b;
    float i = floor(hue * 6.0f);
    float f = hue * 6.0f - i;
    float p = value * (1.0f - saturation);
    float q = value * (1.0f - f * saturation);
    float t = value * (1.0f - (1.0f - f) * saturation);

    switch (int(i) % 6) {
        case 0: r = value; g = t; b = p; break;
        case 1: r = q; g = value; b = p; break;
        case 2: r = p; g = value; b = t; break;
        case 3: r = p; g = q; b = value; break;
        case 4: r = t; g = p; b = value; break;
        case 5: r = value; g = p; b = q; break;
    }

    // Chuyển đổi sang kiểu RGB với giá trị [0, 255]
    unsigned char red = (unsigned char)(r * 255);
    unsigned char green = (unsigned char)(g * 255);
    unsigned char blue = (unsigned char)(b * 255);

    return (Color){red, green, blue, 220};  // Trả về màu với alpha 220
}

void Bar::mergeSmallBars(vector<Bar> &bars, float threshold)
{
    int totalQuantity = 0;

    // Tính tổng số lượng
    for (const auto& bar : bars) {
        totalQuantity += bar.getQuantity();
    }

    // Tìm các sản phẩm có tỷ lệ dưới threshold
    vector<Bar> mergedBars;
    int otherQuantity = 0;
    for (const auto& bar : bars) {
        float percentage = (float)bar.getQuantity() / totalQuantity * 100.0f;
        if (percentage < threshold) {
            otherQuantity += bar.getQuantity();
        } else {
            mergedBars.push_back(bar);
        }
    }

    // Thêm phần "Other" nếu cần
    if (otherQuantity > 0) {
        mergedBars.push_back(Bar(0, 0, otherQuantity, "Other"));
    }

    // Cập nhật danh sách bars
    bars = mergedBars;
}

vector<string> Bar::WrapText(const string &text, int maxWidth, int fontSize)
{
    vector<string> lines;
    string currentLine;
    string word;
    
    for (char c : text) {
        if (c == ' ' || c == '\n') {
            if (MeasureText((currentLine + word).c_str(), fontSize) > maxWidth) {
                lines.push_back(currentLine);
                currentLine = word + " ";
            } else {
                currentLine += word + " ";
            }
            word.clear();
            if (c == '\n') {
                lines.push_back(currentLine);
                currentLine.clear();
            }
        } else {
            word += c;
        }
    }

    if (!word.empty()) {
        if (MeasureText((currentLine + word).c_str(), fontSize) > maxWidth) {
            lines.push_back(currentLine);
            currentLine = word;
        } else {
            currentLine += word;
        }
    }

    if (!currentLine.empty()) {
        lines.push_back(currentLine);
    }

    return lines;
}

void Statistical::pieChart()
{
    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 720;
    

    map<int, vector<Bar>> yearlyData;
    ifstream inputFile("DB/sales.txt");
    if (!inputFile) {
        cerr << "Không thể mở tệp dữ liệu!" << endl;
        exit(1);
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string yearStr, monthStr, priceStr, quantityStr, nameStr;
        getline(iss, yearStr, ',');
        getline(iss, monthStr, ',');
        getline(iss, priceStr, ',');
        getline(iss, quantityStr, ',');
        getline(iss, nameStr, ',');

        int year = stoi(yearStr);
        int month = stoi(monthStr);
        int price = stoi(priceStr);
        int quantity = stoi(quantityStr);
        string name = nameStr;

        bool found = false;
        for (auto& bar : yearlyData[year]) {
            if (bar.getName() == name) {
                bar.setQuantity(bar.getQuantity() + quantity);
                found = true;
                break;
            }
        }
        if (!found) {
            Bar newBar(month, price, quantity, name);
            yearlyData[year].push_back(newBar);
        }
    }
    inputFile.close();

    // Hợp nhất các sản phẩm nhỏ thành "Other"
    for (auto& pair : yearlyData) {
        Bar::mergeSmallBars(pair.second, 5.0f);
    }

    int currentYear = 2024;
    string inputYear = to_string(currentYear);
    bool isInputActive = false;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_N)) {
            isInputActive = true;
            inputYear = "";
        }

        if (isInputActive) {
            for (int key = 48; key <= 57; key++) {
                if (IsKeyPressed(key)) {
                    inputYear += (char)key;
                }
            }
            if (IsKeyPressed(KEY_BACKSPACE) && inputYear.size() > 0) {
                inputYear.pop_back();
            }
            if (IsKeyPressed(KEY_ENTER)) {
                if (!inputYear.empty()) {
                    currentYear = stoi(inputYear);
                }
                isInputActive = false;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (yearlyData.count(currentYear) > 0) {
            auto& bars = yearlyData[currentYear];
            int totalQuantity = 0;
            for (const auto& bar : bars) {
                totalQuantity += bar.getQuantity();
            }

            float startAngle = 0.0f;
            for (size_t i = 0; i < bars.size(); i++) {
                float angle = ((float)bars[i].getQuantity() / totalQuantity) * 360.0f;
                Color color = Bar::GetUniqueColor(i, bars.size());
                DrawCircleSector((Vector2){SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2}, 200, startAngle, startAngle + angle, 50, color);
                startAngle += angle;
                vector<string> wrappedText = Bar::WrapText(bars[i].getName(), 80, 15);
                float textAngle = startAngle - (angle / 2);
                Vector2 textPosition = {
                    SCREEN_WIDTH / 2 + 240 * cos(textAngle * DEG2RAD),
                    SCREEN_HEIGHT / 2 + 240 * sin(textAngle * DEG2RAD)
                };
                // Hiển thị từng dòng
                for (size_t line = 0; line < wrappedText.size(); line++) {
                    DrawText(wrappedText[line].c_str(), textPosition.x - 15, textPosition.y - 15 + line * 18, 14, BLACK);
                }
                string percentageText = TextFormat("%.1f%%", ((float)bars[i].getQuantity() / totalQuantity) * 100);
                DrawText(percentageText.c_str(), textPosition.x - 15, textPosition.y + wrappedText.size() * 12, 16, BLUE);
            }

            DrawText(TextFormat("Total Quantity: %d", totalQuantity), 10, 10, 20, DARKGREEN);
        }

        if (isInputActive) {
            DrawText("Enter Year:", 10, 40, 20, BLUE);
            DrawText(inputYear.c_str(), 150, 40, 20, DARKGRAY);
        } else {
            DrawText("Press ENTER to confirm year", 10, 40, 20, GREEN);
        }

        EndDrawing();
    }
}

void Statistical::barChart()
{
    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 720;
    // Dữ liệu doanh thu theo năm sẽ được đọc từ tệp
    map<int, vector<Bar>> yearlyData;
    // Đọc dữ liệu từ tệp
    ifstream inputFile("DB/sales.txt");
    if (!inputFile) {
        cerr << "Không thể mở tệp dữ liệu!" << endl;
        exit(1);  // Thoát nếu không thể mở tệp
    }
    string line;
    while (getline(inputFile, line)){
        istringstream iss(line);
        string yearStr, monthStr, priceStr, quantityStr, nameStr;
        getline(iss, yearStr, ',');
        getline(iss, monthStr, ',');
        getline(iss, priceStr, ',');
        getline(iss, quantityStr, ',');
        getline(iss, nameStr, ',');
        int year = stoi(yearStr);
        int month = stoi(monthStr);
        int price = stoi(priceStr);
        int quantity = stoi(quantityStr);
        string name = nameStr;
        //Kiem tra xem thang da ton tai trong nam chua
        bool found = false;
        for (auto& bar : yearlyData[year]){
            if (bar.getMonth() == month){
                //Neu thang da co trong nam, cong gia tri price vao
                bar.setPrice(bar.getPrice() + price);
                // bar.setQuantity(bar.getQuantity() + quantity);
                found = true;
                break;
            }
        }
        // Neu thang chua co trong nam, them thang moi vao nam
        if (!found){
            yearlyData[year].push_back(Bar(month, price, quantity, name));
        }  
    }
    inputFile.close();
    // In ra dữ liệu để kiểm tra
    for (const auto& pair : yearlyData){
        cout << "Nam: " << pair.first << endl;
        for (const auto& bar : pair.second){
            cout << "  Thang " << bar.getMonth() << ": " << bar.getPrice() << endl;
        }
    }
    int currentYear = 2024;
    string inputYear = to_string(currentYear);
    bool isInputActive = false;

    while (!WindowShouldClose()) {
        // Kích hoạt nhập năm khi nhấn phím "N"
        if (IsKeyPressed(KEY_N)) {
            isInputActive = true;  // Bật chế độ nhập năm
            inputYear = "";  // Xóa giá trị hiện tại của input khi bắt đầu nhập
        }

        // Xử lý nhập năm
        if (isInputActive) {
            // Nhập năm
            for (int key = 48; key <= 57; key++) { // Sử dụng mã ASCII cho các phím số từ 0 đến 9
                if (IsKeyPressed(key)) {
                    inputYear += (char)key;  // Thêm ký tự số vào chuỗi inputYear
                }
            }

            // Xử lý phím BACKSPACE để xóa ký tự cuối
            if (IsKeyPressed(KEY_BACKSPACE) && inputYear.size() > 0) {
                inputYear.pop_back();
            }

            // Xử lý khi nhấn ENTER để xác nhận năm
            if (IsKeyPressed(KEY_ENTER)) {
                if (!inputYear.empty()) {
                    currentYear = stoi(inputYear);  // Cập nhật năm
                }
                isInputActive = false;  // Tắt chế độ nhập
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        // if(yearlyData.count(currentYear) == 0){
        //     DrawText("No data for this year", 10, 10, 20, RED);
        // }
        // Hiển thị biểu đồ doanh thu cho năm hiện tại
        if (yearlyData.count(currentYear) > 0) {
            auto& bars = yearlyData[currentYear];
            long long totalRevenue = 0;
            for (const auto& bar : bars) {
                totalRevenue += bar.getPrice();
            }
            // Sắp xếp các thanh theo tháng (tăng dần) bằng Insertion Sort
            Bar::insertionSort(bars);
            int maxValue = 0;
            for (const auto &bar : bars) {
                if (bar.getPrice() > maxValue) maxValue = bar.getPrice();
            }

            // Tính toán chiều rộng của thanh
            float barWidth = (float)SCREEN_WIDTH / (bars.size() + 2);
            float centerX = SCREEN_WIDTH / 2;

            // Vẽ biểu đồ với số tiền ở đỉnh
            for (size_t i = 0; i < bars.size(); i++) {
                float barHeight = ((float)bars[i].getPrice() / maxValue) * (SCREEN_HEIGHT - 150);
                float xPos = centerX + (i - bars.size() / 2.0f) * barWidth;

                // Vẽ thanh
                DrawRectangle(xPos, SCREEN_HEIGHT - barHeight - 50, barWidth - 20, barHeight, BLUE);
                DrawText(TextFormat("%d", bars[i].getPrice()), xPos + (barWidth - 20) / 2 - MeasureText(TextFormat("%d", bars[i].getPrice()), 10) / 2, SCREEN_HEIGHT - barHeight - 50 - 15, 10, BLACK);

                // Vẽ số tháng dưới thanh
                DrawText(TextFormat("%d", bars[i].getMonth()), xPos + (barWidth - 20) / 2 - MeasureText(TextFormat("%d", bars[i].getMonth()), 10) / 2, SCREEN_HEIGHT - 30, 10, BLACK);
            }
            // Hiển thị tổng doanh thu
            // Tính toán chiều rộng của văn bản
            int textWidth = MeasureText(TextFormat("Total Revenue: $%lld million", totalRevenue), 20);

            // Tính toán vị trí x để căn giữa văn bản
            int posX = (SCREEN_WIDTH - textWidth) / 2;

            // Hiển thị văn bản tại vị trí x vừa tính được và y = 10 (phía trên màn hình)
            DrawText(TextFormat("Total Revenue: %lld million", totalRevenue), posX, 10, 20, RED);
        }

        // Hiển thị năm hiện tại
        DrawText(TextFormat("Year: %d", currentYear), 10, 15, 20, RED);
        // Hiển thị ô nhập liệu cho năm
        if (isInputActive) {
            DrawText("Enter Year:", 10, 40, 20, BLUE);
            DrawText(inputYear.c_str(), 150, 40, 20, DARKGRAY);
        } else {
            DrawText("Press ENTER to confirm year", 10, 40, 20, GREEN);
        }

        EndDrawing();
    }
}

#include <iostream>
#include <vector>

// تابع برای چاپ مقادیر دما
void printTemperatures(const std::vector<double>& temperatures) {
    for (double temp : temperatures) {
        std::cout << temp << " ";
    }
    std::cout << std::endl;
}

int main() {
    // تعداد گره‌ها در شبکه
    const int num_nodes = 10;
    // فاصله زمانی
    const double delta_t = 0.01;
    // فاصله مکانی
    const double delta_x = 0.1;
    // ضریب انتقال حرارت
    const double alpha = 0.01;

    // مقادیر اولیه دما
    std::vector<double> temperatures(num_nodes, 0.0);
    temperatures[0] = 100.0; // دمای اولیه در گره اول

    // حلقه زمان
    for (int time_step = 0; time_step < 100; ++time_step) {
        // محاسبه دما برای گام بعدی
        std::vector<double> new_temperatures(temperatures);
        for (int i = 1; i < num_nodes - 1; ++i) {
            new_temperatures[i] = temperatures[i] + (alpha * delta_t / (delta_x * delta_x)) *
                                  (temperatures[i - 1] - 2 * temperatures[i] + temperatures[i + 1]);
        }
        temperatures = new_temperatures;
        printTemperatures(temperatures);
    }

    return 0;
}

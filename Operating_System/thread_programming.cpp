/* Write a multithreaded program that calculates various statistical values
 * for a list of numbers. This program will be passed a series of numbers
 * on the command line and will then create three separate worker threads.
 * One thread will determine the average of the numbers, the second will determine the maximum value,
 * and the third will determine the minimum value.
 * For example, suppose your program is passed the integers 90 81 78 95 79 72 85.
 * The program will report: The average value is 82. The minimum value is 72.
 * The maximum value is 95. The variables representing the average, minimum, and maximum values
 * will be stored globally.
 * The worker threads will set these values, and the parent thread will
 * output the values once the workers have exited.
 */

#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
using namespace std;

// Global variables to store statistical values
int average_value;
int min_value;
int max_value;


// const：表示這個參數是常量，即在函數內部不會修改它所引用的對象。
//      這是一種保護機制，確保函數不會意外地修改傳遞給它的數據
// &：表示這個參數是一個引用，即它引用了某個向量對象的內容。
//      通過引用，函數可以直接訪問和操作原始對象，而不需要進行複製，從而節省了內存和計算資源
void calculate_average(const std::vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    average_value = sum / int(numbers.size());
}

void calculate_min(const std::vector<int>& numbers) {
    min_value = *min_element(numbers.begin(), numbers.end());
}

void calculate_max(const std::vector<int>& numbers) {
    max_value = *max_element(numbers.begin(), numbers.end());
}

// argc 表示命令行傳遞給程序的參數數量，即參數個數
// argv 是一個字符串陣列（char*），存儲命令行傳遞給程序的參數。
//      argv[0] 是程序本身的名稱，後續元素包含命令行參數。
int main(int argc, char *argv[]) {
    // Parse command line arguments
    // std::vector 是一個序列容器，它封裝了動態數組。
    //      用來存儲和操作對象的集合，類似於數組，但具有動態大小和其他功能
    //      在這個程序中，我們使用 std::vector<int> 來存儲作為命令行參數傳遞的數字列表
    std::vector<int> numbers;
    for (int i = 1; i < argc; ++i) {
        // push_back() 是 std::vector 類的成員函數，用於將新元素添加到向量的末尾
        //      它接受一個參數，將該參數添加到向量的末尾。
        //      在向量尾部添加元素時，向量的大小會自動增加，並且新元素將被放置在最後一個位置
        // std::stoi 是 C++ 標準庫中的函數，用於將字符串轉換為整數
        //      它接受一個字符串作為參數，並返回相應的整數表示。
        //      如果字符串無法解析為有效的整數，則會拋出 std::invalid_argument 或 std::out_of_range 異常。
        numbers.push_back(std::stoi(argv[i]));
    }

    // Create worker threads
    // std::thread 是表示單個執行緒的類
    //      允許我們創建並發執行，通過產生多個可以獨立運行的執行緒來實現並發執行
    // std::ref 是 C++ 標準庫中的函數，用於創建對象的引用包裝器
    //      用於將對象轉換為對象的引用，以便在需要引用的地方使用。
    //      通常與多線程編程一起使用，用於將對象傳遞給線程函數
    std::thread average_thread(calculate_average, std::ref(numbers));
    std::thread min_thread(calculate_min, std::ref(numbers));
    std::thread max_thread(calculate_max, std::ref(numbers));

    // Wait for worker threads to finish
    average_thread.join();
    min_thread.join();
    max_thread.join();

    // Output results
    // std::cout 是 C++ 標準庫中用於輸出的流對象。它表示標準輸出流，通常指向屏幕
    //      可以使用 std::cout 將數據輸出到控制台
    std::cout << "The average value is " << average_value << "." << std::endl;
    std::cout << "The minimum value is " << min_value << "." << std::endl;
    std::cout << "The maximum value is " << max_value << "." << std::endl;

    return 0;
}


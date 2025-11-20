#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> printerQueue;

    // Adding print jobs 
    printerQueue.push("Printer job");
    printerQueue.push("Second Printer job");
    printerQueue.push("Third Printer job");

    std::cout << "Printer queue started...\n";

    // Process the queue
    while (!printerQueue.empty()) {
        std::cout << "Printing: " << printerQueue.front() << std::endl;
        printerQueue.pop();  // Remove the job after printing
    }

    std::cout << "All print jobs done.\n";

    return 0;
}

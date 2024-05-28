/****************************************************************************************
* ALI SAHBAZ
*
*
* Protobuf Template Project
*
* Date          : 28.05.2024
* By            : Ali Sahbaz
* e-mail        : ali_sahbaz@outlook.com
*/
#include <iostream>
#include <fstream>
#include "uart.pb.h" 
  
int main() {
     
    uart_c uart_message;
    uart_message.set_name("TTL");
    uart_message.set_baudrate(115200);
    uart_message.set_max_process_size(1024);


     
    // serialize *********************************************************

    std::ofstream output("uart_message.bin", std::ios::binary);
    if (!uart_message.SerializeToOstream(&output)) {
        std::cerr << "err serialize " << std::endl;
        return -1;
    }

    output.close();




    //  deserialize ******************************************************

    uart_c deserialized_message;
    std::ifstream input("uart_message.bin", std::ios::binary);
    if (!deserialized_message.ParseFromIstream(&input)) {
        std::cerr << "err deserialize " << std::endl;
        return -1;
    }

    input.close();
     




    std::cout << "Name: " << deserialized_message.name() << std::endl;
    std::cout << "Baudrate: " << deserialized_message.baudrate() << std::endl;
    std::cout << "Max Process Size: " << deserialized_message.max_process_size() << std::endl;

    return 0;
}

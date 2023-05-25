#include <memory>
#include "tcpsocket.hpp"
#include "udpsocket.hpp"
#include <fstream>

int main(int argc, char *argv[])
{
    std::unique_ptr<bahiart::NetworkManager::Socket> socket = std::make_unique<bahiart::NetworkManager::TcpSocket>();
    try
    {
        socket->setupAddress(argv[1], argv[2]);
        socket->openConnection();

        std::string spawn("(scene rsg/agent/nao/nao_hetero.rsg 0)(syn)");
        socket->sendMessage(spawn);
      
        std::string init("(init (unum 11)(teamname BahiaRT))(syn)");
        bool isInit = false;

        std::ifstream log;
        //CHANGE TO THE RELATIVE PATH OF THE TXT. FILE, COMPARED TO WHERE THE BINARY IS.
        log.open("/home/anacarol/bahiart2023/tests/networkmodel/testNetworkModelLog.txt");
        std::string message;
        if(!log.is_open() || !log){
            std::cout << "failed to open file" << std::endl;
            exit(0);
        }
        int respCounter = 0;
        while(true) { 
            while (socket->receiveMessage()) {
                
                if(!isInit){
                    socket->sendMessage(init);
                    isInit = true;
                }
                if(!log.eof()){
                    std::cout << "before reading" << std::endl;
                
                    std::getline(log, message);
                    
                    std::cout << "line read -> " << message << std::endl;
                    if(log){
                        socket->sendMessage(message);
                    }
                }
               
                std::cout << "Server response: '" << socket->getMessage() << "'" << std::endl;
                std::cout << "Message Length: " << socket->getMessage().length() << std::endl;
                respCounter++;
            }
        }
        
    }
    catch (const std::exception& exception)
    {
        std::cout << "std::exception - Default exception at main()" << std::endl;
        return 0;
    }
}

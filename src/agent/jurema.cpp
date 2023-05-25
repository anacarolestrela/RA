#include <iostream>
#include "tcpsocket.hpp"

int main(int argc, char **argv){
    bahiart::NetworkManager::TcpSocket socket{};

    socket.setupAddress("localhost","3100");
    socket.openConnection();

    std::string spawn("(scene rsg/agent/nao/nao_hetero.rsg 0)(syn)");
    socket.sendMessage(spawn);

    while(!socket.receiveMessage())
    {
        continue;
    }
    std::cout << socket.getMessage() << std::endl;


    std::string init("(init (unum 11)(teamname BahiaRT))(syn)");
    socket.sendMessage(init);

    while(!socket.receiveMessage())
    {
        continue;
    }
    std::cout << socket.getMessage() << std::endl;

    std::string beampos = "(beam -0.15 -0.06 0)(syn)";
    socket.sendMessage(beampos);

    while(!socket.receiveMessage())
    {
        continue;
    }
    std::cout << socket.getMessage() << std::endl;

    int count = 0;
    while (true)
    {
        std::string joint{};
        std::cout << count << std::endl;

        if(count >= 500 && count <700)
        {
           joint = "(lle3 100)(lle4 -5)(syn)";

        }
        else if(count >= 700 && count <900)
        {
            joint = "(lle3 0)(lle4 0)(lae1 -50)(rae1 -50)(syn)";
        }
        else if(count >= 900 && count <140)
        {
            joint = "(lae1 0)(rae1 0)(lle1 100)(lle2 100(syn)";
        }
        else
        {
            joint = "(lle3 0)(lae1 0)(rae1 0)(syn)";
        }
        count++;
       socket.sendMessage(joint);

       while(!socket.receiveMessage())
       {
        continue;
       }
       std::cout << socket.getMessage() << std::endl;
    }
    

    return 0;
}
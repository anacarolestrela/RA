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

        joint =  "(lle1 0)(rle1 0)(lle3 0)(rle3 0)(lae1 0)(lle4 0)(rle4 0)(rae1 0)(lle2 0)(rae2 0)(lae2 0)(lae3 0)(rae3 0)(lle5 0)(rle5 0)(syn)";

        if(count >= 200 && count <300)
        {
           joint = "(lle3 200)(lle4 -5)(syn)";

        }  else if(count >= 301 && count <330)
        {
            joint = "(lle3 -100)(lle4 5)(syn)";
        
        } 
         else if(count >= 331 && count <350)
        {
            joint = "(lle3 0)(lle4 0)(lae2 100)(rae2 -100)(syn)";
        }
          else if(count >= 351 && count <380)
        {
            joint = "(lae2 0)(rae2 0)(lle4 0)(syn)";
        }
        //levantar austin
          else if(count >= 381 && count <400)
          {
             joint = "(lle3 19)(lle4 -40)(lle5 20)(rle3 19)(rle4 -40)(rle5 20)(lae1 -100)(rae1 -100)(lae3 -100)(rae3 100)(lae4 -10)(rae4 10)(syn)";
          }
            else if(count >= 401 && count <430)
            {
                joint ="(lae2 -100)(rae2 100)(lle3 -100)(rle3 -500)(rle3 -500)(lle5 20)(rle5 20)(lle4 -100)(rle4 -100)(he2 -100)(syn)";
            }
            else if(count >= 431 && count <440)
            {
                joint ="(lle3 -500)(rle3 -500)(lle4 100)(rle4 100)(lle5 -20)(rle5 -20)(lae2 -100)(rae2 100)(syn)";
            } 


          /*
          
         else if(count >= 601 && count <700)
        {
            joint = "(lle3 50)(rle3 50)(rae3 -20)(lae3 20)(syn)";
        }
        else if(count >= 701 && count <800)
        {
            joint = "(rle2 100)(lle2 -100)(syn)";
        }
*/

        //levantar antingo
        /*
        else if(count >= 500 && count <550)
        {
            joint = "(lle3 -100)(rle3 -100)(lae1 -50)(rae1 -50)(syn)";
        }
        else if(count >= 550 && count <600)
        {
            joint = "(lae1 0)(rae1 0)(syn)";
        }

        if(count >= 600 && count <700)
        {
           joint = "(lle3 -100)(lle4 5)(syn)";

        }

        if (count >=700 && count <750)
        {
            joint= "(lle3 100)(rle3 100)(lae1 100)(rae1 100)(syn)";
        }


        if (count >=750 && count <800)
        {
            joint= "(lle3 -100)(rle3 -100)(lle2 -100)(rle2 -100)(syn)";
        }*/

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
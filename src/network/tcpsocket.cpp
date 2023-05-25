#include "tcpsocket.hpp"

bahiart::NetworkManager::TcpSocket::TcpSocket()
{
    this->sockType = SOCK_STREAM;
}

void bahiart::NetworkManager::TcpSocket::openConnection()
{
    try
    {
        if (connect(this->socketFileDescriptor, this->serverInfo->ai_addr, this->serverInfo->ai_addrlen) < 0)
        {
            throw bahiart::NetworkManager::SocketException("Couldn't connect to remote host", errno);
        }
        return;
    }

    catch (bahiart::NetworkManager::SocketException& exception)
    {
        std::cerr << "SocketException - Error during socket connection ---> " << exception.what() << std::endl;
        return;
    }

    catch (std::exception& exception)
    {
        std::cerr << "std::exception - Default exception at openConnection() --->" << exception.what() << std::endl;
        return;
    }

    return;
}

void bahiart::NetworkManager::TcpSocket::sendMessage(std::string& message)
{
    try
    {               
        /* Encodes the length of the message, from a host unsigned int, to a network one. */
        unsigned int encodedMessageInt = htonl(message.size());

        /* Converts the encoded length to (char *) */
        std::string encodedMessageChar((const char*)&encodedMessageInt,sizeof(unsigned int));

        /* Initialize the string that will be sent to server and attribute its value to size of message encoded plus the message */
        std::string str = encodedMessageChar + message;

        std::cout << "bahiart -> sending message -> " << str << std::endl;

        /* Tries to send the message buffer from the just established connection, otherwise, throws an error. */
        if (send(this->socketFileDescriptor, str.data(), str.size(), 0) < 0){
            throw SocketException("Couldn't send the message to the server", errno);
        }
        
    }

    catch (bahiart::NetworkManager::SocketException& exception)
    {
        std::cerr << "SocketException - Error during socket messaging ---> " << exception.what() << std::endl;
        return;
    }

    catch (std::exception& exception)
    {
        std::cerr << "std::exception - Default exception at sendMessage()" << exception.what() << std::endl;
        return;
    }

}

bool bahiart::NetworkManager::TcpSocket::receiveMessage()
{
    if(!checkMessages()){
        return false;
    }

    /*Number of bytes read from the received data.*/
    unsigned int bytesRead{};

    /* Total length of the received data. */
    unsigned int bufferLength{};

    try {
        
        /* Cleaning buffer before using */
        this->buffer.clear();
    
        /* Checking if the data size of received message is equal/greater than 4 bytes */    
        while(bytesRead < sizeof(unsigned int)) {
            bytesRead += recv(this->socketFileDescriptor, this->buffer.data() + bytesRead, sizeof(unsigned int) - bytesRead, 0);
            if (!checkMessages()){
                throw bahiart::NetworkManager::SocketException("Undefined message length.", errno);
            }
        }

        /* Convert received string length from network to host */
        bufferLength = ntohl(*((unsigned int*) this->buffer.data())); 

        /* Resizing buffer to fit the entire data expected to be received */
        this->buffer.resize(bufferLength + 1, 0);
        /* +1 to preserve null terminator. */

        /* Setting bytesRead to 0 so it can be used in next loop */
        bytesRead = 0;

        /* Loop for reading messages until the bytes read be equal to total message length */
        while (bytesRead < bufferLength && checkMessages()) {
            bytesRead += recv(this->socketFileDescriptor, this->buffer.data() + bytesRead, bufferLength - bytesRead, 0);
        }

        return true;
    }
    catch (bahiart::NetworkManager::SocketException& exception)
    {
        std::cout << "SocketException - Error during receiving messages ---> " << exception.what() << std::endl;
        return false;
    }

    catch (std::exception& exception)
    {
        std::cout << "std::exception - Default exception at receiveMessage()" << std::endl;
        return false;
    }
    
}

bahiart::NetworkManager::TcpSocket::~TcpSocket()
{
    close(this->socketFileDescriptor); // closes connection to the server
    freeaddrinfo(this->serverInfo);    // getaddrinfo()'s linked tree, used in struct addrinfo *serverInfo, is freed;
}

#include "udpsocket.hpp"

bahiart::NetworkManager::UdpSocket::UdpSocket()
{
    this->sockType = SOCK_DGRAM;
}

void bahiart::NetworkManager::UdpSocket::sendMessage(std::string &message)
{
    try
    {
        /* Defines the size of the message buffer as the length of the message per se,
        plus 4 bytes for the initial unsigned int representing message length. */
        unsigned int bufferLength = message.length() + 4;

        /* Encodes the length of the message, from a host unsigned int, to a network one. */
        unsigned int encodedMessageInt = htonl(message.size());

        /* Converts the encoded length to (char *) */
        std::string encodedMessageChar((const char *)&encodedMessageInt, sizeof(unsigned int));

        /* Initialize the string that will be sent to server and attribute its value to size of message encoded plus the message */
        std::string str = encodedMessageChar + message;

        /* Tries to send the message buffer from the just established connection, otherwise, throws an error */
        if (sendto(socketFileDescriptor, this->buffer.data(), bufferLength, 0, this->serverInfo->ai_addr, this->serverInfo->ai_addrlen) < 0)
        {
            throw SocketException("Couldn't send the message to the server", errno);
        }

        this->buffer.clear();
    }

    catch (const bahiart::NetworkManager::SocketException &exception)
    {
        std::cerr << "SocketException - Error during socket messaging ---> " << exception.what() << std::endl;
        return;
    }

    catch (const std::exception &exception)
    {
        std::cerr << "std::exception - Default exception at sendMessage() ---> " << exception.what() << std::endl;
        return;
    }
}

bool bahiart::NetworkManager::UdpSocket::receiveMessage()
{
    if (!checkMessages())
    {
        return false;
    }

    /* Struct designed to be large enough to fit both ipv4 and ipv6 structures */
    struct sockaddr_storage fromaAddr
    {
    };

    /* Type designed to hold length of socket structures. */
    socklen_t fromLen = sizeof fromaAddr;

    /* Total length of the received data. */
    unsigned int bufferLength{};

    try
    {

        /* Cleaning buffer before using */
        this->buffer.clear();

        /* Checking if the data size of received message is equal/greater than 4 bytes */
        if (recvfrom(this->socketFileDescriptor, this->buffer.data(), this->buffer.capacity(), MSG_PEEK, (struct sockaddr *)&fromaAddr, &fromLen) < 4)
        {
            throw bahiart::NetworkManager::SocketException("Length of message is less than 4 bytes.");
        }

        /*
        Clarifying, in the condition above the parameter MSG_PEEK was used
        because UDP doesn't have support to lost packets, so it only sends
        the data one time. MSG_PEEK condition tells the server we are only
        taking a peek inside the data, and we will actually read it later.
        */

        /* Convert received string length from network to host */
        bufferLength = ntohl(*((unsigned int *)this->buffer.data()));

        /* Resizing buffer to fit the entire message */
        this->buffer.resize(bufferLength + 4 + 1, 0);
        /* +1 to preserve null terminator. */

        /* Writing the message in buffer vector */
        if (recvfrom(this->socketFileDescriptor, this->buffer.data(), this->buffer.capacity(), 0, (struct sockaddr *)&fromaAddr, &fromLen) < 0)
        {
            throw bahiart::NetworkManager::SocketException("recvfrom()");
        }

        /* Erasing first 4 elements from buffer where length of message is */
        this->buffer.erase(this->buffer.begin(), this->buffer.begin() + 4);

        return true;
    }
    catch (bahiart::NetworkManager::SocketException &exception)
    {
        std::cout << "SocketException - Error during receiving messages ---> " << exception.what() << std::endl;
        return false;
    }

    catch (std::exception &exception)
    {
        std::cout << "std::exception - Default exception at receiveMessage()" << std::endl;
        return false;
    }
}

bahiart::NetworkManager::UdpSocket::~UdpSocket()
{
    freeaddrinfo(this->serverInfo); // getaddrinfo()'s linked tree, used in struct addrinfo *serverInfo, is freed;
}

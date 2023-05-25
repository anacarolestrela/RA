/** @file tcpsocket.hpp
 *  @brief Network Manager class inherited from Socket to connect through TCP protocol.
 *
 *  Contains functions to establish connection from the agents to the server and manage message exchanges.
 *
 *  @author Glenda Santana (bahiart)
 *  @author Alan Nascimento (bahiart)
 *  @author Kalvin Albuquerque (bahiart)
 *
 */

#ifndef TCP_SOCKET_HPP
#define TCP_SOCKET_HPP

#include "socket.hpp"

namespace bahiart::NetworkManager
{
    /**
     * \brief Network Manager class inherited from Socket to connect through TCP protocol.
     *
     * The TcpSocket class provides functions to establishes connection through agents and server and manage message exchanges.
     */
    class TcpSocket : public bahiart::NetworkManager::Socket
    {
    public:
        /**
         * \brief Sets superclass' socket type used in address setup
         */
        TcpSocket();

        /**
         * \brief Establishes TCP connection to the server.
         *
         * \throw Exception: Couldn't connect to remote host.
         */
        void openConnection() override;

        /**
         * \brief Sends message to the stored socket descriptor.
         *
         * The message length will be calculated and stored in a unsigned int variable and converted from host to network long (htonl), after
         * that, this variable will be converted to char * and concatenated with the actual message and stored in a new string variable - the one that
         * will be sent to server.
         *
         * \param message String message that will be sent to server.
         *
         * \throw Exception: Couldn't send the message to the server.
         */
        void sendMessage(std::string &message) override;

        /**
         * \brief Reads messages from the server.
         *
         * Checks if there is available data ready to be read, if true, read the first 4 bytes from message received (the total size of message)
         * and converts it from char to encoded (htonl) unsigned int, and from encoded unsigned int to decoded unsigned int (ntohl), this way,
         * the size of the message is a valid number. Right away, a loop is started to receive the entire message, checking, by comparing the number of
         * bytes read with the total message length, if the message was totally received. The message will be accessible by calling the getMessage() function
         *
         * \return True if there is message ready to be read, false if there isn't or an error occurred.
         *
         * \throw Exception: Undefined message length.
         *
         * \sa getMessage()
         */
        bool receiveMessage() override;

        /**
         * \brief Closes connection to remote host (socket descriptor)
         */
        ~TcpSocket();
    };
}
#endif
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class Program
{
    static void Main()
    {
        // starts Winsock DLLs
        if (WSAStartup(MAKEWORD(2, 2), out var wsaData) != 0)
            return;

        // create server socket
        Socket serverSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        if (serverSocket == null)
        {
            WSACleanup();
            return;
        }

        // binds socket to address
        IPEndPoint serverEndPoint = new IPEndPoint(IPAddress.Any, 27000);
        serverSocket.Bind(serverEndPoint);

        // listen on a socket
        serverSocket.Listen(1);

        Console.WriteLine("Waiting for client connection\n");

        // accepts a connection from a client
        Socket connectionSocket = null;
        bool connection = true;

        // receives RxBuffer
        byte[] rxBuffer = new byte[128];

        // sends SentMssg
        byte[] sentMssg = Encoding.ASCII.GetBytes("Received Message");
        byte[] terminateServer = Encoding.ASCII.GetBytes("quit");
        byte[] terminateConnection = Encoding.ASCII.GetBytes("bye");

        bool newConnection = false;  // For new connections only. Applicable when a client disconnects from the server.

        try
        {
            connectionSocket = serverSocket.Accept();
            Console.WriteLine("Connection Established\n");

            while (connection)
            {
                if (newConnection)
                {
                    Console.WriteLine("Waiting for a new client connection\n");

                    connectionSocket = serverSocket.Accept();
                    Console.WriteLine("Connection with New client Established\n");

                    // changes when a connection has been established to avoid an infinite cycle.
                    newConnection = false;
                }

                connectionSocket.Receive(rxBuffer);
                Console.WriteLine("Msg Rx: " + Encoding.ASCII.GetString(rxBuffer).TrimEnd('\0'));

                if (Encoding.ASCII.GetString(rxBuffer).TrimEnd('\0') == Encoding.ASCII.GetString(terminateServer))
                {
                    connection = false;
                    connectionSocket.Close();    // closes incoming socket
                    serverSocket.Close();        // closes server socket
                    WSACleanup();                // frees Winsock resources
                }

                if (Encoding.ASCII.GetString(rxBuffer).TrimEnd('\0') == Encoding.ASCII.GetString(terminateConnection))
                {
                    connectionSocket.Close();    // closes incoming socket
                    newConnection = true;
                }

                connectionSocket.Send(sentMssg);
            }
        }
        finally
        {
            connectionSocket?.Close();
        }
    }

    const int AF_INET = 2;
    const int SOCK_STREAM = 1;
    const int IPPROTO_TCP = 6;

    [System.Runtime.InteropServices.DllImport("ws2_32.dll", SetLastError = true)]
    static extern int WSAStartup(ushort wVersionRequested, out WSAData lpWSAData);

    [System.Runtime.InteropServices.DllImport("ws2_32.dll", SetLastError = true)]
    static extern int WSACleanup();

    [System.Runtime.InteropServices.DllImport("ws2_32.dll", SetLastError = true)]
    static extern SocketError WSAGetLastError();

    [System.Runtime.InteropServices.DllImport("ws2_32.dll", SetLastError = true)]
    static extern Socket socket(int af, int socketType, int protocol);

    [System.Runtime.InteropServices.DllImport("ws2_32.dll", SetLastError = true)]
    static extern int bind(IntPtr s, ref sockaddr name, int namelen);

    [System.Runtime.InteropServices.DllImport("ws2_32.dll", SetLastError = true)]
    static extern int listen(IntPtr s, int backlog);

    [System.Runtime.InteropServices.DllImport("ws2_32.dll", SetLastError = true)]
    static extern IntPtr accept(IntPtr s, IntPtr addr, IntPtr addrlen);

    [System.Runtime.InteropServices.DllImport("ws2_32.dll", SetLastError = true)]
    static extern int closesocket(IntPtr s);

    [System.Runtime.InteropServices.DllImport("ws2_32.dll", SetLastError = true)]
    static extern int recv(IntPtr s, byte[] buf, int len, SocketFlags flags);

    [System.Runtime.InteropServices.DllImport("ws2_32.dll", SetLastError = true)]
    static extern int send(IntPtr s, byte[] buf, int len, SocketFlags flags);

    [System.Runtime.InteropServices.StructLayout(System.Runtime.InteropServices.LayoutKind.Sequential)]
    struct WSAData
    {
        public ushort wVersion;
        public ushort wHighVersion;
        [System.Runtime.InteropServices.MarshalAs(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 257)]
        public string szDescription;
        [System.Runtime.InteropServices.MarshalAs(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 129)]
        public string szSystemStatus;
        public ushort iMaxSockets;
        public ushort iMaxUdpDg;
        public IntPtr lpVendorInfo;
    }

    [System.Runtime.InteropServices.StructLayout(System.Runtime.InteropServices.LayoutKind.Sequential)]
    struct sockaddr
    {
        public ushort sa_family;
        [System.Runtime.InteropServices.MarshalAs(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 14)]
        public string sa_data;
    }

    const int MAKEWORD(int low, int high) => (ushort) ((high << 8) | low);
}

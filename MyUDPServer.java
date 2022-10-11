import java.net.*;
class MyUDPServer
{
    public static int serverPort = 998;
    public static int clientPort = 999;
    public static int buffer_size = 1024;
    public static DatagramSocket ds; 
    public static byte buffer[] = new byte[buffer_size];

    public static void TheServer() throws Exception
    {
        int pos = 0;
        System.out.println("\n Enter text(q to exit)... \n");
        while (true) {
            int c = System.in.read();
            switch (c) {
                case 'q':
                    System.out.println("Server Quits.");
                    return ;

                case '\r':
                    break;

                case '\n':
                    // for localhost target -----
                    ds.send(new DatagramPacket(buffer, pos, InetAddress.getLocalHost(), clientPort));
                    pos = 0;
                    break;

                default:
                buffer[pos++] = (byte) c;
                    break;
            }
        }
    }

    public static void main(String[] args) throws Exception
    {
        ds = new DatagramSocket(serverPort);
        TheServer();
        ds.close();
    }
}

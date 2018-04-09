/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package serverappsocket;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Inet4Address;
import java.net.Inet6Address;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.logging.Level;
import java.util.logging.Logger;
import messageProtocol.*;

/**
 *
 * @author matheus
 */
public class Server extends ServerSocket {

    private ArrayList<ClientConnection> connections = new ArrayList<>();
    private String enderecoIP;

   // ArrayList<Groups> grupos = new ArrayList<>();
    private final int port;

    public Server(int port) throws IOException {
        super(port);
        this.port = port;
        this.enderecoIP = getFirstNonLoopbackAddress(true, false).toString();
        System.out.println("IP: " + this.enderecoIP + "\nPorta: " + this.port);

    }

    public void startServer() {
        System.out.println("Accepting new connections...");
        Message msg;
        while (true) {
            try {

                ClientConnection cc;

                Socket client = this.accept();

                cc = new ClientConnection(this, client);
                System.out.println(client.getInetAddress().getHostAddress() + " is now online.");

                msg = ((HandShake) cc.getIn().readObject());
                cc.control((HandShake) msg);

                System.out.println(cc.getNickname() + " is now online.");
                this.connections.add(cc);

                //msg = new Message("olá, vocÊ está conectado",cc.getNickname(),enderecoIP);
                //cc.getOut().writeObject(msg);
                Thread t = new Thread(cc);
                t.start();

            } catch (Exception e) {
                System.out.println("" + e);
            }
        }

    }

    public void foward(Audio ad) {
        ObjectOutputStream out;
        try {
            for (int i = 0; i < connections.size(); i++) {
                out = connections.get(i).getOut();
                out.writeUnshared(ad);
                out.reset();
            }
        } catch (IOException ex) {
            Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public void foward(Message message) {
        ObjectOutputStream out;
        try {
            if (message.getTo().equals(enderecoIP)) {
                for (int i = 0; i < connections.size(); i++) {

                    out = connections.get(i).getOut();

                    out.writeUnshared(message);
                    out.reset();
                }
            } else {
                for (int i = 0; i < connections.size(); i++) {
                    if (message.getTo().equals(connections.get(i).getNickname())) {

                        out = connections.get(i).getOut();

                        out.writeObject(message);
                        out.reset();
                    }
                }
            }
        } catch (IOException ex) {
            Logger.getLogger(ClientConnection.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public ArrayList<ClientConnection> getConnections() {
        return connections;
    }

    private static InetAddress getFirstNonLoopbackAddress(boolean preferIpv4, boolean preferIPv6) throws SocketException {
        Enumeration en = NetworkInterface.getNetworkInterfaces();
        while (en.hasMoreElements()) {
            NetworkInterface i = (NetworkInterface) en.nextElement();
            for (Enumeration en2 = i.getInetAddresses(); en2.hasMoreElements();) {
                InetAddress addr = (InetAddress) en2.nextElement();
                if (!addr.isLoopbackAddress()) {
                    if (addr instanceof Inet4Address) {
                        if (preferIPv6) {
                            continue;
                        }
                        return addr;
                    }
                    if (addr instanceof Inet6Address) {
                        if (preferIpv4) {
                            continue;
                        }
                        return addr;
                    }
                }
            }
        }
        return null;
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package serverappsocket;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author matheus
 */
public class ServerAppSocket {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            // TODO code application logic here
            
            
            Server server = new Server(8080);
            server.startServer();
        } catch (IOException ex) {
            Logger.getLogger(ServerAppSocket.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
    }
    
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package serverappsocket;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import messageProtocol.*;

/**
 *
 * @author matheus
 */
public class ClientConnection implements Runnable {

    private String nickname;
    private Server sv;
    private Socket client;

    private ObjectOutputStream out;
    private ObjectInputStream in;

    public ClientConnection(Server server, Socket client) throws IOException {
        this.sv = server;
        this.client = client;
        in = new ObjectInputStream(client.getInputStream());
        out = new ObjectOutputStream(client.getOutputStream());

    }

    public Socket getSocket() {
        return this.client;
    }

    @Override
    public void run() {
        Audio ad = null;
        byte [] data;
        
        try {

            while (true) {
                //in.reset();
                //System.out.println(nickname + " Passei aqui 1");
                Object message =  in.readObject();
                //System.out.println(message.toString());
                //System.out.println(nickname + " Passei aqui 2 - " + message.getContent());
                //message = (Message)message;

                if (message instanceof ControlClass) {

                    //System.out.println("teste");
                }else if(message instanceof Audio){
                    System.out.println("Arquivo de áudio recebido");
                    ad = ((Audio)message);
                    data = ad.getStreamData();
                    if(data != null ){
                        System.out.println("arquivo não nulo");
                    }
                    if(data.length != 0){
                        System.out.println("Arquivo com dados");
                    }
                    
                    for(int i=0; i<data.length;i++){
                        System.out.println(data[i]);
                    }   
                        
                    sv.foward(ad);
                    
                } 
                
                else {

                    System.out.println(((Message)message).getContent().toString());
                    
                    sv.foward((Message) message);
                }
                //in.close();
            }
        } catch (Exception e) {
            System.out.println(nickname + " - A excecao no servidor eh ");
            e.printStackTrace();
        }

    }

    public void control(HandShake hd) {
        this.nickname = hd.getFrom();
    }

    /*  
     public void control(Group g){
     Groups gp = new Groups(g.getContent().toString());
     gp.add(this);   
     }
     */
    public String getNickname() {
        return nickname;
    }

    public ObjectOutputStream getOut() {
        return out;
    }

    public ObjectInputStream getIn() {
        return in;
    }
}

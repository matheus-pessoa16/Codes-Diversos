/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package messageProtocol;

/**
 *
 * @author matheus
 */
public class Text extends Message{

    
   
    
    public Text(Object content, String to, String from) {
        super(content, to, from);
    }
    
   
    public String play() {
        return this.getContent().toString();
    }
    
    
    
    
}

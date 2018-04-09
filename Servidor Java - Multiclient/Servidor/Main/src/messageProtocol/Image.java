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
public class Image extends Message{

    public Image(Byte []content, String to, String from) {
        super(content, to, from);
    }
    
}

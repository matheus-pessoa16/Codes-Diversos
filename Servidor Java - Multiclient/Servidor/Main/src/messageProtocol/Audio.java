/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package messageProtocol;

import java.io.Serializable;

/**
 *
 * @author matheus
 */
public class Audio implements Serializable{
    
    private byte [] streamData;
    private int sizeBuffer, offset;
    private String to, from;

    public Audio(byte[] streamData, int sizeBuffer, int offset, String to, String from) {
        this.streamData = streamData;
        this.sizeBuffer = sizeBuffer;
        this.offset = offset;
        this.to = to;
        this.from = from;
    }

    public byte[] getStreamData() {
        return streamData;
    }

    public int getSizeBuffer() {
        return sizeBuffer;
    }

    public int getOffset() {
        return offset;
    }

    public String getTo() {
        return to;
    }

    public String getFrom() {
        return from;
    }
    
    
   
    
    
}

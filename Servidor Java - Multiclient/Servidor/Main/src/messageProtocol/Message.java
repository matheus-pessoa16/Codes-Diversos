package messageProtocol;

import java.io.Serializable;


public class Message implements Serializable{
    
    
    private String from, to;
    Object content;

    public Message(Object content, String to, String from) {
        setContent(content);
        setFrom(from);
        setTo(to);
    }

    protected void setFrom(String from) {
        this.from = from;
    }

    protected void setTo(String to) {
        this.to = to;
    }

    protected void setContent(Object content) {
        this.content = content;
    }
    
    
    public String getFrom() {
        return from;
    }

    public String getTo() {
        return to;
    }

    public Object getContent() {
        return content;
    }
        
    @Override
    public String toString(){
        return content.toString();
    }
    
    
}

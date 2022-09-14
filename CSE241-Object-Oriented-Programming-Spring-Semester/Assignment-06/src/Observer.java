import java.util.ArrayList;
import java.util.List;

public abstract class Observer { // observer class

    protected ArrayList<Entry> listOfViewer = new ArrayList<Entry>();  /* arraylist for the viewers */
    protected ArrayList<Entry> listOfPlayer = new ArrayList<Entry>();  /* arraylist for the players */
    public abstract void addMessage(ArrayList<Entry> originalEntries);  /* if new entry added this fuction calls */
    public abstract void removeMessage(ArrayList<Entry> originalEntries);  /* if entry is removed this function calls */
    public abstract void show_list();  /* shows the list */
    public abstract void next(String type);  /* jump the next type of the object */
    public abstract void previous(String type);  /* jump the previous type of the object */
}

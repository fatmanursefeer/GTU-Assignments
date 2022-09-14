import java.util.ArrayList;
import java.util.List;

public class Dataset {
    
    public ArrayList<Observer> observers = new ArrayList<Observer>();  /* this arraylist holds the observers */
    public ArrayList<Entry> entries = new ArrayList<Entry>();  /* this arraylist holds the entries */

    public void register(Observer newObserver)
    {
        observers.add(newObserver);  /* adding the observer in the arraylist */
    }

    public void remove_observer(Observer rmvObserver)
    {
        observers.remove(rmvObserver);  /* removing  the observer in the arraylist */
    }

    public void notifyPlayerObserversForAdd()
    {
        for(Observer obs : observers)
        {
            if(obs instanceof Player)
            {
                obs.addMessage(entries);  /* if the new player type entry is added all of the player observers nodify */
            }
        }
    }

    public void notifyViewerObserversForAdd()
    {
        for(Observer obs : observers)
        {
            if(obs instanceof Viewer)
            {
                obs.addMessage(entries);  /* if the new viewer type entry is added all of the viewer observers nodify */
            }
        }
    }

    public void add(Entry newEntry)
    {
        entries.add(newEntry);  /* new entry is adding */
        if(newEntry instanceof Playable)
        {
            notifyPlayerObserversForAdd();  /* if entry is playable tis functions calls */
        }
        else if(newEntry instanceof Non_playable)
        {
            notifyViewerObserversForAdd();  /* if entry is non_playable tis functions calls */
        }
    }

    public void notifyPlayerObserversForDelete()
    {
        for(Observer obs : observers)
        {
            if(obs instanceof Player)
            {
                obs.removeMessage(entries);  /* if the player type entry is removed all of the player observers nodify */
            }
        }
    }

    public void notifyViewerObserversForDelete()
    {
        for(Observer obs : observers)
        {
            if(obs instanceof Viewer)
            {
                obs.removeMessage(entries);  /* if the viewer type entry is removed all of the viewer observers nodify */
            }
        }
    }

    public void remove(Playable deletedEntry)
    {
        entries.remove((Entry) deletedEntry);  /* entry is removing of the arraylist */
        notifyPlayerObserversForDelete();  /* if entry is playable tis functions calls */
    }

    public void remove(Non_playable deletedEntry)
    {
        entries.remove((Entry) deletedEntry);  /* entry is removing of the arraylist */
        notifyViewerObserversForDelete();  /* if entry is non_playable tis functions calls */
    }

}

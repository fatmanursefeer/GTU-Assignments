import java.util.ArrayList;
import java.util.List;

public class Player extends Observer {

    private int currentIndex = 0;

    public Player()
    {
        /* empty */
    }

    @Override
    public void addMessage(ArrayList<Entry> originalEntries)
    {
        listOfPlayer.clear();  /* clears the arraylist */
        for(Entry ent : originalEntries)
        {
            if(ent instanceof Playable)
            {
                listOfPlayer.add(ent);  /* fills the arraylist after adding new object */
            }
        }
    }

    @Override
    public void removeMessage(ArrayList<Entry> originalEntries)
    {
        listOfPlayer.clear();  /* clear the arraylist */
        for(Entry ent : originalEntries)
        {
            if(ent instanceof Playable)
            {
                listOfPlayer.add(ent);  /* fills the arraylist after the removing object */
            }
        }
    }

    @Override
    public void show_list()
    {
        for(Entry ent : listOfPlayer)
        {
            System.out.println(ent.getName());  /* prints all the object */
        }
    }

    public Playable currently_playing()
    {
        int i = 0;
        for(Entry ent : listOfPlayer)
        {
            if(i == currentIndex)
            {
                return ((Playable) ent);   /* returns the current object */
            }
            i++;
        }
        return null;   
    }

    @Override
    public void next(String type)
    {
        int i = 0, flag = 0, flag2 = 0;
        if(listOfPlayer.size() == 0)
        {
            System.out.println("This list is empty!!!");  /* if the arraylist is empty this message is writing */
            flag = 1;
        }
        if(((currentIndex + 1) == listOfPlayer.size()) && (flag == 0))  /* if the end of the arraylist go to begin of the arraylist */
        {
            currentIndex = -1;
        }
        if((type == "audio") && (flag == 0))  /* if the audio is text */
        {
            for(i = currentIndex + 1; i < listOfPlayer.size(); i++)
            {
                if((listOfPlayer.get(i) instanceof Playable) && (listOfPlayer.get(i) instanceof Non_visual))  /* if type == audio */
                {
                    currentIndex = i;  /* equalization of the current index */
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0)  /* if there is no audio object until end of the list then go to begin of the array and search again */
            {
                for(i = 0; i < listOfPlayer.size(); i++)
                {
                    if((listOfPlayer.get(i) instanceof Playable) && (listOfPlayer.get(i) instanceof Non_visual))  /* if type == audio */
                    {
                        currentIndex = i;
                        break;
                    }
                }
            }
        }
        if((type == "video") && (flag == 0))  /* if the type is video */
        {
            for(i = currentIndex + 1; i < listOfPlayer.size(); i++)
            {
                if((listOfPlayer.get(i) instanceof Playable) && (listOfPlayer.get(i) instanceof Visual))  /* if type == video */
                {
                    currentIndex = i;  /* equalization of the current index */
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0)  /* if there is no video object until end of the list then go to begin of the array and search again */
            {
                for(i = 0; i < listOfPlayer.size(); i++)
                {
                    if((listOfPlayer.get(i) instanceof Playable) && (listOfPlayer.get(i) instanceof Visual))  /* if type == video */
                    {
                        currentIndex = i;
                        break;
                    }
                }
            }
        }
    }

    @Override
    public void previous(String type)
    {
        int i = 0, flag = 0, flag2 = 0;
        if(listOfPlayer.size() == 0)
        {
            System.out.println("This list is empty!!!");  /* if the arraylist is empty this message is writing */
            flag = 1;
        }
        if((currentIndex == 0) && (flag == 0))
        {
            currentIndex = listOfPlayer.size();  /* if current object is begin of the array go to end of the array */
        }
        if((type == "audio") && (flag == 0))  /* if the type is audio */
        {
            for(i = currentIndex - 1; i >= 0; i--)
            {
                if((listOfPlayer.get(i) instanceof Playable) && (listOfPlayer.get(i) instanceof Non_visual))  /* if type == audio */
                {
                    currentIndex = i;  /* equalization of the current index */
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0)  /* if there is no audio object until begin of the list then go to end of the array and search again */
            {
                for(i = listOfPlayer.size() - 1; i >= 0; i--)
                {
                    if((listOfPlayer.get(i) instanceof Playable) && (listOfPlayer.get(i) instanceof Non_visual))  /* if type == audio */
                    {
                        currentIndex = i;
                        break;
                    }
                }
            }
        }
        if((type == "video") && (flag == 0))  /* if the type is video */
        {
            for(i = currentIndex - 1; i >= 0; i--)
            {
                if((listOfPlayer.get(i) instanceof Playable) && (listOfPlayer.get(i) instanceof Visual))  /* if type == video */
                {
                    currentIndex = i;  /* equalization of the current index */
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0)  /* if there is no video object until begin of the list then go to end of the array and search again */
            {
                for(i = listOfPlayer.size() - 1; i >= 0; i--)
                {
                    if((listOfPlayer.get(i) instanceof Playable) && (listOfPlayer.get(i) instanceof Visual))  /* if type == video */
                    {
                        currentIndex = i;
                        break;
                    }
                }
            }
        }
    }
}

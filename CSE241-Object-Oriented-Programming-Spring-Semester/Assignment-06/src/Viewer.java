import java.util.ArrayList;
import java.util.List;

public class Viewer extends Observer {

    private int currentIndex = 0;

    public Viewer()
    {
        /* empty */
    }

    @Override
    public void addMessage(ArrayList<Entry> originalEntries)
    {
        listOfViewer.clear();  /* clears the arraylist */
        for(Entry ent : originalEntries)
        {
            if(ent instanceof Non_playable)
            {
                listOfViewer.add(ent);  /* fills the arraylist after adding new object */
            }
        }
    }
 
    @Override
    public void removeMessage(ArrayList<Entry> originalEntries)
    {
        listOfViewer.clear();  /* clear the arraylist */
        for(Entry ent : originalEntries)
        {
            if(ent instanceof Non_playable)
            {
                listOfViewer.add(ent);  /* fills the arraylist after the removing object */
            }
        }
    }

    @Override
    public void show_list()
    {
        for(Entry ent : listOfViewer)
        {
            System.out.println(ent.getName());  /* prints all the object */
        }
    }

    public Non_playable currently_viewing()
    {
        int i = 0;
        for(Entry ent : listOfViewer)
        {
            if(i == currentIndex)
            {
                return ((Non_playable) ent);   /* returns the current object */
            }
            i++;
        }
        return null;
    }

    @Override
    public void next(String type)
    {
        int i = 0, flag = 0, flag2 = 0;
        if(listOfViewer.size() == 0)
        {
            System.out.println("This list is empty!!!");  /* if the arraylist is empty this message is writing */
            flag = 1;
        }
        if(((currentIndex + 1) == listOfViewer.size()) && (flag == 0))  /* if the end of the arraylist go to begin of the arraylist */
        {
            currentIndex = -1;
        }
        if((type == "text") && (flag == 0))  /* if the type is text */
        {
            for(i = currentIndex + 1; i < listOfViewer.size(); i++)
            {
                if((listOfViewer.get(i) instanceof Non_playable) && (listOfViewer.get(i) instanceof Non_visual))  /* if type == text */
                {
                    currentIndex = i;  /* equalization of the current index */
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0)  /* if there is no text object until end of the list then go to begin of the array and search again */
            {
                for(i = 0; i < listOfViewer.size(); i++)
                {
                    if((listOfViewer.get(i) instanceof Non_playable) && (listOfViewer.get(i) instanceof Non_visual))  /* if type == text */
                    {
                        currentIndex = i;
                        break;
                    }
                }
            }
        }
        if((type == "image") && (flag == 0))  /* if the type is image */
        {
            for(i = currentIndex + 1; i < listOfViewer.size(); i++)
            {
                if((listOfViewer.get(i) instanceof Non_playable) && (listOfViewer.get(i) instanceof Visual))  /* if type == image */
                {
                    currentIndex = i;  /* equalization of the current index */
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0)  /* if there is no image object until end of the list then go to begin of the array and search again */
            {
                for(i = 0; i < listOfViewer.size(); i++)
                {
                    if((listOfViewer.get(i) instanceof Non_playable) && (listOfViewer.get(i) instanceof Visual))  /* if type == image */
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
        if(listOfViewer.size() == 0)
        {
            System.out.println("This list is empty!!!");  /* if the arraylist is empty this message is writing */
            flag = 1;
        }
        if((currentIndex == 0) && (flag == 0))
        {
            currentIndex = listOfViewer.size();  /* if current object is begin of the array go to end of the array */
        }
        if((type == "text") && (flag == 0))  /* if the type is text */
        {
            for(i = currentIndex - 1; i >= 0; i--)
            {
                if((listOfViewer.get(i) instanceof Non_playable) && (listOfViewer.get(i) instanceof Non_visual))  /* if type == text */
                {
                    currentIndex = i;  /* equalization of the current index */
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0)  /* if there is no text object until begin of the list then go to end of the array and search again */
            {
                for(i = listOfViewer.size() - 1; i >= 0; i--)
                {
                    if((listOfViewer.get(i) instanceof Non_playable) && (listOfViewer.get(i) instanceof Non_visual))  /* if type == text */
                    {
                        currentIndex = i;
                        break;
                    }
                }
            }
        }
        if((type == "image") && (flag == 0))  /* if the type is image */
        {
            for(i = currentIndex - 1; i >= 0; i--)
            {
                if((listOfViewer.get(i) instanceof Non_playable) && (listOfViewer.get(i) instanceof Visual))  /* if type == image */
                {
                    currentIndex = i;  /* equalization of the current index */
                    flag2 = 1;
                    break;
                }
            }
            if(flag2 == 0)  /* if there is no image object until begin of the list then go to end of the array and search again */
            {
                for(i = listOfViewer.size() - 1; i >= 0; i--)
                {
                    if((listOfViewer.get(i) instanceof Non_playable) && (listOfViewer.get(i) instanceof Visual))  /* if type == image */
                    {
                        currentIndex = i;
                        break;
                    }
                }
            }
        }
    }
}

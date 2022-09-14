public class Test {
    public static void main(String[] args) {
        Dataset ds = new Dataset();  /* create dataset */

        Player p1 = new Player();  /* create player1 */
        Player p2 = new Player();  /* create player2 */
        
        Viewer v1 = new Viewer();  /* create viewer1 */
        Viewer v2 = new Viewer();  /* create viewer2 */

        ds.register(p1);  /* registering */
        ds.register(p2);
        ds.register(v1);
        ds.register(v2);

        ds.add(new Image("image1", 1, 9.9));  /* adding new object */
        ds.add(new Audio("audio1", 4.4, 2.2));
        ds.add(new Image("image2", 7, 19.9));
        ds.add(new Video("video1", 3.3, 10));
        ds.add(new Text("text1", 5.5));
        ds.add(new Audio("audio2", 5.4, 8.2));
        ds.add(new Text("text2", 51.5));
        ds.add(new Audio("audio3", 43.14, 90.12));
        ds.add(new Text("text3", 51.11));
        ds.add(new Video("video2", 13.43, 5));
        ds.add(new Image("image3", 4, 8.9));

        System.out.println("\nPlayer list");
        p1.show_list();   /* print player list */
        Playable p0 = p1.currently_playing();  /* returns current player object */
        ds.remove(p0);  /* remove the object */
        System.out.println("\nRemoved object informations:");
        p0.info();  /* prints the informations of the object */
        System.out.println("\nPlayer list after removed object:");
        p1.show_list();

        System.out.println("\nViewer list");
        v1.show_list();
        Non_playable v0 = v1.currently_viewing();  /* returns current viewer object */
        ds.remove(v0);
        System.out.println("\nRemoved object informations:");
        v0.info();
        System.out.println("\nViewer list after removed object:");
        v1.show_list();

        ds.add(new Video("video3", 89.3, 90));  /* adding new objects */
        ds.add(new Text("text4", 77.5));
        ds.add(new Audio("audio4", 23.8, 7.2));
        ds.add(new Image("image4", 3, 87.2));

        System.out.println("\nPlayer list after adding new objects");
        p2.show_list();

        System.out.println("\nCurrent Player object informations:");
        Playable plyr0 = p2.currently_playing();
        plyr0.info();
        System.out.println();

        System.out.println("\nCurrent Player object informations after next(video):");
        p2.next("video");  /* go to next player object type of the video */
        plyr0 = p2.currently_playing();
        plyr0.info();
        System.out.println();

        System.out.println("\nCurrent Player object informations after next(video):");
        p2.next("video");
        plyr0 = p2.currently_playing();
        plyr0.info();
        System.out.println();

        System.out.println("\nCurrent Player object informations after previous(video):");
        p2.previous("video");  /* go to previous player object type of the video*/
        plyr0 = p2.currently_playing();
        plyr0.info();
        System.out.println();

        System.out.println("\nCurrent Player object informations after next(video):");
        p2.next("video");
        plyr0 = p2.currently_playing();
        plyr0.info();
        System.out.println();

        System.out.println("\nViewer list after adding new objects");
        v2.show_list();

        System.out.println("\nCurrent Viewer object informations:");
        Non_playable vievr0 = v2.currently_viewing();
        vievr0.info();
        System.out.println();

        System.out.println("\nCurrent Viewer object informations after next(text):");
        v2.next("text");   /* go to next viewer object type of the text */
        vievr0 = v2.currently_viewing();
        vievr0.info();
        System.out.println();

        System.out.println("\nCurrent Viewer object informations after next(text):");
        v2.next("text");
        vievr0 = v2.currently_viewing();
        vievr0.info();
        System.out.println();

        System.out.println("\nCurrent Viewer object informations after previous(text):");
        v2.previous("text");  /* go to previous viewer object type of the text */
        vievr0 = v2.currently_viewing();
        vievr0.info();
        System.out.println();

        System.out.println("\nCurrent Viewer object informations after next(text):");
        v2.next("text");
        vievr0 = v2.currently_viewing();
        vievr0.info();
        System.out.println();

        System.out.println("\nPlayer list");
        p2.show_list();

        System.out.println("\nCurrent Player object informations:");
        plyr0 = p2.currently_playing();
        plyr0.info();
        System.out.println();

        System.out.println("\nCurrent Player object informations after next(audio):");
        p2.next("audio");  /* go to next player object type of the audio */
        plyr0 = p2.currently_playing();
        plyr0.info();
        System.out.println();

        System.out.println("\nCurrent Player object informations after previous(audio):");
        p2.previous("audio");  /* go to previous player object type of the audio */
        plyr0 = p2.currently_playing();
        plyr0.info();
        System.out.println();

        System.out.println("\nCurrent Player object informations after next(audio):");
        p2.next("audio");
        plyr0 = p2.currently_playing();
        plyr0.info();
        System.out.println();

        System.out.println("\nCurrent Player object informations after next(audio):");
        p2.next("audio");
        plyr0 = p2.currently_playing();
        plyr0.info();
        System.out.println();

        System.out.println("\nViewer list");
        v2.show_list();

        System.out.println("\nCurrent Viewer object informations:");
        vievr0 = v2.currently_viewing();
        vievr0.info();
        System.out.println();

        System.out.println("\nCurrent Viewer object informations after next(image):");
        v2.next("image");   /* go to next viewer object type of the image */
        vievr0 = v2.currently_viewing();
        vievr0.info();
        System.out.println();

        System.out.println("\nCurrent Viewer object informations after previous(image):");
        v2.previous("image");   /* go to previous viewer object type of the image */
        vievr0 = v2.currently_viewing();
        vievr0.info();
        System.out.println();

        System.out.println("\nCurrent Viewer object informations after next(image):");
        v2.next("image");
        vievr0 = v2.currently_viewing();
        vievr0.info();
        System.out.println();

        System.out.println("\nPlayer List for Player1:");
        p1.show_list();
        System.out.println("\nPlayer List for Player2:");
        p2.show_list();

        ds.remove_observer(p2);  /* removing the player */
        System.out.println("\nPlayer2 is unregister");

        Playable pl = p1.currently_playing();
        ds.remove(pl);
        System.out.println("\nRemoved object informations:");
        pl.info();

        System.out.println("\nPlayer List for Player1:");
        p1.show_list();
        System.out.println("\nPlayer List for Player2:");    /* this is shows the player2 is not notify about the objects */
        p2.show_list();

        System.out.println("\nViewer List for Viewer1:");
        v1.show_list();
        System.out.println("\nViewer List for Viewer2:");
        v2.show_list();

        ds.remove_observer(v2);  /* removing the viewer */
        System.out.println("\nViewer2 is unregister");

        ds.add(new Text("text5", 98.1));
        System.out.println("\nNew text object is added");

        System.out.println("\nViewer List for Viewer1:");
        v1.show_list();
        System.out.println("\nViewer List for Viewer2:");   /* this is shows the viewer is not notify about the objects */
        v2.show_list();
    }
}
import java.util.ArrayList;
import scr.*;

/**
 * @author Fatma Nur Sefer
 * @version 1.0
 * @since 2020-01-05
 */

public class DayofYearSetMain{

    /**
	 * The main method runs tests.
	 * For the runs the code you have to write "make run" in the terminal.
	 * @param args Unused.
	 * @return Nothing.
	 */

    public static void main(String args[]){
        DayofYearSet s1 = new DayofYearSet();   /* creates the sets object */
        DayofYearSet s2 = new DayofYearSet();
        DayofYearSet s3 = new DayofYearSet();
        DayofYearSet s4 = new DayofYearSet();

        s1.add(2,3);   /* adds the values to set */
        s1.add(2,4);
        s1.add(4,17);
        s1.add(5,7);
        s1.add(11,9);
        s1.add(7,7);
        s1.add(7,9);
        s1.add(8,16);
        s1.add(7,29);

        System.out.print("\nS1: \n");
        System.out.print(s1.toString());   /* prints the set */
        System.out.print("\nSize of s1 is: " + s1.set_size + "\nAnd size of all sets is: " + DayofYearSet.get_count() + "\n\n");

        s2.add(11,9);   /* adds the values to set */
        s2.add(4,4);
        s2.add(2,3);
        s2.add(6,7);
        s2.add(5,3);
        s2.add(12,27);
        s2.add(10,19);
        s2.add(5,13);

        System.out.print("\nS2: \n");
        System.out.print(s2.toString());   /* prints the set */
        System.out.print("\nSize of s2 is: " + s2.set_size + "\nAnd size of all sets is: " + DayofYearSet.get_count() + "\n\n");

        boolean t = s1.equals(s2);  /* checks the sets are equal or not */
        System.out.print("\nS1 and S2 equal each other?(yes:true, no:false): " + t + "\n");

        s3 = (s1.unionSet(s2)).complementSet();   /* try union and complement functions */
        s4 = (s1.complementSet()).intersectionSet(s2.complementSet());   /* try complement and intersection functions */

        System.out.print("\nSize of s3 is " + s3.set_size + "\nAnd Size of s4 is: " + s4.set_size);

        t = s3.equals(s4);   /* test the de morgan */
        System.out.print("\n\nTesting De Morgan\nS3 and S4 equal each other?(yes:true, no:false): " + t + "\n");

        s3.write_file();   /* writes to file set */

        System.out.print("\nS1: \n");
        System.out.print(s1.toString());
        s1.remove(1);   /* removes 1. index of the set */
        System.out.print("\n\nRemoved elements which is the 1. index of the S1.\nS1: \n");
        System.out.print(s1.toString());
        s1.remove(3);   /* removes 3. index of the set */
        System.out.print("\n\nRemoved elements which is the 3. index of the S1.\nS1: \n");
        System.out.print(s1.toString());

        ArrayList<DayofYearSet.DayofYear> s5 = new ArrayList<DayofYearSet.DayofYear>();   /* create ArrayList object */
        s5.add(new DayofYearSet.DayofYear(10,7));   /* fill the array */
        s5.add(new DayofYearSet.DayofYear(5,9));
        s5.add(new DayofYearSet.DayofYear(2,25));
        s5.add(new DayofYearSet.DayofYear(8,3));
        s5.add(new DayofYearSet.DayofYear(6,11));
        s5.add(new DayofYearSet.DayofYear(9,22));
        s5.add(new DayofYearSet.DayofYear(4,25));

        DayofYearSet s6 = new DayofYearSet(s5);   /* takes the arrays value to the set */
        System.out.print("\nS6: \n");
        System.out.print(s6.toString());
        
        DayofYearSet s14 = new DayofYearSet();
        DayofYearSet s15 = new DayofYearSet();

        s14 = (s6.unionSet(s2)).complementSet();   /* try union and complement functions */
        s15 = (s6.complementSet()).intersectionSet(s2.complementSet());   /* try complement and intersection functions */

        System.out.print("\nSize of S14 is " + s14.set_size + "\nAnd Size of S15 is: " + s15.set_size);

        t = s14.equals(s15);   /* test the de morgan */
        System.out.print("\n\nTesting De Morgan\nS14 and S15 equal each other?(yes:true, no:false): " + t + "\n");

        DayofYearSet s7 = new DayofYearSet();
        DayofYearSet s8 = new DayofYearSet();
        DayofYearSet s9 = new DayofYearSet();

        s7.add(10,9);   /* fills the set */
        s7.add(8,3);
        s7.add(12,3);
        s7.add(6,7);
        s7.add(12,27);
        s7.add(5,13);
        s7.add(5,9);

        System.out.print("\nS7: \n");
        System.out.print(s7.toString());

        s8 = (s6.unionSet(s7)).complementSet();  /* try union and complement functions */
        s9 = (s6.complementSet()).intersectionSet(s7.complementSet());   /* try complement and intersection functions */

        System.out.print("\nSize of S8 is " + s8.set_size + "\nAnd Size of S9 is: " + s9.set_size);

        t = s8.equals(s9);   /* test de morgan */
        System.out.print("\n\nTesting De Morgan\nS8 and S9 equal each other?(yes:true, no:false): " + t + "\n");

        DayofYearSet s18 = new DayofYearSet();
        DayofYearSet s19 = new DayofYearSet();

        s18 = (s2.unionSet(s7)).complementSet();  /* try union and complement functions */
        s19 = (s2.complementSet()).intersectionSet(s7.complementSet());   /* try complement and intersection functions */

        System.out.print("\nSize of S18 is " + s18.set_size + "\nAnd Size of S19 is: " + s19.set_size);

        t = s18.equals(s19);   /* test de morgan */
        System.out.print("\n\nTesting De Morgan\nS18 and S19 equal each other?(yes:true, no:false): " + t + "\n");

        ArrayList<DayofYearSet.DayofYear> s10 = new ArrayList<DayofYearSet.DayofYear>();   /* create ArrayList object */
        s10.add(new DayofYearSet.DayofYear(1,7));   /* fills the array */
        s10.add(new DayofYearSet.DayofYear(11,24));
        s10.add(new DayofYearSet.DayofYear(12,25));
        s10.add(new DayofYearSet.DayofYear(6,7));
        s10.add(new DayofYearSet.DayofYear(7,13));
        s10.add(new DayofYearSet.DayofYear(6,10));
        s10.add(new DayofYearSet.DayofYear(5,13));
        s10.add(new DayofYearSet.DayofYear(9,12));
        s10.add(new DayofYearSet.DayofYear(2,15));

        DayofYearSet s11 = new DayofYearSet(s10);   /* takes the array values to the set */
        System.out.print("\ns11: \n");
        System.out.print(s11.toString());
        System.out.print("\nSize of s11 is: " + s11.set_size + "\n\n");

        DayofYearSet s16 = new DayofYearSet();
        DayofYearSet s17 = new DayofYearSet();

        s16 = (s1.unionSet(s11)).complementSet();  /* try union and complement functions */
        s17 = (s1.complementSet()).intersectionSet(s11.complementSet());   /* try complement and intersection functions */

        System.out.print("\nSize of S16 is " + s16.set_size + "\nAnd Size of S17 is: " + s17.set_size);

        t = s16.equals(s17);   /* test de morgan */
        System.out.print("\n\nTesting De Morgan\nS16 and S17 equal each other?(yes:true, no:false): " + t + "\n");

        s11.write_file(); /* writes to file */

        DayofYearSet s12 = new DayofYearSet();
        DayofYearSet s13 = new DayofYearSet();

        System.out.print("\n----TESTING DIFFERENCE OF THE SETS----\n");

        System.out.print("\ns1: \n");
        System.out.print(s1.toString());
        System.out.print("\ns2: \n");
        System.out.print(s2.toString());

        System.out.print("\nDifference of the S1 and S2: \n");
        s12 = s1.differenceSet(s2);

        System.out.print("\ns12: \n");
        System.out.print(s12.toString());

        System.out.print("\ns7: \n");
        System.out.print(s7.toString());
        System.out.print("\ns11: \n");
        System.out.print(s11.toString());

        System.out.print("\nDifference of the S7 and S11: \n");
        s13 = s7.differenceSet(s11);

        System.out.print("\ns13: \n");
        System.out.print(s13.toString());
    }
}
